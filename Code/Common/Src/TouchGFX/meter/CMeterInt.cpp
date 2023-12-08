
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
//         File : CMeterInt.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Interior temperature meter class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Meter/CMeterInt.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMeterInt::CMeterInt()
{
//	addInteger(intPrecision, intCharSpacingRatio, touchgfx::TypedText(intText), colorR, colorG, colorB);
//	addDecimal(decPrecision, decCharSpacingRatio, touchgfx::TypedText(decText), colorR, colorG, colorB);
	addInteger(intPrecision, intCharSpacingRatio, intText, colorR, colorG, colorB);
	addDecimal(decPrecision, decCharSpacingRatio, decText, colorR, colorG, colorB);
	addUnit(unitCText, unitFText, colorR, colorG, colorB);
	addDot(dotText, colorR, colorG, colorB);

	Container::setHeight(MAX(touchgfx::TypedText(intText).getFont()->getFontHeight(), touchgfx::TypedText(decText).getFont()->getFontHeight()));
}

}   //namespace touchgfx
