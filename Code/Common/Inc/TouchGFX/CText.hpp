
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
	CText(int initialLength, const TypedText& type, uint8_t colorR, uint8_t colorG, uint8_t colorB)
	{
		curLength = initialLength;
		buffer = (Unicode::UnicodeChar*)calloc(curLength + 1, sizeof(Unicode::UnicodeChar));   //+1 = null termination character
		setWildcard(buffer);
		setColor(Color::getColorFromRGB(colorR, colorG, colorB));
		setTypedText(type);
	}

	//-----------------------------------------------------------------------------
	void addTo(Container& c)
	{
		dsp.add(c, *this);
	}

	//-----------------------------------------------------------------------------
	void setXY(int16_t x, int16_t y)
	{
//		setRotation(TEXT_ROTATE_180);
		TextAreaWithOneWildcard::setXY(x, y);
	}

	//-----------------------------------------------------------------------------
	void operator=(const char* newText)
	{
		int newLen = strlen(newText);
		if(newLen > curLength)
		{
			free(buffer);
			buffer = (Unicode::UnicodeChar*)malloc((newLen + 1) * sizeof(Unicode::UnicodeChar));   //+1 = null termination character
		}
		curLength = newLen;
		memset(buffer, 0, curLength * sizeof(Unicode::UnicodeChar));
		Unicode::fromUTF8((uint8_t*)newText, buffer, newLen);
		resizeToCurrentText();
	}

	Unicode::UnicodeChar* buffer;

protected:
	int curLength = 0;
};





class CMeterDigit : public Container
{
public:
	CMeterDigit(const TypedText& type, uint8_t colorR, uint8_t colorG, uint8_t colorB)
	{
		digit = new CText(1, type, colorR, colorG, colorB);
		background.setColor(Color::getColorFromRGB(86, 88, 90));
	}

	//-----------------------------------------------------------------------------
	void addTo(Container& c)
	{
		dsp.add(c, *this);
		dsp.add(*this, background);
		digit->addTo(*this);
	}

	//-----------------------------------------------------------------------------
	void operator=(const char* newDigit)
	{
		digit->operator=(newDigit);
		const GlyphNode* node = digit->getTypedText().getFont()->getGlyph(digit->buffer[0]);
		digit->setXY(node->left * -1, 0);
		background.setWidthHeight(digit->getWidth() - (digit->getWidth() - node->width()), digit->getHeight());
		Container::setWidthHeight(background);
	}

private:
	Box background;
	CText* digit;
};





class CMeterValue : public Container
{
public:
	CMeterValue(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);
	void update(int16_t value);
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
	CText** digits;
	uint8_t precision;
	uint8_t spacingRatio;   //Set to 0 for no ratio (original font aspect)
	TypedText textType;

	Box back;
};





}   //namespace touchgfx


#endif   //CTEXT_HPP



























