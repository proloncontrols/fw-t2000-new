
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


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define CFG_E2_ADDRESS   0   //Configuration data base address in E2


//=============================================================================
//  S T R U C T S
//-----------------------------------------------------------------------------
//typedef struct {
//	CFG_HoldingRegister_t Register;
//	uint16_t              Multiplier;
//	void*                 DataAddress;
//	uint16_t              DataSize;
//} CFG_HoldingRegisterLookup_t;


//=============================================================================
//  C O N S T A N T S
//-----------------------------------------------------------------------------
//static const CFG_HoldingRegisterLookup_t CFG_HoldingRegisterLookup[] =
//{
//	{ CfgHrDeviceType,       1, NULL,                     0                                },
//	{ CfgHrSoftVer,        100, NULL,                     0                                },
//	{ CfgHrHardVer,        100, NULL,                     0                                },
//
//	{ CfgHrModBusID,         1, &CFG_Data.ModBusID,       sizeof(CFG_DataModBusId_t)       },
//	{ CfgHrModBusName,       1,  CFG_Data.ModBusName,     sizeof(CFG_DataModBusName_t)     },
//
//	{ CfgHrComBaudRate,      1, &CFG_Data.ComBaudRate,    sizeof(CFG_DataComBaudRate_t)    },
//	{ CfgHrComStopBits,      1, &CFG_Data.ComStopBits,    sizeof(CFG_DataComStopBits_t)    },
//	{ CfgHrComParity,        1, &CFG_Data.ComParity,      sizeof(CFG_DataComParity_t)      },
//
//	{ CfgHrScrLanguage,      1, &CFG_Data.ScrLanguage,    sizeof(CFG_DataScrLanguage_t)    },
//	{ CfgHrScrOrientation,   1, &CFG_Data.ScrOrientation, sizeof(CFG_DataScrOrientation_t) },
//	{ CfgHrScrTimeout,       1, &CFG_Data.ScrTimeout,     sizeof(CFG_DataScrTimeout_t)     },
//
//	{ CfgHrTempUnit,         1, &CFG_Data.EnvTempUnit,    sizeof(CFG_DataEnvTempUnit_t)    }
//};


//=============================================================================
//  F A C T O R Y   D E F A U L T S   (placed in HEX file)
//-----------------------------------------------------------------------------
//#ifdef PROJECT_APP
//const CFG_Data_t __attribute__((section(".app_data"))) CFG_DefaultData =
//{
////	.ModBusID       = CFG_DEF_MODBUS_ADDRESS,
////	.ModBusName     = CFG_DEF_MODBUS_NAME,
////
////	.ComBaudRate    = CFG_DEF_COM_BAUDRATE,
////	.ComStopBits    = CFG_DEF_COM_STOPBITS,
////	.ComParity      = CFG_DEF_COM_PARITY,
////
////	.ScrLanguage    = CFG_DEF_SCR_LANGUAGE,
////	.ScrOrientation = CFG_DEF_SCR_ORIENTATION,
////	.ScrTimeout     = CFG_DEF_SCR_TIMEOUT,
////
////	.EnvTempUnit    = CFG_DEF_ENV_TEMP_UNIT
//};
//#endif


//=============================================================================
//  P R O T O T Y P E S
//-----------------------------------------------------------------------------
static const CFG_HldRegFormat_t* CFG_GetLookup (CFG_HldReg_t Register);


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CFG_Load(void)
{
	E2_Read(&CFG_Data, CFG_E2_ADDRESS, sizeof(CFG_Data_t));
}

//-----------------------------------------------------------------------------
void CFG_Save(void)
{
	E2_Write(&CFG_Data, CFG_E2_ADDRESS, sizeof(CFG_Data_t));
}

//-----------------------------------------------------------------------------
void CFG_Modified(void)
{
	FMK_PostSystemEvent(FmkSysEvtUpdCfg);
}

//-----------------------------------------------------------------------------
void CFG_Read(CFG_HldReg_t Register, void* Data)
{
	const CFG_HldRegFormat_t* Lookup = CFG_GetLookup(Register);

	if(Lookup)
	{
		switch(Lookup->RamSize)
		{
			case sizeof(uint8_t):
			{
				uint8_t* Src = (uint8_t*)Lookup->RamAddress;
				uint16_t* Dst = (uint16_t*)Data;
				*Dst = *Src;
			}
			break;

			case sizeof(uint16_t):
			{
				uint16_t* Src = (uint16_t*)Lookup->RamAddress;
				uint16_t* Dst = (uint16_t*)Data;
				*Dst = *Src;
			}
			break;

			case sizeof(CFG_DataLoc_t):
			{
				uint8_t* Src = (uint8_t*)Lookup->RamAddress;
				uint16_t* Dst = (uint16_t*)Data;

				for(int i = 0; i < sizeof(CFG_DataLoc_t); i+=2)
				{
					Dst[i]   = Src[i];
					Dst[i] <<= 8;
					Dst[i]  += Src[i+1];
				}
				//memcpy(Data, Lookup->RamAddress, sizeof(CFG_DataLoc_t));
			}
			break;
		}
	}
}

//-----------------------------------------------------------------------------
void CFG_Write(CFG_HldReg_t Register, void* Data)
{
	const CFG_HldRegFormat_t* Lookup = CFG_GetLookup(Register);

	if(Lookup)
	{
		switch(Lookup->RamSize)
		{
			case sizeof(uint8_t):
			{
				uint8_t* Src = (uint8_t*)Data;
				uint8_t* Dst = (uint8_t*)Lookup->RamAddress;
				*Dst = *Src;
			}
			break;

			case sizeof(uint16_t):
			{
				uint16_t* Src = (uint16_t*)Data;
				uint16_t* Dst = (uint16_t*)Lookup->RamAddress;
				*Dst = *Src;
			}
			break;

			case sizeof(CFG_DataLoc_t):
				memcpy(Lookup->RamAddress, Data, sizeof(CFG_DataLoc_t));
			break;
		}

		FMK_PostSystemEvent(FmkSysEvtUpdCfg);
	}
}


//=============================================================================
//  P R I V A T E S
//-----------------------------------------------------------------------------
static const CFG_HldRegFormat_t* CFG_GetLookup(CFG_HldReg_t Register)
{
	for(int i = 0; i < NUMBER_OF_ELEMENTS_IN(CFG_HldRegFormat); i++)
	{
		if(CFG_HldRegFormat[i].Register == Register)
			return &CFG_HldRegFormat[i];
	}
	return NULL;
}
