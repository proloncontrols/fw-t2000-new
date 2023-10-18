
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
	MbFctRdCoils     = 1,
	MbFctRdInRegs    = 4,
	MbFctRdHldRegs   = 3,
	MbFctRdDscIn     = 2,
	MbFctWrSglCoil   = 5,
	MbFctWrMplCoils  = 15,
	MbFctWrSglReg    = 6,
	MbFctWrMplRegs   = 16,
	MbFctMEIT        = 43
} MB_Function_t;

typedef enum {
	MbSubFctMEITUpgrade = 1,    //Firmware upgrade
} MB_SubFunction_t;


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

//--------------------------------
typedef struct {
	uint8_t SubFunction;
	uint8_t Data;       //<-- Used as pointer to data in packet
} MB_FctMEIT_t;

typedef struct {
	uint8_t Code;
} MB_FctError_t;

typedef union {
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
