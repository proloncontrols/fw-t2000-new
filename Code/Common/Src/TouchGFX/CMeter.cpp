
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
//  Description : TouchGFX widget class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <CMeter.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CMeter::CMeter(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& text)
{
    txtSign.setXY(0, 0);
    txtSign.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
    txtSign.setLinespacing(0);
    txtSignBuffer[0] = 0;
    txtSign.setWildcard(txtSignBuffer);
    txtSign.resizeToCurrentText();
    txtSign.setTypedText(text);
    add(txtSign);

    txtIntegralHundreds.setXY(0, 0);
    txtIntegralHundreds.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
    txtIntegralHundreds.setLinespacing(0);
    txtIntegralHundredsBuffer[0] = 0;
    txtIntegralHundreds.setWildcard(txtIntegralHundredsBuffer);
    txtIntegralHundreds.resizeToCurrentText();
    txtIntegralHundreds.setTypedText(text);
    add(txtIntegralHundreds);

    txtIntegralTenths.setXY(0, 0);
    txtIntegralTenths.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
    txtIntegralTenths.setLinespacing(0);
    txtIntegralTenthsBuffer[0] = 0;
    txtIntegralTenths.setWildcard(txtIntegralTenthsBuffer);
    txtIntegralTenths.resizeToCurrentText();
    txtIntegralTenths.setTypedText(text);
    add(txtIntegralTenths);

    txtIntegralUnits.setXY(0, 0);
    txtIntegralUnits.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
    txtIntegralUnits.setLinespacing(0);
    txtIntegralUnitsBuffer[0] = 0;
    txtIntegralUnits.setWildcard(txtIntegralUnitsBuffer);
    txtIntegralUnits.resizeToCurrentText();
    txtIntegralUnits.setTypedText(text);
    add(txtIntegralUnits);

    txtFractional.setXY(0, 0);
    txtFractional.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
    txtFractional.setLinespacing(0);
    txtFractionalBuffer[0] = 0;
    txtFractional.setWildcard(txtFractionalBuffer);
    txtFractional.resizeToCurrentText();
    txtFractional.setTypedText(text);
    add(txtFractional);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeter::display(double value)
{
	double fractional;
	double integral = modf(value, &fractional);

	if(fractional > 10.0)
		fractional /= 10;
}

}   //namespace touchgfx



















































