
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
static const CFG_RegFormat_t* CFG_GetRegFormat(uint16_t Register);


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CFG_Load(void)
{
	CFG.Product.DevType = 4;   //TODO: Create define
	CFG.Product.SoftVer = APP_VERSION;
	CFG.Product.HardVer = FMK_GetSharedFlash()->HardwareVersion;
	E2_Read(&CFG.Data, CFG_E2_ADDRESS, sizeof(CFG_Data_t));
}

//-----------------------------------------------------------------------------
void CFG_Save(void)
{
	E2_Write(&CFG.Data, CFG_E2_ADDRESS, sizeof(CFG_Data_t));
}

//-----------------------------------------------------------------------------
void CFG_Modified(void)
{
	FMK_PostSystemEvent(FmkSysEvtUpdCfg);
}

//-----------------------------------------------------------------------------
void CFG_Read(uint16_t Register, uint16_t Quantity, uint16_t* Data)
{
	const CFG_RegFormat_t* Format;

	for(uint16_t i = 0; i < Quantity; i++)
	{
		Format = CFG_GetRegFormat(Register++);
		if(Format)
		{
			switch(Format->Type)
			{
				case RegType8:
					Data[i] = REVERSE_ORDER_16((uint16_t)(*((uint8_t*)Format->RamAddress)));
				break;

				case RegType16:
					Data[i] = REVERSE_ORDER_16(*((uint16_t*)Format->RamAddress));
				break;

				case RegTypeLoc:
				{
					memcpy(Data, Format->RamAddress, CFG_MODBUS_NAME_SIZE);
					for(int i = 0; i < CFG_MODBUS_NAME_SIZE/2; i++)
						Data[i] = REVERSE_ORDER_16(Data[i]);
				}
				break;

				case RegTypeTemp:
					Data[i] = REVERSE_ORDER_16((uint16_t)(*((int16_t*)Format->RamAddress)));
				break;

				case RegTypePercent:
					Data[i] = REVERSE_ORDER_16((uint16_t)(*((int8_t*)Format->RamAddress)));
				break;
			}
		}
	}


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
}
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
void CFG_Write(uint16_t Register, uint16_t Quantity, uint16_t* Data)
{
	const CFG_RegFormat_t* Format;

	for(uint16_t i = 0; i < Quantity; i++)
	{
		Format = CFG_GetRegFormat(Register++);
		if(Format)
		{
//			switch(Format->Type)
//			{
//				case RegType8:    { Data[i] = REVERSE_ORDER_16((uint16_t)(*((uint8_t*)Format->RamAddress)));    break; }
//				case RegType16:   {	Data[i] = REVERSE_ORDER_16(*((uint16_t*)Format->RamAddress));               break; }
//				case RegTypeLoc:  { memcpy(Data, Format->RamAddress, CFG_MODBUS_NAME_SIZE);                     break; }
//				case RegTypeTemp: { Data[i] = REVERSE_ORDER_16((uint16_t)(*((int16_t*)Format->RamAddress)));    break; }
//			}
		}
	}

	FMK_PostSystemEvent(FmkSysEvtUpdCfg);
}
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
static const CFG_RegFormat_t* CFG_GetRegFormat(uint16_t Register)
{
	for(int i = 0; i < NUMBER_OF_ELEMENTS_IN(CFG_RegFormat); i++)
	{
		if(CFG_RegFormat[i].Number == Register)
			return &CFG_RegFormat[i];
	}
	return NULL;
}
//static const CFG_HldRegFormat_t* CFG_GetLookup(CFG_HldReg_t Register)
//{
//	for(int i = 0; i < NUMBER_OF_ELEMENTS_IN(CFG_HldRegFormat); i++)
//	{
//		if(CFG_HldRegFormat[i].Register == Register)
//			return &CFG_HldRegFormat[i];
//	}
//	return NULL;
//}
