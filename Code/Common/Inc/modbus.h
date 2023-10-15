
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
//         File : modbus.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : ModBus protocol header file
//=============================================================================
#ifndef MB_H
#define MB_H

#ifdef MB_GLOBAL
#define MB_EXTERN
#else
#define MB_EXTERN   extern
#endif


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "basic.h"
#include "com.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define MB_ADDR_BROADCAST   0x00


//=============================================================================
//  F U N C T I O N S
//-----------------------------------------------------------------------------
typedef enum {
	MbFctRdDscIn     = 2,
	MbFctRdCoils     = 1,
	MbFctWrSglCoil   = 5,
	MbFctWrMplCoils  = 15,
	MbFctRdInRegs    = 4,
	MbFctRdHldRegs   = 3,
	MbFctWrSglReg    = 6,
	MbFctWrMplRegs   = 16,
	MbFctRdWrMplRegs = 23,
	MbFctMskWrReg    = 22,
	MbFctRdFifoQueue = 24,
	MbFctMEIT        = 43
} MB_Function_t;

typedef enum {
	MbSubFctMEITUpgrade = 1,    //Firmware upgrade
} MB_SubFunction_t;


//=============================================================================
//  H O L D I N G   R E G I S T E R S
//-----------------------------------------------------------------------------
//typedef enum {
//	MbHldRegDeviceType = 1,
//	MbHldRegSoftVer,
//	MbHldRegHardVer,
//	MbHldRegBaudRate,
//	MbHldRegParity,
//	MbHldRegtopBits,
//	MbHldRegAddress,
//	MbHldRegScrOrientation,
//	MbHldRegScrTimeout,
//	MbHldRegTempUnit
//} MB_HoldingRegister_t;


//=============================================================================
//  E R R O R S
//-----------------------------------------------------------------------------
typedef enum {
	MbErrIllegalFunction    = 1,
	MbErrIllegalDataAddress = 2,
	MbErrIllegalDataValue   = 3,
	MbErrSlaveDeviceFailure = 4
} MB_Error_t;


//=============================================================================
//  C O N F I G U R A T I O N
//-----------------------------------------------------------------------------
typedef enum {
	MbHrDeviceType = 1,
	MbHrSoftVer,
	MbHrHardVer,

	MbHrModBusID,
	MbHrComBaudRate,
	MbHrComStopBits,
	MbHrComParity,
} MB_HldReg_t;

#define MB_CFG_DEF_ADDRESS           123   //ModBus device address TODO: Change to correct value

#define MB_CFG_DEF_TEMP_UNIT         0     //0=celsius 1=fahrenheit
#define MB_CFG_DEF_SCR_ORIENTATION   0     //0=portrait 1=landscape
#define MB_CFG_DEF_SCR_TIMEOUT       0     //In seconds (0=disabled)

#pragma pack(1)

typedef struct {
	uint8_t ModBusID;

	uint8_t ComBaudRate;
	uint8_t ComStopBits;
	uint8_t ComParity;

	uint8_t Location[8];

	uint8_t ScrOrientation;
	uint16_t ScrTimeout;

	uint8_t TempUnit;
} FMK_Config_t;

#pragma pack()


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
#pragma pack(1)

typedef struct {
	uint8_t Address;
	uint8_t Function;
} MB_PktHeader_t;





//--------------------------------
typedef struct {
	uint16_t Address;
	uint16_t Quantity;
} MB_FctRdCoilsReq_t;
//-------
typedef struct {
	uint8_t ByteCount;
} MB_FctRdCoilsAns_t;

//--------------------------------
typedef struct {
	uint16_t Address;
	uint16_t Quantity;
} MB_FctRdInRegsReq_t;
//-------
typedef struct {
	uint8_t ByteCount;
} MB_FctRdInRegsAns_t;

//--------------------------------
typedef struct {
	uint16_t Address;
	uint16_t Quantity;
} MB_FctRdHldRegsReq_t;
//-------
typedef struct {
	uint8_t ByteCount;
} MB_FctRdHldRegsAns_t;

//--------------------------------
typedef struct {
	uint16_t Address;
	uint16_t Quantity;
} MB_FctRdDscInsReq_t;
//-------
typedef struct {
	uint8_t ByteCount;
} MB_FctRdDscInsAns_t;

//--------------------------------
typedef struct {
	uint16_t Address;
	uint16_t Value;
} MB_FctWrSglCoilReq_t;
//-------
typedef struct {
	uint16_t Address;
	uint16_t Value;
} MB_FctWrSglCoilAns_t;

//--------------------------------
typedef struct {
	uint16_t Address;
	uint16_t Quantity;
	uint8_t ByteCount;
} MB_FctWrMplCoilsReq_t;
//-------
typedef struct {
	uint16_t Address;
	uint16_t Quantity;
} MB_FctWrMplCoilsAns_t;

//--------------------------------
typedef struct {
	uint16_t Address;
	uint16_t Value;
} MB_FctWrSglRegReq_t;
//-------
typedef struct {
	uint16_t Address;
	uint16_t Value;
} MB_FctWrSglRegAns_t;

//--------------------------------
typedef struct {
	uint16_t Address;
	uint16_t Quantity;
	uint8_t ByteCount;
} MB_FctWrMplRegsReq_t;
//-------
typedef struct {
	uint16_t Address;
	uint16_t QtyWritten;
} MB_FctWrMplRegsAns_t;





typedef struct {
	uint16_t Address;
	uint16_t Quantity;
} MB_FctReadReq_t;

typedef struct {
	uint8_t ByteCount;
} MB_FctReadAns_t;

typedef struct {
	uint16_t Address;
	uint16_t Value;
} MB_FctWriteSglReg_t;

typedef struct {
	uint16_t Address;
	uint16_t Quantity;
	uint8_t ByteCount;
} MB_FctWriteMplReg_t;



typedef struct {
	uint16_t Address;
	uint16_t Quantity;
} MB_Fct16bitReq_t;
typedef struct {
	uint8_t ByteCount;
//	uint16_t Data;      //<-- Used as pointer to data in packet
} MB_Fct16bitAns_t;

typedef struct {
	uint16_t Address;
	uint16_t Quantity;
} MB_Fct8bitReq_t;
typedef struct {
	uint8_t ByteCount;
//	uint8_t Data;       //<-- Used as pointer to data in packet
} MB_Fct8bitAns_t;

typedef struct {
	uint8_t SubFunction;
	uint8_t Data;       //<-- Used as pointer to data in packet
} MB_FctMEIT_t;

typedef struct {
	uint8_t Code;
} MB_FctError_t;

typedef union {
	MB_FctReadReq_t ReadReq;
	MB_FctReadAns_t ReadAns;
	MB_Fct16bitReq_t Fct16bitReq;
	MB_Fct16bitAns_t Fct16bitAns;
	MB_Fct8bitReq_t Fct8bitReq;
	MB_Fct8bitAns_t Fct8bitAns;
	MB_FctMEIT_t FctMEIT;
	MB_FctError_t Error;
} MB_Fct_t;

typedef struct {
	MB_PktHeader_t Header;
	MB_Fct_t Function;
} MB_Packet_t;

#pragma pack()


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void MB_Init    (void);
extern void MB_Process (COM_Connexion_t* Conx);


#endif   //MB_H























