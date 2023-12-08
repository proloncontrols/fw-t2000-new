
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
#include <Meter/CMeterTemp.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMeterSet : public CMeterTemp
{
public:
	CMeterSet();

protected:
	static const uint8_t colorR = 186;
	static const uint8_t colorG = 188;
	static const uint8_t colorB = 190;

	static const uint8_t intPrecision = 4;   //Up to 3 digits integer and minus sign
	static const uint8_t decPrecision = 1;   //1 digit decimal

	static const uint8_t intCharSpacingRatio = 15;
	static const uint8_t decCharSpacingRatio = 15;

	static const TypedTextId intText   = T_METER_LARGE;
	static const TypedTextId dotText   = T_METER_SMALL;
	static const TypedTextId decText   = T_METER_SMALL;
	static const TypedTextId unitCText = T_METER_SMALL;
	static const TypedTextId unitFText = T_METER_SMALL;
};

}   //namespace touchgfx


#endif   //CMETER_EXT_HPP
