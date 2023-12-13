
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
//  S W I T C H E S
//-----------------------------------------------------------------------------
//#define CMETER_WITH_BACKGROUND   //Uncomment to apply a background to widget (for debug purposes only)


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Meter/CMeter.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <touchgfx/Color.hpp>
#include <touchgfx/Bitmap.hpp>
#include <CDisplay.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMeter::CMeter()
{
#ifdef CMETER_WITH_BACKGROUND
	add(background);
	background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
#endif
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeter::addTo(Container& c)
{
	dsp.add(c, *this);

	if(integer)   dsp.add(*this, *integer);
	if(decimal)   dsp.add(*this, *decimal);
//	if(unit)      dsp.add(*this, *unit);
//	if(dot)       dsp.add(*this, *dot);
	if(image)     dsp.add(*this, *image);
}

//-----------------------------------------------------------------------------
void CMeter::addInteger(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
	integer = new CMeterValue(newPrecision, newSpacingRatio, touchgfx::TypedText(newTypedText), newColorR, newColorG, newColorB);
//	add(*integer);
}

//-----------------------------------------------------------------------------
void CMeter::addDecimal(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
	decimal = new CMeterValue(newPrecision, newSpacingRatio, touchgfx::TypedText(newTypedText), newColorR, newColorG, newColorB);
//	add(*decimal);
}

//-----------------------------------------------------------------------------
void CMeter::addUnit(const TypedText& newTypedTextC, const TypedText& newTypedTextF, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
//	unit = new TextArea;
//	unit = new CText(2);
//	unit->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
	unitTempC = newTypedTextC;
	unitTempF = newTypedTextF;
//	add(*unit);
}

void CMeter::addUnit(const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
//	unit = new TextArea;
//	unit = new CText(1);
//	unit->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
//	unit->setTypedText(touchgfx::TypedText(newTypedText));
//	add(*unit);
}

//-----------------------------------------------------------------------------
void CMeter::addDot(const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
//	dot = new TextArea;
//	dot = new CText(1);
//	dot->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
//	dot->setTypedText(touchgfx::TypedText(newTypedText));
//	add(*dot);
}

//-----------------------------------------------------------------------------
void CMeter::addImage(const Bitmap& bmp)
{
	image = new CImage;
	image->setBitmap(bmp);
//	add(*image);
}

//-----------------------------------------------------------------------------
void CMeter::resizeBackground()
{
#ifdef CMETER_WITH_BACKGROUND
	background.setWidthHeight(*this);
#endif
}





//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------



}   //namespace touchgfx
