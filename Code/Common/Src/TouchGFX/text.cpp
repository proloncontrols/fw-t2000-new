
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
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CText::CText(touchgfx::TextArea& Text)
    : CWidget(Text),
	  m_Text { Text }
{
}

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
touchgfx::Rect CText::getRect()
{
	return m_Text.getRect();
}

void CText::initialize()
{
//	CRect initialRect;
//	getRect(initialRect);

//	touchgfx::TextRotation rotation = touchgfx::TEXT_ROTATE_0;
//	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//		rotation = touchgfx::TEXT_ROTATE_270;
//
//	m_Text.setPosition(initialRect.x, initialRect.y, initialRect.width, initialRect.height);
//	m_Text.setRotation(rotation);


//	CRect* rect = getRect();
//
//	touchgfx::TextRotation rotation = touchgfx::TEXT_ROTATE_0;
//	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//		rotation = touchgfx::TEXT_ROTATE_270;
//
//	m_Text.setPosition(rect->x, rect->y, rect->width, rect->height);
//	m_Text.setRotation(rotation);
};

//-----------------------------------------------------------------------------
void CText::getPosition(CRect& rect)
{
	rect = vRect;
//	rect = m_Text.getRect();
};

//-----------------------------------------------------------------------------
void CText::setPosition(CRect& rect)
{
	vRect = rect;
	formatRect();
	m_Text.setPosition(fRect.x, fRect.y, fRect.width, fRect.height);

	//	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//		convertRectTo270deg(rect);
//
//	m_Text.setPosition(rect.x, rect.y, rect.width, rect.height);
};
