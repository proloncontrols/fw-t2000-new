
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
//-----------------------------------------------------------------------------
//         File : envSHT4x.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Environmental sensor (temperature/humidity)
//                SHT4x device implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "env_sht4x.h"
#include "app.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define ENV_SHT4x_I2C_TIMEOUT              500     //500 milliseconds
#define ENV_SHT4x_I2C_BUSY_CHECK           100     //Check 100 times max

#define ENV_SHT4x_CRC_INITIAL              0xFF
#define ENV_SHT4x_CRC_POLYNOM              0x31

#define ENV_SHT4x_DELAY_READ_SN            2       //   2 msec - No actual maximum delay (test showed around 1 msec, so 2 msec for +/- 1 msec)
#define ENV_SHT4x_DELAY_PRECISION_HIGH     10      //  10 msec - Actual maximum delay is 8.3 msec
#define ENV_SHT4x_DELAY_PRECISION_MEDIUM   5       //   5 msec - Actual maximum delay is 4.5 msec
#define ENV_SHT4x_DELAY_PRECISION_LOW      2       //   2 msec - Actual maximum delay is 1.6 msec
#define ENV_SHT4x_DELAY_HEATING_LONG       1200    //1200 msec - Actual maximum delay is 1190 msec
#define ENV_SHT4x_DELAY_HEATING_SHORT      125     // 125 msec - Actual maximum delay is 120 msec
#define ENV_SHT4x_DELAY_RESET              2       //   2 msec - Actual maximum delay is 1 msec, so 2 msec for +/- 1 msec
#define ENV_SHT4x_DELAY_INTER_COMMAND      10      //  10 msec delay between commands sent to sensor when executing multi-command sequence

#define ENV_SHT4x_HUMIDITY_0_PERCENT       3145    //Reading value for 0% humidity
#define ENV_SHT4x_HUMIDITY_100_PERCENT     55573   //Reading value for 100% humidity

//#define ENV_SHT4x_COMMAND_GET_SN           0x89
//#define ENV_SHT4x_COMMAND_RESET            0x94


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef enum {
	SHT4xPrecisionHigh   = 0xFD,   //Measure T & RH with high precision (high repeatability)
	SHT4xPrecisionMedium = 0xF6,   //Measure T & RH with medium precision (medium repeatability)
	SHT4xPrecisionLow    = 0xE0,   //Measure T & RH with lowest precision (low repeatability)
	SHT4xHeat200Long     = 0x39,   //Activate heater with 200mW for 1s,   including a high precision measurement just before deactivation
	SHT4xHeat200Short    = 0x32,   //Activate heater with 200mW for 0.1s, including a high precision measurement just before deactivation
	SHT4xHeat110Long     = 0x2F,   //Activate heater with 110mW for 1s,   including a high precision measurement just before deactivation
	SHT4xHeat110Short    = 0x24,   //Activate heater with 110mW for 0.1s, including a high precision measurement just before deactivation
	SHT4xHeat20Long      = 0x1E,   //Activate heater with 20mW  for 1s,   including a high precision measurement just before deactivation
	SHT4xHeat20Short     = 0x15,   //Activate heater with 20mW  for 0.1s, including a high precision measurement just before deactivation
	SHT4xGetSN           = 0x89,
	SHT4xReset           = 0x94
} ENV_SHT4x_Cmd_t;

typedef struct {
	ENV_SHT4x_Cmd_t Command;
	uint16_t        Delay;
} ENV_SHT4x_Command_t;

#pragma pack(1)
typedef struct {
	uint16_t Data;
	uint8_t  Checksum;
} ENV_SHT4x_Result_t;
#pragma pack()


//=============================================================================
//  C O N S T A N T S
//-----------------------------------------------------------------------------
// Only 1 measurement mode at a time is supported.
// Uncomment the one required.
const ENV_SHT4x_Command_t ENV_SHT4x_Command =
{ SHT4xPrecisionHigh,   ENV_SHT4x_DELAY_PRECISION_HIGH   }
//{ SHT4xPrecisionMedium, ENV_SHT4x_DELAY_PRECISION_MEDIUM }
//{ SHT4xPrecisionLow,    ENV_SHT4x_DELAY_PRECISION_LOW    }
//{ SHT4xHeat200Long,     ENV_SHT4x_DELAY_HEATING_LONG     }
//{ SHT4xHeat200Short,    ENV_SHT4x_DELAY_HEATING_SHORT    }
//{ SHT4xHeat110Long,     ENV_SHT4x_DELAY_HEATING_LONG     }
//{ SHT4xHeat110Short,    ENV_SHT4x_DELAY_HEATING_SHORT    }
//{ SHT4xHeat20Long,      ENV_SHT4x_DELAY_HEATING_LONG     }
//{ SHT4xHeat20Short,     ENV_SHT4x_DELAY_HEATING_SHORT    }
;


//=============================================================================
//  P R O T O T Y P E S
//-----------------------------------------------------------------------------
static uint8_t ENV_SHT4x_CalculateCRC (void* Data, uint16_t Len);


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void ENV_SHT4x_Read(ENV_Readings_t* Readings)
{
	ENV_SHT4x_Result_t Result[2];

	//Send read command
	if(HAL_I2C_Master_Transmit(&APP_I2C_HW, ENV_SHT4x_I2C_ADDRESS, (uint8_t*)&ENV_SHT4x_Command, 1, ENV_SHT4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Wait for read command approximate completion time to elapse
	osDelay(ENV_SHT4x_Command.Delay);

	//Wait for read command cycle to actually complete
	if(HAL_I2C_IsDeviceReady(&APP_I2C_HW, ENV_SHT4x_I2C_ADDRESS, ENV_SHT4x_I2C_BUSY_CHECK, ENV_SHT4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Read data
	if(HAL_I2C_Master_Receive(&APP_I2C_HW, ENV_SHT4x_I2C_ADDRESS, (uint8_t*)&Result, sizeof(Result), ENV_SHT4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Validate data integrity (CRC)
	if((ENV_SHT4x_CalculateCRC(&Result[0], sizeof(ENV_SHT4x_Result_t)) != 0) || (ENV_SHT4x_CalculateCRC(&Result[1], sizeof(ENV_SHT4x_Result_t)) != 0))
		return;

	//Convert data and load readings
	Readings->Temp = __REVSH(Result[0].Data);

	Readings->Hum = __REVSH(Result[1].Data);
	if(Readings->Hum < ENV_SHT4x_HUMIDITY_0_PERCENT)          //Crop humidity readings outside 0-100% boundaries
		Readings->Hum = ENV_SHT4x_HUMIDITY_0_PERCENT;         //
	else if(Readings->Hum > ENV_SHT4x_HUMIDITY_100_PERCENT)   //
		Readings->Hum = ENV_SHT4x_HUMIDITY_100_PERCENT;       //

	Readings->CO2 = 0;
}

//-----------------------------------------------------------------------------
void ENV_SHT4x_Reset(ENV_Readings_t* Readings)
{
	ENV_SHT4x_Cmd_t Command;
	ENV_SHT4x_Result_t Result[2];

	//Send reset command
	Command = SHT4xReset;
	if(HAL_I2C_Master_Transmit(&APP_I2C_HW, ENV_SHT4x_I2C_ADDRESS, &Command, sizeof(ENV_SHT4x_Cmd_t), ENV_SHT4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Wait for reset command approximate completion time to elapse
	osDelay(ENV_SHT4x_DELAY_RESET);

	//Wait for reset command cycle to actually complete
	HAL_I2C_IsDeviceReady(&APP_I2C_HW, ENV_SHT4x_I2C_ADDRESS, ENV_SHT4x_I2C_BUSY_CHECK, ENV_SHT4x_I2C_TIMEOUT);

	//Wait inter-command delay
	osDelay(ENV_SHT4x_DELAY_INTER_COMMAND);

	//Send serial number command
	Command = SHT4xGetSN;
	if(HAL_I2C_Master_Transmit(&APP_I2C_HW, ENV_SHT4x_I2C_ADDRESS, &Command, sizeof(ENV_SHT4x_Cmd_t), ENV_SHT4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Wait for serial number command approximate completion time to elapse
	osDelay(ENV_SHT4x_DELAY_READ_SN);

	//Wait for serial number command cycle to actually complete
	if(HAL_I2C_IsDeviceReady(&APP_I2C_HW, ENV_SHT4x_I2C_ADDRESS, ENV_SHT4x_I2C_BUSY_CHECK, ENV_SHT4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Read serial number
	if(HAL_I2C_Master_Receive(&APP_I2C_HW, ENV_SHT4x_I2C_ADDRESS, (uint8_t*)&Result, sizeof(Result), ENV_SHT4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Validate serial number integrity (CRC)
	if((ENV_SHT4x_CalculateCRC(&Result[0], sizeof(ENV_SHT4x_Result_t)) != 0) || (ENV_SHT4x_CalculateCRC(&Result[1], sizeof(ENV_SHT4x_Result_t)) != 0))
		return;

	//Load serial number
	Readings->SN[0] = Result[0].Data;
	Readings->SN[1] = Result[1].Data;
}

//-----------------------------------------------------------------------------
void ENV_SHT4x_Format(ENV_Readings_t* Readings)
{
	Readings->TempC =  (int16_t)((-45.0 + (175.0 * Readings->Temp / 65535)) * 100.0);
	Readings->TempF =  (int16_t)((-49.0 + (315.0 * Readings->Temp / 65535)) * 100.0);
	Readings->HumP  = (uint16_t)((-6.0  + (125.0 * Readings->Hum  / 65535)) * 100.0);
//	Readings->TempC = -45.0 + (175.0 * Readings->Temp / 65535);
//	Readings->TempF = -49.0 + (315.0 * Readings->Temp / 65535);
//	Readings->HumP  = -6.0  + (125.0 * Readings->Hum  / 65535);
}


//=============================================================================
//  P R I V A T E S
//-----------------------------------------------------------------------------
static uint8_t ENV_SHT4x_CalculateCRC(void* Data, uint16_t Len)
{
    uint8_t TheCRC = ENV_SHT4x_CRC_INITIAL;

    for(uint16_t i = 0; i < Len; i++)
    {
    	TheCRC ^= *(uint8_t*)(Data + i);
    	for(uint16_t j = 0; j < 8; j++)
    	{
    		if(TheCRC & 0x80)
    			TheCRC = (TheCRC << 1) ^ ENV_SHT4x_CRC_POLYNOM;
    		else
    			TheCRC <<= 1;
    	}
    }
	return TheCRC;
}
