
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
//         File : CMeterInt.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Interior temperature meter class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <CMeterInt.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMeterInt::CMeterInt()
{
	integer = new CString(intString, intPrecision, touchgfx::TypedText(intText), colorR, colorG, colorB);
	integer->setCharSpacingRatio(intCharSpacingRation);
	add(*integer);

	dot.setColor(touchgfx::Color::getColorFromRGB(colorR, colorG, colorB));
	dot.setTypedText(touchgfx::TypedText(dotText));
	add(dot);

	decimal = new CString(decString, decPrecision, touchgfx::TypedText(decText), colorR, colorG, colorB);
	decimal->setCharSpacingRatio(decCharSpacingRation);
	add(*decimal);

	unit.setColor(touchgfx::Color::getColorFromRGB(colorR, colorG, colorB));
	add(unit);

	Container::setHeight(MAX(touchgfx::TypedText(intText).getFont()->getFontHeight(), touchgfx::TypedText(decText).getFont()->getFontHeight()));
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeterInt::display(double value, bool celsius)
{
	double intDoubleValue;
	double decDoubleValue = modf(value, &intDoubleValue);

	int intValue = (int)intDoubleValue;
	int decValue = (int)(decDoubleValue * pow(10.0, (double)decPrecision));

	char strInteger[intPrecision + 1];
	char strDecimal[decPrecision + 1];

	sprintf(strInteger, "%d", intValue);
	sprintf(strDecimal, "%d", decValue);

	integer->setText(strInteger);
	decimal->setText(strDecimal);

	if(celsius)
		unit.setTypedText(touchgfx::TypedText(unitCText));
	else
		unit.setTypedText(touchgfx::TypedText(unitFText));
	unit.setXY(integer->getWidth(), Container::getHeight() - integer->getMaxGlyphHeight() - (unit.getTypedText().getFont()->getFontHeight() - unit.getTypedText().getFont()->getGlyph(unit.getTypedText().getText()[0])->top()));

	Container::setWidth(integer->getWidth() + MAX(unit.getWidth(), dot.getWidth() + decimal->getWidth()));
	integer->setXY(0, Container::getHeight() - integer->getHeight());
	dot.setXY(integer->getWidth(), Container::getHeight() - dot.getHeight());
	decimal->setXY(integer->getWidth() + dot.getWidth(), Container::getHeight() - decimal->getHeight());

	resizeBackground();
}

}   //namespace touchgfx
