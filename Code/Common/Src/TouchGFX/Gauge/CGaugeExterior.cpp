
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
//-----------------------------------------------------------------------------
//         File : CGaugeExterior.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Exterior temperature gauge display class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>
#include <Gauge/CGaugeExterior.hpp>


namespace touchgfx
{
//#define SHOW_BACKGROUND
//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CGaugeExterior::CGaugeExterior()
{
#ifdef SHOW_BACKGROUND
	background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
	add(background);
#endif

	add(integer);
//	add(unitC);
//	add(unitF);

//	image.setImage(BITMAP_OUTSIDE_24X24_ID);
	add(image);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CGaugeExterior::update(int16_t temperature, bool celsius)
{
	if(temperature < -999)
		temperature = -999;
	else if(temperature > 999)
		temperature = 999;

	char string[8];
	sprintf(string, "%d", temperature);

	integer = string;
	integer.setXY(1, 1);

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

	image.setXY(integer.getWidth() + (integerSpacingRatio / 2), integer.getHeight() - image.getHeight());

//	Container::setWidthHeight(MAX(unit->getX() + unit->getWidth(), image.getX() + image.getWidth()), integer.getHeight() + integer.getBaseline());

#ifdef SHOW_BACKGROUND
	background.setWidthHeight(*this);
#endif
}

//-----------------------------------------------------------------------------
void CGaugeExterior::render()
{
//	dsp.setPosition(*this, *this);
	integer.render();
//	unitC.render();
//	unitF.render();
//	image.render();
	Container::invalidate();
}

}   //namespace touchgfx
