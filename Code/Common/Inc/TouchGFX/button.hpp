
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
//         File : button.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX button class/tools header file
//=============================================================================
#ifndef BTN_H
#define BTN_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "widget.hpp"


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CButton : public CWidget
{
private:
	touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& m_Button;

public:
	CButton(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& Button);

	virtual touchgfx::Rect getRect();
	virtual void place();
	virtual void getPosition(CRect& rect);
	virtual void setPosition(CRect& rect);
};


#endif   //BTN_H
