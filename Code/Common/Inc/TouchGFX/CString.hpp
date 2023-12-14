
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
//         File : CString.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Basic string class header file
//=============================================================================
#ifndef CSTRING_HPP
#define CSTRING_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CString : public TextAreaWithOneWildcard
{
public:
	CString(const TypedText& newType, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);

	void operator=(const char* newString);

private:
	int curLength = 0;
	Unicode::UnicodeChar* buffer = NULL;
};

}   //namespace touchgfx


#endif   //CSTRING_HPP
