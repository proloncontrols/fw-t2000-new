
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
//         File : CMeter.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Meter widget class header file
//=============================================================================
#ifndef CMETER_HPP
#define CMETER_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMeter : public Container
{
public:
	CMeter(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& text);
	virtual void display(double value);

protected:
    touchgfx::TextAreaWithOneWildcard txtSign;
    static const uint16_t TXT_SIGN_SIZE = 2;
    touchgfx::Unicode::UnicodeChar txtSignBuffer[TXT_SIGN_SIZE];

    touchgfx::TextAreaWithOneWildcard txtIntegralHundreds;
    static const uint16_t TXT_INTEGRAL_HUNDREDS_SIZE = 2;
    touchgfx::Unicode::UnicodeChar txtIntegralHundredsBuffer[TXT_INTEGRAL_HUNDREDS_SIZE];

    touchgfx::TextAreaWithOneWildcard txtIntegralTenths;
    static const uint16_t TXT_INTEGRAL_TENTHS_SIZE = 2;
    touchgfx::Unicode::UnicodeChar txtIntegralTenthsBuffer[TXT_INTEGRAL_TENTHS_SIZE];

    touchgfx::TextAreaWithOneWildcard txtIntegralUnits;
    static const uint16_t TXT_INTEGRAL_UNITS_SIZE = 2;
    touchgfx::Unicode::UnicodeChar txtIntegralUnitsBuffer[TXT_INTEGRAL_UNITS_SIZE];

    touchgfx::TextAreaWithOneWildcard txtFractional;
    static const uint16_t TXT_FRACTIONAL_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtFractionalBuffer[TXT_FRACTIONAL_SIZE];
};

}   //namespace touchgfx


#endif   //CMETER_HPP
