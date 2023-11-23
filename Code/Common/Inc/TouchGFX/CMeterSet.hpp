
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
//         File : CMeterSet.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Setpoint temperature meter class header file
//=============================================================================
#ifndef CMETER_SET_HPP
#define CMETER_SET_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CMeter.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMeterSet : public CMeter
{
public:
	CMeterSet();
	void display(double value);

private:
	static const TypedTextId intText = T_METER_LARGE_DIGITS;
	static const TypedTextId dotText = T_METER_SMALL_DOT;
	static const TypedTextId decText = T_METER_SMALL_DIGITS;

	static const uint8_t intCharSpacingRation = 15;
	static const uint8_t decCharSpacingRation = 15;

	static const uint8_t colorR = 186;
	static const uint8_t colorG = 188;
	static const uint8_t colorB = 190;

	static const uint8_t intPrecision = 4;   //Up to 3 digits integer and minus sign
	static const uint8_t decPrecision = 1;   //1 digit decimal

	CChar intString[intPrecision];
	CChar decString[decPrecision];

	TextArea dot;
};

}   //namespace touchgfx


#endif   //CMETER_EXT_HPP
