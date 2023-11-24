
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
void CMeter::addInteger()
{
	intChars = (CChar**)malloc(sizeof(CChar*) * meterIntPrecision);
	for(uint8_t i = 0; i < meterIntPrecision; i++)
		intChars[i] = new CChar();
	integer = new CString(*intChars, meterIntPrecision, touchgfx::TypedText(meterIntText), meterColorR, meterColorG, meterColorB);
	integer->setCharSpacingRatio(meterIntCharSpacingRation);
	add(*integer);
}

//-----------------------------------------------------------------------------
void CMeter::addDecimal()
{
	decChars = (CChar**)malloc(sizeof(CChar*) * meterDecPrecision);
	for(uint8_t i = 0; i < meterDecPrecision; i++)
		decChars[i] = new CChar();
	decimal = new CString(*decChars, meterDecPrecision, touchgfx::TypedText(meterDecText), meterColorR, meterColorG, meterColorB);
	decimal->setCharSpacingRatio(meterDecCharSpacingRation);
	add(*decimal);
}

//-----------------------------------------------------------------------------
void CMeter::addDot()
{
	dot = new TextArea;
	dot->setColor(touchgfx::Color::getColorFromRGB(meterColorR, meterColorG, meterColorB));
	dot->setTypedText(touchgfx::TypedText(meterDotText));
	add(*dot);
}

//-----------------------------------------------------------------------------
void CMeter::addUnit()
{
	unit = new TextArea;
	unit->setColor(touchgfx::Color::getColorFromRGB(meterColorR, meterColorG, meterColorB));
	add(*unit);
}

//-----------------------------------------------------------------------------
void CMeter::resizeBackground()
{
	background.setWidthHeight(*this);
}

}   //namespace touchgfx
