
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
#define CFG_MB_LOC_SIZE   16

#define CFG_MB_ADD_MIN    0x0001   //TBD
#define CFG_MB_ADD_MAX    0xFFFE   //
#define CFG_MB_QTY_MIN    1
#define CFG_MB_QTY_MAX    125


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
//  S P E C I F I C   D A T A   T Y P E S   D E F I N I T I O N
//-----------------------------------------------------------------------------
//typedef enum {
//	RegType8 = 0,
//	RegType16,
//	RegTypeLoc,
//	RegTypeTemp,
//	RegTypePercent
//} CFG_RegType_t;

//typedef uint8_t  Type8_t;
//typedef uint16_t Type16_t;
//typedef int16_t  TypeTemp_t;
//typedef int8_t   TypePercent_t;

//typedef uint16_t Multiplier_t;

//typedef struct {
//	uint16_t      Number;
//	CFG_RegType_t Type;
//	Multiplier_t  Multiplier;
//	void*         RamAddress;
//} CFG_RegFormat_t;


//=============================================================================
//  C O N F I G U R A T I O N   D A T A   S T R U C T U R E S   I N   R A M
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
//#pragma pack(1)
//typedef struct {
//	MB_8bit_t    DevType;
//	MB_16bit_t   SoftVer;
//	MB_16bit_t   HardVer;
//} CFG_Product_t;
//
//typedef struct {
//	MB_Temp_t    DefHeatSP;
//	MB_Temp_t    DefCoolSP;
//	MB_Temp_t    Prop;
//	MB_8bit_t    CoolInt;
//	MB_8bit_t    HeatInt;
//	MB_Temp_t    MinHeatSP;
//	MB_Temp_t    MaxHeatSP;
//	MB_Temp_t    MinCoolSP;
//	MB_Temp_t    MaxCoolSP;
//	MB_Temp_t    UnocHeatOff;
//	MB_Temp_t    UnocCoolOff;
//	MB_Temp_t    UnocHeatSPLim;
//	MB_Temp_t    UnocCoolSPLim;
//	MB_8bit_t    DOSource;
//	MB_Percent_t DOSP;
//	MB_8bit_t    DOMode;
//	MB_Percent_t DOBand;
//	MB_8bit_t    DORevAct;
//	MB_8bit_t    AOSource;
//	MB_Percent_t AOSP;
//	MB_8bit_t    AOMode;
//	MB_Percent_t AOBand;
//	MB_8bit_t    AORevAct;
//	MB_8bit_t    AOPulsed;
//	MB_8bit_t    AORange;
//	MB_8bit_t    GrpCode1;
//	MB_8bit_t    GrpCode2;
//	MB_8bit_t    GrpCode3;
//	MB_8bit_t    GrpWeight1;
//	MB_8bit_t    GrpWeight2;
//	MB_8bit_t    GrpWeight3;
//	MB_8bit_t    GblWeight;
//	MB_Temp_t    RoomTempCal;
//	MB_8bit_t    UnocModeOverrTime;
//	MB_8bit_t    RadFloorId;
//	MB_Temp_t    MinSlabTemp;
//	MB_Temp_t    MaxSlabTemp;
//	MB_Temp_t    MinSlabTempUnoc;
//	MB_Temp_t    OutTempRadCutOff;
//	MB_Temp_t    RadProp;
//	MB_16bit_t   RadInt;
//	MB_Temp_t    CalAuxInTemp;
//	MB_16bit_t   RadCycleTime;
//	MB_8bit_t    AIMode;
//	MB_8bit_t    MorningWarmUpTime;
//	//-----------------------
//	MB_8bit_t    Address;
//	MB_8bit_t    TempUnit;
//	MB_8bit_t    Location[CFG_MODBUS_NAME_SIZE];
//	MB_8bit_t    BaudRate;
//	MB_8bit_t    Parity;
//	MB_8bit_t    StopBits;
//	MB_8bit_t    Language;
//	//-----------------------
//	MB_Temp_t    DisMinSP;
//	MB_Temp_t    DisMidSP;
//	MB_Temp_t    DisMaxSP;
//	MB_Percent_t DisMinDem;
//	MB_Percent_t DisMidDem;
//	MB_Percent_t DisMaxDem;
//	MB_Temp_t    DisProp;
//	MB_8bit_t    DisInt;
//	MB_8bit_t    DisMode;
//	MB_8bit_t    IntDropRate;
//	MB_Percent_t DOOverr;
//	MB_Percent_t AOOverr;
//	MB_8bit_t    SchOverr;
//	//-----------------------
//	MB_8bit_t    ScrOrientation;
//	MB_8bit_t    ScrBrightness;
//	MB_16bit_t   ScrTimeout;
//} CFG_Data_t;

typedef struct {
	CFG_Product_t Prd;
	CFG_Data_t    Dta;
} CFG_t;
#pragma pack()
//#pragma pack(1)
//typedef struct {
//	Type8_t  DevType;
//	Type16_t SoftVer;
//	Type16_t HardVer;
//} CFG_Product_t;
//
//typedef struct {
//	TypeTemp_t    DefHeatSP;
//	TypeTemp_t    DefCoolSP;
//	TypeTemp_t    Prop;
//	Type8_t       CoolInt;
//	Type8_t       HeatInt;
//	TypeTemp_t    MinHeatSP;
//	TypeTemp_t    MaxHeatSP;
//	TypeTemp_t    MinCoolSP;
//	TypeTemp_t    MaxCoolSP;
//	TypeTemp_t    UnocHeatOff;
//	TypeTemp_t    UnocCoolOff;
//	TypeTemp_t    UnocHeatSPLim;
//	TypeTemp_t    UnocCoolSPLim;
//	Type8_t       DOSource;
//	TypePercent_t DOSP;
//	Type8_t       DOMode;
//	TypePercent_t DOBand;
//	Type8_t       DORevAct;
//	Type8_t       AOSource;
//	TypePercent_t AOSP;
//	Type8_t       AOMode;
//	TypePercent_t AOBand;
//	Type8_t       AORevAct;
//	Type8_t       AOPulsed;
//	Type8_t       AORange;
//	Type8_t       GrpCode1;
//	Type8_t       GrpCode2;
//	Type8_t       GrpCode3;
//	Type8_t       GrpWeight1;
//	Type8_t       GrpWeight2;
//	Type8_t       GrpWeight3;
//	Type8_t       GblWeight;
//	TypeTemp_t    RoomTempCal;
//	Type8_t       UnocModeOverrTime;
//	Type8_t       RadFloorId;
//	TypeTemp_t    MinSlabTemp;
//	TypeTemp_t    MaxSlabTemp;
//	TypeTemp_t    MinSlabTempUnoc;
//	TypeTemp_t    OutTempRadCutOff;
//	TypeTemp_t    RadProp;
//	Type16_t      RadInt;
//	TypeTemp_t    CalAuxInTemp;
//	Type16_t      RadCycleTime;
//	Type8_t       AIMode;
//	Type8_t       MorningWarmUpTime;
//	//-----------------------
//	Type8_t       Address;
//	Type8_t       TempUnit;
//	Type8_t       Location[CFG_MODBUS_NAME_SIZE];
//	Type8_t       BaudRate;
//	Type8_t       Parity;
//	Type8_t       StopBits;
//	Type8_t       Language;
//	//-----------------------
//	TypeTemp_t    DisMinSP;
//	TypeTemp_t    DisMidSP;
//	TypeTemp_t    DisMaxSP;
//	TypePercent_t DisMinDem;
//	TypePercent_t DisMidDem;
//	TypePercent_t DisMaxDem;
//	TypeTemp_t    DisProp;
//	Type8_t       DisInt;
//	Type8_t       DisMode;
//	Type8_t       IntDropRate;
//	TypePercent_t DOOverr;
//	TypePercent_t AOOverr;
//	Type8_t       SchOverr;
//	//-----------------------
//	Type8_t       ScrOrientation;
//	Type8_t       ScrBrightness;
//	Type16_t      ScrTimeout;
//} CFG_Data_t;
//
//typedef struct {
//	CFG_Product_t Prd;
//	CFG_Data_t    Dta;
//} CFG_t;
//#pragma pack()

CFG_EXTERN CFG_t CFG;


////=============================================================================
////  C O N F I G U R A T I O N   F O R M A T   D E F I N I T I O N
////-----------------------------------------------------------------------------
//static const MB_Register_t CFG_Registers[] =
//{
//	{  1,   MbReg8,           1,   &CFG.Prd.DevType           },
//	{  2,   MbReg16,          1,   &CFG.Prd.SoftVer           },
//	{  3,   MbReg16,          1,   &CFG.Prd.HardVer           },
//	//------------------------------------------------------------
//	{  4,   MbReg16,        100,   &CFG.Dta.DefHeatSP         },
//	{  5,   MbReg16,        100,   &CFG.Dta.DefCoolSP         },
//	{  6,   MbReg16,        100,   &CFG.Dta.Prop              },
//	{  7,   MbReg8,           1,   &CFG.Dta.CoolInt           },
//	{  8,   MbReg8,           1,   &CFG.Dta.HeatInt           },
//	{  9,   MbRegTemp,      100,   &CFG.Dta.MinHeatSP         },
//	{ 10,   MbRegTemp,      100,   &CFG.Dta.MaxHeatSP         },
//	{ 11,   MbRegTemp,      100,   &CFG.Dta.MinCoolSP         },
//	{ 12,   MbRegTemp,      100,   &CFG.Dta.MaxCoolSP         },
//	{ 13,   MbRegTemp,      100,   &CFG.Dta.UnocHeatOff       },
//	{ 14,   MbRegTemp,      100,   &CFG.Dta.UnocCoolOff       },
//	{ 15,   MbRegTemp,      100,   &CFG.Dta.UnocHeatSPLim     },
//	{ 16,   MbRegTemp,      100,   &CFG.Dta.UnocCoolSPLim     },
//	{ 17,   MbReg8,           1,   &CFG.Dta.DOSource          },
//	{ 18,   MBRegPercent,     1,   &CFG.Dta.DOSP              },
//	{ 19,   MbReg8,           1,   &CFG.Dta.DOMode            },
//	{ 20,   MBRegPercent,     1,   &CFG.Dta.DOBand            },
//	{ 21,   MbReg8,           1,   &CFG.Dta.DORevAct          },
//	{ 22,   MbReg8,           1,   &CFG.Dta.AOSource          },
//	{ 23,   MBRegPercent,     1,   &CFG.Dta.AOSP              },
//	{ 24,   MbReg8,           1,   &CFG.Dta.AOMode            },
//	{ 25,   MBRegPercent,     1,   &CFG.Dta.AOBand            },
//	{ 26,   MbReg8,           1,   &CFG.Dta.AORevAct          },
//	{ 27,   MbReg8,           1,   &CFG.Dta.AOPulsed          },
//	{ 28,   MbReg8,           1,   &CFG.Dta.AORange           },
//	{ 29,   MbReg8,           1,   &CFG.Dta.GrpCode1          },
//	{ 30,   MbReg8,           1,   &CFG.Dta.GrpCode2          },
//	{ 31,   MbReg8,           1,   &CFG.Dta.GrpCode3          },
//	{ 32,   MbReg8,           1,   &CFG.Dta.GrpWeight1        },
//	{ 33,   MbReg8,           1,   &CFG.Dta.GrpWeight2        },
//	{ 34,   MbReg8,           1,   &CFG.Dta.GrpWeight3        },
//	{ 35,   MbReg8,           1,   &CFG.Dta.GblWeight         },
//	{ 36,   MbRegTemp,      100,   &CFG.Dta.RoomTempCal       },
//	{ 37,   MbReg8,           1,   &CFG.Dta.UnocModeOverrTime },
//	{ 38,   MbReg8,           1,   &CFG.Dta.RadFloorId        },
//	{ 39,   MbRegTemp,      100,   &CFG.Dta.MinSlabTemp       },
//	{ 40,   MbRegTemp,      100,   &CFG.Dta.MaxSlabTemp       },
//	{ 41,   MbRegTemp,      100,   &CFG.Dta.MinSlabTempUnoc   },
//	{ 42,   MbRegTemp,      100,   &CFG.Dta.OutTempRadCutOff  },
//	{ 43,   MbRegTemp,      100,   &CFG.Dta.RadProp           },
//	{ 44,   MbReg16,          1,   &CFG.Dta.RadInt            },
//	{ 45,   MbRegTemp,      100,   &CFG.Dta.CalAuxInTemp      },
//	{ 46,   MbReg16,          1,   &CFG.Dta.RadCycleTime      },
//	{ 47,   MbReg8,           1,   &CFG.Dta.AIMode            },
//	{ 48,   MbReg8,           1,   &CFG.Dta.MorningWarmUpTime },
//	//------------------------------------------------------------
//	{ 49,   MbReg8,           1,   &CFG.Dta.Address           },
//	{ 50,   MbReg8,           1,   &CFG.Dta.TempUnit          },
//	{ 52,   MbRegLoc,         1,    CFG.Dta.Location          },
//	{ 60,   MbReg8,           1,   &CFG.Dta.BaudRate          },
//	{ 61,   MbReg8,           1,   &CFG.Dta.Parity            },
//	{ 62,   MbReg8,           1,   &CFG.Dta.StopBits          },
//	{ 64,   MbReg8,           1,   &CFG.Dta.Language          },
//	//------------------------------------------------------------
//	{ 65,   MbRegTemp,      100,   &CFG.Dta.DisMinSP          },
//	{ 66,   MbRegTemp,      100,   &CFG.Dta.DisMidSP          },
//	{ 67,   MbRegTemp,      100,   &CFG.Dta.DisMaxSP          },
//	{ 68,   MBRegPercent,     1,   &CFG.Dta.DisMinDem         },
//	{ 69,   MBRegPercent,     1,   &CFG.Dta.DisMidDem         },
//	{ 70,   MBRegPercent,     1,   &CFG.Dta.DisMaxDem         },
//	{ 71,   MbRegTemp,      100,   &CFG.Dta.DisProp           },
//	{ 72,   MbReg8,           1,   &CFG.Dta.DisInt            },
//	{ 73,   MbReg8,           1,   &CFG.Dta.DisMode           },
//	{ 74,   MbReg8,           1,   &CFG.Dta.IntDropRate       },
//	{ 75,   MBRegPercent,     1,   &CFG.Dta.DOOverr           },
//	{ 76,   MBRegPercent,     1,   &CFG.Dta.AOOverr           },
//	{ 77,   MbReg8,           1,   &CFG.Dta.SchOverr          },
//	//------------------------------------------------------------
//	{ 78,   MbReg8,           1,   &CFG.Dta.ScrOrientation    },
//	{ 79,   MbReg8,           1,   &CFG.Dta.ScrBrightness     },
//	{ 80,   MbReg16,          1,   &CFG.Dta.ScrTimeout        },
//};
//
extern const MB_Register_t CFG_Registers[];
//extern const uint16_t CFG_RegisterCount;
//static const uint16_t CFG_RegisterCount = NUMBER_OF_ELEMENTS_IN(CFG_Registers);
//static const CFG_RegFormat_t CFG_RegFormat[] =
//{
//	{  1,   RegType8,           1,   &CFG.Prd.DevType           },
//	{  2,   RegType16,          1,   &CFG.Prd.SoftVer           },
//	{  3,   RegType16,          1,   &CFG.Prd.HardVer           },
//	//------------------------------------------------------------
//	{  4,   RegType16,        100,   &CFG.Dta.DefHeatSP         },
//	{  5,   RegType16,        100,   &CFG.Dta.DefCoolSP         },
//	{  6,   RegType16,        100,   &CFG.Dta.Prop              },
//	{  7,   RegType8,           1,   &CFG.Dta.CoolInt           },
//	{  8,   RegType8,           1,   &CFG.Dta.HeatInt           },
//	{  9,   RegTypeTemp,      100,   &CFG.Dta.MinHeatSP         },
//	{ 10,   RegTypeTemp,      100,   &CFG.Dta.MaxHeatSP         },
//	{ 11,   RegTypeTemp,      100,   &CFG.Dta.MinCoolSP         },
//	{ 12,   RegTypeTemp,      100,   &CFG.Dta.MaxCoolSP         },
//	{ 13,   RegTypeTemp,      100,   &CFG.Dta.UnocHeatOff       },
//	{ 14,   RegTypeTemp,      100,   &CFG.Dta.UnocCoolOff       },
//	{ 15,   RegTypeTemp,      100,   &CFG.Dta.UnocHeatSPLim     },
//	{ 16,   RegTypeTemp,      100,   &CFG.Dta.UnocCoolSPLim     },
//	{ 17,   RegType8,           1,   &CFG.Dta.DOSource          },
//	{ 18,   RegTypePercent,     1,   &CFG.Dta.DOSP              },
//	{ 19,   RegType8,           1,   &CFG.Dta.DOMode            },
//	{ 20,   RegTypePercent,     1,   &CFG.Dta.DOBand            },
//	{ 21,   RegType8,           1,   &CFG.Dta.DORevAct          },
//	{ 22,   RegType8,           1,   &CFG.Dta.AOSource          },
//	{ 23,   RegTypePercent,     1,   &CFG.Dta.AOSP              },
//	{ 24,   RegType8,           1,   &CFG.Dta.AOMode            },
//	{ 25,   RegTypePercent,     1,   &CFG.Dta.AOBand            },
//	{ 26,   RegType8,           1,   &CFG.Dta.AORevAct          },
//	{ 27,   RegType8,           1,   &CFG.Dta.AOPulsed          },
//	{ 28,   RegType8,           1,   &CFG.Dta.AORange           },
//	{ 29,   RegType8,           1,   &CFG.Dta.GrpCode1          },
//	{ 30,   RegType8,           1,   &CFG.Dta.GrpCode2          },
//	{ 31,   RegType8,           1,   &CFG.Dta.GrpCode3          },
//	{ 32,   RegType8,           1,   &CFG.Dta.GrpWeight1        },
//	{ 33,   RegType8,           1,   &CFG.Dta.GrpWeight2        },
//	{ 34,   RegType8,           1,   &CFG.Dta.GrpWeight3        },
//	{ 35,   RegType8,           1,   &CFG.Dta.GblWeight         },
//	{ 36,   RegTypeTemp,      100,   &CFG.Dta.RoomTempCal       },
//	{ 37,   RegType8,           1,   &CFG.Dta.UnocModeOverrTime },
//	{ 38,   RegType8,           1,   &CFG.Dta.RadFloorId        },
//	{ 39,   RegTypeTemp,      100,   &CFG.Dta.MinSlabTemp       },
//	{ 40,   RegTypeTemp,      100,   &CFG.Dta.MaxSlabTemp       },
//	{ 41,   RegTypeTemp,      100,   &CFG.Dta.MinSlabTempUnoc   },
//	{ 42,   RegTypeTemp,      100,   &CFG.Dta.OutTempRadCutOff  },
//	{ 43,   RegTypeTemp,      100,   &CFG.Dta.RadProp           },
//	{ 44,   RegType16,          1,   &CFG.Dta.RadInt            },
//	{ 45,   RegTypeTemp,      100,   &CFG.Dta.CalAuxInTemp      },
//	{ 46,   RegType16,          1,   &CFG.Dta.RadCycleTime      },
//	{ 47,   RegType8,           1,   &CFG.Dta.AIMode            },
//	{ 48,   RegType8,           1,   &CFG.Dta.MorningWarmUpTime },
//	//------------------------------------------------------------
//	{ 49,   RegType8,           1,   &CFG.Dta.Address           },
//	{ 50,   RegType8,           1,   &CFG.Dta.TempUnit          },
//	{ 52,   RegTypeLoc,         1,    CFG.Dta.Location          },
//	{ 60,   RegType8,           1,   &CFG.Dta.BaudRate          },
//	{ 61,   RegType8,           1,   &CFG.Dta.Parity            },
//	{ 62,   RegType8,           1,   &CFG.Dta.StopBits          },
//	{ 64,   RegType8,           1,   &CFG.Dta.Language          },
//	//------------------------------------------------------------
//	{ 65,   RegTypeTemp,      100,   &CFG.Dta.DisMinSP          },
//	{ 66,   RegTypeTemp,      100,   &CFG.Dta.DisMidSP          },
//	{ 67,   RegTypeTemp,      100,   &CFG.Dta.DisMaxSP          },
//	{ 68,   RegTypePercent,     1,   &CFG.Dta.DisMinDem         },
//	{ 69,   RegTypePercent,     1,   &CFG.Dta.DisMidDem         },
//	{ 70,   RegTypePercent,     1,   &CFG.Dta.DisMaxDem         },
//	{ 71,   RegTypeTemp,      100,   &CFG.Dta.DisProp           },
//	{ 72,   RegType8,           1,   &CFG.Dta.DisInt            },
//	{ 73,   RegType8,           1,   &CFG.Dta.DisMode           },
//	{ 74,   RegType8,           1,   &CFG.Dta.IntDropRate       },
//	{ 75,   RegTypePercent,     1,   &CFG.Dta.DOOverr           },
//	{ 76,   RegTypePercent,     1,   &CFG.Dta.AOOverr           },
//	{ 77,   RegType8,           1,   &CFG.Dta.SchOverr          },
//	//------------------------------------------------------------
//	{ 78,   RegType8,           1,   &CFG.Dta.ScrOrientation    },
//	{ 79,   RegType8,           1,   &CFG.Dta.ScrBrightness     },
//	{ 80,   RegType16,          1,   &CFG.Dta.ScrTimeout        },
//};


//=============================================================================
//  F A C T O R Y   D E F A U L T S
//-----------------------------------------------------------------------------
#ifdef CFG_GLOBAL
#ifdef PROJECT_APP
const CFG_Data_t __attribute__((section(".app_data"))) CFG_DefaultData =
{
	.DefHeatSP         =  2150,
	.DefCoolSP         =  2250,
	.Prop              =  300,
	.CoolInt           =  30,
	.HeatInt           =  30,
	.MinHeatSP         =  1900,
	.MaxHeatSP         =  2500,
	.MinCoolSP         =  2000,
	.MaxCoolSP         =  2600,
	.UnocHeatOff       =  300,
	.UnocCoolOff       =  500,
	.UnocHeatSPLim     =  1500,
	.UnocCoolSPLim     =  3000,
	.DOSource          =  0,
	.DOSP              =  50,
	.DOMode            =  1,
	.DOBand            =  40,
	.DORevAct          =  0,
	.AOSource          =  0,
	.AOSP              =  25,
	.AOMode            =  0,
	.AOBand            =  75,
	.AORevAct          =  0,
	.AOPulsed          =  0,
	.AORange           =  0,
	.GrpCode1          =  0,
	.GrpCode2          =  0,
	.GrpCode3          =  0,
	.GrpWeight1        =  0,
	.GrpWeight2        =  0,
	.GrpWeight3        =  0,
	.GblWeight         =  1,
	.RoomTempCal       =  0,
	.UnocModeOverrTime =  0,
	.RadFloorId        =  0,
	.MinSlabTemp       =  2100,
	.MaxSlabTemp       =  2700,
	.MinSlabTempUnoc   =  1900,
	.OutTempRadCutOff  =  1500,
	.RadProp           =  100,
	.RadInt            =  60,
	.CalAuxInTemp      =  0,
	.RadCycleTime      =  15,
	.AIMode            =  0,
	.MorningWarmUpTime =  0,
	//-------------------------
	.Address           =  123,
	.TempUnit          =  CfgEnvTempC,
	.Location          = {'M','o','d','u','l','e','N','a','m','e',0,0,0,0,0,0},
	.BaudRate          =  CfgComBaud57600,
	.Parity            =  CfgComParityNone,
	.StopBits          =  CfgComStopBits1,
	.Language          =  0,
	//-------------------------
	.DisMinSP          =  1300,
	.DisMidSP          =  2100,
	.DisMaxSP          =  3000,
	.DisMinDem         = -100,
	.DisMidDem         =  0,
	.DisMaxDem         =  100,
	.DisProp           =  2000,
	.DisInt            =  15,
	.DisMode           =  0,
	.IntDropRate       =  3,
	.DOOverr           =  255,
	.AOOverr           =  255,
	.SchOverr          =  255,
	//-------------------------
	.ScrOrientation    =  CfgScrOrientP,
	.ScrBrightness     =  0,
	.ScrTimeout        =  0
};
#endif
#endif


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void CFG_Load     (void);
extern void CFG_Save     (void);
extern void CFG_Modified (void);
//extern void CFG_Read     (uint16_t Register, uint16_t Quantity, uint16_t* Data);
//extern void CFG_Write    (uint16_t Register, uint16_t Quantity, uint16_t* Data);


#ifdef __cplusplus
}
#endif


#endif   //CFG_H































