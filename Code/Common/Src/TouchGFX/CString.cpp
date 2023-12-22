
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
//  Description : Basic string class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <CString.hpp>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CString::CString()
{
	curLength = 0;
	buffer = NULL;
	if(dsp.orientation != CDisplay::NATIVE)
		setRotation(TEXT_ROTATE_180);
}


//=============================================================================
//  O P E R A T O R S
//-----------------------------------------------------------------------------
void CString::operator=(const char* newString)
{
	int newLen = strlen(newString);
	if(newLen > curLength)
	{
		if(buffer)
			free(buffer);
		buffer = (Unicode::UnicodeChar*)malloc((newLen + 1) * sizeof(Unicode::UnicodeChar));   //+1 = null termination character
		setWildcard(buffer);
	}
	curLength = newLen;
	memset(buffer, 0, (curLength + 1) * sizeof(Unicode::UnicodeChar));
	Unicode::fromUTF8((uint8_t*)newString, buffer, newLen);
	resizeToCurrentText();
	invalidate();
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CString::initialize(const TypedText& newType, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
	setColor(Color::getColorFromRGB(newColorR, newColorG, newColorB));
	setTypedText(newType);
}

//-----------------------------------------------------------------------------
void CString::render()
{
//	dsp.setPosition(*this, *this);
}

}   //namespace touchgfx
