
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
//         File : CScreen.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Screen rotation parameters implementation file
//=============================================================================
#ifndef CSCREEN_HPP
#define CSCREEN_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/hal/Types.hpp>


namespace touchgfx
{

//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define CLIENT_ORIGIN_LANDSCAPE_X   24
#define CLIENT_ORIGIN_LANDSCAPE_Y   0
#define CLIENT_ORIGIN_PORTRAIT_X    0
#define CLIENT_ORIGIN_PORTRAIT_Y    24
#define CLIENT_WIDTH                672
#define CLIENT_HEIGHT               672
////
//// Thermostat orientation (portrait)
////
////    Screen orientation (landscape)
////    -------------------------------------   ---
////    |    |                         |    |    |
////    |    |                         |    |    |
////    |    |                         |    |    |
////    |    |                         |    |    |
////    |    |                         |    |    |
////    | NU |     Client (square)     | NU |   672
////    |    |                         |    |    |
////    |    |                         |    |    |
////    |    |                         |    |    |
////    |    |                         |    |    |
////    |    |                         |    |    |
////    -------------------------------------   ---
////
////    |-24-|---------- 672 ----------|-24-|
////    |--------------- 720 ---------------|


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef enum {
	SCR_LANDSCAPE,
	SCR_PORTRAIT
} ScrDirection;


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
void setScrOriginX(int16_t x);
void setScrOriginY(int16_t y);
void setScrDirection(ScrDirection d);
int16_t cnvScrX(int16_t);
int16_t cnvScrY(int16_t);
ScrDirection getScrDir();

}   //namespace touchgfx


#endif   //CSCREEN_HPP