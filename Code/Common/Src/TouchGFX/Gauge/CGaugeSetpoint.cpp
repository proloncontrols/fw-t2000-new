
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
//         File : CGaugeSetpoint.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Interior temperature gauge display class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>
#include <Gauge/CGaugeSetpoint.hpp>


namespace touchgfx
{
//#define SHOW_BACKGROUND
//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CGaugeSetpoint::CGaugeSetpoint()
{
#ifdef SHOW_BACKGROUND
	background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
	add(background);
#endif

	add(integer);
	add(decimal);
	add(unitC);
	add(unitF);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CGaugeSetpoint::update(int16_t temperature, bool celsius)
{
	char integerString[8];
	int integerValue = temperature / 100;
	sprintf(integerString, "%d", integerValue);
	integer = integerString;
	integer.setXY(1, 1);

	char decimalString[8];
	int decimalValue = abs((temperature % 100) / 10);
	sprintf(decimalString, ".%d", decimalValue);
	decimal = decimalString;
	decimal.setXY(integer.getWidth(), integer.getHeight() - decimal.getHeight() + decimal.getBaseline());

	CLabel* unit;
	if(celsius)
	{
		unit = &unitC;
		unitC.setVisible(true);
		unitF.setVisible(false);
	}
	else
	{
		unit = &unitF;
		unitC.setVisible(false);
		unitF.setVisible(true);
	}
	unit->setXY(integer.getWidth(), integer.getY());

	Container::setWidthHeight(integer.getWidth() + MAX(unit->getWidth(), decimal.getWidth()), integer.getHeight() + decimal.getBaseline());

#ifdef SHOW_BACKGROUND
	background.setWidthHeight(*this);
#endif
}

//-----------------------------------------------------------------------------
void CGaugeSetpoint::render()
{
	dsp.setPosition(*this, *this);
	integer.render();
	decimal.render();
	unitC.render();
	unitF.render();
	Container::invalidate();
}

}   //namespace touchgfx
