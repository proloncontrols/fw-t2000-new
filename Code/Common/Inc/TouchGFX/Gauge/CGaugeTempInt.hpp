
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
//         File : CGaugeTempInt.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Interior temperature gauge display class header file
//=============================================================================
#ifndef CGAUGE_TEMP_INT_HPP
#define CGAUGE_TEMP_INT_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CDisplay.hpp>
#include <Gauge/CGauge.hpp>
#include <touchgfx/hal/Types.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CGaugeTemperatureInterior : public Container //CGauge
{
public:
    CGaugeTemperatureInterior()
	{
		add(background);
		background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));

		add(integer);
		add(decimal);
	}

	void update(float temp, bool celsius)
	{
		integer = "-21";
		integer.setXY(1, 1);

		decimal = ".5";
		decimal.setXY(integer.getWidth(), integer.getHeight() - decimal.getHeight() + decimal.getBaseline());

		Container::setWidthHeight(integer.getWidth() + decimal.getWidth(), integer.getHeight() + decimal.getBaseline());

		background.setWidthHeight(*this);
	}

	void invalidate()
	{
		dsp.setPosition(*this, *this);

		integer.invalidate();
		decimal.invalidate();
	}

private:
	const static int integerPrecision = 4;
	const static int integerSpacingRatio = 15;
	const static TypedTextId integerText = T_GAUGE_DIGITS_INTEGER_HUGE;

	const static int decimalPrecision = 2;
	const static int decimalSpacingRatio = 15;
	const static TypedTextId decimalText = T_GAUGE_DIGITS_DECIMAL_MEDIUM;

	const static uint8_t colorR = 255;
	const static uint8_t colorG = 255;
	const static uint8_t colorB = 255;

	Box background;
	CText integer = CText(integerPrecision, integerSpacingRatio, integerText, colorR, colorG, colorB);
	CText decimal = CText(decimalPrecision, decimalSpacingRatio, decimalText, colorR, colorG, colorB);
};

}   //namespace touchgfx


#endif   //CGAUGE_TEMP_INT_HPP
