
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
//         File : CText.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Text class header file
//=============================================================================
#ifndef CTEXT_HPP
#define CTEXT_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stddef.h>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CText : public TextAreaWithOneWildcard
{
public:
	CText(int initialLength);

	void setXY(int16_t x, int16_t y);
	void setText(const char* newText);
	void setLength(int newLength);

private:
	int curLength = 0;
	Unicode::UnicodeChar* buffer = NULL;
};

}   //namespace touchgfx


#endif   //CTEXT_HPP
