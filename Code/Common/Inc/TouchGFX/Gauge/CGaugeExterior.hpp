
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
//         File : CGaugeExterior.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Exterior temperature gauge display class header file
//=============================================================================
#ifndef CGAUGE_EXTERIOR_HPP
#define CGAUGE_EXTERIOR_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CText.hpp>
#include <CLabel.hpp>
#include <CImage.hpp>
#include <Bitmapdatabase.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CGaugeExterior : public Container
{
public:
	CGaugeExterior();

	void update(int16_t temperature, bool celsius);
	void invalidate();

private:
	const static uint8_t colorR = 186;
	const static uint8_t colorG = 188;
	const static uint8_t colorB = 190;

	const static int integerPrecision = 4;   //Includes the minus sign
	const static int integerSpacingRatio = 15;
	const static TypedTextId integerText = T_GAUGE_TEMPERATURE_EXTERIOR_LARGE;

	const static TypedTextId unitTextC = T_GAUGE_TEMPERATURE_EXTERIOR_SMALL_C;
	const static TypedTextId unitTextF = T_GAUGE_TEMPERATURE_EXTERIOR_SMALL_F;

	const static BitmapId imageId = BITMAP_OUTSIDE_24X24_ID;

	Box background;
	CText integer = CText(integerPrecision, integerSpacingRatio, integerText, colorR, colorG, colorB);
	CLabel unitC = CLabel(unitTextC, colorR, colorG, colorB);
	CLabel unitF = CLabel(unitTextF, colorR, colorG, colorB);
	CImage image = CImage(imageId);
};

}   //namespace touchgfx


#endif   //CGAUGE_EXTERIOR_HPP
