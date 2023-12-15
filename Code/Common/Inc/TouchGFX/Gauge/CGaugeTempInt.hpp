
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
#include <Gauge/CGauge.hpp>
#include <touchgfx/hal/Types.hpp>
#include <texts/TextKeysAndLanguages.hpp>

#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Color.hpp>
#include <CDisplay.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class Cont1 : public Container
{
public:
	Box background;

	Cont1(int16_t width, int16_t height, uint8_t colorR, uint8_t colorG, uint8_t colorB)
	{
		setWidthHeight(width, height);

		add(background);
		background.setWidthHeight(*this);
		background.setColor(Color::getColorFromRGB(colorR, colorG, colorB));
	}
};


class Cont2 : public Container
{
public:
	Box background;

	Cont2(int16_t width, int16_t height, uint8_t colorR, uint8_t colorG, uint8_t colorB)
	{
		setWidthHeight(width, height);

		add(background);
		background.setWidthHeight(*this);
		background.setColor(Color::getColorFromRGB(colorR, colorG, colorB));
	}
};


class CGaugeTemperatureInterior : public Container //CGauge
{
public:
//	Box background;
//	Cont1 cont1 = Cont1(400, 300, 255, 255, 255);
//	Cont2 cont2 = Cont2(350, 200, 0, 0, 0);
//
//	CText txt1 = CText(4, 15, T_GAUGE_DIGITS_INTEGER_HUGE, 255, 255, 255);
//    CText txt2 = CText(3, 15, T_GAUGE_DIGITS_DECIMAL_MEDIUM, 255, 255, 255);
//
    CGaugeTemperatureInterior(Container& newOwner)
    	:owner(newOwner)
	{
    	owner.add(*this);

//    	owner = newOwner;
//		setWidthHeight(500, 400);
//
//		add(background);
//		background.setWidthHeight(*this);
//		background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
//
//		add(cont1);
//		dsp.setXY(cont1, 10, 10);
//
//		cont1.add(cont2);
//		dsp.setXY(cont2, 10, 10);
//
//		cont2.add(txt1);
//		txt1 = "-21";
//		dsp.setXY(txt1, 10, 10);
//
//		cont2.add(txt2);
//		txt2 = ".5";
//		dsp.setXY(txt2, dsp.getX(txt1) + txt1.getWidth(), dsp.getY(txt1) + (txt1.getHeight() - txt2.getHeight()) + txt2.getBaseline());

		add(background);
		background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));

		add(integer);
		add(decimal);

//		add(integer);
//		integer = "-21";
////		dsp.setXY(integer, 1, 1);
////		integer.setXY(1, 1);
//		dsp.setX(integer, 1);
//		dsp.setY(integer, 1);
//
//		add(decimal);
//		decimal = ".5";
////		dsp.setXY(decimal, dsp.getX(integer) + integer.getWidth(), dsp.getY(integer) + (integer.getHeight() - decimal.getHeight()) + decimal.getBaseline());
////		decimal.setXY(integer.getX() + integer.getWidth(), integer.getY() + (integer.getHeight() - decimal.getHeight()) + decimal.getBaseline());
//		dsp.setX(decimal, 1);
//		dsp.setY(decimal, 1);
//
////		Container::setWidth(integer.getWidth() + decimal.getWidth());
////		Container::setHeight(dsp.getY(integer) + dsp.getY(decimal) + decimal.getHeight());
////		Container::setHeight(integer.getY() + decimal.getY() + decimal.getHeight());
//
//		Container::setWidthHeight(500, 300);
//
//		background.setWidthHeight(*this);
}



	void init()
	{
//		add(integer);
//		integer = "-21";
//		dsp.setXY(integer, 1, 1);
//		integer.setXY(1, 1);
		dsp.setX(integer, 1);
		dsp.setY(integer, 1);

//		add(decimal);
		decimal = ".5";
//		dsp.setXY(decimal, dsp.getX(integer) + integer.getWidth(), dsp.getY(integer) + (integer.getHeight() - decimal.getHeight()) + decimal.getBaseline());
//		decimal.setXY(integer.getX() + integer.getWidth(), integer.getY() + (integer.getHeight() - decimal.getHeight()) + decimal.getBaseline());
		dsp.setX(decimal, 1);
		dsp.setY(decimal, 1);

//		Container::setWidth(integer.getWidth() + decimal.getWidth());
//		Container::setHeight(dsp.getY(integer) + dsp.getY(decimal) + decimal.getHeight());
//		Container::setHeight(integer.getY() + decimal.getY() + decimal.getHeight());

		Container::setWidthHeight(500, 300);
		background.setPosition(*this);
	}

//	void addTo(Container& c);



	void update(float temp, bool celsius)
	{
		integer = "-21";
		dsp.setXY(integer, 1, 1);

		dsp.setWidthHeight(*this, 500, 300);
		background.setWidthHeight(*this);
	}



private:
	const static int integerPrecision = 4;
	const static int integerSpacingRatio = 15;
	const static TypedTextId integerText = T_GAUGE_DIGITS_INTEGER_HUGE;

	const static int decimalPrecision = 2;
	const static int decimalSpacingRatio = 15;
	const static TypedTextId decimalText = T_GAUGE_DIGITS_DECIMAL_MEDIUM;

//	const static int unitPrecision = 2;
//	const static int unitSpacingRatio = 15;
//	const static TypedTextId unitTextC = T_GAUGE_UNIT_C_SMALL;
//	const static TypedTextId unitTextF = T_GAUGE_UNIT_F_SMALL;

	const static uint8_t colorR = 255;
	const static uint8_t colorG = 255;
	const static uint8_t colorB = 255;

	Container& owner;
	Box background;

	CText integer = CText(integerPrecision, integerSpacingRatio, integerText, colorR, colorG, colorB);
	CText decimal = CText(decimalPrecision, decimalSpacingRatio, decimalText, colorR, colorG, colorB);

//	CText* integer = NULL;
//	CText* decimal = NULL;
//	CText* unitC = NULL;
//	CText* unitF = NULL;
////	CImage* image = NULL;
};

}   //namespace touchgfx


#endif   //CGAUGE_TEMP_INT_HPP









