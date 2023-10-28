
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
//         File : text.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX text class/tools implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "text.hpp"


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CText::placeOnScreen()
{
	touchgfx::Rect* CurRect = getCurrentRect();

	touchgfx::TextRotation Rotation = touchgfx::TEXT_ROTATE_0;
	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
		Rotation = touchgfx::TEXT_ROTATE_270;

	m_Text.setPosition(CurRect->x, CurRect->y, CurRect->width, CurRect->height);
	m_Text.setRotation(Rotation);
};
