
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
//         File : CMeter.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Meter base class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CMeter.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/Bitmap.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMeter::CMeter()
{
	add(background);
	background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeter::setBackgroundColor(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue)
{
	background.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
}

//-----------------------------------------------------------------------------
void CMeter::addInteger(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
	integer = new CMeterValue(newPrecision, newSpacingRatio, touchgfx::TypedText(newTypedText), newColorR, newColorG, newColorB);
	add(*integer);
}

//-----------------------------------------------------------------------------
void CMeter::addDecimal(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
	decimal = new CMeterValue(newPrecision, newSpacingRatio, touchgfx::TypedText(newTypedText), newColorR, newColorG, newColorB);
	add(*decimal);
}

//-----------------------------------------------------------------------------
void CMeter::addUnit(const TypedText& newTypedTextC, const TypedText& newTypedTextF, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
	unit = new TextArea;
	unit->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
	unitTempC = newTypedTextC;
	unitTempF = newTypedTextF;
	add(*unit);
}

void CMeter::addUnit(const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
	unit = new TextArea;
	unit->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
	unit->setTypedText(touchgfx::TypedText(newTypedText));
	add(*unit);
}

//-----------------------------------------------------------------------------
void CMeter::addDot(const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
	dot = new TextArea;
	dot->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
	dot->setTypedText(touchgfx::TypedText(newTypedText));
	add(*dot);
}

//-----------------------------------------------------------------------------
void CMeter::addImage(const Bitmap& bmp)
{
	image = new CImage;
	image->setBitmap(bmp);
	add(*image);
}

//-----------------------------------------------------------------------------
void CMeter::resizeBackground()
{
	background.setWidthHeight(*this);
}





//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMeter::CMeterValue::CMeterValue(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& nexTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
	precision = newPrecision;
	spacingRatio = newSpacingRatio;
	textType = nexTypedText;

	digits = (CMeterDigit**)malloc(sizeof(CMeterDigit*) * precision);
	for(uint8_t i = 0; i < precision; i++)
	{
		digits[i] = new CMeterDigit;
		digits[i]->widget.setTypedText(textType);
		digits[i]->widget.setWildcard(digits[i]->buffer);
		digits[i]->widget.setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
		add(digits[i]->widget);
	}

	valueString = (char*)calloc(precision + 1, sizeof(char));

	Container::setHeight(textType.getFont()->getFontHeight());
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeter::CMeterValue::display(int16_t value)
{
	int len;
	int16_t newWidth;
	int16_t spacingWidth;
	char* valPtr;
	CMeterDigit* digPtr;
	CMeterDigit** dspPtr;
	const GlyphNode* glyph;

	sprintf(valueString, "%d", value);
	len = strlen(valueString);

	newWidth = 0;
	if(spacingRatio != 0)
	{
		spacingWidth = textType.getFont()->getFontHeight() / spacingRatio;
		newWidth = spacingWidth;
	}

	maxGlyphHeight = 0;

	valPtr = &valueString[len - 1];
	dspPtr = &digits[precision - 1];
	for(int i = 0; i < len; i++)
	{
		digPtr = *dspPtr;
		Unicode::fromUTF8((uint8_t*)valPtr, digPtr->buffer, 1);
		digPtr->widget.resizeToCurrentText();

		glyph = textType.getFont()->getGlyph(digPtr->buffer[0]);

		if(glyph->top() > maxGlyphHeight)
			maxGlyphHeight = glyph->top();

		if(spacingRatio == 0)
			newWidth += digPtr->widget.getWidth();
		else
			newWidth += glyph->width() + spacingWidth;

		valPtr--;
		dspPtr--;
	}

	Container::setWidth(newWidth);

	if(spacingRatio != 0)
		newWidth -= spacingWidth;

	dspPtr = &digits[precision - 1];
	for(int i = 0; i < len; i++)
	{
		digPtr = *dspPtr;
		if(spacingRatio == 0)
		{
			newWidth -= digPtr->widget.getWidth();
			digPtr->widget.setXY(newWidth, Container::getHeight() - digPtr->widget.getHeight());
		}
		else
		{
			glyph = textType.getFont()->getGlyph(digPtr->buffer[0]);
			newWidth -= glyph->width();
			digPtr->widget.setXY(newWidth - glyph->left, Container::getHeight() - digPtr->widget.getHeight());
			newWidth -= spacingWidth;
		}

		dspPtr--;
	}
}

//-----------------------------------------------------------------------------
uint8_t CMeter::CMeterValue::getPrecision()
{
	return precision;
}

//-----------------------------------------------------------------------------
int16_t CMeter::CMeterValue::getMaxGlyphHeight()
{
	return maxGlyphHeight;
}


}   //namespace touchgfx
