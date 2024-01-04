
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
//-----------------------------------------------------------------------------
//         File : CText.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Manipulated text class implementation file
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
//  CText
//-----------------------------------------------------------------------------
//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CText::CText(int newMaxLength, int newSpacingRatio, const TypedText& newType, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
//	background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
//	add(background);

	maxLength = newMaxLength;

	spacingWidth = 0;
	if(newSpacingRatio != 0)
		spacingWidth = newType.getFont()->getFontHeight() / newSpacingRatio;

	type = newType;

	digits = (CDigit**)malloc(maxLength * sizeof(CDigit*));   //precision MUST include the minus sign
	for(int i = 0; i < maxLength; i++)
	{
		digits[i] = new CDigit(newType, newColorR, newColorG, newColorB);
		add(*digits[i]);
	}

	curLength = 0;
}


//=============================================================================
//  O P E R A T O R S
//-----------------------------------------------------------------------------
void CText::operator=(const char* newText)
{
	int len;
	int16_t maximumTop;
	int16_t totalWidth = 0;

	len = strlen(newText);
	if(len <= maxLength)
	{
		for(int i = 0; i < maxLength; i++)
			digits[i]->setDigit(0);

		for(int i = 0; i < len; i++)
		{
			digits[i]->setDigit(newText[i]);
			digits[i]->setX(totalWidth);
			totalWidth += digits[i]->getWidth();
			totalWidth += spacingWidth;
		}
		Container::setWidth(totalWidth);

		maximumTop = 0;
		for(int i = 0; i < len; i++)
		{
			if(digits[i]->getGlyph()->top() > maximumTop)
				maximumTop = digits[i]->getGlyph()->top();
		}
		for(int i = 0; i < len; i++)
			digits[i]->setY((type.getFont()->getFontHeight() - maximumTop) * -1);
		Container::setHeight(digits[0]->getHeight() - (type.getFont()->getFontHeight() - maximumTop));

		curLength = len;

//		background.setWidthHeight(*this);
	}
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CText::render()
{
//	dsp.setPosition(*this, *this);
	for(int i = 0; i < curLength; i++)
		digits[i]->render();
	Container::invalidate();
}

//-----------------------------------------------------------------------------
int16_t CText::getBaseline()
{
	return digits[0]->getHeight() - type.getFont()->getFontHeight();
}

//-----------------------------------------------------------------------------
int CText::getLength()
{
	return curLength;
}





//=============================================================================
//  CText::CDigit
//-----------------------------------------------------------------------------
//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CText::CDigit::CDigit(const TypedText& newType, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
//	background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
//	add(background);

	if(dsp.orientation != CDisplay::NATIVE)
		area.setRotation(TEXT_ROTATE_180);
	area.setColor(Color::getColorFromRGB(newColorR, newColorG, newColorB));
	area.setTypedText(newType);
	area.setWildcard(buffer);
	add(area);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CText::CDigit::setDigit(const char newDigit)
{
	Unicode::fromUTF8((uint8_t*)&newDigit, buffer, 1);
	buffer[1] = 0;

	area.resizeToCurrentText();

	const GlyphNode* node = getGlyph();
	if(dsp.orientation == CDisplay::NATIVE)
		area.setXY(node->left * -1, 0);
	else
		area.setXY((area.getWidth() - node->width() - node->left) * -1, 0);
	Container::setWidthHeight(area.getWidth() - (area.getWidth() - node->width()), area.getHeight());

//	background.setWidthHeight(*this);
}

//-----------------------------------------------------------------------------
void CText::CDigit::render()
{
//	dsp.setPosition(*this, *this);
}

//-----------------------------------------------------------------------------
const Font* CText::CDigit::getFont()
{
	return area.getTypedText().getFont();
}

//-----------------------------------------------------------------------------
const GlyphNode* CText::CDigit::getGlyph()
{
	return getFont()->getGlyph(buffer[0]);
}

}   //namespace touchgfx
