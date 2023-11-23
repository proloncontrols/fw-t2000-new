
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
//         File : CChar.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Font single character manipulation header file
//=============================================================================
#ifndef CCHAR_HPP
#define CCHAR_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CChar : public TextAreaWithOneWildcard
{
public:
	CChar();

	void setFont(const TypedText& textType);
	void setFontColor(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue);

	const Font* getFont();
	const GlyphNode* getGlyph();

	void setChar(char ch);

protected:
	Unicode::UnicodeChar buffer[2];
};

};   //namespace touchgfx


#endif   //CCHAR_HPP
