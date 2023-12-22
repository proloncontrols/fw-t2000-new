
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
//         File : CGaugeTemperatureInterior.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Interior temperature gauge display class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>
#include <Gauge/CGaugeInterior.hpp>


namespace touchgfx
{
//#define SHOW_BACKGROUND
//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CGaugeInterior::CGaugeInterior()
{
#ifdef SHOW_BACKGROUND
	background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
	add(background);
#endif

	add(integer);
	add(decimal);
//	add(unitC);
//	add(unitF);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CGaugeInterior::update(float temperature, bool celsius)
{
	int index;
	int dotIndex;
	char integerString[8];
	char decimalString[8];

	if(temperature < -999.9)
		temperature = -999.9;
	else if(temperature > 999.9)
		temperature = 999.9;

	char precisionString[2];
	sprintf(precisionString, "%d", decimalPrecision - 1);   //-1 removes the dot

	char formatString[6];
	strcpy(formatString, "%.");
	strcat(formatString, precisionString);
	strcat(formatString, "f");

	char valueString[8];
	sprintf(valueString, formatString, temperature);

	memset(integerString, 0, sizeof(integerString));
	for(index = 0; valueString[index] != '.'; index++)
		integerString[index] = valueString[index];
	integer = integerString;
	integer.setXY(1, 1);

	dotIndex = index;
	memset(decimalString, 0, sizeof(decimalString));
	while(index < (int)strlen(valueString))
	{
		decimalString[index - dotIndex] = valueString[index];
		index++;
	}
	decimal = decimalString;
	decimal.setXY(integer.getWidth(), integer.getHeight() - decimal.getHeight() + decimal.getBaseline());

//	CLabel* unit;
	if(celsius)
	{
//		unit = &unitC;
//		unitC.setVisible(true);
//		unitF.setVisible(false);
	}
	else
	{
//		unit = &unitF;
//		unitC.setVisible(false);
//		unitF.setVisible(true);
	}
//	unit->setXY(integer.getWidth(), integer.getY());

//	Container::setWidthHeight(integer.getWidth() + MAX(unit->getWidth(), decimal.getWidth()), integer.getHeight() + decimal.getBaseline());

#ifdef SHOW_BACKGROUND
	background.setWidthHeight(*this);
#endif
}

//-----------------------------------------------------------------------------
void CGaugeInterior::render()
{
//	dsp.setPosition(*this, *this);
	integer.render();
	decimal.render();
//	unitC.render();
//	unitF.render();
	Container::invalidate();
}

}   //namespace touchgfx
