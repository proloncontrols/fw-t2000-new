
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
//         File : CMeterDigit.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Meter digit class header file
//=============================================================================
#ifndef CMETER_DIGIT_HPP
#define CMETER_DIGIT_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>


namespace touchgfx
{

//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define DIGIT_BUFFER_SIZE   2   //TextArea wildcard buffer size "including null"


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMeterDigit
{
public:
	CMeterDigit();
	char getDigit();
	void setDigit(char digit);
	const Font* getFont();
	const GlyphNode* getGlyph();
	touchgfx::TextAreaWithOneWildcard& getWidget();
	touchgfx::Unicode::UnicodeChar* getBuffer();

private:
    touchgfx::TextAreaWithOneWildcard widget;
    touchgfx::Unicode::UnicodeChar buffer[DIGIT_BUFFER_SIZE];
};

}   //namespace touchgfx


#endif   //CMETER_DIGIT_HPP
