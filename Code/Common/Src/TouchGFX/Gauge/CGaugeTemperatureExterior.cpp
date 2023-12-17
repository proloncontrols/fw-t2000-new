
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
//         File : CGaugeTemperatureExterior.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Exterior temperature gauge display class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Gauge/CGaugeTemperatureExterior.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CGaugeTemperatureExterior::CGaugeTemperatureExterior()
{
	integer = new CText(integerPrecision, integerSpacingRatio, integerText, colorR, colorG, colorB);
	add(*integer);

	unitC = new CLabel(unitTextC, colorR, colorG, colorB);
	add(*unitC);

	unitF = new CLabel(unitTextF, colorR, colorG, colorB);
	add(*unitF);

	image = new CImage(imageId);
	add(*image);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CGaugeTemperatureExterior::update(float temp, bool celsius)
{
	CGaugeTemperature::update(temp, celsius);
}

//-----------------------------------------------------------------------------
void CGaugeTemperatureExterior::invalidate()
{
	CGauge::invalidate();
}

}   //namespace touchgfx
