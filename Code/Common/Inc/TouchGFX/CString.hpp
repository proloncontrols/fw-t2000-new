
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
//  Description : Array of CChar manipulation header file
//=============================================================================
#ifndef CSTRING_HPP
#define CSTRING_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CChar.hpp>
#include <touchgfx/Containers/Container.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CString : public Container
{
public:
	CString(CChar* array, int capacity, const TypedText& textType, uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue);
	void setCharSpacingRatio(uint8_t ratio);
	void setText(const char* newText);
	int16_t getMaxGlyphHeight();

private:
	CChar* strArray;
	int16_t strCapacity;
	uint8_t charSpacingRatio;
	int16_t charSpacingWidth;
	int16_t maxGlyphHeight;
};

}   //namespace touchgfx


#endif   //CSTRING_HPP
