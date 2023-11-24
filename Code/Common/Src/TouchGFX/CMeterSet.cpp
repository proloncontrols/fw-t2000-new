
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
//         File : CMeterSet.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Setpoint temperature meter class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <CMeterSet.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMeterSet::CMeterSet()
{
	addInteger(intPrecision, intCharSpacingRation, touchgfx::TypedText(intText), colorR, colorG, colorB);
//	integer = new CMeterValue(intPrecision, intCharSpacingRation, touchgfx::TypedText(intText), colorR, colorG, colorB);
//	add(*integer);

	addDecimal(decPrecision, decCharSpacingRation, touchgfx::TypedText(decText), colorR, colorG, colorB);
//	decimal = new CMeterValue(decPrecision, decCharSpacingRation, touchgfx::TypedText(decText), colorR, colorG, colorB);
//	add(*decimal);

	dot = new TextArea;
	dot->setColor(touchgfx::Color::getColorFromRGB(colorR, colorG, colorB));
	dot->setTypedText(touchgfx::TypedText(dotText));
	add(*dot);

	unit = new TextArea;
	unit->setColor(touchgfx::Color::getColorFromRGB(colorR, colorG, colorB));
	add(*unit);

	Container::setHeight(MAX(touchgfx::TypedText(intText).getFont()->getFontHeight(), touchgfx::TypedText(decText).getFont()->getFontHeight()));
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//void CMeterSet::display(double value, bool celsius)
//{
//}

}   //namespace touchgfx
