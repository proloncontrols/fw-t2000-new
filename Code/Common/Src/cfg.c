
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
//  P R O T O T Y P E S
//-----------------------------------------------------------------------------
//static const MB_Register_t* CFG_GetRegister(uint16_t Register);
//static const CFG_RegFormat_t* CFG_GetRegFormat(uint16_t Register);


//=============================================================================
//  C O N F I G U R A T I O N   F O R M A T   D E F I N I T I O N
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

const uint16_t CFG_RegisterCount = *(&CFG_Registers + 1) - CFG_Registers; //NUMBER_OF_ELEMENTS_IN(CFG_Registers);


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

//-----------------------------------------------------------------------------
//void CFG_Read(uint16_t Register, uint16_t Quantity, uint16_t* Data)
//{
//	const MB_Register_t* Reg;
//
//	for(uint16_t i = 0; i < Quantity; i++)
//	{
//		Reg = CFG_GetRegister(Register++);
//		if(Reg)
//		{
//			switch(Reg->Type)
//			{
//				case MbReg8:
//					Data[i] = REVERSE_ORDER_16((uint16_t)(*((uint8_t*)Reg->Ram)));
//				break;
//
//				case MbReg16:
//					Data[i] = REVERSE_ORDER_16(*((uint16_t*)Reg->Ram));
//				break;
//
//				case MbRegLoc:
//				{
//					memcpy(Data, Reg->Ram, CFG_MODBUS_LOC_SIZE);
//					for(int i = 0; i < CFG_MODBUS_LOC_SIZE/2; i++)
//						Data[i] = REVERSE_ORDER_16(Data[i]);
//				}
//				break;
//
//				case MbRegTemp:
//					Data[i] = REVERSE_ORDER_16((uint16_t)(*((int16_t*)Reg->Ram)));
//				break;
//
//				case MBRegPercent:
//					Data[i] = REVERSE_ORDER_16((uint16_t)(*((int8_t*)Reg->Ram)));
//				break;
//			}
//		}
//	}
////	const CFG_RegFormat_t* Format;
////
////	for(uint16_t i = 0; i < Quantity; i++)
////	{
////		Format = CFG_GetRegFormat(Register++);
////		if(Format)
////		{
////			switch(Format->Type)
////			{
////				case RegType8:
////					Data[i] = REVERSE_ORDER_16((uint16_t)(*((uint8_t*)Format->RamAddress)));
////				break;
////
////				case RegType16:
////					Data[i] = REVERSE_ORDER_16(*((uint16_t*)Format->RamAddress));
////				break;
////
////				case RegTypeLoc:
////				{
////					memcpy(Data, Format->RamAddress, CFG_MODBUS_NAME_SIZE);
////					for(int i = 0; i < CFG_MODBUS_NAME_SIZE/2; i++)
////						Data[i] = REVERSE_ORDER_16(Data[i]);
////				}
////				break;
////
////				case RegTypeTemp:
////					Data[i] = REVERSE_ORDER_16((uint16_t)(*((int16_t*)Format->RamAddress)));
////				break;
////
////				case RegTypePercent:
////					Data[i] = REVERSE_ORDER_16((uint16_t)(*((int8_t*)Format->RamAddress)));
////				break;
////			}
////		}
////	}
//
//
////	const CFG_HldRegFormat_t* Lookup = CFG_GetLookup(Register);
////
////	if(Lookup)
////	{
////		switch(Lookup->RamSize)
////		{
////			case sizeof(uint8_t):
////			{
////				uint8_t* Src = (uint8_t*)Lookup->RamAddress;
////				uint16_t* Dst = (uint16_t*)Data;
////				*Dst = *Src;
////			}
////			break;
////
////			case sizeof(uint16_t):
////			{
////				uint16_t* Src = (uint16_t*)Lookup->RamAddress;
////				uint16_t* Dst = (uint16_t*)Data;
////				*Dst = *Src;
////			}
////			break;
////
////			case sizeof(CFG_DataLoc_t):
////			{
////				uint8_t* Src = (uint8_t*)Lookup->RamAddress;
////				uint16_t* Dst = (uint16_t*)Data;
////
////				for(int i = 0; i < sizeof(CFG_DataLoc_t); i+=2)
////				{
////					Dst[i]   = Src[i];
////					Dst[i] <<= 8;
////					Dst[i]  += Src[i+1];
////				}
////				//memcpy(Data, Lookup->RamAddress, sizeof(CFG_DataLoc_t));
////			}
////			break;
////		}
////	}
//}
//void CFG_Read(CFG_HldReg_t Register, void* Data)
//{
//	const CFG_HldRegFormat_t* Lookup = CFG_GetLookup(Register);
//
//	if(Lookup)
//	{
//		switch(Lookup->RamSize)
//		{
//			case sizeof(uint8_t):
//			{
//				uint8_t* Src = (uint8_t*)Lookup->RamAddress;
//				uint16_t* Dst = (uint16_t*)Data;
//				*Dst = *Src;
//			}
//			break;
//
//			case sizeof(uint16_t):
//			{
//				uint16_t* Src = (uint16_t*)Lookup->RamAddress;
//				uint16_t* Dst = (uint16_t*)Data;
//				*Dst = *Src;
//			}
//			break;
//
//			case sizeof(CFG_DataLoc_t):
//			{
//				uint8_t* Src = (uint8_t*)Lookup->RamAddress;
//				uint16_t* Dst = (uint16_t*)Data;
//
//				for(int i = 0; i < sizeof(CFG_DataLoc_t); i+=2)
//				{
//					Dst[i]   = Src[i];
//					Dst[i] <<= 8;
//					Dst[i]  += Src[i+1];
//				}
//				//memcpy(Data, Lookup->RamAddress, sizeof(CFG_DataLoc_t));
//			}
//			break;
//		}
//	}
//}

//-----------------------------------------------------------------------------
//void CFG_Write(uint16_t Register, uint16_t Quantity, uint16_t* Data)
//{
//	const MB_Register_t* Reg;
//
//	for(uint16_t i = 0; i < Quantity; i++)
//	{
//		Reg = CFG_GetRegister(Register++);
//		if(Reg)
//		{
////			switch(Format->Type)
////			{
////				case RegType8:    { Data[i] = REVERSE_ORDER_16((uint16_t)(*((uint8_t*)Format->RamAddress)));    break; }
////				case RegType16:   {	Data[i] = REVERSE_ORDER_16(*((uint16_t*)Format->RamAddress));               break; }
////				case RegTypeLoc:  { memcpy(Data, Format->RamAddress, CFG_MODBUS_NAME_SIZE);                     break; }
////				case RegTypeTemp: { Data[i] = REVERSE_ORDER_16((uint16_t)(*((int16_t*)Format->RamAddress)));    break; }
////			}
//		}
//	}
//
//	FMK_PostSystemEvent(FmkSysEvtUpdCfg);
////	const CFG_RegFormat_t* Format;
////
////	for(uint16_t i = 0; i < Quantity; i++)
////	{
////		Format = CFG_GetRegFormat(Register++);
////		if(Format)
////		{
//////			switch(Format->Type)
//////			{
//////				case RegType8:    { Data[i] = REVERSE_ORDER_16((uint16_t)(*((uint8_t*)Format->RamAddress)));    break; }
//////				case RegType16:   {	Data[i] = REVERSE_ORDER_16(*((uint16_t*)Format->RamAddress));               break; }
//////				case RegTypeLoc:  { memcpy(Data, Format->RamAddress, CFG_MODBUS_NAME_SIZE);                     break; }
//////				case RegTypeTemp: { Data[i] = REVERSE_ORDER_16((uint16_t)(*((int16_t*)Format->RamAddress)));    break; }
//////			}
////		}
////	}
////
////	FMK_PostSystemEvent(FmkSysEvtUpdCfg);
//}
//void CFG_Write(CFG_HldReg_t Register, void* Data)
//{
//	const CFG_HldRegFormat_t* Lookup = CFG_GetLookup(Register);
//
//	if(Lookup)
//	{
//		switch(Lookup->RamSize)
//		{
//			case sizeof(uint8_t):
//			{
//				uint8_t* Src = (uint8_t*)Data;
//				uint8_t* Dst = (uint8_t*)Lookup->RamAddress;
//				*Dst = *Src;
//			}
//			break;
//
//			case sizeof(uint16_t):
//			{
//				uint16_t* Src = (uint16_t*)Data;
//				uint16_t* Dst = (uint16_t*)Lookup->RamAddress;
//				*Dst = *Src;
//			}
//			break;
//
//			case sizeof(CFG_DataLoc_t):
//				memcpy(Lookup->RamAddress, Data, sizeof(CFG_DataLoc_t));
//			break;
//		}
//
//		FMK_PostSystemEvent(FmkSysEvtUpdCfg);
//	}
//}


//=============================================================================
//  P R I V A T E S
//-----------------------------------------------------------------------------
//static const MB_Register_t* CFG_GetRegister(uint16_t Register)
//{
//	for(int i = 0; i < NUMBER_OF_ELEMENTS_IN(CFG_Registers); i++)
//	{
//		if(CFG_Registers[i].Number == Register)
//			return &CFG_Registers[i];
//	}
//	return NULL;
//}
//static const CFG_RegFormat_t* CFG_GetRegFormat(uint16_t Register)
//{
//	for(int i = 0; i < NUMBER_OF_ELEMENTS_IN(CFG_RegFormat); i++)
//	{
//		if(CFG_RegFormat[i].Number == Register)
//			return &CFG_RegFormat[i];
//	}
//	return NULL;
//}
//static const CFG_HldRegFormat_t* CFG_GetLookup(CFG_HldReg_t Register)
//{
//	for(int i = 0; i < NUMBER_OF_ELEMENTS_IN(CFG_HldRegFormat); i++)
//	{
//		if(CFG_HldRegFormat[i].Register == Register)
//			return &CFG_HldRegFormat[i];
//	}
//	return NULL;
//}
