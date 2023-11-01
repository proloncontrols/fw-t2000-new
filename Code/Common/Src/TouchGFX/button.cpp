
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
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CButton::CButton(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& Button)
	: CWidget(Button),
	  m_Button { Button }
{
}

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
touchgfx::Rect CButton::getRect()
{
	return m_Button.getRect();
}

void CButton::place()
{
	CRect* rect = getCurRect();

	m_Button.setPosition(rect->x, rect->y, rect->width, rect->height);

//	CRect initialRect;
//	getRect(initialRect);
//	m_Button.setPosition(initialRect.x, initialRect.y, initialRect.width, initialRect.height);

//	CRect* rect = getRect();

//	m_Button.setPosition(rect->x, rect->y, rect->width, rect->height);

//	formatRect();
//	m_Button.setPosition(fRect.x, fRect.y, fRect.width, fRect.height);
};

//-----------------------------------------------------------------------------
void CButton::getPosition(CRect& rect)
{
	CRect curRect = (CRect&)m_Button.getRect();
	screenToClient(curRect);
	rect = curRect;

//	CRect widgetRect = (CRect&)m_Button.getRect();


//	rect = m_Button.getRect();
};

//-----------------------------------------------------------------------------
void CButton::setPosition(CRect& rect)
{
	CRect newRect = rect;
	clientToScreen(newRect);
	m_Button.setPosition(newRect.x, newRect.y, newRect.width, newRect.height);

//	vRect = rect;
//	formatRect();
//	m_Button.setPosition(fRect.x, fRect.y, fRect.width, fRect.height);
};





























