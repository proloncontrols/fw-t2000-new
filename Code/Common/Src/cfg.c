
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
typedef struct {
	CFG_HoldingRegister_t Register;
	void*                 FieldAddress;
	int                   FieldSize;
} CFG_HoldingRegisterLookup_t;


static CFG_Data_t CFG_Data;


//=============================================================================
//  C O N S T A N T S
//-----------------------------------------------------------------------------
static const CFG_HoldingRegisterLookup_t CFG_HoldingRegisterLookup [] =
{
	{ CfgHrModBusID,       &CFG_Data.ModBusID,       sizeof(CFG_DataModBusId_t)       },
	{ CfgHrModBusName,      CFG_Data.ModBusName,     sizeof(CFG_DataModBusName_t)     },

	{ CfgHrComBaudRate,    &CFG_Data.ComBaudRate,    sizeof(CFG_DataComBaudRate_t)    },
	{ CfgHrComStopBits,    &CFG_Data.ComStopBits,    sizeof(CFG_DataComStopBits_t)    },
	{ CfgHrComParity,      &CFG_Data.ComParity,      sizeof(CFG_DataComParity_t)      },

	{ CfgHrScrLanguage,    &CFG_Data.ScrLanguage,    sizeof(CFG_DataScrLanguage_t)    },
	{ CfgHrScrOrientation, &CFG_Data.ScrOrientation, sizeof(CFG_DataScrOrientation_t) },
	{ CfgHrScrTimeout,     &CFG_Data.ScrTimeout,     sizeof(CFG_DataScrTimeout_t)     },

	{ CfgHrTempUnit,       &CFG_Data.EnvTempUnit,    sizeof(CFG_DataEnvTempUnit_t)    }
};


//=============================================================================
//  F A C T O R Y   D E F A U L T S   (placed in HEX file)
//-----------------------------------------------------------------------------
#ifdef PROJECT_APP
const CFG_Data_t __attribute__((section(".app_data"))) CFG_DefaultData =
{
	.ModBusID       = CFG_DEF_MODBUS_ADDRESS,
	.ModBusName     = CFG_DEF_MODBUS_NAME,

	.ComBaudRate    = CFG_DEF_COM_BAUDRATE,
	.ComStopBits    = CFG_DEF_COM_STOPBITS,
	.ComParity      = CFG_DEF_COM_PARITY,

	.ScrLanguage    = CFG_DEF_SCR_LANGUAGE,
	.ScrOrientation = CFG_DEF_SCR_ORIENTATION,
	.ScrTimeout     = CFG_DEF_SCR_TIMEOUT,

	.EnvTempUnit    = CFG_DEF_ENV_TEMP_UNIT
};
#endif


//=============================================================================
//  P R O T O T Y P E S
//-----------------------------------------------------------------------------
static const CFG_HoldingRegisterLookup_t* CFG_GetLookup (CFG_HoldingRegister_t Register);


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CFG_Load(CFG_Data_t* Cfg)
{
	E2_Read(Cfg, CFG_E2_ADDRESS, sizeof(CFG_Data_t));
}

//-----------------------------------------------------------------------------
void CFG_Save(CFG_Data_t* Cfg)
{
	E2_Write(Cfg, CFG_E2_ADDRESS, sizeof(CFG_Data_t));
}

//-----------------------------------------------------------------------------
void CFG_RegRead(CFG_HoldingRegister_t Register, void* Data)
{
	const CFG_HoldingRegisterLookup_t* Lookup = CFG_GetLookup(Register);

	if(Lookup)
	{
		switch(Lookup->FieldSize)
		{
			case sizeof(uint8_t):
			{
				uint8_t* Src = (uint8_t*)Lookup->FieldAddress;
				uint16_t* Dst = (uint16_t*)Data;
				*Dst = *Src;
			}
			break;

			case sizeof(uint16_t):
			{
				uint16_t* Src = (uint16_t*)Lookup->FieldAddress;
				uint16_t* Dst = (uint16_t*)Data;
				*Dst = *Src;
			}
			break;

			case sizeof(CFG_DataModBusName_t):
				memcpy(Data, Lookup->FieldAddress, sizeof(CFG_DataModBusName_t));
			break;
		}
	}
}

//-----------------------------------------------------------------------------
void CFG_RegWrite(CFG_HoldingRegister_t Register, void* Data)
{
	const CFG_HoldingRegisterLookup_t* Lookup = CFG_GetLookup(Register);

	if(Lookup)
	{
		switch(Lookup->FieldSize)
		{
			case sizeof(uint8_t):
			{
				uint8_t* Src = (uint8_t*)Data;
				uint8_t* Dst = (uint8_t*)Lookup->FieldAddress;
				*Dst = *Src;
			}
			break;

			case sizeof(uint16_t):
			{
				uint16_t* Src = (uint16_t*)Data;
				uint16_t* Dst = (uint16_t*)Lookup->FieldAddress;
				*Dst = *Src;
			}
			break;

			case sizeof(CFG_DataModBusName_t):
				memcpy(Lookup->FieldAddress, Data, sizeof(CFG_DataModBusName_t));
			break;
		}
	}
}

//-----------------------------------------------------------------------------
void CFG_RegGet(CFG_HoldingRegister_t Register, void* Data)
{
	CFG_RegRead(Register, Data);
}

//-----------------------------------------------------------------------------
void CFG_RegSet(CFG_HoldingRegister_t Register, void* Data)
{
	CFG_RegWrite(Register, Data);
	FMK_PostSystemEvent(FmkSysEvtUpdCfg);
}


//=============================================================================
//  P R I V A T E S
//-----------------------------------------------------------------------------
static const CFG_HoldingRegisterLookup_t* CFG_GetLookup(CFG_HoldingRegister_t Register)
{
	for(int i = 0; i < NUMBER_OF_ELEMENTS_IN(CFG_HoldingRegisterLookup); i++)
	{
		if(CFG_HoldingRegisterLookup[i].Register == Register)
			return &CFG_HoldingRegisterLookup[i];
	}
	return NULL;
}
