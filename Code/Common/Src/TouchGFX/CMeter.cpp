
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
//         File : CMeter.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Meter base class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <CMeter.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMeter::CMeter()
{
	add(background);
	background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeter::setBackgroundColor(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue)
{
	background.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
}

//-----------------------------------------------------------------------------
void CMeter::resizeBackground()
{
	background.setWidthHeight(*this);
}

}   //namespace touchgfx
