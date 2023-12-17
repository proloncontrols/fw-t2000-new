
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
//         File : CGaugeTemperatureInterior.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Interior temperature gauge display class header file
//=============================================================================
#ifndef CGAUGE_TEMPERATURE_INTERIOR_HPP
#define CGAUGE_TEMPERATURE_INTERIOR_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Gauge/CGaugeTemperature.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CGaugeTemperatureInterior : public CGaugeTemperature
{
public:
	CGaugeTemperatureInterior();

	void update(float temp, bool celsius);
	void invalidate();

private:
	const static int integerPrecision = 4;   //Includes the minus sign
	const static int integerSpacingRatio = 15;
	const static TypedTextId integerText = T_GAUGE_TEMPERATURE_INTERIOR_LARGE;

	const static int decimalPrecision = 2;   //Includes the dot
	const static int decimalSpacingRatio = 15;
	const static TypedTextId decimalText = T_GAUGE_TEMPERATURE_INTERIOR_MEDIUM;

	const static TypedTextId unitTextC = T_GAUGE_TEMPERATURE_INTERIOR_SMALL_C;
	const static TypedTextId unitTextF = T_GAUGE_TEMPERATURE_INTERIOR_SMALL_F;

	const static uint8_t colorR = 255;
	const static uint8_t colorG = 255;
	const static uint8_t colorB = 255;
};

}   //namespace touchgfx


#endif   //CGAUGE_TEMPERATURE_INTERIOR_HPP
