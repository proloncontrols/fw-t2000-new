
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
//         File : cfg.c
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Product configuration implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#define CFG_GLOBAL
#include "basic.h"
#include "cfg.h"
#include "e2.h"
#include "framework.h"
#include "app.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define CFG_E2_ADDRESS   0   //Configuration data base address in E2


//=============================================================================
//  M O D B U S   R E G I S T E R S   D E F I N I T I O N
//-----------------------------------------------------------------------------
const MB_Register_t CFG_Registers[] =
{
	{  1,   MbReg8,           1,   &CFG.Prd.DevType           },
	{  2,   MbReg16,          1,   &CFG.Prd.SoftVer           },
	{  3,   MbReg16,          1,   &CFG.Prd.HardVer           },
	//------------------------------------------------------------
	{  4,   MbReg16,        100,   &CFG.Dta.DefHeatSP         },
	{  5,   MbReg16,        100,   &CFG.Dta.DefCoolSP         },
	{  6,   MbReg16,        100,   &CFG.Dta.Prop              },
	{  7,   MbReg8,           1,   &CFG.Dta.CoolInt           },
	{  8,   MbReg8,           1,   &CFG.Dta.HeatInt           },
	{  9,   MbRegTemp,      100,   &CFG.Dta.MinHeatSP         },
	{ 10,   MbRegTemp,      100,   &CFG.Dta.MaxHeatSP         },
	{ 11,   MbRegTemp,      100,   &CFG.Dta.MinCoolSP         },
	{ 12,   MbRegTemp,      100,   &CFG.Dta.MaxCoolSP         },
	{ 13,   MbRegTemp,      100,   &CFG.Dta.UnocHeatOff       },
	{ 14,   MbRegTemp,      100,   &CFG.Dta.UnocCoolOff       },
	{ 15,   MbRegTemp,      100,   &CFG.Dta.UnocHeatSPLim     },
	{ 16,   MbRegTemp,      100,   &CFG.Dta.UnocCoolSPLim     },
	{ 17,   MbReg8,           1,   &CFG.Dta.DOSource          },
	{ 18,   MBRegPercent,     1,   &CFG.Dta.DOSP              },
	{ 19,   MbReg8,           1,   &CFG.Dta.DOMode            },
	{ 20,   MBRegPercent,     1,   &CFG.Dta.DOBand            },
	{ 21,   MbReg8,           1,   &CFG.Dta.DORevAct          },
	{ 22,   MbReg8,           1,   &CFG.Dta.AOSource          },
	{ 23,   MBRegPercent,     1,   &CFG.Dta.AOSP              },
	{ 24,   MbReg8,           1,   &CFG.Dta.AOMode            },
	{ 25,   MBRegPercent,     1,   &CFG.Dta.AOBand            },
	{ 26,   MbReg8,           1,   &CFG.Dta.AORevAct          },
	{ 27,   MbReg8,           1,   &CFG.Dta.AOPulsed          },
	{ 28,   MbReg8,           1,   &CFG.Dta.AORange           },
	{ 29,   MbReg8,           1,   &CFG.Dta.GrpCode1          },
	{ 30,   MbReg8,           1,   &CFG.Dta.GrpCode2          },
	{ 31,   MbReg8,           1,   &CFG.Dta.GrpCode3          },
	{ 32,   MbReg8,           1,   &CFG.Dta.GrpWeight1        },
	{ 33,   MbReg8,           1,   &CFG.Dta.GrpWeight2        },
	{ 34,   MbReg8,           1,   &CFG.Dta.GrpWeight3        },
	{ 35,   MbReg8,           1,   &CFG.Dta.GblWeight         },
	{ 36,   MbRegTemp,      100,   &CFG.Dta.RoomTempCal       },
	{ 37,   MbReg8,           1,   &CFG.Dta.UnocModeOverrTime },
	{ 38,   MbReg8,           1,   &CFG.Dta.RadFloorId        },
	{ 39,   MbRegTemp,      100,   &CFG.Dta.MinSlabTemp       },
	{ 40,   MbRegTemp,      100,   &CFG.Dta.MaxSlabTemp       },
	{ 41,   MbRegTemp,      100,   &CFG.Dta.MinSlabTempUnoc   },
	{ 42,   MbRegTemp,      100,   &CFG.Dta.OutTempRadCutOff  },
	{ 43,   MbRegTemp,      100,   &CFG.Dta.RadProp           },
	{ 44,   MbReg16,          1,   &CFG.Dta.RadInt            },
	{ 45,   MbRegTemp,      100,   &CFG.Dta.CalAuxInTemp      },
	{ 46,   MbReg16,          1,   &CFG.Dta.RadCycleTime      },
	{ 47,   MbReg8,           1,   &CFG.Dta.AIMode            },
	{ 48,   MbReg8,           1,   &CFG.Dta.MorningWarmUpTime },
	//------------------------------------------------------------
	{ 49,   MbReg8,           1,   &CFG.Dta.Address           },
	{ 50,   MbReg8,           1,   &CFG.Dta.TempUnit          },
	{ 52,   MbRegLoc,         1,    CFG.Dta.Location          },
	{ 60,   MbReg8,           1,   &CFG.Dta.BaudRate          },
	{ 61,   MbReg8,           1,   &CFG.Dta.Parity            },
	{ 62,   MbReg8,           1,   &CFG.Dta.StopBits          },
	{ 64,   MbReg8,           1,   &CFG.Dta.Language          },
	//------------------------------------------------------------
	{ 65,   MbRegTemp,      100,   &CFG.Dta.DisMinSP          },
	{ 66,   MbRegTemp,      100,   &CFG.Dta.DisMidSP          },
	{ 67,   MbRegTemp,      100,   &CFG.Dta.DisMaxSP          },
	{ 68,   MBRegPercent,     1,   &CFG.Dta.DisMinDem         },
	{ 69,   MBRegPercent,     1,   &CFG.Dta.DisMidDem         },
	{ 70,   MBRegPercent,     1,   &CFG.Dta.DisMaxDem         },
	{ 71,   MbRegTemp,      100,   &CFG.Dta.DisProp           },
	{ 72,   MbReg8,           1,   &CFG.Dta.DisInt            },
	{ 73,   MbReg8,           1,   &CFG.Dta.DisMode           },
	{ 74,   MbReg8,           1,   &CFG.Dta.IntDropRate       },
	{ 75,   MBRegPercent,     1,   &CFG.Dta.DOOverr           },
	{ 76,   MBRegPercent,     1,   &CFG.Dta.AOOverr           },
	{ 77,   MbReg8,           1,   &CFG.Dta.SchOverr          },
	//------------------------------------------------------------
	{ 78,   MbReg8,           1,   &CFG.Dta.ScrOrientation    },
	{ 79,   MbReg8,           1,   &CFG.Dta.ScrBrightness     },
	{ 80,   MbReg16,          1,   &CFG.Dta.ScrTimeout        },
};


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CFG_Load(void)
{
	CFG.Prd.DevType = 4;   //TODO: Create define
	CFG.Prd.SoftVer = APP_VERSION;
	CFG.Prd.HardVer = FMK_GetSharedFlash()->HardwareVersion;
	E2_Read(&CFG.Dta, CFG_E2_ADDRESS, sizeof(CFG_Data_t));
}

//-----------------------------------------------------------------------------
void CFG_Save(void)
{
	E2_Write(&CFG.Dta, CFG_E2_ADDRESS, sizeof(CFG_Data_t));
}

//-----------------------------------------------------------------------------
void CFG_Modified(void)
{
	FMK_PostSystemEvent(FmkSysEvtUpdCfg);   //TODO: Implement some kind of event posting after a certain amount of time without any data modification
}
