
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
//         File : CMeterTemp.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Interior/Setpoint temperature meter base class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <Meter/CMeterTemp.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeterTemp::display(double value, bool celsius)
{
	double intDoubleValue;
	double decDoubleValue = modf(value, &intDoubleValue);

	int16_t intValue = (int16_t)intDoubleValue;
	int16_t decValue = (int16_t)abs((decDoubleValue * pow(10.0, (double)decimal->getPrecision())));

	integer->display(intValue);
	decimal->display(decValue);

	integer->setXY(0, 0);
	dot->setXY(integer->getWidth(), Container::getHeight() - dot->getHeight());
	decimal->setXY(integer->getWidth() + dot->getWidth(),  Container::getHeight() - decimal->getHeight());

	if(celsius)
		unit->setTypedText(touchgfx::TypedText(unitTempC));
	else
		unit->setTypedText(touchgfx::TypedText(unitTempF));
	unit->setXY(integer->getWidth(), Container::getHeight() - integer->getMaxGlyphHeight() - (unit->getTypedText().getFont()->getFontHeight() - unit->getTypedText().getFont()->getGlyph(unit->getTypedText().getText()[0])->top()));

	Container::setWidth(integer->getWidth() + MAX(unit->getWidth(), dot->getWidth() + decimal->getWidth()));
	resizeBackground();
}

}   //namespace touchgfx