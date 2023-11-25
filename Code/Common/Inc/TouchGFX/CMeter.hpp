
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
//         File : CMeter.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Meter base class header file
//=============================================================================
#ifndef CMETER_HPP
#define CMETER_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMeter : public Container
{
public:
	CMeter();
	void setBackgroundColor(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue);

protected:
	void addInteger(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& nexTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
	void addDecimal(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
	void addUnit(const TypedText& newTypedTextC, const TypedText& newTypedTextF, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
	void addUnit(const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
	void addDot(const TypedText& newTypedTextP, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
	void resizeBackground();

	class CMeterValue : public Container
	{
	public:
		CMeterValue(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
		void display(int16_t value);
		uint8_t getPrecision();
		int16_t getMaxGlyphHeight();

	protected:
		typedef TextAreaWithOneWildcard MeterDigitWidget;
		typedef Unicode::UnicodeChar MeterDigitBuffer[2];

		class CMeterDigit
		{
		public:
			MeterDigitWidget widget;
			MeterDigitBuffer buffer = {0};
		};

	private:
		char* valueString;
		int16_t maxGlyphHeight;
		CMeterDigit** digits;
		uint8_t precision;
		uint8_t spacingRatio;   //Set to 0 for no ratio
		TypedText textType;
	};

	CMeterValue* integer;
	CMeterValue* decimal;
	TextArea* dot;
	TextArea* unit;
	TypedText unitTempC;
	TypedText unitTempF;
	TypedText unitTempP;

private:
	touchgfx::Box background;
};

}   //namespace touchgfx


#endif   //CMETER_HPP
