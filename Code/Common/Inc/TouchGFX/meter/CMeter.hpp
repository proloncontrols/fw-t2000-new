
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
#include <CText.hpp>
#include <CImage.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
//This class is not meant to be called directly. Use its derived classes instead.
class CMeter : public Container
{
public:
	CMeter();

	void addTo(Container& c);

protected:
	void addInteger(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& nexTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
	void addDecimal(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
	void addUnit(const TypedText& newTypedTextC, const TypedText& newTypedTextF, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
	void addUnit(const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
	void addDot(const TypedText& newTypedTextP, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
	void addImage(const Bitmap& bmp);
	void resizeBackground();

	class CMeterValue : public Container
	{
	public:
		CMeterValue(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
		void display(int16_t value);
		uint8_t getPrecision();
		int16_t getMaxGlyphHeight();
		int16_t getWidth();

	protected:
//		typedef TextAreaWithOneWildcard MeterDigitWidget;
//		typedef Unicode::UnicodeChar MeterDigitBuffer[2];
//
//		class CMeterDigit
//		{
//		public:
//			MeterDigitWidget widget;
//			MeterDigitBuffer buffer = {0};
//		};

	private:
		char* valueString;
		int16_t maxGlyphHeight;
		int16_t newWidth;
		int16_t trailingSpace;
//		CMeterDigit** digits;
//		CText** digits;
		uint8_t precision;
		uint8_t spacingRatio;   //Set to 0 for no ratio (original font aspect)
		TypedText textType;

		Box back;
	};

	CMeterValue* integer = NULL;
	CMeterValue* decimal = NULL;
//	TextArea* dot;
//	TextArea* unit;
//	CText* dot = NULL;
//	CText* unit = NULL;
	TypedText unitTempC;
	TypedText unitTempF;
	TypedText unitTempP;
	CImage* image = NULL;

private:
	touchgfx::Box background;
};

}   //namespace touchgfx


#endif   //CMETER_HPP
