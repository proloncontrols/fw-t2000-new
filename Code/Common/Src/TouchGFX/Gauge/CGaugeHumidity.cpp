
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
//         File : CGaugeHumidity.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Exterior humifity gauge display class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Gauge/CGaugeHumidity.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CGaugeHumidity::CGaugeHumidity()
{
	integer = new CText(integerPrecision, integerSpacingRatio, integerText, colorR, colorG, colorB);
	add(*integer);

	unitP = new CLabel(unit, colorR, colorG, colorB);
	add(*unitF);

	image = new CImage(imageId);
	add(*image);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CGaugeHumidity::update(uint8_t humidity)
{
//	CGaugeTemperature::update(temp, celsius);
}

//-----------------------------------------------------------------------------
void CGaugeHumidity::invalidate()
{
	CGauge::invalidate();
}

}   //namespace touchgfx
