
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
//         File : CMeterTempInt.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Interior temperature meter widget class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CMeterTempInt.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define COLOR_RED     120
#define COLOR_GREEN   14
#define COLOR_BLUE    14


//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CMeterTempInt::CMeterTempInt()
	: CMeterTemp(COLOR_RED, COLOR_GREEN, COLOR_BLUE, touchgfx::TypedText(T_T2000_METER_LARGE), touchgfx::TypedText(T_T2000_METER_SMALL))
{
	displayFractional = true;

    displayString[DISPLAY_LENGTH-1].widget.setTypedText(touchgfx::TypedText(T_T2000_METER_SMALL));
    displayString[DISPLAY_LENGTH-2].widget.setTypedText(touchgfx::TypedText(T_T2000_METER_SMALL));
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeterTempInt::display(double value, bool celsius)
{
	CMeterTemp::display(value, celsius);
}

}   //namespace touchgfx
