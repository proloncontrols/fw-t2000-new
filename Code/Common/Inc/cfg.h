
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
//  C O N F I G U R A T I O N   S T R U C T U R E   F I E L D   T Y P E S
//-----------------------------------------------------------------------------
typedef uint8_t  CFG_DataModBusId_t;
typedef char     CFG_DataModBusName_t[CFG_MODBUS_NAME_SIZE];
typedef uint8_t  CFG_DataComBaudRate_t;
typedef uint8_t  CFG_DataComStopBits_t;
typedef uint8_t  CFG_DataComParity_t;
typedef uint8_t  CFG_DataScrLanguage_t;
typedef uint8_t  CFG_DataScrOrientation_t;
typedef uint16_t CFG_DataScrTimeout_t;
typedef uint8_t  CFG_DataEnvTempUnit_t;


//=============================================================================
//  C O N F I G U R A T I O N   S T R U C T U R E
//-----------------------------------------------------------------------------
#pragma pack(1)
typedef struct {
	CFG_DataModBusId_t       ModBusID;
	CFG_DataModBusName_t     ModBusName;
	CFG_DataComBaudRate_t    ComBaudRate;
	CFG_DataComStopBits_t    ComStopBits;
	CFG_DataComParity_t      ComParity;
	CFG_DataScrLanguage_t    ScrLanguage;
	CFG_DataScrOrientation_t ScrOrientation;
	CFG_DataScrTimeout_t     ScrTimeout;
	CFG_DataEnvTempUnit_t    EnvTempUnit;
} CFG_Data_t;
#pragma pack()


//=============================================================================
//  H O L D I N G   R E G I S T E R S
//-----------------------------------------------------------------------------
typedef enum {
	CfgHrDeviceType = 1,   //These are hardcoded values
	CfgHrSoftVer,          //
	CfgHrHardVer,          //
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
//  D E F A U L T S   V A L U E S
//-----------------------------------------------------------------------------
#define CFG_DEF_MODBUS_ADDRESS    ((CFG_DataModBusId_t)       123)
#define CFG_DEF_MODBUS_NAME       ((CFG_DataModBusName_t)    {'M','o','d','u','l','e','N','a','m','e',0,0,0,0,0,0})
#define CFG_DEF_COM_BAUDRATE      ((CFG_DataComBaudRate_t)    CfgComBaud57600)
#define CFG_DEF_COM_STOPBITS      ((CFG_DataComStopBits_t)    CfgComStop1)
#define CFG_DEF_COM_PARITY        ((CFG_DataComParity_t)      CfgComParityNone)
#define CFG_DEF_SCR_LANGUAGE      ((CFG_DataScrLanguage_t)    CfgScrLanEnglish)
#define CFG_DEF_SCR_ORIENTATION   ((CFG_DataScrOrientation_t) CfgScrOrientP)
#define CFG_DEF_SCR_TIMEOUT       ((CFG_DataScrTimeout_t)     0)
#define CFG_DEF_ENV_TEMP_UNIT     ((CFG_DataEnvTempUnit_t)    CfgEnvTempC)


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
CFG_EXTERN CFG_Data_t CFG_Data;


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void CFG_Load     (void);
extern void CFG_Save     (void);
extern void CFG_Modified (void);
extern void CFG_Read     (CFG_HoldingRegister_t Register, void* Data);
extern void CFG_Write    (CFG_HoldingRegister_t Register, void* Data);


#ifdef __cplusplus
}
#endif


#endif   //CFG_H































