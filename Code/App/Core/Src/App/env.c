
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2023
//-----------------------------------------------------------------------------
//         File : env.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Environmental elements (temperature/humidity/CO2)
//                implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "env.h"
#include "env_sht4x.h"
#include "env_scd4x.h"
#include "event.h"
#include "app.h"
#include "framework.h"


//=============================================================================
//  C O N S T A N T S
//-----------------------------------------------------------------------------
static const osThreadAttr_t ENV_ThreadAttributes =
{
	.name       = "ENVThread",
    .stack_size = 128 * 4,
    .priority   = (osPriority_t)osPriorityNormal,
};


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef struct {
	osThreadId_t   ThreadId;
	osMutexId_t    MutexId;
	ENV_Readings_t Data;
	uint32_t       TempAvg;
	uint32_t       HumAvg;
	uint32_t       CO2Avg;
	uint16_t       TempBuffer[ENV_AVERAGE_SIZE];
	uint16_t       HumBuffer[ENV_AVERAGE_SIZE];
	uint16_t       CO2Buffer[ENV_AVERAGE_SIZE];
	bool_t         FirstReading;
	void         (*ReadDevice)  (ENV_Readings_t* Readings);   //Polymorphism - sensor data reading
	void         (*ResetDevice) (ENV_Readings_t* Readings);   //Polymorphism - sensor reset
	void         (*Format)      (ENV_Readings_t* Readings);   //Polymorphism - format raw readings
} ENV_t;


//=============================================================================
//  V A R I A B L E S
//-----------------------------------------------------------------------------
static ENV_t ENV;


//=============================================================================
//  P R O T O T Y P E S
//-----------------------------------------------------------------------------
static void ENV_AcquireData (void);
static void ENV_ReleaseData (void);
static void ENV_Thread      (void* Argument);


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void ENV_Init(void)
{
	ENV.MutexId = osMutexNew(NULL);
	if(ENV.MutexId == NULL)
		Error_Handler();

	ENV.ThreadId = osThreadNew(ENV_Thread, NULL, &ENV_ThreadAttributes);
	if(ENV.ThreadId == NULL)
		Error_Handler();
}

//-----------------------------------------------------------------------------
void ENV_Read(ENV_Readings_t* Readings)
{
	if(ENV.Data.Device > EnvDevNone)
	{
		ENV_AcquireData();

		//Perform averages and format data
		ENV.TempAvg = 0;
		for(int i = 0; i < ENV_AVERAGE_SIZE; i++)
			ENV.TempAvg += ENV.TempBuffer[i];
		ENV.Data.Temp = (uint16_t)(ENV.TempAvg / ENV_AVERAGE_SIZE);
		ENV.Data.TempC = 0.0;
		ENV.Data.TempF = 0.0;

		ENV.HumAvg = 0;
		for(int i = 0; i < ENV_AVERAGE_SIZE; i++)
			ENV.HumAvg += ENV.HumBuffer[i];
		ENV.Data.Hum = (uint16_t)(ENV.HumAvg / ENV_AVERAGE_SIZE);
		ENV.Data.HumP = 0.0;

		ENV.CO2Avg = 0;
		for(int i = 0; i < ENV_AVERAGE_SIZE; i++)
			ENV.CO2Avg += ENV.CO2Buffer[i];
		ENV.Data.CO2 = (uint16_t)(ENV.CO2Avg / ENV_AVERAGE_SIZE);

		ENV.Format(&ENV.Data);

		memcpy(Readings, &ENV.Data, sizeof(ENV_Readings_t));

		ENV_ReleaseData();
	}
}


//=============================================================================
//  P R I V A T E S
//-----------------------------------------------------------------------------
static void ENV_AcquireData(void)
{
	//TODO: Validate timeout
	if(osMutexAcquire(ENV.MutexId, osWaitForever) != osOK)
		Error_Handler();
}

//-----------------------------------------------------------------------------
static void ENV_ReleaseData(void)
{
	if(osMutexRelease(ENV.MutexId) != osOK)
		Error_Handler();
}

//-----------------------------------------------------------------------------
static void ENV_Thread(void* Argument)
{
	osDelay(ENV_POWER_UP_DELAY);

	ENV_AcquireData();

	if(HAL_I2C_IsDeviceReady(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, ENV_DEVICE_DETECT_ATTEMPTS, HAL_MAX_DELAY) == HAL_OK)
	{
		ENV.Data.Device = EnvDevSCD4x;
		ENV.ReadDevice = ENV_SCD4x_Read;
		ENV.ResetDevice = ENV_SCD4x_Reset;
		ENV.Format = ENV_SCD4x_Format;
	}
	else if(HAL_I2C_IsDeviceReady(&APP_I2C_HW, ENV_SHT4x_I2C_ADDRESS, ENV_DEVICE_DETECT_ATTEMPTS, HAL_MAX_DELAY) == HAL_OK)
	{
		ENV.Data.Device = EnvDevSHT4x;
		ENV.ReadDevice = ENV_SHT4x_Read;
		ENV.ResetDevice = ENV_SHT4x_Reset;
		ENV.Format = ENV_SHT4x_Format;
	}

	if(ENV.Data.Device > EnvDevNone)
	{
		ENV.ResetDevice(&ENV.Data);
		ENV.FirstReading = TRUE;
	}

	ENV_ReleaseData();

	while(1)
	{
		osDelay(ENV_READ_INTERVAL);

		ENV_AcquireData();

		if(ENV.Data.Device > EnvDevNone)
		{
			ENV.ReadDevice(&ENV.Data);

			if(ENV.FirstReading)
			{
				//Fill buffers with first readings in order to perform averages
				for(int i = 0; i < ENV_AVERAGE_SIZE; i++)
					ENV.TempBuffer[i] = ENV.Data.Temp;

				for(int i = 0; i < ENV_AVERAGE_SIZE; i++)
					ENV.HumBuffer[i] = ENV.Data.Hum;

				for(int i = 0; i < ENV_AVERAGE_SIZE; i++)
					ENV.CO2Buffer[i] = ENV.Data.CO2;
			}
			else
			{
				//Insert new readings
				for(int i = 0; i < ENV_AVERAGE_SIZE-1; i++)
					ENV.TempBuffer[i] = ENV.TempBuffer[i+1];
				ENV.TempBuffer[ENV_AVERAGE_SIZE-1] = ENV.Data.Temp;

				for(int i = 0; i < ENV_AVERAGE_SIZE-1; i++)
					ENV.HumBuffer[i] = ENV.HumBuffer[i+1];
				ENV.HumBuffer[ENV_AVERAGE_SIZE-1] = ENV.Data.Hum;

				for(int i = 0; i < ENV_AVERAGE_SIZE-1; i++)
					ENV.CO2Buffer[i] = ENV.CO2Buffer[i+1];
				ENV.CO2Buffer[ENV_AVERAGE_SIZE-1] = ENV.Data.CO2;
			}

			ENV.FirstReading = FALSE;
		}

		ENV_ReleaseData();

		FMK_PostFlag(NUM2POS(EvtGrpEnv));
//		FMK_PostFlag(EnvFlag);
	}
}
