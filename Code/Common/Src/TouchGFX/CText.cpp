
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
//         File : CText.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Text class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <string.h>
#include <CText.hpp>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
//CText::CText(int capacity)
//{
//	curCapacity = capacity;
//
//	buffer = (Unicode::UnicodeChar*)calloc(curCapacity + 1, sizeof(Unicode::UnicodeChar));   //+1 = null termination character
//	text.setWildcard(buffer);
//
//	setColorFore(defaultForeColorR, defaultForeColorG, defaultForeColorB);
//	setColorBack(defaultBackColorR, defaultBackColorG, defaultBackColorB);
//}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//void CText::addTo(Container& c)
//{
//	dsp.add(c, *this);
//
//	dsp.add(*this, back);
//	dsp.add(*this, text);
//}

//-----------------------------------------------------------------------------
//void CText::setXY(int16_t x, int16_t y)
//{
////	text.setRotation(TEXT_ROTATE_180);
////	TextAreaWithOneWildcard::setXY(x, y);
//	Container::setXY(x, y);
//}

//-----------------------------------------------------------------------------
//void CText::setTypedText(const TypedText& type)
//{
//	text.setTypedText(type);
//}

//-----------------------------------------------------------------------------
//void CText::setColorFore(uint8_t colorR, uint8_t colorG, uint8_t colorB)
//{
//	text.setColor(Color::getColorFromRGB(colorR, colorG, colorB));
//}

//-----------------------------------------------------------------------------
//void CText::setColorBack(uint8_t colorR, uint8_t colorG, uint8_t colorB)
//{
//	back.setColor(Color::getColorFromRGB(colorR, colorG, colorB));
//}

//-----------------------------------------------------------------------------
//void CText::operator=(const char* newText)
//{
//	int newLen = strlen(newText);
//
//	if(newLen > curCapacity)
//	{
//		free(buffer);
//		buffer = (Unicode::UnicodeChar*)malloc((newLen + 1) * sizeof(Unicode::UnicodeChar));   //+1 = null termination character
//	}
//	curCapacity = newLen;
//	memset(buffer, 0, curCapacity * sizeof(Unicode::UnicodeChar));
//
//	Unicode::fromUTF8((uint8_t*)newText, buffer, strlen(newText));
//	text.resizeToCurrentText();
//
//	const GlyphNode* node = getCharGlyph(0);
//
//	text.setX(node->left * -1);
//
//	back.setWidthHeight(text.getWidth() - (text.getWidth() - node->width()), text.getHeight());
//	Container::setWidthHeight(text.getWidth() - (text.getWidth() - node->width()), text.getHeight());
//
////	back.setWidth(text.getWidth());
////	Container::setWidth(text.getWidth());
//}

//-----------------------------------------------------------------------------
//void CText::setText(const char* newText)
//{
//	int newLen = strlen(newText);
//
//	if(newLen > curCapacity)
//	{
//		free(buffer);
//		buffer = (Unicode::UnicodeChar*)malloc((newLen + 1) * sizeof(Unicode::UnicodeChar));   //+1 = null termination character
//	}
//	curCapacity = newLen;
//	memset(buffer, 0, curCapacity * sizeof(Unicode::UnicodeChar));
//
//	Unicode::fromUTF8((uint8_t*)newText, buffer, strlen(newText));
//	resizeToCurrentText();
//}

////-----------------------------------------------------------------------------
//char CText::getCharAt(int index)
//{
//	char c = 0;
//
//	if(index < curLength)
//		Unicode::toUTF8(&buffer[index], (uint8_t*)&c, 1);
//
//	return c;
//}
//
////-----------------------------------------------------------------------------
//void CText::setCharAt(int index, char newChar)
//{
//	if(index < curLength)
//	{
//		Unicode::fromUTF8((uint8_t*)&newChar, &buffer[index], 1);
////		resizeToCurrentText();
//	}
//}
//
////-----------------------------------------------------------------------------
//const Font* CText::getTextFont()
//{
//	return text.getTypedText().getFont();
//}
//
////-----------------------------------------------------------------------------
//const GlyphNode* CText::getCharGlyph(int index)
//{
//	if(index >= curLength)
//		index = 0;
//
//	return getTextFont()->getGlyph(buffer[index]);
//}





#include <stdio.h>


//CMeterDigit::CMeterDigit(const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
//{
//	CText::setTypedText(newTypedText);
//	CText::setColorFore(newColorR, newColorG, newColorB);
//}


CMeterValue::CMeterValue(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& nexTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
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
//		digits[i] = new CText(1);
//		digits[i]->setTypedText(textType);
//		digits[i]->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
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
int16_t width[4];
int16_t left[4];
void CMeterValue::update(int16_t value)
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
//		digits[i]->setCharAt(0, valueString[i]);

//		width[i] = digits[i]->getTextWidth();
//		left[i] = digits[i]->getCharGlyph(0)->left;

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
	for(int i = 0; i < len; i++)
	{
//		if(digits[j]->getCharGlyph(0)->left > trailingSpace)
//			trailingSpace = digits[j]->getCharGlyph(0)->left;

		digits[j]->setXY(newWidth, Container::getHeight() - digits[j]->getHeight());

//		newWidth += (digits[j]->getWidth() - digits[j]->getCharGlyph(0)->left);

		j--;
	}

//	back.setPosition(*this);
//	back.setColor(touchgfx::Color::getColorFromRGB(86, 88, 90));
//	Container::setWidth(newWidth);
}

//-----------------------------------------------------------------------------
uint8_t CMeterValue::getPrecision()
{
	return precision;
}

//-----------------------------------------------------------------------------
int16_t CMeterValue::getMaxGlyphHeight()
{
	return maxGlyphHeight;
}

//-----------------------------------------------------------------------------
int16_t CMeterValue::getWidth()
{
	return newWidth;
}





}   //namespace touchgfx































