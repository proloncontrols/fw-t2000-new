
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
//         File : CGaugeTemperatureExterior.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Exterior temperature gauge display class header file
//=============================================================================
#ifndef CGAUGE_TEMPERATURE_EXTERIOR_HPP
#define CGAUGE_TEMPERATURE_EXTERIOR_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Gauge/CGaugeTemperature.hpp>
#include <Bitmapdatabase.hpp>
#include <touchgfx/Bitmap.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CGaugeTemperatureExterior : public CGaugeTemperature
{
public:
	CGaugeTemperatureExterior();

	void update(float temp, bool celsius);
	void invalidate();

private:
	const static int integerPrecision = 4;   //Includes the minus sign
	const static int integerSpacingRatio = 15;
	const static TypedTextId integerText = T_GAUGE_TEMPERATURE_EXTERIOR_LARGE;

	const static TypedTextId unitTextC = T_GAUGE_TEMPERATURE_EXTERIOR_SMALL_C;
	const static TypedTextId unitTextF = T_GAUGE_TEMPERATURE_EXTERIOR_SMALL_F;

	const static BitmapId imageId = BITMAP_OUTSIDE_24X24_ID;

	const static uint8_t colorR = 86;
	const static uint8_t colorG = 88;
	const static uint8_t colorB = 90;
};

}   //namespace touchgfx


#endif   //CGAUGE_TEMPERATURE_EXTERIOR_HPP
