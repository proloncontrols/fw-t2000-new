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
////         File : CMeter.cpp
////         Date : -----------
////       Author : Jean-Francois Barriere
////-----------------------------------------------------------------------------
////  Description : TouchGFX widget class implementation file
////=============================================================================
//
//
//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CMeter.hpp>
//#include <stdio.h>
//#include <string.h>
//#include <CMeter.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
//CMeterDigit::CMeterDigit()
//{
//}



CMeterValue::CMeterValue()
{
}



CMeter::CMeter()
{
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//char CMeterDigit::getDigit()
//{
//	uint8_t digit;
//	Unicode::toUTF8(buffer, &digit, 1);
//	return (char)digit;
//}
//
//void CMeterDigit::setDigit(char digit)
//{
//	Unicode::fromUTF8((uint8_t*)&digit, buffer, 1);
//}
//
//const Font* CMeterDigit::getFont()
//{
//	return widget.getTypedText().getFont();
//}
//
//const GlyphNode* CMeterDigit::getGlyph()
//{
//	return getFont()->getGlyph(buffer[0]);
//}
//
//touchgfx::TextAreaWithOneWildcard& CMeterDigit::getWidget()
//{
//	return widget;
//}
//
//touchgfx::Unicode::UnicodeChar* CMeterDigit::getBuffer()
//{
//	return buffer;
//}



void CMeterValue::initialize(int maxLen, uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& text)
{
	value = (CMeterDigit*)(sizeof(CMeterDigit) * maxLen);

	for(int i = 0; i < maxLen; i++)
	{
		value[i].getWidget().setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
		value[i].getBuffer()[0] = 0;
		value[i].getWidget().setWildcard(value[i].getBuffer());
		value[i].getWidget().setTypedText(text);
	}
}

const Font* CMeterValue::getFont()
{
	return text.getFont();
}

void CMeter::initialize(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& textIntegral, const TypedText& textFractional)
{
}









//void CMeter::display(double value)
//{
//	int strLength;
//	int virtualWidth;
//	char* strPtr;
//	DisplayChar* dspPtr;
//	const GlyphNode* glyph;
//	char strValue[DISPLAY_LENGTH + 1];
//
//
//	if((value < -999.9) || (value > 999.9))
//		value = 0.0;
//
//	sprintf(strValue, "%.1f", value);
//	strLength = strlen(strValue);
//	if(!displayFractional)
//		strLength -= 2;
//
//	virtualWidth = 0;
//	strPtr = &strValue[strLength - 1];
//	dspPtr = &displayString[DISPLAY_LENGTH - 1];
//	for(int i = 0; i < strLength; i++)
//	{
//		Unicode::fromUTF8((uint8_t*)strPtr, dspPtr->buffer, 1);
//		glyph = dspPtr->widget.getTypedText().getFont()->getGlyph(dspPtr->buffer[0]);
//		dspPtr->widget.setWidth(glyph->left + glyph->width());
//		firstCharLeftWidth = glyph->left;
//		virtualWidth += dspPtr->widget.getWidth();
//		strPtr--;
//		dspPtr--;
//	}
//	setWidth(virtualWidth + firstCharLeftWidth);
//
//	dspPtr = &displayString[DISPLAY_LENGTH - 1];
//	for(int i = 0; i < strLength; i++)
//	{
//		virtualWidth -= dspPtr->widget.getWidth();
//		dspPtr->widget.setXY(virtualWidth, getHeight() - dspPtr->widget.getTypedText().getFont()->getFontHeight());
//		dspPtr->widget.invalidate();
//		dspPtr--;
//	}
//
//	background.setPosition(*this);
//}
//
//
////=============================================================================
////  P R O T E C T E D
////-----------------------------------------------------------------------------
//int16_t CMeter::getDotX()
//{
//	if(displayFractional)
//		return displayString[DISPLAY_LENGTH - 2].widget.getX();
//
//	return getWidth();
//}
//
////-----------------------------------------------------------------------------
//void CMeter::setBaseline(int16_t base)
//{
//	for(int i = 0; i < DISPLAY_LENGTH; i++)
//		displayString[i].widget.setBaselineY(base);
//}

}   //namespace touchgfx







