
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
//         File : env.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Environmental elements (temperature/humidity/CO2)
//                header file
//=============================================================================
#ifndef ENV_H
#define ENV_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "main.h"


//=============================================================================
//  C O N F I G U R A T I O N
//-----------------------------------------------------------------------------
#define ENV_READ_INTERVAL            5000   //Retrieve sensor readings at 5 seconds interval
#define ENV_POWER_UP_DELAY           1500   //1.5 second (worst case is 1 second "SCD4x", so we give it 50% more)
#define ENV_DEVICE_DETECT_ATTEMPTS   100    //Check 100 times max per device
#define ENV_AVERAGE_SIZE             16     //Number of consecutive readings making up an average reading


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef enum {
	EnvDevPowerup,         //Sensor currently powering up (data is not available during this state)
	EnvDevNone,            //No sensor detected or sensor not responding
	EnvDevSHT4x,           //Sensirion parts SHT4x
	EnvDevSCD4x            //Sensirion parts SCD4x
} ENV_Device_t;

typedef struct {
	ENV_Device_t Device;   //Sensor type
	uint16_t     SN[3];    //Sensor serial number
	uint16_t     Temp;     //Temperature
	int16_t      TempC;    //Temperature degree C (multiplier applied)
	int16_t      TempF;    //Temperature degree F (multiplier applied)
//	float        TempC;    //Temperature degree C
//	float        TempF;    //Temperature degree F
	uint16_t     Hum;      //Humidity
	uint16_t     HumP;     //Humidity percentage (multiplier applied)
//	float        HumP;     //Humidity percentage
	uint16_t     CO2;      //CO2
} ENV_Readings_t;


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void ENV_Init (void);                       //Initialize environmental object
extern void ENV_Read (ENV_Readings_t* Readings);   //Retrieve environmental readings


#endif   //ENV_H
