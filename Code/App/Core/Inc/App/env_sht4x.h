
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
//         File : envSHT4x.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Environmental elements (temperature/humidity)
//                SHT4x device header file
//=============================================================================
#ifndef ENV_SHT4x_H
#define ENV_SHT4x_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "env.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define ENV_SHT4x_I2C_ADDRESS   (0x44 << 1)   //Device physical address


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//These are not to be called directly.
extern void ENV_SHT4x_Read   (ENV_Readings_t* Readings);
extern void ENV_SHT4x_Reset  (ENV_Readings_t* Readings);
extern void ENV_SHT4x_Format (ENV_Readings_t* Readings);


#endif   //ENV_SHT4x_H
