
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
//         File : framework.c
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : System base architecture source file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#define FMK_GLOBAL
#include "framework.h"
#include "event.h"
#include "project.h"
#include "modbus.h"
#include "app.h"
#include "flash.h"
#include "e2.h"
#include "ui.h"


//=============================================================================
//  P R O J E C T   C O N F I G U R A T I O N
//-----------------------------------------------------------------------------
#ifdef PROJECT_APP
#define FMK_BOOT_VERSION          0x0000
#define FMK_SHARED_FLASH_ADDRESS  FMK_ADDR_BOOTL_SHARED

const PRD_Banner_t __attribute__((section(".app_header"))) FMK_Header = PRJ_PRD_HEADER;
const PRD_Banner_t __attribute__((section(".app_footer"))) FMK_Footer = PRJ_PRD_FOOTER;
#endif
//-----------------------------------------------
#ifdef PROJECT_BOOTL
#define FMK_BOOT_VERSION          APP_VERSION
#define FMK_SHARED_FLASH_ADDRESS  FMK_ADDR_BOOTL_SHARED
#define FMK_INT_START             FMK_ADDR_APP_INT_START
#define FMK_INT_END               FMK_ADDR_APP_INT_END
#define FMK_EXT_START             FMK_ADDR_APP_EXT_START
#define FMK_EXT_END               FMK_ADDR_APP_EXT_END
#define FMK_SECTOR_INT_START      4
#define FMK_SECTOR_INT_COUNT      4
#define FMK_SECTOR_ASSET_START    0
#define FMK_SECTOR_ASSET_COUNT    1016
#define FMK_SECTOR_EXT_START      1016
#define FMK_SECTOR_EXT_COUNT      8

const PRD_Banner_t __attribute__((section(".boot_header"))) FMK_Header = PRD_BOOTLOADER_HEADER;
const PRD_Banner_t __attribute__((section(".boot_footer"))) FMK_Footer = PRD_BOOTLOADER_FOOTER;
#endif
//-----------------------------------------------
#ifdef PROJECT_BOOTU
#define FMK_BOOT_VERSION          0x0000
#define FMK_SHARED_FLASH_ADDRESS  FMK_ADDR_BOOTU_SHARED
#define FMK_INT_START             FMK_ADDR_BOOTL_START
#define FMK_INT_END               FMK_ADDR_BOOTL_END
#define FMK_SECTOR_INT_START      0
#define FMK_SECTOR_INT_COUNT      4

const PRD_Banner_t __attribute__((section(".app_header"))) FMK_Header = PRD_BOOTUPDATER_HEADER;
const PRD_Banner_t __attribute__((section(".app_footer"))) FMK_Footer = PRD_BOOTUPDATER_FOOTER;
#endif


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define FMK_FRAMEWORK_DATA_SIZE   1024
#define FMK_MODBUS_DATA_SIZE      128
#define FMK_E2_ACQUIRE_TIMEOUT    5000   //5 seconds


//=============================================================================
//  C O N S T A N T S
//-----------------------------------------------------------------------------
#if defined(PROJECT_BOOTL) || defined(PROJECT_BOOTU) || (defined(PROJECT_APP) && defined(DEBUG))
const FMK_SharedFlash_t __attribute__((section(".shared_flash"))) FMK_SharedFlashData =
{
	//Product
	.FamilyID  = PRJ_PRD_ID_FAMILY,
	.ProductID = PRJ_PRD_ID,
	.Header    = PRJ_PRD_HEADER,
	.Footer    = PRJ_PRD_FOOTER,
	//Hardware
	.HardwareVersion = PRJ_HARDWARE_VERSION,
	//Bootloader
	.BootVersion = FMK_BOOT_VERSION,
};
#endif


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef struct {
	osMutexId_t       E2Mutex;
	FMK_SystemEvent_t Event;
	FMK_Cmd_t*        CmdIn;
	FMK_Cmd_t*        CmdOut;
	uint16_t          CalculatedCRC;
	FLASH_Device_t    FlashDevice;
	uint16_t          FlashDataSize;
} FMK_t;

typedef void (*EntryPoint)(void);


//=============================================================================
//  L O C A L   V A R I A B L E S
//-----------------------------------------------------------------------------
static FMK_t FMK;
static FMK_SharedRam_t* FMK_SharedRam = (FMK_SharedRam_t*)&FMK_ADDR_RAM_SHARED;
static FMK_SharedFlash_t* FMK_SharedFlash = (FMK_SharedFlash_t*)&FMK_SHARED_FLASH_ADDRESS;


//=============================================================================
//  P R O T O T Y P E S
//-----------------------------------------------------------------------------
static void     FMK_OnSystem                     (void);
static void     FMK_OnCom                        (void);

static bool_t   FMK_ComFramework                 (COM_Connexion_t* Conx);
static bool_t   FMK_ComModBus                    (COM_Connexion_t* Conx);
static void     FMK_Upgrade                      (COM_Connexion_t* Conx);
static void     FMK_Tx                           (COM_Connexion_t* Conx);

static void     FMK_CmdIdentify                  (COM_Connexion_t* Conx);
static void     FMK_CmdEnter                     (COM_Connexion_t* Conx);
static void     FMK_CmdLeave                     (COM_Connexion_t* Conx);
static void     FMK_CmdFirmwareErase             (COM_Connexion_t* Conx);
static void     FMK_CmdFirmwareWrite             (COM_Connexion_t* Conx);
static void     FMK_CmdFirmwareRead              (COM_Connexion_t* Conx);
static void     FMK_CmdAssetErase                (COM_Connexion_t* Conx);
static void     FMK_CmdAssetWrite                (COM_Connexion_t* Conx);
static void     FMK_CmdAssetRead                 (COM_Connexion_t* Conx);
static void     FMK_CmdDataWrite                 (COM_Connexion_t* Conx);
static void     FMK_CmdDataRead                  (COM_Connexion_t* Conx);
static void     FMK_CmdResult                    (COM_Connexion_t* Conx, uint8_t Result);

#ifndef PROJECT_BOOTL
static bool_t   FMK_ValidateBootL                (void);
#endif

#ifdef PROJECT_BOOTL
static bool_t   FMK_ValidateAppBootU             (void);
#endif

static void     FMK_Enter                        (COM_Connexion_t* Conx, uint32_t Address);
static bool_t   FMK_ValidateBanner               (const PRD_Banner_t Banner, uint32_t FlashAddress);

#ifndef PROJECT_APP
static bool_t   FMK_ValidateFlashAddressFirmware (uint32_t Address, uint16_t Length);
static bool_t   FMK_ValidateFlashAddressAsset    (uint32_t Address, uint16_t Length);
static bool_t   FMK_ValidateE2Address            (uint32_t Address, uint16_t Length);
#endif

#if defined(PROJECT_BOOTL) || defined(PROJECT_BOOTU)
static void     FMK_CRCCalculate                 (uint8_t* Data, uint16_t Length);
static void     FMK_CRCClear                     (void);
static uint16_t FMK_CRCGet                       (void);
#endif


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void FMK_Init(void)
{
	APP_OnInitBegin();
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	FMK.E2Mutex = osMutexNew(NULL);
	CFG_Load(&CFG_Data);
	UI_Init();
	FMK_Flags = osEventFlagsNew(NULL);
	MB_Init();
	COM_Init();

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	APP_OnInitEnd();
}

//-----------------------------------------------------------------------------
void FMK_Entry(void)
{
	APP_OnEntryBegin();
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// Reserved for internal process

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	APP_OnEntryEnd();
}

//-----------------------------------------------------------------------------
void FMK_Main(void)
{
	uint32_t Flag = osEventFlagsWait(FMK_Flags, EVT_ALL_GROUPS_MASK, osFlagsWaitAny, APP_IDLE_PERIODIC_TIMEOUT);

	if(Flag == osFlagsErrorTimeout)   //Execute periodic processes
		APP_OnPeriodic();

	else if(!(Flag & 0x80000000U))    //No unexpected error
	{
		     if(Flag & NUM2POS(EvtGrpSys))   FMK_OnSystem();     //System events
		else if(Flag & NUM2POS(EvtGrpCom))   FMK_OnCom();        //Communication events
		else                                 APP_OnFlag(Flag);   //Event is not meant for the framework
	}
}

//-----------------------------------------------------------------------------
void FMK_E2Acquire(void)
{
	if(osMutexAcquire(FMK.E2Mutex, FMK_E2_ACQUIRE_TIMEOUT) != osOK)
		Error_Handler();
}

//-----------------------------------------------------------------------------
void FMK_E2Release(void)
{
	if(osMutexRelease(FMK.E2Mutex) != osOK)
		Error_Handler();
}

//-----------------------------------------------------------------------------
void FMK_SetBootAddress(uint32_t Address)
{
	FLASH_OBProgramInitTypeDef Init;

	if(HAL_FLASH_OB_Unlock() != HAL_OK)
		Error_Handler();

	HAL_FLASHEx_OBGetConfig(&Init);
	if(Init.BootAddr0 != Address)
	{
		Init.BootConfig = OB_BOOT_ADD0;
		Init.OptionType = OPTIONBYTE_BOOTADD;
		Init.BootAddr0  = Address;

		if(HAL_FLASHEx_OBProgram(&Init) != HAL_OK)
			Error_Handler();

		if(HAL_FLASH_OB_Launch() != HAL_OK)
			Error_Handler();
	}

	if(HAL_FLASH_OB_Lock() != HAL_OK)
		Error_Handler();
}

////-----------------------------------------------------------------------------
void FMK_PostFlag(uint32_t Flag)
{
	osEventFlagsSet(FMK_Flags, Flag);
}

//-----------------------------------------------------------------------------
void FMK_PostSystemEvent(FMK_SystemEvent_t Event)
{
	FMK.Event = Event;
	osEventFlagsSet(FMK_Flags, NUM2POS(EvtGrpSys));
}


//=============================================================================
//  P R I V A T E
//-----------------------------------------------------------------------------
static void FMK_OnSystem(void)
{
	if(FMK.Event == FmkSysEvtRdy)
	{
		if(FMK_SharedRam->Entry == FMK_ENTRY_FROM_CODE)
		{
			FMK_SharedRam->Entry = 0;   //Make sure no answer is to be sent upon any warm starts other than upgrade
			FMK_Conx = COM_GetConnexion(FMK_SharedRam->Media);
			FMK_Conx->Protocol = FMK_SharedRam->Protocol;

			if(FMK_Conx->Protocol == ComProtocolFmk)
			{
				FMK_Packet_t* PktIn  = (FMK_Packet_t*)FMK_Conx->PacketIn.Payload;
				FMK_Packet_t* PktOut = (FMK_Packet_t*)FMK_Conx->PacketOut.Payload;
				FMK.CmdIn  = (FMK_Cmd_t*)&PktIn->Command;
				FMK.CmdOut = (FMK_Cmd_t*)&PktOut->Command;
			}
			else
			{
				MB_Packet_t* PktIn  = (MB_Packet_t*)FMK_Conx->PacketIn.Payload;
				MB_Packet_t* PktOut = (MB_Packet_t*)FMK_Conx->PacketOut.Payload;
				FMK.CmdIn = (FMK_Cmd_t*)&PktIn->Function.FctMEIT.Data;
				FMK.CmdOut = (FMK_Cmd_t*)&PktOut->Function.FctMEIT.Data;

				PktOut->Header.Address               = CFG_Data.ModBusID; // FMK_Config.Address;
				PktOut->Header.Function              = MbFctMEIT;
				PktOut->Function.FctMEIT.SubFunction = MbSubFctMEITUpgrade;
			}

			FMK_CmdIdentify(FMK_Conx);
		}
		else
		{
			FMK_Conx = COM_GetConnexion(ComMediaRs485);
			COM_Rx(FMK_Conx);
		}
	}

	else if(FMK.Event == FmkSysEvtRst)
	{
		__disable_irq();
		NVIC_SystemReset();
	}

	else if(FMK.Event == FmkSysEvtUpdCfg)
	{
		FMK_E2Acquire();
		CFG_Save(&CFG_Data);
		FMK_E2Release();
	}
}

//-----------------------------------------------------------------------------
static void FMK_OnCom(void)
{
	FMK_Conx = COM_GetConnexion(COM_GetMedia());

	if(FMK_Conx->Event == ComEventRxCplt)
	{
		if(COM_ValidateCRC(FMK_Conx))
		{
			if(FMK_ComFramework(FMK_Conx))
				return;

			if(FMK_ComModBus(FMK_Conx))
				return;

			APP_OnCom(FMK_Conx);
		}
		else
			COM_Rx(FMK_Conx);
	}

	else if(FMK_Conx->Event == ComEventTxCplt)
		COM_Rx(FMK_Conx);
}

//-----------------------------------------------------------------------------
static bool_t FMK_ComFramework(COM_Connexion_t* Conx)
{
	FMK_Packet_t* PktIn = (FMK_Packet_t*)Conx->PacketIn.Payload;

	Conx->ModBusAddress = MB_ADDR_BROADCAST;   //On received packst, initialize ModBus address to broadcast (0) no matter what
	if(PktIn->Header.Header == FMK_HEADER)     //Framework packet?
	{
		FMK_Packet_t* PktOut = (FMK_Packet_t*)Conx->PacketOut.Payload;
		FMK_Cmd_t* CmdIn = (FMK_Cmd_t*)&PktIn->Command;

		PktOut->Header.Header = FMK_HEADER;
		Conx->Protocol = ComProtocolFmk;
		FMK.CmdIn = CmdIn;
		FMK.CmdOut = (FMK_Cmd_t*)&PktOut->Command;
		FMK.FlashDataSize = FMK_FRAMEWORK_DATA_SIZE;
		FMK_Upgrade(Conx);
		return TRUE;   //Command has been processed
	}
	return FALSE;
}

//-----------------------------------------------------------------------------
static bool_t FMK_ComModBus(COM_Connexion_t* Conx)
{
	MB_Packet_t* PktIn = (MB_Packet_t*)Conx->PacketIn.Payload;

	if(PktIn->Header.Address == MB_ADDR_BROADCAST)
		return FALSE;   //On broadcast packet, pass control to application

	if(PktIn->Header.Address != CFG_Data.ModBusID)
//	if(PktIn->Header.Address != FMK_Config.Address)
	{
		COM_Rx(Conx);
		return TRUE;    //Ignore packet if it does not belong to us
	}

	//Packet belongs to us...
	if((PktIn->Header.Function == MbFctMEIT) && (PktIn->Function.FctMEIT.SubFunction == MbSubFctMEITUpgrade))   //Firmware upgrade packet?
	{
		MB_Packet_t* PktOut = (MB_Packet_t*)Conx->PacketOut.Payload;

		PktOut->Header.Address = PktIn->Header.Address;
		PktOut->Header.Function = PktIn->Header.Function;
		PktOut->Function.FctMEIT.SubFunction = PktIn->Function.FctMEIT.SubFunction;
		Conx->Protocol = ComProtocolMb;
		FMK.CmdIn = (FMK_Cmd_t*)&PktIn->Function.FctMEIT.Data;
		FMK.CmdOut = (FMK_Cmd_t*)&PktOut->Function.FctMEIT.Data;
		FMK.FlashDataSize = FMK_MODBUS_DATA_SIZE;
		FMK_Upgrade(Conx);
		return TRUE;
	}

	Conx->ModBusAddress = CFG_Data.ModBusID;
//	Conx->ModBusAddress = FMK_Config.Address;
	return FALSE;                               //Pass control to application
}

//-----------------------------------------------------------------------------
static void FMK_Upgrade(COM_Connexion_t* Conx)
{
	switch(FMK.CmdIn->Command)
	{
		case FmkCmdIdentify:        { FMK_CmdIdentify        (Conx);   break; }
		case FmkCmdEnter:           { FMK_CmdEnter           (Conx);   break; }
		case FmkCmdLeave:           { FMK_CmdLeave           (Conx);   break; }
		case FmkCmdFirmwareErase:   { FMK_CmdFirmwareErase   (Conx);   break; }
		case FmkCmdFirmwareWrite:   { FMK_CmdFirmwareWrite   (Conx);   break; }
		case FmkCmdFirmwareRead:    { FMK_CmdFirmwareRead    (Conx);   break; }
		case FmkCmdAssetErase:      { FMK_CmdAssetErase      (Conx);   break; }
		case FmkCmdAssetWrite:      { FMK_CmdAssetWrite      (Conx);   break; }
		case FmkCmdAssetRead:       { FMK_CmdAssetRead       (Conx);   break; }
		case FmkCmdDataWrite:       { FMK_CmdDataWrite       (Conx);   break; }
		case FmkCmdDataRead:        { FMK_CmdDataRead        (Conx);   break; }

		default:
			FMK_CmdResult(Conx, FmkErrUnknownCommand);
		break;
	}
}

//-----------------------------------------------------------------------------
static void FMK_Tx(COM_Connexion_t* Conx)
{
	uint16_t PktLen = Conx->PacketOut.Length;   //First, initialize with current upgrade command length only

	//Then, add current protocol header length
	if(Conx->Protocol == ComProtocolFmk)
		PktLen += sizeof(FMK_PktHeader_t);
	else
		PktLen += sizeof(MB_PktHeader_t) + 1;   //+1 is for MEIT sub function

	COM_Checksum_t* Checksum = (COM_Checksum_t*)(Conx->PacketOut.Payload + (uint32_t)PktLen);   //Get pointer to checksum destination
	*Checksum = COM_CRC16(Conx->PacketOut.Payload, PktLen);
	Conx->PacketOut.Length = PktLen + sizeof(COM_Checksum_t);   //Finally, add length of checksum to get packet total length
	COM_Tx(Conx);
}

//-----------------------------------------------------------------------------
static void FMK_CmdIdentify(COM_Connexion_t* Conx)
{
	FMK_CmdIdentify_t* CmdOut = (FMK_CmdIdentify_t*)FMK.CmdOut;

	CmdOut->Answer.Command         = FmkCmdIdentify;
	CmdOut->Answer.FamilyID        = FMK_SharedFlash->FamilyID;
	CmdOut->Answer.ProductID       = FMK_SharedFlash->ProductID;
	CmdOut->Answer.HardwareVersion = FMK_SharedFlash->HardwareVersion;
	CmdOut->Answer.BootVersion     = FMK_SharedFlash->BootVersion;
#ifdef PROJECT_APP
	CmdOut->Answer.Firmware        = FmkFirmApp;
	CmdOut->Answer.AppVersion      = APP_VERSION;
#endif
#ifdef PROJECT_BOOTL
	CmdOut->Answer.Firmware        = FmkFirmBootL;
	CmdOut->Answer.AppVersion      = 0;
#endif
#ifdef PROJECT_BOOTU
	CmdOut->Answer.Firmware        = FmkFirmBootU;
	CmdOut->Answer.BootVersion     = FMK_BOOT_VERSION;
	CmdOut->Answer.AppVersion      = APP_VERSION;
#endif

	Conx->PacketOut.Length = sizeof(FMK_CmdIdentify_t);
	FMK_Tx(Conx);
}

//-----------------------------------------------------------------------------
static void FMK_CmdEnter(COM_Connexion_t* Conx)
{
#ifdef PROJECT_APP
	if(FMK_ValidateBootL())
		FMK_Enter(Conx, (uint32_t)&FMK_ADDR_BOOTL_VECTORS);
	else
		FMK_CmdResult(Conx, FmkErrBanners);
#else
	FLASH_Init(FlashDeviceExt);
	FMK_CmdResult(Conx, FmkErrNone);
#endif
}

//-----------------------------------------------------------------------------
static void FMK_CmdLeave(COM_Connexion_t* Conx)
{
#ifdef PROJECT_APP
	FMK_CmdResult(Conx, FmkErrForbidden);
#else
	uint16_t ReceivedCRC = ((FMK_CmdLeave_t*)FMK.CmdIn)->CalculatedCRC;

	if((ReceivedCRC != 0xFFFF) && ((ReceivedCRC == 0x0000) || (ReceivedCRC != FMK_CRCGet())))
		FMK_CmdResult(Conx, FmkErrFirmwareCRC);
	else
	{
		FLASH_Reset(FlashDeviceExt);
#ifdef PROJECT_BOOTL
		if(FMK_ValidateAppBootU())
			FMK_Enter(Conx, (uint32_t)&FMK_ADDR_APP_VECTORS);
		else
#else
		if(FMK_ValidateBootL())
			FMK_Enter(Conx, (uint32_t)&FMK_ADDR_BOOTL_VECTORS);
		else
#endif
			FMK_CmdResult(Conx, FmkErrBanners);
	}
#endif
}

//-----------------------------------------------------------------------------
static void FMK_CmdFirmwareErase(COM_Connexion_t* Conx)
{
#ifdef PROJECT_APP
	FMK_CmdResult(Conx, FmkErrForbidden);
#else
	FMK_CmdFirmwareErase_t* CmdIn = (FMK_CmdFirmwareErase_t*)FMK.CmdIn;

	UI_ProgressInit(CmdIn->ProgressSteps);
	if(FLASH_Erase(FlashDeviceCpu, FMK_SECTOR_INT_START, FMK_SECTOR_INT_COUNT) != HAL_OK)
		FMK_CmdResult(Conx, FmkErrErase);

#ifdef PROJECT_BOOTL
	else if(FLASH_Erase(FlashDeviceExt, FMK_SECTOR_EXT_START, FMK_SECTOR_EXT_COUNT) != HAL_OK)
		FMK_CmdResult(Conx, FmkErrErase);

#endif
	else
	{
		FMK_CRCClear();
		FMK_CmdResult(Conx, FmkErrNone);
	}
#endif
}

//-----------------------------------------------------------------------------
static void FMK_CmdFirmwareWrite(COM_Connexion_t* Conx)
{
#ifdef PROJECT_APP
	FMK_CmdResult(Conx, FmkErrForbidden);
#else
	FMK_CmdFirmwareWrite_t* CmdIn = (FMK_CmdFirmwareWrite_t*)FMK.CmdIn;
	FMK_CmdFirmwareWrite_t* CmdOut = (FMK_CmdFirmwareWrite_t*)FMK.CmdOut;

	CmdOut->Command = FmkCmdFirmwareWrite;

	if(!FMK_ValidateFlashAddressFirmware(CmdIn->Address, CmdIn->Length))
		FMK_CmdResult(Conx, FmkErrAddress);

	else
	{
		if(CmdIn->Length != FMK.FlashDataSize)
			FMK_CmdResult(Conx, FmkErrWrite);

		else if(FLASH_Write(FMK.FlashDevice, &CmdIn->Data, CmdIn->Address, CmdIn->Length) != HAL_OK)
			FMK_CmdResult(Conx, FmkErrWrite);

		else
		{
			FMK_CRCCalculate(&CmdIn->Data, CmdIn->Length);
			FMK_CmdResult(Conx, FmkErrNone);
			UI_ProgressInc();
		}
	}
#endif
}

//-----------------------------------------------------------------------------
static void FMK_CmdFirmwareRead(COM_Connexion_t* Conx)
{
	FMK_CmdResult(Conx, FmkErrUnknownCommand);
}

//-----------------------------------------------------------------------------
static void FMK_CmdAssetErase(COM_Connexion_t* Conx)
{
#ifndef PROJECT_BOOTL
	FMK_CmdResult(Conx, FmkErrForbidden);
#else
	FMK_CmdAssetErase_t* CmdIn = (FMK_CmdAssetErase_t*)FMK.CmdIn;
	FMK_CmdAssetErase_t* CmdOut = (FMK_CmdAssetErase_t*)FMK.CmdOut;

	CmdOut->Command = FmkCmdAssetErase;

 	if((CmdIn->SectorStart >= FMK_SECTOR_ASSET_START) && ((CmdIn->SectorStart + CmdIn->SectorCount) < FMK_SECTOR_ASSET_COUNT))
	{
		if(FLASH_Erase(FlashDeviceExt, CmdIn->SectorStart, CmdIn->SectorCount) != HAL_OK)
			FMK_CmdResult(Conx, FmkErrErase);
		else
		{
			FMK_CmdResult(Conx, FmkErrNone);
			UI_ProgressInc();
		}
	}
	else
		FMK_CmdResult(Conx, FmkErrSector);
#endif
}

//-----------------------------------------------------------------------------
static void FMK_CmdAssetWrite(COM_Connexion_t* Conx)
{
#ifdef PROJECT_APP
	FMK_CmdResult(Conx, FmkErrForbidden);
#else
	FMK_CmdAssetWrite_t* CmdIn = (FMK_CmdAssetWrite_t*)FMK.CmdIn;
	FMK_CmdAssetWrite_t* CmdOut = (FMK_CmdAssetWrite_t*)FMK.CmdOut;

	CmdOut->Command = FmkCmdAssetWrite;

	if(!FMK_ValidateFlashAddressAsset(CmdIn->Address, CmdIn->Length))
		FMK_CmdResult(Conx, FmkErrAddress);

	else
	{
		if(CmdIn->Length != FMK.FlashDataSize)
			FMK_CmdResult(Conx, FmkErrWrite);

		else if(FLASH_Write(FlashDeviceExt, &CmdIn->Data, CmdIn->Address, CmdIn->Length) != HAL_OK)
			FMK_CmdResult(Conx, FmkErrWrite);

		else
		{
			FMK_CRCCalculate(&CmdIn->Data, CmdIn->Length);
			FMK_CmdResult(Conx, FmkErrNone);
			UI_ProgressInc();
		}
	}
#endif
}

//-----------------------------------------------------------------------------
static void FMK_CmdAssetRead(COM_Connexion_t* Conx)
{
#ifdef PROJECT_APP
	FMK_CmdResult(Conx, FmkErrForbidden);
#else
	FMK_CmdResult(Conx, FmkErrUnknownCommand);
#endif
}

//-----------------------------------------------------------------------------
static void FMK_CmdDataWrite(COM_Connexion_t* Conx)
{
#ifdef PROJECT_APP
	FMK_CmdResult(Conx, FmkErrForbidden);
#else
	FMK_CmdDataWrite_t* CmdIn = (FMK_CmdDataWrite_t*)FMK.CmdIn;
	FMK_CmdDataWrite_t* CmdOut = (FMK_CmdDataWrite_t*)FMK.CmdOut;

	CmdOut->Command = FmkCmdDataWrite;

	if(!FMK_ValidateE2Address(CmdIn->Address, CmdIn->Length))
		FMK_CmdResult(Conx, FmkErrAddress);

	else
	{
		if(E2_Write(&CmdIn->Data, CmdIn->Address - (uint32_t)&FMK_DATA_START, CmdIn->Length) == 0)
			FMK_CmdResult(Conx, FmkErrWrite);
		else
		{
			FMK_CRCCalculate(&CmdIn->Data, CmdIn->Length);
			FMK_CmdResult(Conx, FmkErrNone);
			UI_ProgressInc();
		}
	}
#endif
}

//-----------------------------------------------------------------------------
static void FMK_CmdDataRead(COM_Connexion_t* Conx)
{
	FMK_CmdResult(Conx, FmkErrUnknownCommand);
}

//-----------------------------------------------------------------------------
static void FMK_CmdResult(COM_Connexion_t* Conx, uint8_t Result)
{
	FMK_Cmd_t* CmdIn = (FMK_Cmd_t*)FMK.CmdIn;
	FMK_CmdResult_t* CmdOut = (FMK_CmdResult_t*)FMK.CmdOut;

	Conx->PacketOut.Length = 1;
	CmdOut->Command = CmdIn->Command;
	if(Result != FmkErrNone)
	{
		CmdOut->Command |= FMK_COMMAND_ERROR_SIGNAL;
		CmdOut->Result = Result;
		Conx->PacketOut.Length = sizeof(FMK_CmdResult_t);
	}
	FMK_Tx(Conx);
}

//-----------------------------------------------------------------------------
#ifdef PROJECT_BOOTL
static bool_t FMK_ValidateAppBootU(void)
{
	PRD_Banner_t Header = PRD_BOOTUPDATER_HEADER;
	PRD_Banner_t Footer = PRD_BOOTUPDATER_FOOTER;

	//Validate that header/footer banners match shared flash banners
	if(FMK_ValidateBanner(FMK_SharedFlash->Header, (uint32_t)&FMK_ADDR_APP_HEADER) && FMK_ValidateBanner(FMK_SharedFlash->Footer, (uint32_t)&FMK_ADDR_APP_FOOTER))
		return TRUE;
	//Validate that header/footer is for a bootupdater
	if(FMK_ValidateBanner(Header, (uint32_t)&FMK_ADDR_BOOTU_HEADER) && FMK_ValidateBanner(Footer, (uint32_t)&FMK_ADDR_BOOTU_FOOTER))
		return TRUE;
	return FALSE;
}
#else
static bool_t FMK_ValidateBootL(void)
{
	PRD_Banner_t Header = PRD_BOOTLOADER_HEADER;
	PRD_Banner_t Footer = PRD_BOOTLOADER_FOOTER;

	//Validate that header/footer is for a bootloader
	if(FMK_ValidateBanner(Header, (uint32_t)&FMK_ADDR_BOOTL_HEADER) && FMK_ValidateBanner(Footer, (uint32_t)&FMK_ADDR_BOOTL_FOOTER))
		return TRUE;
	return FALSE;
}
#endif

//-----------------------------------------------------------------------------
static void FMK_Enter(COM_Connexion_t* Conx, uint32_t Address)
{
	FMK_SetBootAddress(Address);
	FMK_SharedRam->Entry    = FMK_ENTRY_FROM_CODE;
	FMK_SharedRam->Media    = Conx->Media;
	FMK_SharedRam->Protocol = Conx->Protocol;
	UI_ScreenSwitchTo(UiScrIdReset);   //Will clear screen then reset unit
}

//-----------------------------------------------------------------------------
static bool_t FMK_ValidateBanner(const PRD_Banner_t Banner, uint32_t FlashAddress)
{
	uint8_t* BannerFlashAddress = (uint8_t*)FlashAddress;

	for(int i = 0; i < PRD_SIZE_BANNER; i++)
	{
		if(Banner[i] != BannerFlashAddress[i])
			return FALSE;
	}
	return TRUE;
}

//-----------------------------------------------------------------------------
#ifndef PROJECT_APP
static bool_t FMK_ValidateFlashAddressFirmware(uint32_t Address, uint16_t Length)
{
	uint32_t FlashStartAddress;
	uint32_t FlashEndAddress;
	uint32_t FlashSumAddress;

	//Validate internal portion
	FlashStartAddress = (uint32_t)&FMK_INT_START;
	FlashEndAddress   = (uint32_t)&FMK_INT_END;
	FlashSumAddress   =  Address + Length - 1;
	if((Address >= FlashStartAddress) && (Address <= FlashEndAddress) && (FlashSumAddress <= FlashEndAddress))
	{
		FMK.FlashDevice = FlashDeviceCpu;
		return TRUE;
	}

#ifdef PROJECT_BOOTL
	//Validate external portion
	FlashStartAddress = (uint32_t)&FMK_EXT_START;
	FlashEndAddress   = (uint32_t)&FMK_EXT_END;
	FlashSumAddress   =  Address + Length - 1;
	if((Address >= FlashStartAddress) && (Address <= FlashEndAddress) && (FlashSumAddress <= FlashEndAddress))
	{
		FMK.FlashDevice = FlashDeviceExt;
		return TRUE;
	}
#endif

	return FALSE;
}

static bool_t FMK_ValidateFlashAddressAsset(uint32_t Address, uint16_t Length)
{
	uint32_t FlashStartAddress;
	uint32_t FlashEndAddress;
	uint32_t FlashSumAddress;

	FlashStartAddress = (uint32_t)&FMK_ADDR_APP_ASSET_START;
	FlashEndAddress   = (uint32_t)&FMK_ADDR_APP_ASSET_END;
	FlashSumAddress   =  Address + Length - 1;
	if((Address >= FlashStartAddress) && (Address <= FlashEndAddress) && (FlashSumAddress <= FlashEndAddress))
		return TRUE;

	return FALSE;
}

static bool_t FMK_ValidateE2Address(uint32_t Address, uint16_t Length)
{
	uint32_t FlashStartAddress;
	uint32_t FlashEndAddress;
	uint32_t FlashSumAddress;

	FlashStartAddress = (uint32_t)&FMK_DATA_START;
	FlashEndAddress   = (uint32_t)&FMK_DATA_END;
	FlashSumAddress   =  Address + Length - 1;
	if((Address >= FlashStartAddress) && (Address <= FlashEndAddress) && (FlashSumAddress <= FlashEndAddress))
		return TRUE;

	return FALSE;
}
#endif

//-----------------------------------------------------------------------------
#if defined(PROJECT_BOOTL) || defined(PROJECT_BOOTU)
static void FMK_CRCClear(void)
{
	FMK.CalculatedCRC = 0xFFFF;
}

//-----------------------------------------------------------------------------
//crc16 CCITT
static void FMK_CRCCalculate(uint8_t* Data, uint16_t Length)
{
	uint8_t x;

	while(Length--)
	{
		x = FMK.CalculatedCRC >> 8 ^ *Data++;
		x ^= (x >> 4);
		FMK.CalculatedCRC = (FMK.CalculatedCRC << 8) ^ ((uint16_t)(x << 12)) ^ ((uint16_t)(x << 5)) ^ ((uint16_t)x);
	}
}

//-----------------------------------------------------------------------------
static uint16_t FMK_CRCGet(void)
{
	return FMK.CalculatedCRC;
}
#endif
