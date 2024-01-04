
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
//-----------------------------------------------------------------------------
//         File : CButtonToggle.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Toggle button class header file
//=============================================================================
#ifndef CBUTTON_TOGGLE_HPP
#define CBUTTON_TOGGLE_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CButton.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CButtonToggle : public CButton
{
	bool state;

protected:
	virtual void handleClickEvent(const ClickEvent& event);

public:
	CButtonToggle();

	void setState(bool newState);
	bool getState();
};

}   //namespace touchgfx


#endif   //CBUTTON_TOGGLE_HPP
