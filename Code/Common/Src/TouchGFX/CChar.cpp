
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
//         File : CChar.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Font single character manipulation implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CChar.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------


//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CChar::CChar()
{
	setWildcard(buffer);
}


//=============================================================================
//  M E T H O D E S
//-----------------------------------------------------------------------------
void CChar::setFont(const TypedText& textType)
{
	setTypedText(textType);
}

//-----------------------------------------------------------------------------
void CChar::setFontColor(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue)
{
	setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
}

//-----------------------------------------------------------------------------
const Font* CChar::getFont()
{
	return getTypedText().getFont();
}

//-----------------------------------------------------------------------------
const GlyphNode* CChar::getGlyph()
{
	return getFont()->getGlyph(buffer[0]);
}

//-----------------------------------------------------------------------------
void CChar::setChar(char ch)
{
	Unicode::fromUTF8((uint8_t*)&ch, buffer, 1);
	resizeToCurrentText();
}

};   //namespace touchgfx
