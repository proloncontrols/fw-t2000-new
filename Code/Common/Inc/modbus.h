
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
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
	MbFctRdHldRegs = 3,
	MbFctRdInpRegs = 4,
	MbFctWrSglReg  = 6,
	MbFctWrMplRegs = 16,
	MbFctMEIT      = 43
} MB_Function_t;

typedef enum {
	MbSubFctMEITUpgrade = 1    //Firmware upgrade
} MB_SubFunction_t;


//=============================================================================
//  E R R O R S
//-----------------------------------------------------------------------------
typedef enum {
	MbErrIllegalFunction = 1,
	MbErrIllegalDataAddress,
	MbErrIllegalDataValue,
	MbErrSlaveDeviceFailure
} MB_Error_t;


//=============================================================================
//  D A T A  /  R E G I S T E R   T Y P E S
//-----------------------------------------------------------------------------
typedef enum {
	MbReg8 = 0,
	MbReg16,
	MbRegLoc,
	MbRegTemp,
	MBRegPercent
	//TODO: Add MbRegCommand type
} MB_Reg_t;

typedef struct {
	uint16_t Number;
	MB_Reg_t Type;
	uint16_t Multiplier;
	void*    Ram;
} MB_Register_t;


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
#pragma pack(1)

typedef struct {
	uint8_t Address;     //Module address
	uint8_t Function;    //ModBus function to perform
} MB_PktHeader_t;

//--------------------------------
typedef struct {         //Request to read from registers
	uint16_t Address;    //Starting address of registers to read
	uint16_t Quantity;   //Number of registers to read
} MB_FctReadReq_t;
//-------
typedef struct {         //Answer to registers reading request
	uint8_t ByteCount;   //Total number of bytes that make up registers read (quantity * 2)
	//...                //<-- Data read is inserted here by the reading process
} MB_FctReadAns_t;

//--------------------------------
typedef struct {         //Request to write to registers
	uint16_t Address;    //Starting address of registers to write
	uint16_t Param;      //Function dependant parameter: WriteSingleRegister->data to write, WriteMultipleRegisters->number of registers to write
	//...                //<-- With WriteMultipleRegisters function, data to write is retrieved here by the writing process
} MB_FctWriteReq_t;
//-------
typedef struct {         //Answer to registers writing request
	uint16_t Address;    //Requested starting address
	uint16_t Param;      //Function dependant parameter: WriteSingleRegister->requested data to write, WriteMultipleRegisters->number of registers written
} MB_FctWriteAns_t;

//--------------------------------
typedef struct {
	uint8_t SubFunction;
	uint8_t Data;        //<-- Used as pointer to data in packet
} MB_FctMEIT_t;

typedef struct {
	uint8_t Code;
} MB_FctError_t;

typedef union {
	MB_FctMEIT_t  FctMEIT;
	MB_FctError_t Error;
} MB_Fct_t;

typedef struct {
	MB_PktHeader_t Header;
	MB_Fct_t       Function;
} MB_Packet_t;

#pragma pack()


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern void MB_Init    (void);
extern void MB_Process (COM_Connexion_t* Conx);


#endif   //MB_H
