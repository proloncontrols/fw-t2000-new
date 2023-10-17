
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
//  D E F I N E S
//-----------------------------------------------------------------------------
#define CFG_MODBUS_NAME_SIZE   16


//=============================================================================
//  D E F A U L T S   V A L U E S
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


//=============================================================================
//  H O L D I N G   R E G I S T E R S
//-----------------------------------------------------------------------------
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


//=============================================================================
//  E N U M S
//-----------------------------------------------------------------------------
typedef enum {
	CfgComBaud1200 = 0,
	CfgComBaud2400,
	CfgComBaud4800,
	CfgComBaud19200,
	CfgComBaud38400,
	CfgComBaud57600,
	CfgComBaud115200
} CFG_ComBaud_t;

typedef enum {
	CfgComStop1 = 0,
	CfgComStop1_5,
	CfgComStop2
} CFG_ComStop_t;

typedef enum {
	CfgComParityNone = 0,
	CfgComParityEven,
	CfgComParityOdd
} CFG_ComParity_t;

typedef enum {
	CfgScrLanEnglish = 0,
	CfgScrLanFrench
} CFG_ScrLanguage_t;

//Screen orientation is based on the thermostat unit itself, not on the LCD unit.
//LCD unit orientation is the opposite of thermostat's.
typedef enum {
	CfgScrOrientP = 0,   //Portrait in relation to the thermostat (landscape for LCD)
	CfgScrOrientL        //Landscape in relation to the thermostat (portrait for LCD)
} CFG_ScrOrientation_t;

typedef enum {
	CfgEnvTempC = 0,
	CfgEnvTempF
} CFG_EnvTempUnit_t;


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
CFG_EXTERN CFG_Data_t CFG_Data;


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void   CFG_Load     (CFG_Data_t* Cfg);
extern void   CFG_Save     (CFG_Data_t* Cfg);
extern bool_t CFG_RegRead  (CFG_HoldingRegister_t Register, void* Data);
extern bool_t CFG_RegWrite (CFG_HoldingRegister_t Register, void* Data);


#ifdef __cplusplus
}
#endif


#endif   //CFG_H































