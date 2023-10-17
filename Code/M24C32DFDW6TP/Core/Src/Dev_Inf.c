
//==============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2023
//------------------------------------------------------------------------------
//         File : Dev_Info.c
//         Date : -----------
//       Author : Jean-Francois Barriere
//------------------------------------------------------------------------------
//  Description : STM32CubeProgrammer external loader driver device information implementation file
//              : For serial EEPROM part number M24C32DFDW6TP
//==============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "Dev_Inf.h"


//=============================================================================
//  D E V I C E   D E F I N I T I O N
//-----------------------------------------------------------------------------
struct StorageInfo __attribute__((section(".Dev_info"))) StorageInfo =
{
    "M24C32DFDW6TP_T2000",   //Device name
	I2C_EEPROM,              //Device type
    0x07000000,              //Device start address
    0x00001000,              //Device size 4KB
    0x20,                    //Programming page size 32B
    0xFF,                    //Initial content of erased memory
    {
		{ 0x00000001, 0x00001000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000 }
    }
};
