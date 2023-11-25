
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
//         File : CMeterInt.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Interior temperature meter class header file
//=============================================================================
#ifndef CMETER_INT_HPP
#define CMETER_INT_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CMeterTemp.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMeterInt : public CMeterTemp
{
public:
	CMeterInt();

protected:
	static const uint8_t colorR = 186;
	static const uint8_t colorG = 188;
	static const uint8_t colorB = 190;

	static const uint8_t intPrecision = 4;   //Up to 3 digits integer and minus sign
	static const uint8_t decPrecision = 1;   //1 digit decimal

	static const uint8_t intCharSpacingRation = 15;
	static const uint8_t decCharSpacingRation = 15;

	static const TypedTextId intText   = T_METER_HUGE_DIGITS;
	static const TypedTextId dotText   = T_METER_MEDIUM_DOT;
	static const TypedTextId decText   = T_METER_MEDIUM_DIGITS;
	static const TypedTextId unitCText = T_METER_MEDIUM_UNIT_C;
	static const TypedTextId unitFText = T_METER_MEDIUM_UNIT_F;
};

}   //namespace touchgfx


#endif   //CMETER_INT_HPP
