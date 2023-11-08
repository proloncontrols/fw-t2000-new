
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
//         File : CButton.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX button widget class/tools implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "CButton.hpp"


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CButton::CButton(CButtonCustom& button)
	: CWidget(button),
	  m_Button(button)
{
}
//CButtonCustom::CButtonCustom()
//{
//}
////CButton::CButton(BoxWithBorderButtonStyle< ClickButtonTrigger >& button)
////	: CWidget(button),
////	  m_Button(button)
////{
////}
//int Tmp = 0;
//void CButtonCustom::handleClickEvent(const ClickEvent& event)
//{
//	Tmp++;
//}

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CButton::position()
{
//	Rect rect = CWidget::getRect(m_Button.getRect());
//
//	m_Button.setPosition(rect.x, rect.y, rect.width, rect.height);
};

//-----------------------------------------------------------------------------
void CButton::getPosition(Rect& rect)
{
};

//-----------------------------------------------------------------------------
void CButton::setPosition(Rect& rect)
{
};

}   //namespace touchgfx
