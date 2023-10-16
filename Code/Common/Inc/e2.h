
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
//         File : e2.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//------------------------------------------------------------------------------
//  Description : Serial EEPROM header file
//==============================================================================
#ifndef E2_H
#define E2_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "main.h"
#include "basic.h"


//=============================================================================
//  C O N F I G U R A T I O N
//-----------------------------------------------------------------------------
#define E2_I2C                hi2c2   //Actual peripheral instance handler
#define E2_TIMEOUT            500     //500 msec
#define E2_I2C_ADDRESS        0xA0    //Physical address
#define E2_I2C_ADDRESS_MASK   0x2U    //Physical address MSB mask
#define E2_SIZE               512     //512 bytes
#define E2_PAGE_SIZE          16      //16 bytes
#define E2_BUSY_CHECK         100     //Check 100 times max


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
extern uint16_t E2_Read  (void* pData, uint16_t Address, uint16_t Count);
extern uint16_t E2_Write (void* pData, uint16_t Address, uint16_t Count);


#endif   //E2_H
