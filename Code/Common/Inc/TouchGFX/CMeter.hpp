
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
//  Description : Meter class header file
//=============================================================================
#ifndef CMETER_HPP
#define CMETER_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stddef.h>
#include <string.h>
#include <touchgfx/Containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

class CMeterChar : public TextAreaWithOneWildcard
{
public:
	CMeterChar() { setWildcard(buffer); }

	void setFont(const TypedText& t) { setTypedText(t); }
	void setFontColor(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue) { setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue)); }

	const Font* getFont() { return getTypedText().getFont(); }
	const GlyphNode* getGlyph() { return getFont()->getGlyph(buffer[0]); }
	void setChar(char ch)
	{
		Unicode::fromUTF8((uint8_t*)&ch, buffer, 1);
		resizeToCurrentText();
	}

protected:
	Unicode::UnicodeChar buffer[2];
};

//#define MAX_LEN 32
//class CText : public Container
//{
//public:
//	CText()
//	{
//		add(background);
//		background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
//		add(widget);
//		widget.setWildcard(buffer);
//	}
//
//	void setFont(const TypedText& t) { widget.setTypedText(t); }
//	void setFontColorFore(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue) { widget.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue)); }
//	void setFontColorBack(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue) { background.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue)); }
//
//	uint16_t getLength() { return Unicode::strlen(buffer); }
//	const Font* getFont() { return widget.getTypedText().getFont(); }
//	const GlyphNode* getGlyph(uint16_t index) { return getFont()->getGlyph(buffer[index]); }
//
//	void setText(char* s)
//	{
//		Unicode::fromUTF8((uint8_t*)s, buffer, MAX_LEN);
//		widget.resizeToCurrentText();
//		Container::setWidth(widget.getWidth());
//		Container::setHeight(widget.getHeight());
//		background.setPosition(0, 0, Container::getWidth(), Container::getHeight());
//		invalidate();
//	}
//
//protected:
//	touchgfx::Box background;
//	TextAreaWithOneWildcard widget;
//	Unicode::UnicodeChar buffer[MAX_LEN];
//};

class CMeterText : public Container
{
public:
	CMeterText()
	{
		add(background);
		background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		strText = NULL;
		strLen = 0;
		charSpacingRatio = 0;
		charSpacingWidth = 0;
	}

	void initialize(CMeterChar* newText, int newLen, const TypedText& t, uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue)
	{
		strText = newText;
		strLen = newLen;
		for(int i = 0; i < strLen; i++)
		{
			add(newText[i]);
			newText[i].setTypedText(t);
			newText[i].setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
		}

		Container::setHeight(t.getFont()->getFontHeight());
	}

	void setColorBack(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue)
	{
		background.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
	}

	void setCharSpacingRatio(uint8_t ratio)
	{
		charSpacingRatio = ratio;
	}

	void setText(char* newText)
	{
		int16_t len = strlen(newText);

		char* newTextChar = &newText[len - 1];
		CMeterChar* textChar = &strText[strLen - 1];

		if(charSpacingRatio != 0)
			charSpacingWidth = textChar->getFont()->getFontHeight() / charSpacingRatio;

		int16_t newWidth = 0;
		if(charSpacingRatio != 0)
			newWidth = charSpacingWidth;

		for(int16_t i = 0; (i < len) && (i < strLen); i++)
		{
			textChar->setChar(*newTextChar);
			if(charSpacingWidth == 0)
				newWidth += textChar->getWidth();
			else
				newWidth += (textChar->getGlyph()->width() + charSpacingWidth);
			newTextChar--;
			textChar--;
		}

		Container::setWidth(newWidth);

		textChar = &strText[strLen - 1];

		if(charSpacingRatio != 0)
			newWidth -= charSpacingWidth;

		for(int16_t i = 0; (i < len) && (i < strLen); i++)
		{
			if(charSpacingRatio == 0)
			{
				newWidth -= textChar->getWidth();
				textChar->setXY(newWidth, Container::getHeight() - textChar->getHeight());
			}
			else
			{
				newWidth -= textChar->getGlyph()->width();
				textChar->setXY(newWidth - textChar->getGlyph()->left, Container::getHeight() - textChar->getHeight());
				newWidth -= charSpacingWidth;
			}
			textChar--;
		}

		background.setPosition(0, 0, Container::getWidth(), Container::getHeight());
	}

protected:
	CMeterChar* strText;
	int16_t strLen;
	uint8_t charSpacingRatio;
	int16_t charSpacingWidth;

private:
	touchgfx::Box background;
};



class CTextMeterValueIntegral : public CMeterText
{
public:
	static const int charCount = 4;

protected:
	CMeterChar value[charCount];
};















//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define METER_VALUE_MAX_CHAR   6   //Maximum number of character in value, ex: "-100.0"
//#define METER_UNIT_MAX_CHAR    2   //Maximum number of character in unit, ex: "°C"


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef enum {
	METER_UNIT_NONE,
	METER_UNIT_CELSIUS,
	METER_UNIT_FAHRENHEIT,
	METER_UNIT_HUMIDITY
} MeterUnit;


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMeter : public Container
{
public:
	CMeter();
//	void initialize(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& text);
//	void initialize(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& textLarge, const TypedText& textSmall);

	void initialize(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& textLarge, const TypedText& textSmall, bool integral);
	void setUnit(MeterUnit newUnit);
	virtual void display(double newValue);

protected:
	class CDigit
	{
	public:
		CDigit();
		char getDigit();
		void setDigit(char digit);
		const Font* getFont();
		const GlyphNode* getGlyph();
		touchgfx::TextAreaWithOneWildcard& getWidget();
		touchgfx::Unicode::UnicodeChar* getBuffer();

	private:
	    touchgfx::TextAreaWithOneWildcard widget;
	    touchgfx::Unicode::UnicodeChar buffer[2];   //Character + null
	};

	bool integralOnly;
    int leftMostCharacterLeftWidth;
	touchgfx::Box background;
	CDigit value[METER_VALUE_MAX_CHAR];
//	CDigit unit[2];

	MeterUnit curUnit;
    touchgfx::TextAreaWithOneWildcard unit;
    touchgfx::Unicode::UnicodeChar unitBuffer[3];   //Max unit length, ex: "°C" + null
    void getUnitXY(int16_t& x, int16_t& y);
};

}   //namespace touchgfx


#endif   //CMETER_VALUE_HPP
