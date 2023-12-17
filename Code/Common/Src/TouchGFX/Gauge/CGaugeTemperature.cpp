
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
//         File : CGaugeTemperature.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Temperature gauge display base class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <CDisplay.hpp>
#include <Gauge/CGaugeTemperature.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CGaugeTemperature::CGaugeTemperature()
{
//	add(background);
//	background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CGaugeTemperature::update(float temp, bool celsius)
{
	int index;
	int dotIndex;
	char integerString[8];
	char decimalString[8];

	char precisionString[2];
	sprintf(precisionString, "%d", decimalDigits);

	char formatString[6];
	strcpy(formatString, "%.");
	strcat(formatString, precisionString);
	strcat(formatString, "f");

	char valueString[8];
	sprintf(valueString, formatString, temp);

	memset(integerString, 0, sizeof(integerString));
	for(index = 0; valueString[index] != '.'; index++)
		integerString[index] = valueString[index];
	*integer = integerString;
	integer->setXY(1, 1);

	if(decimal)
	{
		dotIndex = index;
		memset(decimalString, 0, sizeof(decimalString));
		while(index < (int)strlen(valueString))
		{
			decimalString[index - dotIndex] = valueString[index];
			index++;
		}
		*decimal = decimalString;
		decimal->setXY(integer->getWidth(), integer->getHeight() - decimal->getHeight() + decimal->getBaseline());
	}

	CLabel* unit;
	if(celsius)
	{
		unit = unitC;
		unitC->setVisible(true);
		unitF->setVisible(false);
	}
	else
	{
		unit = unitF;
		unitC->setVisible(false);
		unitF->setVisible(true);
	}
	unit->setXY(integer->getWidth(), integer->getY());

	if(!decimal)
		Container::setWidthHeight(integer->getWidth() + unit->getWidth(), integer->getHeight());
	else
		Container::setWidthHeight(integer->getWidth() + MAX(unit->getWidth(), decimal->getWidth()), integer->getHeight() + decimal->getBaseline());

//	background.setWidthHeight(*this);
}

}   //namespace touchgfx






































