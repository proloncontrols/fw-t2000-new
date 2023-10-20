
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
//  N O T E
//-----------------------------------------------------------------------------
//  Standard C coding practice regarding location of variables and constants
//  is to place their definition in a header file (.h), and their implementation
//  in a seperate source file (.c).
//  For the purpose of this project, everything is placed in this header file.
//  This is done to facilitate its manipulation when needed.
//-----------------------------------------------------------------------------


//=============================================================================
//  I N S T R U C T I O N S
//-----------------------------------------------------------------------------
//  To add a new holding register or configuration item, the following steps MUST be obeyed:
//
//  1- OPTIONAL  - Create a specific data typedef for the register/item in the "SPECIFIC DATA TYPES DEFINITION" section
//  2- MANDATORY - Add register in the CFG_HldReg_t enum and initialize it to its corresponding number
//  3- MANDATORY - Add register/item in the CFG_Data_t structure (as its newly created typedef if applicable)
//  4- MANDATORY - Create its format in the "HOLDING REGISTERS FORMAT DEFINITION" section
//  5- MANDATORY - Define its default value in the "FACTOTY DEFAULTS" section
//  6- OPTIONAL  - Define its parameters in the "CONFIGURATION PARAMETERS DEFINITION" section (if needed)
//-----------------------------------------------------------------------------


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define CFG_MODBUS_NAME_SIZE   16


//=============================================================================
//  S P E C I F I C   D A T A   T Y P E S   D E F I N I T I O N
//-----------------------------------------------------------------------------
typedef uint8_t  CFG_Data8_t;
typedef int8_t   CFG_Data8S_t;
typedef uint16_t CFG_Data16_t;
typedef char     CFG_DataLoc_t[CFG_MODBUS_NAME_SIZE];
typedef uint16_t CFG_DataTemp_t;
typedef uint16_t CFG_Multiplier_t;


//=============================================================================
//  H O L D I N G   R E G I S T E R S   D E F I N I T I O N
//-----------------------------------------------------------------------------
typedef enum {
	CfgHrDevType           = 1,     //Read-only
	CfgHrSoftVer           = 2,     //
	CfgHrHardVer           = 3,     //
	//-------------------------
	CfgHrDefHeatSP         = 4,
	CfgHrDefCoolSP         = 5,
	CfgHrProp              = 6,
	CfgHrCoolInt           = 7,
	CfgHrHeatInt           = 8,
	CfgHrMinHeatSP         = 9,
	CfgHrMaxHeatSP         = 10,
	CfgHrMinCoolSP         = 11,
	CfgHrMaxCoolSP         = 12,
	CfgHrUnocHeatOffset    = 13,
	CfgHrUnocCoolOffset    = 14,
	CfgHrUnocHeatSPLim     = 15,
	CfgHrUnocCoolSPLim     = 16,
	CfgHrDOSource          = 17,
	CfgHrDOSP              = 18,
	CfgHrDOMode            = 19,
	CfgHrDOBand            = 20,
	CfgHrDORevAct          = 21,
	CfgHrAOSource          = 22,
	CfgHrAOSP              = 23,
	CfgHrAOMode            = 24,
	CfgHrAOBand            = 25,
	CfgHrAORevAct          = 26,
	CfgHrAOPulsed          = 27,
	CfgHrAORange           = 28,
	CfgHrGroupCode1        = 29,
	CfgHrGroupCode2        = 30,
	CfgHrGroupCode3        = 31,
	CfgHrGroupWeight1      = 32,
	CfgHrGroupWeight2      = 33,
	CfgHrGroupWeight3      = 34,
	CfgHrGlobalWeight      = 35,
	CfgHrRoomTempCal       = 36,
	CfgHrUnocModeOverrTime = 37,
	CfgHrRadFloorId        = 38,
	CfgHrMinSlabTemp       = 39,
	CfgHrMaxSlabTemp       = 40,
	CfgHrMinSlabTempUnoc   = 41,
	CfgHrOutTempRadCutoff  = 42,
	CfgHrRadProp           = 43,
	CfgHrRadInt            = 44,
	CfgHrCalAuxInTemp      = 45,
	CfgHrRadCycleTime      = 46,
	CfgHrAIMode            = 47,
	CfgHrMorningWarmUpTemp = 48,
	CfgHrAddress           = 49,
	CfgHrTempUnit          = 50,
	//-------------------------
	CfgHrLocation          = 52,
	//-------------------------
	CfgHrBaudrate          = 60,
	CfgHrParity            = 61,
	CfgHrStopBits          = 62,
	//-------------------------
	CfgHrLanguage          = 64,
	CfgHrDisMinSP          = 65,
	CfgHrDisMidSP          = 66,
	CfgHrDisMaxSP          = 67,
	CfgHrDisMinDem         = 68,
	CfgHrDisMidDem         = 69,
	CfgHrDisMaxDem         = 70,
	CfgHrDisProp           = 71,
	CfgHrDisInt            = 72,
	CfgHrDisMode           = 73,
	CfgHrIntDropRate       = 74,
	CfgHrDOOverride        = 75,
	CfgHrAOOverride        = 76,
	CfgHrSchOverride       = 77,
	//-------------------------
	CfgHrScrOrientation    = 78,    //T2000 specific
	CfgHrScrTimeout        = 79,    //
	//-------------------------
	CfgHrReset             = 100,   //Processes
	CfgHrReprogram         = 101    //
} CFG_HldReg_t;


//=============================================================================
//  C O N F I G U R A T I O N   D A T A   S T R U C T U R E   I N   R A M
//-----------------------------------------------------------------------------
#pragma pack(1)
typedef struct {
	CFG_DataTemp_t DefHeatSP;
	CFG_DataTemp_t DefCoolSP;
	CFG_DataTemp_t Prop;
	CFG_Data8_t    CoolInt;
	CFG_Data8_t    HeatInt;
	CFG_DataTemp_t MinHeatSP;
	CFG_DataTemp_t MaxHeatSP;
	CFG_DataTemp_t MinCoolSP;
	CFG_DataTemp_t MaxCoolSP;
	CFG_DataTemp_t UnocHeatOffset;
	CFG_DataTemp_t UnocCoolOffset;
	CFG_DataTemp_t UnocHeatSPLim;
	CFG_DataTemp_t UnocCoolSPLim;
	CFG_Data8_t    DOSource;
	CFG_Data8_t    DOSP;
	CFG_Data8_t    DOMode;
	CFG_Data8_t    DOBand;
	CFG_Data8_t    DORevAct;
	CFG_Data8_t    AOSource;
	CFG_Data8_t    AOSP;
	CFG_Data8_t    AOMode;
	CFG_Data8_t    AOBand;
	CFG_Data8_t    AORevAct;
	CFG_Data8_t    AOPulsed;
	CFG_Data8_t    AORange;
	CFG_Data8_t    GroupCode1;
	CFG_Data8_t    GroupCode2;
	CFG_Data8_t    GroupCode3;
	CFG_Data8_t    GroupWeight1;
	CFG_Data8_t    GroupWeight2;
	CFG_Data8_t    GroupWeight3;
	CFG_Data8_t    GlobalWeight;
	CFG_DataTemp_t RoomTempCal;
	CFG_Data8_t    UnocModeOverrTime;
	CFG_Data8_t    RadFloorId;
	CFG_DataTemp_t MinSlabTemp;
	CFG_DataTemp_t MaxSlabTemp;
	CFG_DataTemp_t MinSlabTempUnoc;
	CFG_DataTemp_t OutTempRadCutoff;
	CFG_DataTemp_t RadProp;
	CFG_Data16_t   RadInt;
	CFG_DataTemp_t CalAuxInTemp;
	CFG_Data16_t   RadCycleTime;
	CFG_Data8_t    AIMode;
	CFG_Data8_t    MorningWarmUpTemp;
	CFG_Data8_t    Address;
	CFG_Data8_t    TempUnit;
	//-------------------------
	CFG_DataLoc_t  Location;
	//-------------------------
	CFG_Data8_t    Baudrate;
	CFG_Data8_t    Parity;
	CFG_Data8_t    StopBits;
	//-------------------------
	CFG_Data8_t    Language;
	CFG_DataTemp_t DisMinSP;
	CFG_DataTemp_t DisMidSP;
	CFG_DataTemp_t DisMaxSP;
	CFG_Data8S_t   DisMinDem;
	CFG_Data8_t    DisMidDem;
	CFG_Data8_t    DisMaxDem;
	CFG_DataTemp_t DisProp;
	CFG_Data8_t    DisInt;
	CFG_Data8_t    DisMode;
	CFG_Data8_t    IntDropRate;
	CFG_Data8_t    DOOverride;
	CFG_Data8_t    AOOverride;
	CFG_Data8_t    SchOverride;
	//-------------------------
	CFG_Data8_t    ScrOrientation;
	CFG_Data16_t   ScrTimeout;
} CFG_Data_t;
#pragma pack()

CFG_EXTERN CFG_Data_t CFG_Data;


//=============================================================================
//  H O L D I N G   R E G I S T E R S   F O R M A T   D E F I N I T I O N
//-----------------------------------------------------------------------------
typedef struct {
	CFG_HldReg_t     Register;
	CFG_Multiplier_t Multiplier;
	void*            RamAddress;
	uint16_t         RamSize;
} CFG_HldRegFormat_t;

#ifndef CFG_GLOBAL
extern const CFG_HldRegFormat_t CFG_HldRegFormat[];
#else
const CFG_HldRegFormat_t CFG_HldRegFormat[] =
{
	{ CfgHrDefHeatSP,         100,   &CFG_Data.DefHeatSP,         sizeof(CFG_DataTemp_t) },
	{ CfgHrDefCoolSP,         100,   &CFG_Data.DefCoolSP,         sizeof(CFG_DataTemp_t) },
	{ CfgHrProp,              100,   &CFG_Data.Prop,              sizeof(CFG_DataTemp_t) },
	{ CfgHrCoolInt,             1,   &CFG_Data.CoolInt,           sizeof(CFG_Data8_t)    },
	{ CfgHrHeatInt,             1,   &CFG_Data.HeatInt,           sizeof(CFG_Data8_t)    },
	{ CfgHrMinHeatSP,         100,   &CFG_Data.MinHeatSP,         sizeof(CFG_DataTemp_t) },
	{ CfgHrMaxHeatSP,         100,   &CFG_Data.MaxHeatSP,         sizeof(CFG_DataTemp_t) },
	{ CfgHrMinCoolSP,         100,   &CFG_Data.MinCoolSP,         sizeof(CFG_DataTemp_t) },
	{ CfgHrMaxCoolSP,         100,   &CFG_Data.MaxCoolSP,         sizeof(CFG_DataTemp_t) },
	{ CfgHrUnocHeatOffset,    100,   &CFG_Data.UnocHeatOffset,    sizeof(CFG_DataTemp_t) },
	{ CfgHrUnocCoolOffset,    100,   &CFG_Data.UnocCoolOffset,    sizeof(CFG_DataTemp_t) },
	{ CfgHrUnocHeatSPLim,     100,   &CFG_Data.UnocHeatSPLim,     sizeof(CFG_DataTemp_t) },
	{ CfgHrUnocCoolSPLim,     100,   &CFG_Data.UnocCoolSPLim,     sizeof(CFG_DataTemp_t) },
	{ CfgHrDOSource,            1,   &CFG_Data.DOSource,          sizeof(CFG_Data8_t)    },
	{ CfgHrDOSP,                1,   &CFG_Data.DOSP,              sizeof(CFG_Data8_t)    },
	{ CfgHrDOMode,              1,   &CFG_Data.DOMode,            sizeof(CFG_Data8_t)    },
	{ CfgHrDOBand,              1,   &CFG_Data.DOBand,            sizeof(CFG_Data8_t)    },
	{ CfgHrDORevAct,            1,   &CFG_Data.DORevAct,          sizeof(CFG_Data8_t)    },
	{ CfgHrAOSource,            1,   &CFG_Data.AOSource,          sizeof(CFG_Data8_t)    },
	{ CfgHrAOSP,                1,   &CFG_Data.AOSP,              sizeof(CFG_Data8_t)    },
	{ CfgHrAOMode,              1,   &CFG_Data.AOMode,            sizeof(CFG_Data8_t)    },
	{ CfgHrAOBand,              1,   &CFG_Data.AOBand,            sizeof(CFG_Data8_t)    },
	{ CfgHrAORevAct,            1,   &CFG_Data.AORevAct,          sizeof(CFG_Data8_t)    },
	{ CfgHrAOPulsed,            1,   &CFG_Data.AOPulsed,          sizeof(CFG_Data8_t)    },
	{ CfgHrAORange,             1,   &CFG_Data.AORange,           sizeof(CFG_Data8_t)    },
	{ CfgHrGroupCode1,          1,   &CFG_Data.GroupCode1,        sizeof(CFG_Data8_t)    },
	{ CfgHrGroupCode2,          1,   &CFG_Data.GroupCode2,        sizeof(CFG_Data8_t)    },
	{ CfgHrGroupCode3,          1,   &CFG_Data.GroupCode3,        sizeof(CFG_Data8_t)    },
	{ CfgHrGroupWeight1,        1,   &CFG_Data.GroupWeight1,      sizeof(CFG_Data8_t)    },
	{ CfgHrGroupWeight2,        1,   &CFG_Data.GroupWeight2,      sizeof(CFG_Data8_t)    },
	{ CfgHrGroupWeight3,        1,   &CFG_Data.GroupWeight3,      sizeof(CFG_Data8_t)    },
	{ CfgHrGlobalWeight,        1,   &CFG_Data.GlobalWeight,      sizeof(CFG_Data8_t)    },
	{ CfgHrRoomTempCal,       100,   &CFG_Data.RoomTempCal,       sizeof(CFG_DataTemp_t) },
	{ CfgHrUnocModeOverrTime,   1,   &CFG_Data.UnocModeOverrTime, sizeof(CFG_Data8_t)    },
	{ CfgHrRadFloorId,          1,   &CFG_Data.RadFloorId,        sizeof(CFG_Data8_t)    },
	{ CfgHrMinSlabTemp,       100,   &CFG_Data.MinSlabTemp,       sizeof(CFG_DataTemp_t) },
	{ CfgHrMaxSlabTemp,       100,   &CFG_Data.MaxSlabTemp,       sizeof(CFG_DataTemp_t) },
	{ CfgHrMinSlabTempUnoc,   100,   &CFG_Data.MinSlabTempUnoc,   sizeof(CFG_DataTemp_t) },
	{ CfgHrOutTempRadCutoff,  100,   &CFG_Data.OutTempRadCutoff,  sizeof(CFG_DataTemp_t) },
	{ CfgHrRadProp,           100,   &CFG_Data.RadProp,           sizeof(CFG_DataTemp_t) },
	{ CfgHrRadInt,              1,   &CFG_Data.RadInt,            sizeof(CFG_Data16_t)   },
	{ CfgHrCalAuxInTemp,      100,   &CFG_Data.CalAuxInTemp,      sizeof(CFG_DataTemp_t) },
	{ CfgHrRadCycleTime,        1,   &CFG_Data.RadCycleTime,      sizeof(CFG_Data16_t)   },
	{ CfgHrAIMode,              1,   &CFG_Data.AIMode,            sizeof(CFG_Data8_t)    },
	{ CfgHrMorningWarmUpTemp,   1,   &CFG_Data.MorningWarmUpTemp, sizeof(CFG_Data8_t)    },
	{ CfgHrAddress,             1,   &CFG_Data.Address,           sizeof(CFG_Data8_t)    },
	{ CfgHrTempUnit,            1,   &CFG_Data.TempUnit,          sizeof(CFG_Data8_t)    },
	{ CfgHrLocation,            1,    CFG_Data.Location,          sizeof(CFG_DataLoc_t)  },
	{ CfgHrBaudrate,            1,   &CFG_Data.Baudrate,          sizeof(CFG_Data8_t)    },
	{ CfgHrParity,              1,   &CFG_Data.Parity,            sizeof(CFG_Data8_t)    },
	{ CfgHrStopBits,            1,   &CFG_Data.StopBits,          sizeof(CFG_Data8_t)    },
	{ CfgHrLanguage,            1,   &CFG_Data.Language,          sizeof(CFG_Data8_t)    },
	{ CfgHrDisMinSP,          100,   &CFG_Data.DisMinSP,          sizeof(CFG_DataTemp_t) },
	{ CfgHrDisMidSP,          100,   &CFG_Data.DisMidSP,          sizeof(CFG_DataTemp_t) },
	{ CfgHrDisMaxSP,          100,   &CFG_Data.DisMaxSP,          sizeof(CFG_DataTemp_t) },
	{ CfgHrDisMinDem,           1,   &CFG_Data.DisMinDem,         sizeof(CFG_Data8_t)    },
	{ CfgHrDisMidDem,           1,   &CFG_Data.DisMidDem,         sizeof(CFG_Data8_t)    },
	{ CfgHrDisMaxDem,           1,   &CFG_Data.DisMaxDem,         sizeof(CFG_Data8_t)    },
	{ CfgHrDisProp,           100,   &CFG_Data.DisProp,           sizeof(CFG_DataTemp_t) },
	{ CfgHrDisInt,              1,   &CFG_Data.DisInt,            sizeof(CFG_Data8_t)    },
	{ CfgHrDisMode,             1,   &CFG_Data.DisMode,           sizeof(CFG_Data8_t)    },
	{ CfgHrIntDropRate,         1,   &CFG_Data.IntDropRate,       sizeof(CFG_Data8_t)    },
	{ CfgHrDOOverride,          1,   &CFG_Data.DOOverride,        sizeof(CFG_Data8_t)    },
	{ CfgHrAOOverride,          1,   &CFG_Data.AOOverride,        sizeof(CFG_Data8_t)    },
	{ CfgHrSchOverride,         1,   &CFG_Data.SchOverride,       sizeof(CFG_Data8_t)    },
	{ CfgHrScrOrientation,      1,   &CFG_Data.ScrOrientation,    sizeof(CFG_Data8_t)    },
	{ CfgHrScrTimeout,          1,   &CFG_Data.ScrTimeout,        sizeof(CFG_Data16_t)   }
};
#endif


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
//  F A C T O R Y   D E F A U L T S
//-----------------------------------------------------------------------------
//#define CFG_DEF_MODBUS_ADDRESS    ((CFG_DataModBusId_t)       123)
//#define CFG_DEF_MODBUS_NAME       ((CFG_DataModBusName_t)    {'M','o','d','u','l','e','N','a','m','e',0,0,0,0,0,0})
//#define CFG_DEF_COM_BAUDRATE      ((CFG_DataComBaudRate_t)    CfgComBaud57600)
//#define CFG_DEF_COM_STOPBITS      ((CFG_DataComStopBits_t)    CfgComStop1)
//#define CFG_DEF_COM_PARITY        ((CFG_DataComParity_t)      CfgComParityNone)
//#define CFG_DEF_SCR_LANGUAGE      ((CFG_DataScrLanguage_t)    CfgScrLanEnglish)
//#define CFG_DEF_SCR_ORIENTATION   ((CFG_DataScrOrientation_t) CfgScrOrientP)
//#define CFG_DEF_SCR_TIMEOUT       ((CFG_DataScrTimeout_t)     0)
//#define CFG_DEF_ENV_TEMP_UNIT     ((CFG_DataEnvTempUnit_t)    CfgEnvTempC)

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
	.UnocHeatOffset    =  300,
	.UnocCoolOffset    =  500,
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
	.GroupCode1        =  0,
	.GroupCode2        =  0,
	.GroupCode3        =  0,
	.GroupWeight1      =  0,
	.GroupWeight2      =  0,
	.GroupWeight3      =  0,
	.GlobalWeight      =  1,
	.RoomTempCal       =  0,
	.UnocModeOverrTime =  0,
	.RadFloorId        =  0,
	.MinSlabTemp       =  2100,
	.MaxSlabTemp       =  2700,
	.MinSlabTempUnoc   =  1900,
	.OutTempRadCutoff  =  1500,
	.RadProp           =  100,
	.RadInt            =  60,
	.CalAuxInTemp      =  0,
	.RadCycleTime      =  15,
	.AIMode            =  0,
	.MorningWarmUpTemp =  0,
	.Address           =  123,
	.TempUnit          =  CfgEnvTempC,
	//-------------------------
	.Location          = {'M','o','d','u','l','e','N','a','m','e',0,0,0,0,0,0},
//	.Location          = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	//-------------------------
	.Baudrate          =  CfgComBaud57600,
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
	.DOOverride        =  255,
	.AOOverride        =  255,
	.SchOverride       =  255,
	//-------------------------
	.ScrOrientation    =  CfgScrOrientP,
	.ScrTimeout        =  0
};
#endif
#endif


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
//#define CFG_MODBUS_NAME_SIZE   16


//=============================================================================
//  C O N F I G U R A T I O N   S T R U C T U R E   F I E L D   T Y P E S
//-----------------------------------------------------------------------------
//typedef uint8_t  CFG_DataModBusId_t;
//typedef char     CFG_DataModBusName_t[CFG_MODBUS_NAME_SIZE];
//typedef uint8_t  CFG_DataComBaudRate_t;
//typedef uint8_t  CFG_DataComStopBits_t;
//typedef uint8_t  CFG_DataComParity_t;
//typedef uint8_t  CFG_DataScrLanguage_t;
//typedef uint8_t  CFG_DataScrOrientation_t;
//typedef uint16_t CFG_DataScrTimeout_t;
//typedef uint8_t  CFG_DataEnvTempUnit_t;


//=============================================================================
//  C O N F I G U R A T I O N   S T R U C T U R E
//-----------------------------------------------------------------------------
//#pragma pack(1)
//typedef struct {
//	CFG_DataModBusId_t       ModBusID;
//	CFG_DataModBusName_t     ModBusName;
//	CFG_DataComBaudRate_t    ComBaudRate;
//	CFG_DataComStopBits_t    ComStopBits;
//	CFG_DataComParity_t      ComParity;
//	CFG_DataScrLanguage_t    ScrLanguage;
//	CFG_DataScrOrientation_t ScrOrientation;
//	CFG_DataScrTimeout_t     ScrTimeout;
//	CFG_DataEnvTempUnit_t    EnvTempUnit;
//} CFG_Data_t;
//#pragma pack()


//=============================================================================
//  H O L D I N G   R E G I S T E R S
//-----------------------------------------------------------------------------
//typedef enum {
//	CfgHrDeviceType = 1,   //These are hardcoded values
////	CfgHrSoftVer,          //
////	CfgHrHardVer,          //
//	CfgHrModBusID,
//	CfgHrModBusName,
//	CfgHrComBaudRate,
//	CfgHrComStopBits,
//	CfgHrComParity,
//	CfgHrScrLanguage,
//	CfgHrScrOrientation,
//	CfgHrScrTimeout,
////	CfgHrTempUnit
//} CFG_HoldingRegister_t;


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
//CFG_EXTERN CFG_Data_t CFG_Data;


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void CFG_Load     (void);
extern void CFG_Save     (void);
extern void CFG_Modified (void);
extern void CFG_Read     (CFG_HldReg_t Register, void* Data);
extern void CFG_Write    (CFG_HldReg_t Register, void* Data);


#ifdef __cplusplus
}
#endif


#endif   //CFG_H































