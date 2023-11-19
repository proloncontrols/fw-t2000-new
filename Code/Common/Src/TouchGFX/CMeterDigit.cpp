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
////         File : CMeterDigit.cpp
////         Date : -----------
////       Author : Jean-Francois Barriere
////-----------------------------------------------------------------------------
////  Description : Meter digit class implementation file
////=============================================================================
//
//
//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CMeterDigit.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CMeterDigit::CMeterDigit()
{
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
char CMeterDigit::getDigit()
{
	uint8_t digit;
	Unicode::toUTF8(buffer, &digit, 1);
	return (char)digit;
}

//-----------------------------------------------------------------------------
void CMeterDigit::setDigit(char digit)
{
	Unicode::fromUTF8((uint8_t*)&digit, buffer, 1);
}

//-----------------------------------------------------------------------------
const Font* CMeterDigit::getFont()
{
	return widget.getTypedText().getFont();
}

//-----------------------------------------------------------------------------
const GlyphNode* CMeterDigit::getGlyph()
{
	return getFont()->getGlyph(buffer[0]);
}

//-----------------------------------------------------------------------------
touchgfx::TextAreaWithOneWildcard& CMeterDigit::getWidget()
{
	return widget;
}

//-----------------------------------------------------------------------------
touchgfx::Unicode::UnicodeChar* CMeterDigit::getBuffer()
{
	return buffer;
}

}   //namespace touchgfx
