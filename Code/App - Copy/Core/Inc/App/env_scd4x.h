
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
//         File : envSCD4x.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Environmental elements (temperature/humidity)
//                SCD4x device header file
//=============================================================================
#ifndef ENV_SCD4x_H
#define ENV_SCD4x_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "env.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define ENV_SCD4x_I2C_ADDRESS   (0x62 << 1)   //Device physical address


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//These are not to be called directly.
extern void ENV_SCD4x_Read   (ENV_Readings_t* Readings);
extern void ENV_SCD4x_Reset  (ENV_Readings_t* Readings);
extern void ENV_SCD4x_Format (ENV_Readings_t* Readings);


#endif   //ENV_SCD4x_H
