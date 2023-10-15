
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
//         File : envSCD4x.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Environmental sensor (temperature/humidity/COs)
//                SCD4x device implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "env_scd4x.h"
#include "app.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define ENV_SCD4x_I2C_TIMEOUT            500     //500 milliseconds
#define ENV_SCD4x_I2C_BUSY_CHECK         100     //Check 100 times max

#define ENV_SCD4x_CRC_INITIAL            0xFF
#define ENV_SCD4x_CRC_POLYNOM            0x31

#define ENV_SCD4x_DELAY_START_PERIODIC   2       //  2 msec - No actual maximum delay (test showed around 1 msec, so 2 msec for +/- 1 msec)
#define ENV_SCD4x_DELAY_MEASUREMENT      2       //  2 msec - Actual maximum delay is 1 msec, so 2 msec for +/- 1 msec
#define ENV_SCD4x_DELAY_STOP_PERIODIC    510     //510 msec - Actual maximum delay is 500 msec
#define ENV_SCD4x_DELAY_GET_SN           2       //  2 msec - Actual maximum delay is 1 msec, so 2 msec for +/- 1 msec
#define ENV_SCD4x_DELAY_RESET            25      // 25 msec - Actual maximum delay is 20 msec
#define ENV_SCD4x_DELAY_INTER_COMMAND    10      // 10 msec delay between commands sent to sensor when executing multi-command sequence

#define ENV_SCD4x_HUMIDITY_0_PERCENT     3145    //Reading value for 0% humidity
#define ENV_SCD4x_HUMIDITY_100_PERCENT   55573   //Reading value for 100% humidity


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef enum {
	SCD4xStartPeriodic = 0x21B1,   //Start periodic measurement
	SCD4xMeasurement   = 0xEC05,   //Retrieve measurements
	SCD4xStopPeriodic  = 0x3F86,   //Stop periodic measurement
	SCD4xGetSN         = 0x3682,   //Retrieve sensor serial number
	SCD4xReset         = 0x3646    //Reset sensor
} ENV_SCD4x_Cmd_t;

typedef struct {
	ENV_SCD4x_Cmd_t Command;
	uint16_t        Delay;
} ENV_SCD4x_Command_t;

#pragma pack(1)
typedef struct {
	uint16_t Data;
	uint8_t  Checksum;
} ENV_SCD4x_Result_t;
#pragma pack()


//=============================================================================
//  P R O T O T Y P E S
//-----------------------------------------------------------------------------
static uint8_t ENV_SCD4x_CalculateCRC (void* Data, uint16_t Len);


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void ENV_SCD4x_Read(ENV_Readings_t* Readings)
{
	ENV_SCD4x_Cmd_t Command;
	ENV_SCD4x_Result_t Result[3];

	//Send read command
	Command = __REVSH(SCD4xMeasurement);
	if(HAL_I2C_Master_Transmit(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, (uint8_t*)&Command, 1, ENV_SCD4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Wait for read command approximate completion time to elapse
	osDelay(ENV_SCD4x_DELAY_MEASUREMENT);

	//Wait for read command cycle to actually complete
	if(HAL_I2C_IsDeviceReady(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, ENV_SCD4x_I2C_BUSY_CHECK, ENV_SCD4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Read data
	if(HAL_I2C_Master_Receive(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, (uint8_t*)&Result, sizeof(Result), ENV_SCD4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Validate data integrity (CRC)
	if((ENV_SCD4x_CalculateCRC(&Result[0], sizeof(ENV_SCD4x_Result_t)) != 0) || (ENV_SCD4x_CalculateCRC(&Result[1], sizeof(ENV_SCD4x_Result_t)) != 0) || (ENV_SCD4x_CalculateCRC(&Result[2], sizeof(ENV_SCD4x_Result_t)) != 0))
		return;

	//Convert data and load readings
	Readings->Temp = __REVSH(Result[1].Data);

	Readings->Hum = __REVSH(Result[2].Data);
	if(Readings->Hum < ENV_SCD4x_HUMIDITY_0_PERCENT)          //Crop humidity readings outside 0-100% boundaries
		Readings->Hum = ENV_SCD4x_HUMIDITY_0_PERCENT;         //
	else if(Readings->Hum > ENV_SCD4x_HUMIDITY_100_PERCENT)   //
		Readings->Hum = ENV_SCD4x_HUMIDITY_100_PERCENT;       //

	Readings->CO2 = __REVSH(Result[0].Data);
}

//-----------------------------------------------------------------------------
void ENV_SCD4x_Reset(ENV_Readings_t* Readings)
{
	ENV_SCD4x_Cmd_t Command;
	ENV_SCD4x_Result_t Result[3];

	//Send stop periodic measurement command
	Command = __REVSH(SCD4xStopPeriodic);
	if(HAL_I2C_Master_Transmit(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, (uint8_t*)&Command, sizeof(ENV_SCD4x_Cmd_t), ENV_SCD4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Wait for stop periodic measurement command approximate completion time to elapse
	osDelay(ENV_SCD4x_DELAY_STOP_PERIODIC);

	//Wait for stop periodic measurement command cycle to actually complete
	HAL_I2C_IsDeviceReady(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, ENV_SCD4x_I2C_BUSY_CHECK, ENV_SCD4x_I2C_TIMEOUT);

	//Wait inter-command delay
	osDelay(ENV_SCD4x_DELAY_INTER_COMMAND);

	//Send reset command
	Command = __REVSH(SCD4xReset);
	if(HAL_I2C_Master_Transmit(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, (uint8_t*)&Command, sizeof(ENV_SCD4x_Cmd_t), ENV_SCD4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Wait for reset command approximate completion time to elapse
	osDelay(ENV_SCD4x_DELAY_RESET);

	//Wait for reset command cycle to actually complete
	HAL_I2C_IsDeviceReady(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, ENV_SCD4x_I2C_BUSY_CHECK, ENV_SCD4x_I2C_TIMEOUT);

	//Send serial number command
	Command = __REVSH(SCD4xGetSN);
	if(HAL_I2C_Master_Transmit(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, (uint8_t*)&Command, sizeof(ENV_SCD4x_Cmd_t), ENV_SCD4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Wait for serial number command approximate completion time to elapse
	osDelay(ENV_SCD4x_DELAY_GET_SN);

	//Wait for serial number command cycle to actually complete
	if(HAL_I2C_IsDeviceReady(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, ENV_SCD4x_I2C_BUSY_CHECK, ENV_SCD4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Read serial number
	if(HAL_I2C_Master_Receive(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, (uint8_t*)&Result, sizeof(Result), ENV_SCD4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Validate serial number integrity (CRC)
	if((ENV_SCD4x_CalculateCRC(&Result[0], sizeof(ENV_SCD4x_Result_t)) != 0) || (ENV_SCD4x_CalculateCRC(&Result[1], sizeof(ENV_SCD4x_Result_t)) != 0) || (ENV_SCD4x_CalculateCRC(&Result[2], sizeof(ENV_SCD4x_Result_t)) != 0))
		return;

	//Load serial number
	Readings->SN[0] = __REVSH(Result[0].Data);
	Readings->SN[1] = __REVSH(Result[1].Data);
	Readings->SN[2] = __REVSH(Result[2].Data);

	//Wait inter-command delay
	osDelay(ENV_SCD4x_DELAY_INTER_COMMAND);

	//Send start periodic measurement command
	Command = __REVSH(SCD4xStartPeriodic);
	if(HAL_I2C_Master_Transmit(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, (uint8_t*)&Command, sizeof(ENV_SCD4x_Cmd_t), ENV_SCD4x_I2C_TIMEOUT) != HAL_OK)
		return;

	//Wait for start periodic measurement command approximate completion time to elapse
	osDelay(ENV_SCD4x_DELAY_START_PERIODIC);

	//Wait for start periodic measurement command cycle to actually complete
	HAL_I2C_IsDeviceReady(&APP_I2C_HW, ENV_SCD4x_I2C_ADDRESS, ENV_SCD4x_I2C_BUSY_CHECK, ENV_SCD4x_I2C_TIMEOUT);
}

//-----------------------------------------------------------------------------
void ENV_SCD4x_Format(ENV_Readings_t* Readings)
{
	Readings->TempC = -45.0 + (175.0 * Readings->Temp / 65535);
	Readings->TempF = -49.0 + (315.0 * Readings->Temp / 65535);
	Readings->HumP  = -6.0  + (125.0 * Readings->Hum  / 65535);
}


//=============================================================================
//  P R I V A T E S
//-----------------------------------------------------------------------------
static uint8_t ENV_SCD4x_CalculateCRC(void* Data, uint16_t Len)
{
    uint8_t TheCRC = ENV_SCD4x_CRC_INITIAL;

    for(uint16_t i = 0; i < Len; i++)
    {
    	TheCRC ^= *(uint8_t*)(Data + i);
    	for(uint16_t j = 0; j < 8; j++)
    	{
    		if(TheCRC & 0x80)
    			TheCRC = (TheCRC << 1) ^ ENV_SCD4x_CRC_POLYNOM;
    		else
    			TheCRC <<= 1;
    	}
    }
	return TheCRC;
}
