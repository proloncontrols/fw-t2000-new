
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
#include <stdio.h>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>
#include <Gauge/CGaugeHumidity.hpp>


namespace touchgfx
{
//#define SHOW_BACKGROUND
//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CGaugeHumidity::CGaugeHumidity()
{
#ifdef SHOW_BACKGROUND
	background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
	add(background);
#endif

	add(integer);
	add(unit);
	add(image);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CGaugeHumidity::update(uint8_t humidity)
{
	if(humidity > 100)
		humidity = 100;

	char string[8];
	sprintf(string, "%d", humidity);

	integer = string;
	integer.setXY(1, 1);

	unit.setXY(integer.getWidth(), integer.getY());

	image.setXY(integer.getWidth(), integer.getHeight() - image.getHeight());

	Container::setWidthHeight(integer.getWidth() + MAX(unit.getWidth(), image.getWidth()), integer.getHeight() + integer.getBaseline());

#ifdef SHOW_BACKGROUND
	background.setWidthHeight(*this);
#endif
}

//-----------------------------------------------------------------------------
void CGaugeHumidity::invalidate()
{
	dsp.setPosition(*this, *this);
	integer.invalidate();
	unit.invalidate();
	image.invalidate();
}

}   //namespace touchgfx
