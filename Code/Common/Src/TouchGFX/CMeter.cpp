
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
//  Description : TouchGFX widget class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <CMeter.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CMeter::CMeter(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& textLarge, const TypedText& textSmall)
{
	displayFractional = false;

	setHeight(MAX(textLarge.getFont()->getFontHeight(), textSmall.getFont()->getFontHeight()));

	background.setPosition(*this);
	background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
	add(background);

	for(int i = 0; i < DISPLAY_LENGTH; i++)
	{
		displayString[i].widget.setXY(0, 0);
		displayString[i].widget.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
	    displayString[i].widget.setLinespacing(0);
	    displayString[i].buffer[0] = 0;
	    displayString[i].widget.setWildcard(displayString[i].buffer);
	    displayString[i].widget.resizeToCurrentText();
	    displayString[i].widget.setTypedText(textLarge);
	    add(displayString[i].widget);
	}
    displayString[DISPLAY_LENGTH-1].widget.setTypedText(textSmall);
    displayString[DISPLAY_LENGTH-2].widget.setTypedText(textSmall);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeter::display(double value)
{
	int strLength;
	int virtualWidth;
	int firstCharLeft;
	char* strPtr;
	DisplayChar* dspPtr;
	const GlyphNode* glyph;
	char strValue[DISPLAY_LENGTH + 1];


	if((value < -999.9) || (value > 999.9))
		value = 0.0;

	sprintf(strValue, "%.1f", value);
	strLength = strlen(strValue);
	if(!displayFractional)
		strLength -= 2;

	virtualWidth = 0;
	strPtr = &strValue[strLength - 1];
	dspPtr = &displayString[DISPLAY_LENGTH - 1];
	for(int i = 0; i < strLength; i++)
	{
		Unicode::fromUTF8((uint8_t*)strPtr, dspPtr->buffer, 1);
		glyph = dspPtr->widget.getTypedText().getFont()->getGlyph(dspPtr->buffer[0]);
		dspPtr->widget.setWidth(glyph->left + glyph->width());
		firstCharLeft = glyph->left;
		virtualWidth += dspPtr->widget.getWidth();
		strPtr--;
		dspPtr--;
	}
	setWidth(virtualWidth + firstCharLeft);

	dspPtr = &displayString[DISPLAY_LENGTH - 1];
	for(int i = 0; i < strLength; i++)
	{
		virtualWidth -= dspPtr->widget.getWidth();
		dspPtr->widget.setXY(virtualWidth, getHeight() - dspPtr->widget.getTypedText().getFont()->getFontHeight());
		dspPtr->widget.setBaselineY(dspPtr->widget.getHeight() - 10);
		dspPtr->widget.invalidate();
		dspPtr--;
	}

	background.setPosition(*this);
}

}   //namespace touchgfx



















































