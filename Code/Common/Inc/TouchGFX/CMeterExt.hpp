
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
//         File : CMeterExt.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Exterior temperature meter class header file
//=============================================================================
#ifndef CMETER_EXT_HPP
#define CMETER_EXT_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CMeter.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMeterExt : public CMeter
{
public:
	CMeterExt();
	void display(double Value, bool celsius);

protected:
	static const uint8_t colorR = 186;
	static const uint8_t colorG = 188;
	static const uint8_t colorB = 190;

	static const uint8_t intPrecision = 4;   //Up to 3 digits integer and minus sign

	static const uint8_t intCharSpacingRation = 15;

	static const TypedTextId intText   = T_METER_MEDIUM_DIGITS;
	static const TypedTextId unitCText = T_METER_TINY_UNIT_C;
	static const TypedTextId unitFText = T_METER_TINY_UNIT_F;

	static const uint16_t imageId = BITMAP_OUTSIDE_24X24_ID;
};

}   //namespace touchgfx


#endif   //CMETER_EXT_HPP
