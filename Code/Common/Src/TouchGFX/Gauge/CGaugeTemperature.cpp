
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
#include <Gauge/CGaugeTemperature.hpp>


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
	char integerString[8];
	char decimalString[8];

	double intDoubleValue;
	double decDoubleValue = modf(temp, &intDoubleValue);

	int16_t intValue = (int16_t)intDoubleValue;
	int16_t decValue = (int16_t)abs((decDoubleValue * pow(10.0, (double)decimalDigits)));   //-1 removes the dot

	sprintf(integerString, "%d", intValue);
	sprintf(decimalString, ".%d", decValue);

	*integer = integerString;
	integer->setXY(1, 1);

	*decimal = decimalString;
	decimal->setXY(integer->getWidth(), integer->getHeight() - decimal->getHeight() + decimal->getBaseline());

	Container::setWidthHeight(integer->getWidth() + decimal->getWidth(), integer->getHeight() + decimal->getBaseline());

//	background.setWidthHeight(*this);
}

}   //namespace touchgfx
