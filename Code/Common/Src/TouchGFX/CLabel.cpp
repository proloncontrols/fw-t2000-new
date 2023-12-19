
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
//         File : CLabel.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Fixed text class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CLabel.hpp>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CLabel::CLabel(const TypedText& newType, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
{
	if(dsp.orientation != CDisplay::NATIVE)
		setRotation(TEXT_ROTATE_180);
	setColor(Color::getColorFromRGB(newColorR, newColorG, newColorB));
	setTypedText(newType);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CLabel::render()
{
	dsp.setPosition(*this, *this);
}

}   //namespace touchgfx
