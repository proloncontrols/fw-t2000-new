
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
//  S W I T C H E S
//-----------------------------------------------------------------------------
//#define CMETER_WITH_BACKGROUND   //Uncomment to apply a background to widget (for debug purposes only)


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Meter/CMeter.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <touchgfx/Color.hpp>
#include <touchgfx/Bitmap.hpp>
#include <CDisplay.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMeter::CMeter()
{
#ifdef CMETER_WITH_BACKGROUND
	add(background);
	background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
#endif
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeter::addTo(Container& c)
{
	dsp.add(c, *this);

	if(integer)   dsp.add(*this, *integer);
	if(decimal)   dsp.add(*this, *decimal);
	if(unit)      dsp.add(*this, *unit);
	if(dot)       dsp.add(*this, *dot);
	if(image)     dsp.add(*this, *image);
}

//-----------------------------------------------------------------------------
void CMeter::addInteger(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
	integer = new CMeterValue(newPrecision, newSpacingRatio, touchgfx::TypedText(newTypedText), newColorR, newColorG, newColorB);
//	add(*integer);
}

//-----------------------------------------------------------------------------
void CMeter::addDecimal(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
	decimal = new CMeterValue(newPrecision, newSpacingRatio, touchgfx::TypedText(newTypedText), newColorR, newColorG, newColorB);
//	add(*decimal);
}

//-----------------------------------------------------------------------------
void CMeter::addUnit(const TypedText& newTypedTextC, const TypedText& newTypedTextF, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
//	unit = new TextArea;
	unit = new CText(2);
	unit->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
	unitTempC = newTypedTextC;
	unitTempF = newTypedTextF;
//	add(*unit);
}

void CMeter::addUnit(const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
//	unit = new TextArea;
	unit = new CText(1);
	unit->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
	unit->setTypedText(touchgfx::TypedText(newTypedText));
//	add(*unit);
}

//-----------------------------------------------------------------------------
void CMeter::addDot(const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
//	dot = new TextArea;
	dot = new CText(1);
	dot->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
	dot->setTypedText(touchgfx::TypedText(newTypedText));
//	add(*dot);
}

//-----------------------------------------------------------------------------
void CMeter::addImage(const Bitmap& bmp)
{
	image = new CImage;
	image->setBitmap(bmp);
//	add(*image);
}

//-----------------------------------------------------------------------------
void CMeter::resizeBackground()
{
#ifdef CMETER_WITH_BACKGROUND
	background.setWidthHeight(*this);
#endif
}





//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMeter::CMeterValue::CMeterValue(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& nexTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
//	precision = newPrecision;
//	spacingRatio = newSpacingRatio;
//	textType = nexTypedText;
//
//	digits = (CMeterDigit**)malloc(sizeof(CMeterDigit*) * precision);
//	for(uint8_t i = 0; i < precision; i++)
//	{
//		digits[i] = new CMeterDigit;
//		digits[i]->widget.setTypedText(textType);
//		digits[i]->widget.setWildcard(digits[i]->buffer);
//		digits[i]->widget.setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
//		add(digits[i]->widget);
//	}
//
//	valueString = (char*)calloc(precision + 1, sizeof(char));
//
//	Container::setHeight(textType.getFont()->getFontHeight());

	precision = newPrecision;
	spacingRatio = newSpacingRatio;
	textType = nexTypedText;

	digits = (CText**)malloc(sizeof(CText*) * precision);
	for(uint8_t i = 0; i < precision; i++)
	{
		digits[i] = new CText(1);
		digits[i]->setTypedText(textType);
		digits[i]->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
		add(*digits[i]);
//		dsp.add(*this, *digits[i]);
	}

	valueString = (char*)calloc(precision + 1, sizeof(char));

	Container::setHeight(textType.getFont()->getFontHeight());

	back.setPosition(*this);
	Container::add(back);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeter::CMeterValue::display(int16_t value)
{
//	int len;
//	int16_t newWidth;
//	int16_t spacingWidth;
//	char* valPtr;
//	CMeterDigit* digPtr;
//	CMeterDigit** dspPtr;
//	const GlyphNode* glyph;
//
//	sprintf(valueString, "%d", value);
//	len = strlen(valueString);
//
//	newWidth = 0;
//	if(spacingRatio != 0)
//	{
//		spacingWidth = textType.getFont()->getFontHeight() / spacingRatio;
//		newWidth = spacingWidth;
//	}
//
//	maxGlyphHeight = 0;
//
//	valPtr = &valueString[len - 1];
//	dspPtr = &digits[precision - 1];
//	for(int i = 0; i < len; i++)
//	{
//		digPtr = *dspPtr;
//		Unicode::fromUTF8((uint8_t*)valPtr, digPtr->buffer, 1);
//		digPtr->widget.resizeToCurrentText();
//
//		glyph = textType.getFont()->getGlyph(digPtr->buffer[0]);
//
//		if(glyph->top() > maxGlyphHeight)
//			maxGlyphHeight = glyph->top();
//
//		if(spacingRatio == 0)
//			newWidth += digPtr->widget.getWidth();
//		else
//			newWidth += glyph->width() + spacingWidth;
//
//		valPtr--;
//		dspPtr--;
//	}
//
//	Container::setWidth(newWidth);
//
//	if(spacingRatio != 0)
//		newWidth -= spacingWidth;
//
//	dspPtr = &digits[precision - 1];
//	for(int i = 0; i < len; i++)
//	{
//		digPtr = *dspPtr;
//		if(spacingRatio == 0)
//		{
//			newWidth -= digPtr->widget.getWidth();
//			digPtr->widget.setXY(newWidth, Container::getHeight() - digPtr->widget.getHeight());
//		}
//		else
//		{
//			glyph = textType.getFont()->getGlyph(digPtr->buffer[0]);
//			newWidth -= glyph->width();
//			digPtr->widget.setXY(newWidth - glyph->left, Container::getHeight() - digPtr->widget.getHeight());
//			newWidth -= spacingWidth;
//		}
//
//		dspPtr--;
//	}

	int len;
//	int16_t newWidth;
	int16_t spacingWidth;
//	char* valPtr;
//	CText* digPtr;
//	CText** dspPtr;
//	const GlyphNode* glyph;

	sprintf(valueString, "%d", value);
	len = strlen(valueString);

	newWidth = 0;
	if(spacingRatio != 0)
	{
		spacingWidth = textType.getFont()->getFontHeight() / spacingRatio;
		newWidth = spacingWidth;
	}

	maxGlyphHeight = 0;

//	valPtr = &valueString[len - 1];
//	dspPtr = &digits[precision - 1];
//	for(int i = 0; i < len; i++)
//	{
//		digPtr = *dspPtr;
//		digPtr->setCharAt(0, *valPtr);
////		Unicode::fromUTF8((uint8_t*)valPtr, digPtr->buffer, 1);
//		digPtr->resizeToCurrentText();
//
//		glyph = digPtr->getCharGlyph(0);
////		glyph = textType.getFont()->getGlyph(digPtr->buffer[0]);
//
//		if(glyph->top() > maxGlyphHeight)
//			maxGlyphHeight = glyph->top();
//
//		if(spacingRatio == 0)
//			newWidth += digPtr->getWidth();
//		else
//			newWidth += glyph->width() + spacingWidth;
//
//		valPtr--;
//		dspPtr--;
//	}

//	valPtr = &valueString[0];
//	dspPtr = &digits[0];
//	for(int i = 0; i < len; i++)
//	{
//		digPtr = *dspPtr;
//		digPtr->setCharAt(0, *valPtr);
////		Unicode::fromUTF8((uint8_t*)valPtr, digPtr->buffer, 1);
//		digPtr->resizeToCurrentText();
//
//		glyph = digPtr->getCharGlyph(0);
////		glyph = textType.getFont()->getGlyph(digPtr->buffer[0]);
//
//		if(glyph->top() > maxGlyphHeight)
//			maxGlyphHeight = glyph->top();
//
//		if(spacingRatio == 0)
//			newWidth += digPtr->getWidth();
//		else
//			newWidth += glyph->width() + spacingWidth;
//
//		valPtr++;
//		dspPtr++;
//	}

	newWidth = 0;
	for(int i = 0; i < len; i++)
	{
		digits[i]->setCharAt(0, valueString[i]);
		newWidth += digits[i]->getWidth();
	}

	Container::setWidth(newWidth);

//	if(spacingRatio != 0)
//		newWidth -= spacingWidth;

//	dspPtr = &digits[precision - 1];
//	for(int i = 0; i < len; i++)
//	{
//		digPtr = *dspPtr;
//		if(spacingRatio == 0)
//		{
//			newWidth -= digPtr->getWidth();
//			digPtr->setXY(newWidth, Container::getHeight() - digPtr->getHeight());
//		}
//		else
//		{
//			glyph = digPtr->getCharGlyph(0);
////			glyph = textType.getFont()->getGlyph(digPtr->buffer[0]);
//			newWidth -= glyph->width();
//			digPtr->setXY(newWidth - glyph->left, Container::getHeight() - digPtr->getHeight());
//			newWidth -= spacingWidth;
//		}
//
//		dspPtr--;
//	}

//	dspPtr = &digits[0];
//	for(int i = 0; i < len; i++)
//	{
//		digPtr = *dspPtr;
//		if(spacingRatio == 0)
//		{
//			newWidth -= digPtr->getWidth();
//			digPtr->setXY(newWidth, Container::getHeight() - digPtr->getHeight());
//		}
//		else
//		{
//			glyph = digPtr->getCharGlyph(0);
////			glyph = textType.getFont()->getGlyph(digPtr->buffer[0]);
//			newWidth -= glyph->width();
//			digPtr->setXY(newWidth - glyph->left, Container::getHeight() - digPtr->getHeight());
//			newWidth -= spacingWidth;
//		}
//
//		dspPtr++;
//	}

	newWidth = 0;
//	trailingSpace = 0;
	int j = len - 1;
	for(int i = 0; i < 1/*len*/; i++)
	{
//		if(digits[j]->getCharGlyph(0)->left > trailingSpace)
//			trailingSpace = digits[j]->getCharGlyph(0)->left;

		digits[j]->setXY(newWidth, Container::getHeight() - digits[j]->getHeight());

		newWidth += (digits[j]->getWidth() - digits[j]->getCharGlyph(0)->left);

		j--;
	}

//	back.setPosition(*this);
//	back.setColor(touchgfx::Color::getColorFromRGB(86, 88, 90));
//	Container::setWidth(newWidth);
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

//-----------------------------------------------------------------------------
int16_t CMeter::CMeterValue::getWidth()
{
	return newWidth;
}

}   //namespace touchgfx
