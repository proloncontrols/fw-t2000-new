
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
//         File : CGaugeHumidity.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Exterior humidity gauge display class header file
//=============================================================================
#ifndef CGAUGE_HUMIDITY_HPP
#define CGAUGE_HUMIDITY_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CText.hpp>
#include <CLabel.hpp>
#include <CImage.hpp>
#include <Bitmapdatabase.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CGaugeHumidity : public Container
{
public:
	CGaugeHumidity();

	void update(uint8_t percent);
	void render();

private:
	const static uint8_t colorR = 186;
	const static uint8_t colorG = 188;
	const static uint8_t colorB = 190;

	const static int integerPrecision = 3;   //0-100%
	const static int integerSpacingRatio = 15;
	const static TypedTextId integerText = T_GAUGE_TEMPERATURE_EXTERIOR_LARGE;

	const static TypedTextId unitText = T_GAUGE_TEMPERATURE_EXTERIOR_SMALL_P;

	const static BitmapId imageId = BITMAP_HUMIDITY_30X30_ID;

	Box background;
	CText integer = CText(integerPrecision, integerSpacingRatio, integerText, colorR, colorG, colorB);
//	CLabel unit = CLabel(unitText, colorR, colorG, colorB);
	CImage image; // = CImage(imageId);
};

}   //namespace touchgfx


#endif   //CGAUGE_HUMIDITY_HPP
