
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
//         File : CScreen.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Screen rotation parameters implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CScreen.hpp>


namespace touchgfx
{

//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef struct {
	int16_t originX;
	int16_t originY;
	ScrDirection direction;
} SCR_t;


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
static SCR_t SCR;


//=============================================================================
//  F U N C T I O N S
//-----------------------------------------------------------------------------
void initializeScreen(int16_t x, int16_t y, ScrDirection d)
{
	SCR.originX = x;
	SCR.originY = y;
	SCR.direction = d;
}

//-----------------------------------------------------------------------------
int16_t cnvScrX(int16_t x)
{
	return SCR.originX + x;
}

//-----------------------------------------------------------------------------
int16_t cnvScrY(int16_t y)
{
	return SCR.originY + y;
}

//-----------------------------------------------------------------------------
ScrDirection getScrDir()
{
	return SCR.direction;
}

}   //namespace touchgfx
