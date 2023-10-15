
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
//         File : data.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Product persistent data header file
//=============================================================================
#ifndef DATA_H
#define DATA_H


#ifdef __cplusplus
extern "C" {
#endif


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "main.h"
#include "basic.h"


//=============================================================================
//  V E R S I O N
//-----------------------------------------------------------------------------
#define DATA_VERSION   0x0001   //0.0.0.1


//=============================================================================
//  D E F A U L T S
//-----------------------------------------------------------------------------
#define DATA_DEF_BAUDRATE    3     //0=9600 1=19200 2=38400 3=57600
#define DATA_DEF_PARITY      1     //0=none 1=odd 2=even
#define DATA_DEF_STOPBITS    2     //0=1 1=1.5 2=2
#define DATA_DEF_ORIENTATION 0     //0=portrait 1=landscape
#define DATA_DEF_TIMEOUT     0     //In seconds (0=disabled)
#define DATA_DEF_TEMP_UNIT   0     //0=celsius 1=fahrenheit
#define DATA_DEF_ADDRESS     123   //ModBus device address TODO: Change to correct value


//=============================================================================
//  D A T A   B U F F E R   S T R U C T U R E
//-----------------------------------------------------------------------------
#pragma pack(1)

typedef struct {
	uint8_t ModBusID;
	uint8_t TempUnit;
	uint8_t ScrOrientation;
	uint16_t ScrTimeout;
} DATA_Config_t;

typedef struct {
	uint8_t ComBaud;
	uint8_t ComStop;
	uint8_t ComParity;
} DATA_ModBus_t;

typedef struct {
	uint16_t Version;
	DATA_Config_t Config;
	DATA_ModBus_t ModBus;
} DATA_t;

#pragma pack()


//=============================================================================
//  A D D R E S S E S
//-----------------------------------------------------------------------------
#define DATA_ADDR_OFFSET           0
#define DATA_ADDR_OFFSET_CONFIG    sizeof(uint16_t)
#define DATA_ADDR_OFFSET_MODBUS   (DATA_ADDR_OFFSET_CONFIG + sizeof(DATA_Config_t))


#ifdef __cplusplus
}
#endif


#endif   //CFG_H































