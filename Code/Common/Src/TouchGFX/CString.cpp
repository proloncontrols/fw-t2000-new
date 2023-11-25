//
////=============================================================================
////         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
////         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
////         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
////         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
////         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
////         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
////         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
////
////                        (c) Copyright  2022-2023
////-----------------------------------------------------------------------------
////         File : CString.cpp
////         Date : -----------
////       Author : Jean-Francois Barriere
////-----------------------------------------------------------------------------
////  Description : Array of CChar manipulation implementation file
////=============================================================================
//
//
////=============================================================================
////  I N C L U D E S
////-----------------------------------------------------------------------------
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <CString.hpp>
//#include <touchgfx/Color.hpp>
//
//
//namespace touchgfx
//{
//
////=============================================================================
////  C O N S T R U C T I O N
////-----------------------------------------------------------------------------
//CString::CString(CChar* array, int capacity, const TypedText& textType, uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue)
//{
//	strArray = array;
//	strCapacity = capacity;
//	charSpacingRatio = 0;
//	charSpacingWidth = 0;
//
//	for(int i = 0; i < strCapacity; i++)
//	{
//		add(strArray[i]);
//		strArray[i].setTypedText(textType);
//		strArray[i].setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
//	}
//
//	Container::setHeight(textType.getFont()->getFontHeight());
//}
//
//
////=============================================================================
////  M E T H O D S
////-----------------------------------------------------------------------------
//void CString::setCharSpacingRatio(uint8_t ratio)
//{
//	charSpacingRatio = ratio;
//}
//
////-----------------------------------------------------------------------------
//void CString::setText(const char* newText)
//{
//	int16_t len = strlen(newText);
//
//	const char* newTextChar = &newText[len - 1];
//	CChar* textChar = &strArray[strCapacity - 1];
//
//	if(charSpacingRatio != 0)
//		charSpacingWidth = textChar->getFont()->getFontHeight() / charSpacingRatio;
//
//	maxGlyphHeight = 0;
//	int16_t newWidth = 0;
//	if(charSpacingRatio != 0)
//		newWidth = charSpacingWidth;
//
//	for(int16_t i = 0; (i < len) && (i < strCapacity); i++)
//	{
//		textChar->setChar(*newTextChar);
//		if(textChar->getGlyph()->top() > maxGlyphHeight)
//			maxGlyphHeight = textChar->getGlyph()->top();
//		if(charSpacingWidth == 0)
//			newWidth += textChar->getWidth();
//		else
//			newWidth += (textChar->getGlyph()->width() + charSpacingWidth);
//		newTextChar--;
//		textChar--;
//	}
//
//	Container::setWidth(newWidth);
//
//	textChar = &strArray[strCapacity - 1];
//
//	if(charSpacingRatio != 0)
//		newWidth -= charSpacingWidth;
//
//	for(int16_t i = 0; (i < len) && (i < strCapacity); i++)
//	{
//		if(charSpacingRatio == 0)
//		{
//			newWidth -= textChar->getWidth();
//			textChar->setXY(newWidth, Container::getHeight() - textChar->getHeight());
//		}
//		else
//		{
//			newWidth -= textChar->getGlyph()->width();
//			textChar->setXY(newWidth - textChar->getGlyph()->left, Container::getHeight() - textChar->getHeight());
//			newWidth -= charSpacingWidth;
//		}
//		textChar--;
//	}
//}
//
////-----------------------------------------------------------------------------
//int16_t CString::getMaxGlyphHeight()
//{
//	return maxGlyphHeight;
//}
//
//
//
//
//
//
//
//
//
//
//
//
////CMeterValue::CMeterValue(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTextType, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
////{
////	precision = newPrecision;
////	spacingRatio = newSpacingRatio;
////	textType = newTextType;
////
////	digits = (CMeterDigit**)malloc(sizeof(CMeterDigit*) * precision);
////	for(uint8_t i = 0; i < precision; i++)
////	{
////		digits[i] = new CMeterDigit;
////		digits[i]->widget.setTypedText(textType);
////		digits[i]->widget.setWildcard(digits[i]->buffer);
////		digits[i]->widget.setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
////		add(digits[i]->widget);
////	}
////
////	valueString = (char*)calloc(precision + 1, sizeof(char));
////
////	Container::setHeight(textType.getFont()->getFontHeight());
////}
////
////void CMeterValue::display(int16_t value)
////{
////	int len;
////	int16_t newWidth;
////	int16_t spacingWidth;
////	char* valPtr;
////	CMeterDigit* digPtr;
////	CMeterDigit** dspPtr;
////	const GlyphNode* glyph;
////
////	sprintf(valueString, "%d", value);
////	len = strlen(valueString);
////
////	newWidth = 0;
////	if(spacingRatio != 0)
////	{
////		spacingWidth = textType.getFont()->getFontHeight() / spacingRatio;
////		newWidth = spacingWidth;
////	}
////
////	maxGlyphHeight = 0;
////
////	valPtr = &valueString[len - 1];
////	dspPtr = &digits[precision - 1];
////	for(int i = 0; i < len; i++)
////	{
////		digPtr = *dspPtr;
////		Unicode::fromUTF8((uint8_t*)valPtr, digPtr->buffer, 1);
////		digPtr->widget.resizeToCurrentText();
////
////		glyph = textType.getFont()->getGlyph(digPtr->buffer[0]);
////
////		if(glyph->top() > maxGlyphHeight)
////			maxGlyphHeight = glyph->top();
////
////		if(spacingRatio == 0)
////			newWidth += digPtr->widget.getWidth();
////		else
////			newWidth += glyph->width() + spacingWidth;
////
////		valPtr--;
////		dspPtr--;
////	}
////
////	Container::setWidth(newWidth);
////
////	if(spacingRatio != 0)
////		newWidth -= spacingWidth;
////
////	dspPtr = &digits[precision - 1];
////	for(int i = 0; i < len; i++)
////	{
////		digPtr = *dspPtr;
////		if(spacingRatio == 0)
////		{
////			newWidth -= digPtr->widget.getWidth();
////			digPtr->widget.setXY(newWidth, Container::getHeight() - digPtr->widget.getHeight());
////		}
////		else
////		{
////			glyph = textType.getFont()->getGlyph(digPtr->buffer[0]);
////			newWidth -= glyph->width();
////			digPtr->widget.setXY(newWidth - glyph->left, Container::getHeight() - digPtr->widget.getHeight());
////			newWidth -= spacingWidth;
////		}
////
////		dspPtr--;
////	}
////}
////
////int16_t CMeterValue::getMaxGlyphHeight()
////{
////	return maxGlyphHeight;
////}
//
//
//
//
//
//
//
//
//
//
//
//
//}   //namespace touchgfx
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
