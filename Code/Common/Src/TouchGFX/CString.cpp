
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
//         File : CString.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Array of CChar manipulation implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <string.h>
#include <CString.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CString::CString(CChar* array, int capacity, const TypedText& textType, uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue)
{
	strArray = array;
	strCapacity = capacity;
	charSpacingRatio = 0;
	charSpacingWidth = 0;

	for(int i = 0; i < strCapacity; i++)
	{
		add(strArray[i]);
		strArray[i].setTypedText(textType);
		strArray[i].setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
	}

	Container::setHeight(textType.getFont()->getFontHeight());
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CString::setCharSpacingRatio(uint8_t ratio)
{
	charSpacingRatio = ratio;
}

//-----------------------------------------------------------------------------
void CString::setText(const char* newText)
{
	int16_t len = strlen(newText);

	const char* newTextChar = &newText[len - 1];
	CChar* textChar = &strArray[strCapacity - 1];

	if(charSpacingRatio != 0)
		charSpacingWidth = textChar->getFont()->getFontHeight() / charSpacingRatio;

	int16_t newWidth = 0;
	if(charSpacingRatio != 0)
		newWidth = charSpacingWidth;

	for(int16_t i = 0; (i < len) && (i < strCapacity); i++)
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

	textChar = &strArray[strCapacity - 1];

	if(charSpacingRatio != 0)
		newWidth -= charSpacingWidth;

	for(int16_t i = 0; (i < len) && (i < strCapacity); i++)
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
}

}   //namespace touchgfx
