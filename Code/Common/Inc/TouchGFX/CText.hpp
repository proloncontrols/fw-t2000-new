
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
//         File : CText.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Text class header file
//=============================================================================
#ifndef CTEXT_HPP
#define CTEXT_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <CDisplay.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CText : public TextAreaWithOneWildcard
{
public:
	CText(const TypedText& newType, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
	{
		setColor(Color::getColorFromRGB(newColorR, newColorG, newColorB));
		setTypedText(newType);
	}

	//-----------------------------------------------------------------------------
	void addTo(Container& c)
	{
		dsp.add(c, *this);
	}

	//-----------------------------------------------------------------------------
	void setXY(int16_t x, int16_t y)
	{
		if(dsp.orientation != CDisplay::NATIVE)
			setRotation(TEXT_ROTATE_180);
		TextAreaWithOneWildcard::setXY(x, y);
	}

	//-----------------------------------------------------------------------------
	void operator=(const char* newText)
	{
		int newLen = strlen(newText);
		if(newLen > curLength)
		{
			if(buffer)
				free(buffer);
			buffer = (Unicode::UnicodeChar*)malloc((newLen + 1) * sizeof(Unicode::UnicodeChar));   //+1 = null termination character
			setWildcard(buffer);
		}
		curLength = newLen;
		memset(buffer, 0, (curLength + 1) * sizeof(Unicode::UnicodeChar));
		Unicode::fromUTF8((uint8_t*)newText, buffer, newLen);
		resizeToCurrentText();
	}

	//-----------------------------------------------------------------------------
	int16_t getTextMaxHeight()
	{
		int16_t maxHeight = 0;
		for(int i = 0; i < curLength; i++)
		{
			if(getTypedText().getFont()->getGlyph(buffer[0])->height() > maxHeight)
				maxHeight = getTypedText().getFont()->getGlyph(buffer[0])->height();
		}
		return maxHeight;
	}

	Unicode::UnicodeChar* buffer = NULL;

protected:
	int curLength = 0;
};





class CDigit : public Container
{
public:
	CDigit(const TypedText& newType, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
	{
		background.setColor(Color::getColorFromRGB(140,  80,  140));
		add(background);

		if(dsp.orientation != CDisplay::NATIVE)
			text.setRotation(TEXT_ROTATE_180);
		text.setColor(Color::getColorFromRGB(newColorR, newColorG, newColorB));
		text.setTypedText(newType);
		text.setWildcard(buffer);
		add(text);
	}

	//-----------------------------------------------------------------------------
	void addTo(Container& c)
	{
		dsp.add(c, *this);
	}

	//-----------------------------------------------------------------------------
	void setDigit(const char newDigit)
	{
		Unicode::fromUTF8((uint8_t*)&newDigit, buffer, 1);
		buffer[1] = 0;

		text.resizeToCurrentText();

		const GlyphNode* node = getGlyph();

		if(dsp.orientation == CDisplay::NATIVE)
		{
			text.setXY(node->left * -1, 0);
			Container::setWidthHeight(text.getWidth() - (text.getWidth() - node->width()), text.getHeight());
		}
		else
		{
			text.setXY((text.getWidth() - node->width() - node->left) * -1, 0);
			Container::setWidthHeight(node->width(), text.getHeight());
		}
		background.setWidthHeight(*this);
	}

	//-----------------------------------------------------------------------------
	const Font* getFont()
	{
		return text.getTypedText().getFont();
	}

	//-----------------------------------------------------------------------------
	const GlyphNode* getGlyph()
	{
		return getFont()->getGlyph(buffer[0]);
	}

private:
	Box background;
	TextAreaWithOneWildcard text;
	Unicode::UnicodeChar buffer[2];
};





//class CGaugeDigit : public Container
//{
////#define USE_DEV_BACKGROUND
//public:
//	CGaugeDigit(const TypedText& type, uint8_t colorR, uint8_t colorG, uint8_t colorB)
//	{
//#ifdef USE_DEV_BACKGROUND
//		background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
//		dsp.add(*this, background);
//#endif
//		digit = new CText(type, colorR, colorG, colorB);
//		digit->addTo(*this);
//	}
//
//	//-----------------------------------------------------------------------------
//	void addTo(Container& c)
//	{
//		dsp.add(c, *this);
//	}
//
//	//-----------------------------------------------------------------------------
//	void setDigit(const char newDigit)
//	{
//		char val[2] = {newDigit, 0};
//
//		if(dsp.orientation != CDisplay::NATIVE)
//			digit->setRotation(TEXT_ROTATE_180);
//		digit->operator=(val);
//
//		const GlyphNode* node = digit->getTypedText().getFont()->getGlyph(digit->buffer[0]);
//
//		if(dsp.orientation == CDisplay::NATIVE)
//		{
//			digit->setXY(node->left * -1, 0);
//			Container::setWidthHeight(digit->getWidth() - (digit->getWidth() - node->width()), digit->getHeight());
//		}
//		else
//		{
//			digit->setXY((digit->getWidth() - node->width() - node->left) * -1, 0);
//			Container::setWidthHeight(node->width(), digit->getHeight());
//		}
//#ifdef USE_DEV_BACKGROUND
//		background.setWidthHeight(*this);
//#endif
//	}
//
//private:
//#ifdef USE_DEV_BACKGROUND
//	Box background;
//#endif
//	CText* digit;
//};





class CValue : public Container
{
public:
	CValue(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newType, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
	{
		precision = newPrecision;

		setHeight(newType.getFont()->getFontHeight());
		spacingWidth = 0;
		if(newSpacingRatio != 0)
			spacingWidth = getHeight() / newSpacingRatio;


//		background.setHeight(getHeight());
//		background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
//		add(background);


		digits = (CDigit**)malloc(precision * sizeof(CDigit*));   //precision MUST include the minus sign
		for(uint8_t i = 0; i < precision; i++)
		{
			digits[i] = new CDigit(newType, newColorR, newColorG, newColorB);
			add(*digits[i]);
		}

		valueString = (char*)calloc(precision + 1, sizeof(char));   //+1 = null termination character
}

	//-----------------------------------------------------------------------------
	void addTo(Container& c)
	{
		dsp.add(c, *this);
	}

	//-----------------------------------------------------------------------------
	void update(int16_t value)
	{
		sprintf(valueString, "%d", value);
		int len = strlen(valueString);

		maxTop = 0;
		int16_t gaugeWidth = 0;
		for(int i = 0; i < len; i++)
		{
			digits[i]->setDigit(valueString[i]);
			if(dsp.orientation == CDisplay::NATIVE)
				digits[i]->setXY(gaugeWidth, 0);
			gaugeWidth += digits[i]->getWidth();
			gaugeWidth += spacingWidth;

			if(digits[i]->getGlyph()->top() > maxTop)
				maxTop = digits[i]->getGlyph()->top();
		}

//		background.setWidth(gaugeWidth);
		Container::setWidth(gaugeWidth);

		if(dsp.orientation != CDisplay::NATIVE)
		{
			for(int i = 0; i < len; i++)
			{
				digits[i]->setXY(gaugeWidth - digits[i]->getWidth(), 0);
				gaugeWidth -= digits[i]->getWidth();
				gaugeWidth -= spacingWidth;
			}
		}
	}

	//-----------------------------------------------------------------------------
	int16_t getTopLine()
	{
		return getHeight() - maxTop;;
	}

private:
//	Box background;

	uint8_t precision;

	CDigit** digits;
	char* valueString;
	int16_t spacingWidth;
	int16_t maxTop;
};





//class CGaugeValue : public Container
//{
//public:
//	CGaugeValue(uint8_t valuePrecision, uint8_t spacingRatio, const TypedText& textType, uint8_t colorR, uint8_t colorG, uint8_t colorB)
//	{
//		background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
//		dsp.add(*this, background);
//
//		precision = valuePrecision;
//		type = textType;
//
//		spacingWidth = 0;
//		if(spacingRatio != 0)
//			spacingWidth = type.getFont()->getFontHeight() / spacingRatio;
//
//		digits = (CGaugeDigit**)malloc(precision * sizeof(CGaugeDigit*));   //precision MUST include the minus sign
//		for(uint8_t i = 0; i < precision; i++)
//		{
//			digits[i] = new CGaugeDigit(textType, colorR, colorG, colorB);
//			digits[i]->addTo(*this);
//		}
//
//		valueString = (char*)calloc(precision + 1, sizeof(char));   //+1 = null termination character
//	}
//
//	//-----------------------------------------------------------------------------
//	void addTo(Container& c)
//	{
//		dsp.add(c, *this);
//	}
//
//	//-----------------------------------------------------------------------------
//	void update(int16_t value)
//	{
//		int len;
//		int16_t gaugeWidth;
//
//		sprintf(valueString, "%d", value);
//		len = strlen(valueString);
//
//		gaugeWidth = 0;
//		for(int i = 0; i < len; i++)
//		{
//			digits[i]->setDigit(valueString[i]);
//			if(dsp.orientation == CDisplay::NATIVE)
//				digits[i]->setXY(gaugeWidth, 0);
//			gaugeWidth += digits[i]->getWidth();
//			gaugeWidth += spacingWidth;
//		}
//
//		background.setWidthHeight(gaugeWidth, type.getFont()->getFontHeight());
//		Container::setWidthHeight(background);
//
//		if(dsp.orientation != CDisplay::NATIVE)
//		{
//			for(int i = 0; i < len; i++)
//			{
//				digits[i]->setXY(gaugeWidth - digits[i]->getWidth(), 0);
//				gaugeWidth -= digits[i]->getWidth();
//				gaugeWidth -= spacingWidth;
//			}
//		}
//	}
//
//	uint8_t getPrecision();
//	int16_t getMaxGlyphHeight();
////	int16_t getWidth();
//
//protected:
////		typedef TextAreaWithOneWildcard MeterDigitWidget;
////		typedef Unicode::UnicodeChar MeterDigitBuffer[2];
////
////		class CMeterDigit
////		{
////		public:
////			MeterDigitWidget widget;
////			MeterDigitBuffer buffer = {0};
////		};
//
//private:
//	char* valueString;
//	int16_t spacingWidth;
//
//
//	int16_t maxGlyphHeight;
////	int16_t newWidth;
//	int16_t trailingSpace;
////		CMeterDigit** digits;
//	CGaugeDigit** digits;
//	uint8_t precision;
//	uint8_t spacingRatio;   //Set to 0 for no ratio (original font aspect)
//	TypedText type;
//
//	Box background;
//};





class CGaugeTemperature : public Container
{
public:
	CGaugeTemperature(uint8_t intPrecision, const TypedText& intType,
					  uint8_t decPrecision, const TypedText& decType,
					  const TypedText& unitType, uint8_t newSpacingRatio, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
	{
		integer = new CValue(intPrecision, newSpacingRatio, intType, newColorR, newColorG, newColorB);
		add(*integer);

		decimal = new CValue(decPrecision, newSpacingRatio, decType, newColorR, newColorG, newColorB);
		decimalPrecision = decPrecision;   //MUST include the dot
		add(*decimal);

		Container::setHeight(intType.getFont()->getFontHeight() + 10);

//		unit = new CText(unitType, newColorR, newColorG, newColorB);
//		add(*unit);
	}

	void addTo(Container& c)
	{
		dsp.add(c, *this);
	}

	void update(float temperature, bool celsius)
	{
		double intDoubleValue;
		double decDoubleValue = modf(temperature, &intDoubleValue);

		int16_t intValue = (int16_t)intDoubleValue;
		int16_t decValue = (int16_t)abs((decDoubleValue * pow(10.0, (double)(decimalPrecision - 1))));   //-1 is to remove the dot

		integer->update(intValue);
		decimal->update(decValue);

		integer->setXY(0, 0);
		decimal->setXY(integer->getWidth(),  Container::getHeight() - decimal->getHeight());

	//	if(celsius)
	//		unit->setTypedText(touchgfx::TypedText(unitTempC));
	//	else
	//		unit->setTypedText(touchgfx::TypedText(unitTempF));
	//	unit->setXY(integer->getWidth(), Container::getHeight() - integer->getMaxGlyphHeight() - (unit->getTypedText().getFont()->getFontHeight() - unit->getTypedText().getFont()->getGlyph(unit->getTypedText().getText()[0])->top()));

		Container::setWidth(integer->getWidth() + decimal->getWidth());
	}

private:
	CValue* integer = NULL;
	CValue* decimal = NULL;
	uint8_t decimalPrecision;
//	CText* unit = NULL;
};





}   //namespace touchgfx


#endif   //CTEXT_HPP



























