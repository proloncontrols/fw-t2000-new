
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
//         File : CButton.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX button widget class/tools header file
//=============================================================================
#ifndef WIDGET_BUTTON_HPP
#define WIDGET_BUTTON_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CWidget.hpp>

#include "CButtonCustom.hpp"

namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
//class CButtonTrigger : public ClickButtonTrigger
//{
//    virtual void handleClickEvent(const ClickEvent& event)
//    {
//    	ClickButtonTrigger::handleClickEvent(event);
//    }
//};



//class CButtonCustom : public BoxWithBorderButtonStyle< ClickButtonTrigger >
//{
//public:
//	CButtonCustom();
//
//    virtual void handleClickEvent(const ClickEvent& event) override;
//};

//class CButton : public CWidget, BoxWithBorderButtonStyle< ClickButtonTrigger >
//{
//public:
//	CButton(BoxWithBorderButtonStyle< ClickButtonTrigger >& button);
//
//	virtual void position();
//	virtual void getPosition(Rect& rect);
//	virtual void setPosition(Rect& rect);
//
////protected:
//    virtual void handleClickEvent(const ClickEvent& event) override;
//
//private:
//	BoxWithBorderButtonStyle< ClickButtonTrigger >& m_Button;
//};

class CButton : public CWidget
{
public:
	CButton(CButtonCustom& button);

	virtual void position();
	virtual void getPosition(Rect& rect);
	virtual void setPosition(Rect& rect);

private:
	CButtonCustom& m_Button;
};


}   //namespace touchgfx


#endif   //WIDGET_BUTTON_HPP

























