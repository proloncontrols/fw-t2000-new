
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
typedef enum {
	RegType8 = 0,
	RegType16,
	RegTypeLoc,
	RegTypeTemp,
	RegTypePercent
} CFG_RegType_t;

typedef uint8_t  Type8_t;
typedef uint16_t Type16_t;
typedef int16_t  TypeTemp_t;
typedef int8_t   TypePercent_t;

typedef uint16_t Multiplier_t;

typedef struct {
	uint16_t      Number;
	CFG_RegType_t Type;
	Multiplier_t  Multiplier;
	void*         RamAddress;
} CFG_RegFormat_t;


//=============================================================================
//  C O N F I G U R A T I O N   D A T A   S T R U C T U R E S   I N   R A M
//-----------------------------------------------------------------------------
#pragma pack(1)
typedef struct {
	Type8_t  DevType;
	Type16_t SoftVer;
	Type16_t HardVer;
} CFG_Product_t;

typedef struct {
	TypeTemp_t    DefHeatSP;
	TypeTemp_t    DefCoolSP;
	TypeTemp_t    Prop;
	Type8_t       CoolInt;
	Type8_t       HeatInt;
	TypeTemp_t    MinHeatSP;
	TypeTemp_t    MaxHeatSP;
	TypeTemp_t    MinCoolSP;
	TypeTemp_t    MaxCoolSP;
	TypeTemp_t    UnocHeatOff;
	TypeTemp_t    UnocCoolOff;
	TypeTemp_t    UnocHeatSPLim;
	TypeTemp_t    UnocCoolSPLim;
	Type8_t       DOSource;
	TypePercent_t DOSP;
	Type8_t       DOMode;
	TypePercent_t DOBand;
	Type8_t       DORevAct;
	Type8_t       AOSource;
	TypePercent_t AOSP;
	Type8_t       AOMode;
	TypePercent_t AOBand;
	Type8_t       AORevAct;
	Type8_t       AOPulsed;
	Type8_t       AORange;
	Type8_t       GrpCode1;
	Type8_t       GrpCode2;
	Type8_t       GrpCode3;
	Type8_t       GrpWeight1;
	Type8_t       GrpWeight2;
	Type8_t       GrpWeight3;
	Type8_t       GblWeight;
	TypeTemp_t    RoomTempCal;
	Type8_t       UnocModeOverrTime;
	Type8_t       RadFloorId;
	TypeTemp_t    MinSlabTemp;
	TypeTemp_t    MaxSlabTemp;
	TypeTemp_t    MinSlabTempUnoc;
	TypeTemp_t    OutTempRadCutOff;
	TypeTemp_t    RadProp;
	Type16_t      RadInt;
	TypeTemp_t    CalAuxInTemp;
	Type16_t      RadCycleTime;
	Type8_t       AIMode;
	Type8_t       MorningWarmUpTime;
	//-----------------------
	Type8_t       Address;
	Type8_t       TempUnit;
	//-----------------------
	Type8_t       Location[CFG_MODBUS_NAME_SIZE];
	//-----------------------
	Type8_t       BaudRate;
	Type8_t       Parity;
	Type8_t       StopBits;
	//-----------------------
	Type8_t       Language;
	TypeTemp_t    DisMinSP;
	TypeTemp_t    DisMidSP;
	TypeTemp_t    DisMaxSP;
	TypePercent_t DisMinDem;
	TypePercent_t DisMidDem;
	TypePercent_t DisMaxDem;
	TypeTemp_t    DisProp;
	Type8_t       DisInt;
	Type8_t       DisMode;
	Type8_t       IntDropRate;
	TypePercent_t DOOverr;
	TypePercent_t AOOverr;
	Type8_t       SchOverr;
	//-----------------------
	Type8_t       ScrOrientation;
	Type8_t       ScrBrightness;
	Type16_t      ScrTimeout;
} CFG_Data_t;

typedef struct {
	CFG_Product_t Product;
	CFG_Data_t    Data;
} CFG_t;
#pragma pack()

CFG_EXTERN CFG_t CFG;


//=============================================================================
//  C O N F I G U R A T I O N   F O R M A T   D E F I N I T I O N
//-----------------------------------------------------------------------------
static const CFG_RegFormat_t CFG_RegFormat[] =
{
	{  1,   RegType8,           1,   &CFG.Product.DevType        },
	{  2,   RegType16,          1,   &CFG.Product.SoftVer        },
	{  3,   RegType16,          1,   &CFG.Product.HardVer        },
	//------------------------------------------------------------
	{  4,   RegType16,        100,   &CFG.Data.DefHeatSP         },
	{  5,   RegType16,        100,   &CFG.Data.DefCoolSP         },
	{  6,   RegType16,        100,   &CFG.Data.Prop              },
	{  7,   RegType8,           1,   &CFG.Data.CoolInt           },
	{  8,   RegType8,           1,   &CFG.Data.HeatInt           },
	{  9,   RegTypeTemp,      100,   &CFG.Data.MinHeatSP         },
	{ 10,   RegTypeTemp,      100,   &CFG.Data.MaxHeatSP         },
	{ 11,   RegTypeTemp,      100,   &CFG.Data.MinCoolSP         },
	{ 12,   RegTypeTemp,      100,   &CFG.Data.MaxCoolSP         },
	{ 13,   RegTypeTemp,      100,   &CFG.Data.UnocHeatOff       },
	{ 14,   RegTypeTemp,      100,   &CFG.Data.UnocCoolOff       },
	{ 15,   RegTypeTemp,      100,   &CFG.Data.UnocHeatSPLim     },
	{ 16,   RegTypeTemp,      100,   &CFG.Data.UnocCoolSPLim     },
	{ 17,   RegType8,           1,   &CFG.Data.DOSource          },
	{ 18,   RegTypePercent,     1,   &CFG.Data.DOSP              },
	{ 19,   RegType8,           1,   &CFG.Data.DOMode            },
	{ 20,   RegTypePercent,     1,   &CFG.Data.DOBand            },
	{ 21,   RegType8,           1,   &CFG.Data.DORevAct          },
	{ 22,   RegType8,           1,   &CFG.Data.AOSource          },
	{ 23,   RegTypePercent,     1,   &CFG.Data.AOSP              },
	{ 24,   RegType8,           1,   &CFG.Data.AOMode            },
	{ 25,   RegTypePercent,     1,   &CFG.Data.AOBand            },
	{ 26,   RegType8,           1,   &CFG.Data.AORevAct          },
	{ 27,   RegType8,           1,   &CFG.Data.AOPulsed          },
	{ 28,   RegType8,           1,   &CFG.Data.AORange           },
	{ 29,   RegType8,           1,   &CFG.Data.GrpCode1          },
	{ 30,   RegType8,           1,   &CFG.Data.GrpCode2          },
	{ 31,   RegType8,           1,   &CFG.Data.GrpCode3          },
	{ 32,   RegType8,           1,   &CFG.Data.GrpWeight1        },
	{ 33,   RegType8,           1,   &CFG.Data.GrpWeight2        },
	{ 34,   RegType8,           1,   &CFG.Data.GrpWeight3        },
	{ 35,   RegType8,           1,   &CFG.Data.GblWeight         },
	{ 36,   RegTypeTemp,      100,   &CFG.Data.RoomTempCal       },
	{ 37,   RegType8,           1,   &CFG.Data.UnocModeOverrTime },
	{ 38,   RegType8,           1,   &CFG.Data.RadFloorId        },
	{ 39,   RegTypeTemp,      100,   &CFG.Data.MinSlabTemp       },
	{ 40,   RegTypeTemp,      100,   &CFG.Data.MaxSlabTemp       },
	{ 41,   RegTypeTemp,      100,   &CFG.Data.MinSlabTempUnoc   },
	{ 42,   RegTypeTemp,      100,   &CFG.Data.OutTempRadCutOff  },
	{ 43,   RegTypeTemp,      100,   &CFG.Data.RadProp           },
	{ 44,   RegType16,          1,   &CFG.Data.RadInt            },
	{ 45,   RegTypeTemp,      100,   &CFG.Data.CalAuxInTemp      },
	{ 46,   RegType16,          1,   &CFG.Data.RadCycleTime      },
	{ 47,   RegType8,           1,   &CFG.Data.AIMode            },
	{ 48,   RegType8,           1,   &CFG.Data.MorningWarmUpTime },
	//------------------------------------------------------------
	{ 49,   RegType8,           1,   &CFG.Data.Address           },
	{ 50,   RegType8,           1,   &CFG.Data.TempUnit          },
	//------------------------------------------------------------
	{ 52,   RegTypeLoc,         1,    CFG.Data.Location          },
	//------------------------------------------------------------
	{ 60,   RegType8,           1,   &CFG.Data.BaudRate          },
	{ 61,   RegType8,           1,   &CFG.Data.Parity            },
	{ 62,   RegType8,           1,   &CFG.Data.StopBits          },
	//------------------------------------------------------------
	{ 64,   RegType8,           1,   &CFG.Data.Language          },
	{ 65,   RegTypeTemp,      100,   &CFG.Data.DisMinSP          },
	{ 66,   RegTypeTemp,      100,   &CFG.Data.DisMidSP          },
	{ 67,   RegTypeTemp,      100,   &CFG.Data.DisMaxSP          },
	{ 68,   RegTypePercent,     1,   &CFG.Data.DisMinDem         },
	{ 69,   RegTypePercent,     1,   &CFG.Data.DisMidDem         },
	{ 70,   RegTypePercent,     1,   &CFG.Data.DisMaxDem         },
	{ 71,   RegTypeTemp,      100,   &CFG.Data.DisProp           },
	{ 72,   RegType8,           1,   &CFG.Data.DisInt            },
	{ 73,   RegType8,           1,   &CFG.Data.DisMode           },
	{ 74,   RegType8,           1,   &CFG.Data.IntDropRate       },
	{ 75,   RegTypePercent,     1,   &CFG.Data.DOOverr           },
	{ 76,   RegTypePercent,     1,   &CFG.Data.AOOverr           },
	{ 77,   RegType8,           1,   &CFG.Data.SchOverr          },
	//------------------------------------------------------------
	{ 78,   RegType8,           1,   &CFG.Data.ScrOrientation    },
	{ 79,   RegType8,           1,   &CFG.Data.ScrBrightness     },
	{ 80,   RegType16,          1,   &CFG.Data.ScrTimeout        },
};


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
	.Address           =  123,
	.TempUnit          =  CfgEnvTempC,
	//-------------------------
	.Location          = {'M','o','d','u','l','e','N','a','m','e',0,0,0,0,0,0},
	//-------------------------
	.BaudRate          =  CfgComBaud57600,
	.Parity            =  CfgComParityNone,
	.StopBits          =  CfgComStopBits1,
	//-------------------------
	.Language          =  0,
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
extern void CFG_Read     (uint16_t Register, uint16_t Quantity, uint16_t* Data);
extern void CFG_Write    (uint16_t Register, uint16_t Quantity, uint16_t* Data);


#ifdef __cplusplus
}
#endif


#endif   //CFG_H































