
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


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define CFG_E2_ADDRESS   0   //Configuration data base address in E2





//#define CFG_DATA_LENGTH   0x00001000   //EEPROM data size in bytes (4KB)

//#if defined(PROJECT_APP) && defined(RELEASE)
//const uint8_t __attribute__((section(".app_data"))) CFG_E2Data[CFG_DATA_LENGTH] = { 0 };
//#endif

//#define CFG_E2_MODBUS_ID_ADDR          CFG_E2_ADDRESS
//#define CFG_E2_MODBUS_ID_SIZE          sizeof(uint8_t)
//#define CFG_E2_MODBUS_NAME_ADDR       (CFG_E2_MODBUS_ID_ADDR + CFG_E2_MODBUS_ID_SIZE)
//#define CFG_E2_MODBUS_NAME_SIZE       (sizeof(char) * 8)
//
//#define CFG_E2_COM_BAUD_ADDR          (CFG_E2_MODBUS_NAME_ADDR + CFG_E2_MODBUS_NAME_SIZE)
//#define CFG_E2_COM_BAUD_SIZE           sizeof(uint8_t)
//#define CFG_E2_COM_STOP_ADDR          (CFG_E2_COM_BAUD_ADDR + CFG_E2_COM_BAUD_SIZE)
//#define CFG_E2_COM_STOP_SIZE           sizeof(uint8_t)
//#define CFG_E2_COM_PARITY_ADDR        (CFG_E2_COM_STOP_ADDR + CFG_E2_COM_STOP_SIZE)
//#define CFG_E2_COM_PARITY_SIZE         sizeof(uint8_t)
//
//#define CFG_E2_SCR_LANGUAGE_ADDR      (CFG_E2_COM_PARITY_SIZE + CFG_E2_COM_PARITY_SIZE)
//#define CFG_E2_SCR_LANGUAGE_SIZE       sizeof(uint8_t)
//#define CFG_E2_SCR_ORIENTATION_ADDR   (CFG_E2_SCR_LANGUAGE_ADDR + CFG_E2_SCR_LANGUAGE_SIZE)
//#define CFG_E2_SCR_ORIENTATION_SIZE    sizeof(uint8_t)
//#define CFG_E2_SCR_TIMEOUT_ADDR       (CFG_E2_SCR_ORIENTATION_ADDR + CFG_E2_SCR_ORIENTATION_SIZE)
//#define CFG_E2_SCR_TIMEOUT_SIZE        sizeof(uint16_t)


typedef enum {
	CfgFieldUint8,
	CfgFieldUint16,
	CfgFieldName
} CFG_FieldType_t;

typedef struct {
	CFG_HoldingRegister_t Register;
	void*                 FieldAddress;
	CFG_FieldType_t       FieldType;
} CFG_HoldingRegisterLookup_t;

static const CFG_HoldingRegisterLookup_t CFG_HoldingRegisterLookup [] =
{
	{ CfgHrModBusID,       &CFG_Data.ModBusID,       CfgFieldUint8  },
	{ CfgHrModBusName,      CFG_Data.ModBusName,     CfgFieldName   },

	{ CfgHrComBaudRate,    &CFG_Data.ComBaudRate,    CfgFieldUint8  },
	{ CfgHrComStopBits,    &CFG_Data.ComStopBits,    CfgFieldUint8  },
	{ CfgHrComParity,      &CFG_Data.ComParity,      CfgFieldUint8  },

	{ CfgHrScrLanguage,    &CFG_Data.ScrLanguage,    CfgFieldUint8  },
	{ CfgHrScrOrientation, &CFG_Data.ScrOrientation, CfgFieldUint8  },
	{ CfgHrScrTimeout,     &CFG_Data.ScrTimeout,     CfgFieldUint16 },

	{ CfgHrTempUnit,       &CFG_Data.EnvTempUnit,    CfgFieldUint8  }
};

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

//static const CFG_HoldingRegisterLookup_t CFG_HoldingRegisterLookup [] =
//{
//	{ CfgHrModBusID,       &CFG_Config.ModBusID,       CFG_E2_MODBUS_ID_ADDR,       CFG_E2_MODBUS_ID_SIZE       },
//	{ CfgHrModBusName,      CFG_Config.ModBusName,     CFG_E2_MODBUS_NAME_ADDR,     CFG_E2_MODBUS_NAME_SIZE     },
//
//	{ CfgHrComBaudRate,    &CFG_Config.ComBaudRate,    CFG_E2_COM_BAUD_ADDR,        CFG_E2_COM_BAUD_SIZE        },
//	{ CfgHrComStopBits,    &CFG_Config.ComStopBits,    CFG_E2_COM_STOP_SIZE,        CFG_E2_COM_STOP_SIZE        },
//	{ CfgHrComParity,      &CFG_Config.ComParity,      CFG_E2_COM_PARITY_ADDR,      CFG_E2_COM_PARITY_SIZE      },
//
//	{ CfgHrScrLanguage,    &CFG_Config.ScrLanguage,    CFG_E2_SCR_LANGUAGE_ADDR,    CFG_E2_SCR_LANGUAGE_SIZE    },
//	{ CfgHrScrOrientation, &CFG_Config.ScrOrientation, CFG_E2_SCR_ORIENTATION_ADDR, CFG_E2_SCR_ORIENTATION_SIZE },
//	{ CfgHrScrTimeout,     &CFG_Config.ScrTimeout,     CFG_E2_SCR_TIMEOUT_ADDR,     CFG_E2_SCR_TIMEOUT_SIZE     }
//};

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

//-----------------------------------------------------------------------------
bool_t CFG_RegRead(CFG_HoldingRegister_t Register, uint16_t Count, void* Data)
{
	const CFG_HoldingRegisterLookup_t* Lookup = CFG_GetLookup(Register);

	if(Lookup)
	{
		switch(Lookup->FieldType)
		{
			case CfgFieldUint8:
			{
				memcpy(Data, (uint8_t*)Lookup->FieldAddress, Count);
			}
			break;

			case CfgFieldUint16:
			{
				uint16_t* Src = (uint16_t*)Data;
				uint16_t* Dst = (uint16_t*)Lookup->FieldAddress;
				for(uint16_t i = 0; i < Count; i++)
					Dst[i] = SWAP_ENDIANESS(Src[i]);
			}
			break;

			case CfgFieldName:
			{
			}
			break;

			default:
			{
				return FALSE;
			}
			break;
		}
		return TRUE;
	}
	return FALSE;
}

//-----------------------------------------------------------------------------
bool_t CFG_RegWrite(CFG_HoldingRegister_t Register, uint16_t Count, void* Data)
{
	return TRUE;
}





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
void CFG_Defaults(CFG_Data_t* Cfg)
{
//	Cfg->Version           = CFG_VERSION;
//	Cfg->BaudRate          = CFG_DEF_BAUDRATE;
//	Cfg->Parity            = CFG_DEF_PARITY;
//	Cfg->StopBits          = CFG_DEF_STOPBITS;
//	Cfg->Address           = CFG_DEF_ADDRESS;
//	Cfg->ScreenOrientation = CFG_DEF_ORIENTATION;
//	Cfg->ScreenTimeout     = CFG_DEF_TIMEOUT;
//	Cfg->TempUnit          = CFG_DEF_TEMP_UNIT;

	CFG_Save(Cfg);
}
