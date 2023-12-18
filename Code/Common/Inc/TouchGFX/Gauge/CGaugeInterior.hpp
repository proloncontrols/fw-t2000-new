
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
//         File : CGaugeInterior.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Interior temperature gauge display class header file
//=============================================================================
#ifndef CGAUGE_INTERIOR_HPP
#define CGAUGE_INTERIOR_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CText.hpp>
#include <CLabel.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CGaugeInterior : public Container
{
public:
	CGaugeInterior();

	void update(float temperature, bool celsius);
	void invalidate();

private:
	const static uint8_t colorR = 255;
	const static uint8_t colorG = 255;
	const static uint8_t colorB = 255;

	const static int integerPrecision = 4;   //Includes the minus sign
	const static int integerSpacingRatio = 15;
	const static TypedTextId integerText = T_GAUGE_TEMPERATURE_INTERIOR_LARGE;

	const static int decimalPrecision = 2;   //Includes the dot
	const static int decimalSpacingRatio = 15;
	const static TypedTextId decimalText = T_GAUGE_TEMPERATURE_INTERIOR_MEDIUM;

	const static TypedTextId unitTextC = T_GAUGE_TEMPERATURE_INTERIOR_SMALL_C;
	const static TypedTextId unitTextF = T_GAUGE_TEMPERATURE_INTERIOR_SMALL_F;

	Box background;
	CText integer = CText(integerPrecision, integerSpacingRatio, integerText, colorR, colorG, colorB);
	CText decimal = CText(decimalPrecision, integerSpacingRatio, decimalText, colorR, colorG, colorB);
	CLabel unitC = CLabel(unitTextC, colorR, colorG, colorB);
	CLabel unitF = CLabel(unitTextF, colorR, colorG, colorB);
};

}   //namespace touchgfx


#endif   //CGAUGE_INTERIOR_HPP
