
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


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CText::CText(int capacity)
{
	curCapacity = capacity;
	buffer = (Unicode::UnicodeChar*)calloc(curCapacity + 1, sizeof(Unicode::UnicodeChar));   //+1 = null termination character
	setWildcard(buffer);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CText::addTo(Container& c)
{
	dsp.add(c, *this);
}

//-----------------------------------------------------------------------------
void CText::setXY(int16_t x, int16_t y)
{
	setRotation(TEXT_ROTATE_180);
	TextAreaWithOneWildcard::setXY(x, y);
}

//-----------------------------------------------------------------------------
void CText::operator=(const char* newText)
{
	int newLen = strlen(newText);

	if(newLen > curCapacity)
	{
		free(buffer);
		buffer = (Unicode::UnicodeChar*)malloc((newLen + 1) * sizeof(Unicode::UnicodeChar));   //+1 = null termination character
	}
	curCapacity = newLen;
	memset(buffer, 0, curCapacity * sizeof(Unicode::UnicodeChar));

	Unicode::fromUTF8((uint8_t*)newText, buffer, strlen(newText));
	resizeToCurrentText();
}

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

//-----------------------------------------------------------------------------
char CText::getCharAt(int index)
{
	char c = 0;

	if(index < curCapacity)
		Unicode::toUTF8(&buffer[index], (uint8_t*)&c, 1);

	return c;
}

//-----------------------------------------------------------------------------
void CText::setCharAt(int index, char newChar)
{
	if(index < curCapacity)
	{
		Unicode::fromUTF8((uint8_t*)&newChar, &buffer[index], 1);
		resizeToCurrentText();
	}
}

//-----------------------------------------------------------------------------
const Font* CText::getTextFont()
{
	return typedText.getFont();
}

//-----------------------------------------------------------------------------
const GlyphNode* CText::getCharGlyph(int index)
{
	if(index >= curCapacity)
		index = 0;

	return getTextFont()->getGlyph(buffer[index]);
}

}   //namespace touchgfx































