
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
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>


namespace touchgfx
{

//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define DISPLAY_LENGTH     6   //Maximum number of characters in the display string. Ex: "-100.0"
#define CHAR_BUFFER_SIZE   2   //TextArea wildcard buffer size "including null"

#define INTEGRAL_WEIGHT    3   //Hundreds, tenths and units


//=============================================================================
//  T Y P E D E F S
//-----------------------------------------------------------------------------
typedef struct {
    touchgfx::TextAreaWithOneWildcard widget;
    touchgfx::Unicode::UnicodeChar buffer[CHAR_BUFFER_SIZE];
} DisplayChar;


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMeter : public Container
{
public:
	CMeter(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& textLarge, const TypedText& textSmall);
	void display(double value);

protected:
    touchgfx::Box background;

    DisplayChar displayString[DISPLAY_LENGTH];




	bool displayFractional;

    static const uint16_t TXT_SIZE = 2;

    touchgfx::TextAreaWithOneWildcard txtSign;
    touchgfx::Unicode::UnicodeChar txtSignBuffer[TXT_SIZE];

    touchgfx::TextAreaWithOneWildcard txtIntegral[INTEGRAL_WEIGHT];
    touchgfx::Unicode::UnicodeChar txtIntegralBuffer[INTEGRAL_WEIGHT][TXT_SIZE];

//    touchgfx::TextAreaWithOneWildcard txtIntegralHundreds;
//    touchgfx::Unicode::UnicodeChar txtIntegralHundredsBuffer[TXT_SIZE];

//    touchgfx::TextAreaWithOneWildcard txtIntegralTenths;
//    touchgfx::Unicode::UnicodeChar txtIntegralTenthsBuffer[TXT_SIZE];

//    touchgfx::TextAreaWithOneWildcard txtIntegralUnits;
//    touchgfx::Unicode::UnicodeChar txtIntegralUnitsBuffer[TXT_SIZE];

    touchgfx::TextAreaWithOneWildcard txtDot;
    touchgfx::Unicode::UnicodeChar txtDotBuffer[TXT_SIZE];

    touchgfx::TextAreaWithOneWildcard txtFractional;
    touchgfx::Unicode::UnicodeChar txtFractionalBuffer[TXT_SIZE];
};

}   //namespace touchgfx


#endif   //CMETER_HPP
