
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
//         File : framework.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : System base architecture header file
//=============================================================================
#ifndef FMK_H
#define FMK_H

#ifdef FMK_GLOBAL
#define FMK_EXTERN
#else
#define FMK_EXTERN   extern
#endif

#ifdef __cplusplus
extern "C" {
#endif


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "main.h"
#include "basic.h"
#include "products.h"
#include "com.h"
#include "cfg.h"
#include "data.h"


//=============================================================================
//  L I N K E R   S C R I P T   E X P O R T E D   (memory mapping)
//-----------------------------------------------------------------------------
extern uint32_t FMK_DATA_START;
extern uint32_t FMK_DATA_END;

extern uint32_t FMK_ADDR_RAM_SHARED;

extern uint32_t FMK_ADDR_BOOTL_START;
extern uint32_t FMK_ADDR_BOOTL_VECTORS;
extern uint32_t FMK_ADDR_BOOTL_SHARED;
extern uint32_t FMK_ADDR_BOOTL_HEADER;
extern uint32_t FMK_ADDR_BOOTL_ENTRY;
extern uint32_t FMK_ADDR_BOOTL_FOOTER;
extern uint32_t FMK_ADDR_BOOTL_END;

extern uint32_t FMK_ADDR_BOOTU_START;
extern uint32_t FMK_ADDR_BOOTU_VECTORS;
extern uint32_t FMK_ADDR_BOOTU_SHARED;
extern uint32_t FMK_ADDR_BOOTU_HEADER;
extern uint32_t FMK_ADDR_BOOTU_ENTRY;
extern uint32_t FMK_ADDR_BOOTU_FOOTER;
extern uint32_t FMK_ADDR_BOOTU_END;

extern uint32_t FMK_ADDR_EXT_FLASH_START;

extern uint32_t FMK_ADDR_APP_INT_START;
extern uint32_t FMK_ADDR_APP_VECTORS;
extern uint32_t FMK_ADDR_APP_SHARED;
extern uint32_t FMK_ADDR_APP_HEADER;
extern uint32_t FMK_ADDR_APP_ENTRY;
extern uint32_t FMK_ADDR_APP_INT_END;
extern uint32_t FMK_ADDR_APP_ASSET_START;
extern uint32_t FMK_ADDR_APP_ASSET_END;
extern uint32_t FMK_ADDR_APP_EXT_START;
extern uint32_t FMK_ADDR_APP_FOOTER;
extern uint32_t FMK_ADDR_APP_EXT_END;

extern uint32_t FMK_SHARED_FLASH_SIZE;


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define FMK_ENTRY_FROM_CODE        0x0000C0DE   //Value used by an application to detect the entry mode (in this case, from "CODE", another application. Not a power cycle)
#define FMK_HEADER                 0xC4D2E0F8   //Packet meant for framework (F8 is the first ModBus protocol reserved address value)
#define FMK_COMMAND_SET            0x01         //Base value for framework commands
#define FMK_COMMAND_ERROR_SIGNAL   0x80         //Framework result error signal


//=============================================================================
//  S H A R I N G
//-----------------------------------------------------------------------------
//All fields in this structure are of type uint32_t even if the values stored
//in some of them might not need to be that wide. This is to make sure they are 32bit aligned in RAM
//so that acces to them between contexts is guaranteed to match.
typedef struct {
	uint32_t Entry;      //Application entry source. From cold start (power cycle) or from warm start (software reset)
	uint32_t Media;      //Media used in previous application when performing a warm start
	uint32_t Protocol;   //Protocol used in previous application when performing a warm start
} FMK_SharedRam_t;

#pragma pack(1)

typedef struct {
	//Product
	uint8_t FamilyID;
	uint8_t ProductID;
	PRD_Banner_t Header;
	PRD_Banner_t Footer;
	//Hardware
	uint16_t HardwareVersion;   //Ex: 0x0001 = version 0.0.0.1
	//Bootloader
	uint16_t BootVersion;       //Ex: 0x5678 = version 5.6.7.8
} FMK_SharedFlash_t;

#pragma pack()


//=============================================================================
//  E N U M S
//-----------------------------------------------------------------------------
typedef enum {
	FmkFirmApp = 0,
	FmkFirmBootL,
	FmkFirmBootU,
	//Add firmwares here
	FmkFirmCount
} FMK_Firmware_t;

typedef enum {
	FmkCmdIdentify = FMK_COMMAND_SET,
	FmkCmdEnter,
	FmkCmdLeave,
	FmkCmdFirmwareErase,
	FmkCmdFirmwareWrite,
	FmkCmdFirmwareRead,
	FmkCmdAssetErase,
	FmkCmdAssetWrite,
	FmkCmdAssetRead,
	FmkCmdDataWrite,
	FmkCmdDataRead,
	//Add commands here
	FmkCmdCount,
} FMK_Command_t;

typedef enum {
	FmkErrNone = 0,
	FmkErrUnknownCommand,
	FmkErrInvalidFirmware,
	FmkErrForbidden,
	FmkErrBanners,
	FmkErrAddress,
	FmkErrSector,
	FmkErrErase,
	FmkErrWrite,
	FmkErrRead,
	FmkErrFirmwareCRC,
	FmkErrAssetsCRC,
	FmkErrAssetsVersion,
	//Add errors here
	FmkErrCount,
} FMK_Error_t;


//=============================================================================
//  C O M M U N I C A T I O N
//-----------------------------------------------------------------------------
#pragma pack(1)

typedef union {
	struct {
		uint8_t Command;
	} Query;
	struct {
		uint8_t Command;
		uint8_t Firmware;
		uint8_t FamilyID;
		uint8_t ProductID;
		uint16_t HardwareVersion;
		uint16_t BootVersion;
		uint16_t AppVersion;
	} Answer;
} FMK_CmdIdentify_t;

typedef struct {
	uint8_t Command;
} FMK_CmdEnter_t;

typedef struct {
	uint8_t Command;
	uint16_t CalculatedCRC;
} FMK_CmdLeave_t;

typedef struct {
	uint8_t Command;
	uint8_t Firmware;
	uint32_t ProgressSteps;
} FMK_CmdFirmwareErase_t;

typedef struct {
	uint8_t Command;
	uint8_t Firmware;
	uint32_t Address;
	uint16_t Length;
	uint8_t Data;   //<-- Used as pointer to data in packet
} FMK_CmdFirmwareWrite_t;

typedef struct {
	uint8_t Command;
	uint16_t SectorStart;
	uint16_t SectorCount;
} FMK_CmdAssetErase_t;

typedef struct {
	uint8_t Command;
	uint32_t Address;
	uint16_t Length;
	uint8_t Data;   //<-- Used as pointer to data in packet
} FMK_CmdAssetWrite_t;



typedef struct {
	uint8_t Command;
	uint32_t Address;
	uint16_t Length;
	uint8_t Data;   //<-- Used as pointer to data in packet
} FMK_CmdDataWrite_t;

typedef struct {
	uint8_t Command;
	uint8_t Result;
} FMK_CmdResult_t;

typedef union {
	uint8_t Command;
	FMK_CmdIdentify_t CmdIdentify;
	FMK_CmdEnter_t CmdEnter;
	FMK_CmdLeave_t CmdLeave;
	FMK_CmdFirmwareErase_t CmdFirmwareErase;
	FMK_CmdFirmwareWrite_t CmdFirmwareWrite;
	FMK_CmdAssetErase_t CmdAssetErase;
	FMK_CmdAssetWrite_t CmdAssetWrite;
	FMK_CmdDataWrite_t CmdDataWrite;
	FMK_CmdResult_t CmdResult;
} FMK_Cmd_t;

typedef struct {
	uint32_t Header;
} FMK_PktHeader_t;

typedef struct {
	FMK_PktHeader_t Header;
	FMK_Cmd_t Command;
} FMK_Packet_t;

#pragma pack()

typedef enum {
	FmkSysEvtRdy,     //System is ready
	FmkSysEvtRst,     //Reset system
	FmkSysEvtUpdCfg   //Update EEPROM configuration
} FMK_SystemEvent_t;


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
FMK_EXTERN osEventFlagsId_t FMK_Flags;
FMK_EXTERN COM_Connexion_t* FMK_Conx;


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void FMK_Init            (void);
extern void FMK_Entry           (void);
extern void FMK_Main            (void);
extern void FMK_SetBootAddress  (uint32_t Address);
extern void FMK_PostFlag        (uint32_t Flag);
extern void FMK_PostSystemEvent (FMK_SystemEvent_t Event);

extern void FMK_E2Acquire       (void);
extern void FMK_E2Release       (void);


#ifdef __cplusplus
}
#endif

#endif   //FMK_H
