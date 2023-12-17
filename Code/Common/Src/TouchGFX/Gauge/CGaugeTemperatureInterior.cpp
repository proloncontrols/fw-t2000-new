
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
#include <Gauge/CGaugeTemperatureInterior.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CGaugeTemperatureInterior::CGaugeTemperatureInterior()
{
	integer = new CText(integerPrecision, integerSpacingRatio, integerText, colorR, colorG, colorB);
	add(*integer);

	decimal = new CText(decimalPrecision, decimalSpacingRatio, decimalText, colorR, colorG, colorB);
	decimalDigits = decimalPrecision -1;   //-1 removes the dot
	add(*decimal);

	unitC = new CText(unitPrecision, unitSpacingRatio, unitTextC, colorR, colorG, colorB);
	add(*unitC);

	unitF = new CText(unitPrecision, unitSpacingRatio, unitTextF, colorR, colorG, colorB);
	add(*unitF);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CGaugeTemperatureInterior::update(float temp, bool celsius)
{
	CGaugeTemperature::update(temp, celsius);
}

//-----------------------------------------------------------------------------
void CGaugeTemperatureInterior::invalidate()
{
	CGauge::invalidate();
}

}   //namespace touchgfx
