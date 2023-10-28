
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
//         File : button.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX button class/tools implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "button.hpp"


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CButton::placeOnScreen()
{
	touchgfx::Rect* CurRect = getCurrentRect();

	m_Button.setPosition(CurRect->x, CurRect->y, CurRect->width, CurRect->height);
};