
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
//         File : basic.h
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Basic definitions header file
//=============================================================================
#ifndef BASIC_H
#define BASIC_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "stdint.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define FALSE   0
#define TRUE    (!FALSE)


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef uint8_t bool_t;


//=============================================================================
//  M A C R O S
//-----------------------------------------------------------------------------
#define NUM2POS(x)                 (1 << x)
#define NUMBER_OF_ELEMENTS_IN(x)   (sizeof(x) / sizeof(*x))
#define REVERSE_ORDER_16(x)        ((uint16_t)(((x >> 8) & 0x00FF) + ((x << 8) & 0xFF00)))   //Reverse uint16_t type low and high order bytes


#endif   //BASIC_H
