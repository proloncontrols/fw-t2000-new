
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
#include "modbus.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define CFG_MB_REG_COUNT   71       //***IMPORTANT*** This value MUST match the number of elements in structure APP_Registers
#define CFG_MB_LOC_SIZE    16
#define CFG_MB_ADD_MIN     0x0001   //TBD
#define CFG_MB_ADD_MAX     0xFFFE   //
#define CFG_MB_QTY_MIN     1
#define CFG_MB_QTY_MAX     125


//=============================================================================
//  C O N F I G U R A T I O N   P A R A M E T E R S   D E F I N I T I O N
//-----------------------------------------------------------------------------
typedef enum {
	CfgComBaud9600 = 0,
	CfgComBaud19200,
	CfgComBaud38400,
	CfgComBaud57600,
	CfgComBaud76800,
	CfgComBaud115200
} CFG_ComBaud_t;

typedef enum {
	CfgComParityNone = 0,
	CfgComParityOdd,
	CfgComParityEven
} CFG_ComParity_t;

typedef enum {
	CfgComStopBits1 = 0,
	CfgComStopBits2
} CFG_ComStop_t;

typedef enum {
	CfgScrLanEnglish = 0,
	CfgScrLanFrench
} CFG_ScrLanguage_t;

typedef enum {
	CfgEnvTempC = 0,
	CfgEnvTempF
} CFG_EnvTempUnit_t;

//Screen orientation is based on the thermostat unit itself, not on the LCD unit.
//LCD unit orientation is the opposite of thermostat's.
typedef enum {
	CfgScrOrientP = 0,   //Portrait in relation to the thermostat (landscape for LCD)
	CfgScrOrientL        //Landscape in relation to the thermostat (portrait for LCD)
} CFG_ScrOrientation_t;


//=============================================================================
//  C O N F I G U R A T I O N   D A T A
//-----------------------------------------------------------------------------
#pragma pack(1)
typedef struct {
	uint8_t  DevType;
	uint16_t SoftVer;
	uint16_t HardVer;
} CFG_Product_t;

typedef struct {
	int16_t  DefHeatSP;
	int16_t  DefCoolSP;
	int16_t  Prop;
	uint8_t  CoolInt;
	uint8_t  HeatInt;
	int16_t  MinHeatSP;
	int16_t  MaxHeatSP;
	int16_t  MinCoolSP;
	int16_t  MaxCoolSP;
	int16_t  UnocHeatOff;
	int16_t  UnocCoolOff;
	int16_t  UnocHeatSPLim;
	int16_t  UnocCoolSPLim;
	uint8_t  DOSource;
	int8_t   DOSP;
	uint8_t  DOMode;
	int8_t   DOBand;
	uint8_t  DORevAct;
	uint8_t  AOSource;
	int8_t   AOSP;
	uint8_t  AOMode;
	int8_t   AOBand;
	uint8_t  AORevAct;
	uint8_t  AOPulsed;
	uint8_t  AORange;
	uint8_t  GrpCode1;
	uint8_t  GrpCode2;
	uint8_t  GrpCode3;
	uint8_t  GrpWeight1;
	uint8_t  GrpWeight2;
	uint8_t  GrpWeight3;
	uint8_t  GblWeight;
	int16_t  RoomTempCal;
	uint8_t  UnocModeOverrTime;
	uint8_t  RadFloorId;
	int16_t  MinSlabTemp;
	int16_t  MaxSlabTemp;
	int16_t  MinSlabTempUnoc;
	int16_t  OutTempRadCutOff;
	int16_t  RadProp;
	uint16_t RadInt;
	int16_t  CalAuxInTemp;
	uint16_t RadCycleTime;
	uint8_t  AIMode;
	uint8_t  MorningWarmUpTime;
	//-----------------------
	uint8_t  Address;
	uint8_t  TempUnit;
	uint8_t  Location[CFG_MB_LOC_SIZE];
	uint8_t  BaudRate;
	uint8_t  Parity;
	uint8_t  StopBits;
	uint8_t  Language;
	//-----------------------
	int16_t  DisMinSP;
	int16_t  DisMidSP;
	int16_t  DisMaxSP;
	int8_t   DisMinDem;
	int8_t   DisMidDem;
	int8_t   DisMaxDem;
	int16_t  DisProp;
	uint8_t  DisInt;
	uint8_t  DisMode;
	uint8_t  IntDropRate;
	int8_t   DOOverr;
	int8_t   AOOverr;
	uint8_t  SchOverr;
	//-----------------------
	uint8_t  ScrOrientation;
	uint8_t  ScrBrightness;
	uint16_t ScrTimeout;
} CFG_Data_t;

typedef struct {
	CFG_Product_t Prd;
	CFG_Data_t    Dta;
} CFG_t;
#pragma pack()


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
CFG_EXTERN CFG_t CFG;


//=============================================================================
//  M O D B U S   R E G I S T E R S   D E F I N I T I O N
//-----------------------------------------------------------------------------
extern const MB_Register_t CFG_Registers[];
extern const uint16_t      CFG_RegisterCount;


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void CFG_Load     (void);
extern void CFG_Save     (void);
extern void CFG_Modified (void);


#ifdef __cplusplus
}
#endif


#endif   //CFG_H































