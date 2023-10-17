
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
//         File : cfg.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Product configuration header file
//=============================================================================
#ifndef CFG_H
#define CFG_H


#ifdef CFG_GLOBAL
#define CFG_EXTERN
#else
#define CFG_EXTERN   extern
#endif


#ifdef __cplusplus
extern "C" {
#endif


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "main.h"
#include "basic.h"


//=============================================================================
//  V E R S I O N
//-----------------------------------------------------------------------------
#define CFG_VERSION   0x0001   //0.0.0.1


typedef enum {
	CfgHrDeviceType = 1,
	CfgHrSoftVer,
	CfgHrHardVer,

	CfgHrModBusID,
	CfgHrModBusName,

	CfgHrComBaudRate,
	CfgHrComStopBits,
	CfgHrComParity,

	CfgHrScrLanguage,
	CfgHrScrOrientation,
	CfgHrScrTimeout,

	CfgHrTempUnit
} CFG_HoldingRegister_t;

#define CFG_MODBUS_NAME_SIZE   16

#pragma pack(1)
typedef struct {
	uint8_t  ModBusID;
	char     ModBusName[CFG_MODBUS_NAME_SIZE];

	uint8_t  ComBaudRate;
	uint8_t  ComStopBits;
	uint8_t  ComParity;

	uint8_t  ScrLanguage;
	uint8_t  ScrOrientation;
	uint16_t ScrTimeout;

	uint8_t  EnvTempUnit;
} CFG_Data_t;
#pragma pack()

bool_t CFG_RegRead  (CFG_HoldingRegister_t Register, uint16_t Count, void* Data);
bool_t CFG_RegWrite (CFG_HoldingRegister_t Register, uint16_t Count, void* Data);

CFG_EXTERN CFG_Data_t CFG_Data;


//=============================================================================
//  D E F A U L T S
//-----------------------------------------------------------------------------
#define CFG_DEF_MODBUS_ADDRESS    123
#define CFG_DEF_MODBUS_NAME       "ModuleName"

#define CFG_DEF_COM_BAUDRATE      3
#define CFG_DEF_COM_STOPBITS      1
#define CFG_DEF_COM_PARITY        0

#define CFG_DEF_SCR_LANGUAGE      0
#define CFG_DEF_SCR_ORIENTATION   0
#define CFG_DEF_SCR_TIMEOUT       0

#define CFG_DEF_ENV_TEMP_UNIT     0




#define CFG_DEF_BAUDRATE    3     //0=9600 1=19200 2=38400 3=57600
#define CFG_DEF_PARITY      1     //0=none 1=odd 2=even
#define CFG_DEF_STOPBITS    2     //0=1 1=1.5 2=2
#define CFG_DEF_ADDRESS     123   //ModBus device address TODO: Change to correct value
#define CFG_DEF_ORIENTATION 0     //0=portrait 1=landscape
#define CFG_DEF_TIMEOUT     0     //In seconds (0=disabled)
#define CFG_DEF_TEMP_UNIT   0     //0=celsius 1=fahrenheit


//=============================================================================
//  E N U M S
//-----------------------------------------------------------------------------
//Screen orientation is based on the thermostat unit itself and not on the LCD unit.
//The LCD unit is the opposite of the thermostat.
typedef enum {
	CfgOrientP = 0,   //Portrait in relation to the thermostat (landscape for LCD)
	CfgOrientL        //Landscape in relation to the thermostat (portrait for LCD)
} CFG_Orientation_t;

typedef enum {
	CfgTempC = 0,
	CfgTempF
} CFG_TempUnit_t;


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
//#pragma pack(1)
//
//typedef struct {
//	uint16_t Version;
//	uint8_t  BaudRate;
//	uint8_t  Parity;
//	uint8_t  StopBits;
//	uint8_t  Address;
//	uint8_t  ScreenOrientation;
//	uint16_t ScreenTimeout;
//	uint8_t  TempUnit;
//} CFG_Config_t;
//
//#pragma pack()


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void CFG_Load     (CFG_Data_t* Cfg);
extern void CFG_Save     (CFG_Data_t* Cfg);
extern void CFG_Defaults (CFG_Data_t* Cfg);


#ifdef __cplusplus
}
#endif


#endif   //CFG_H































