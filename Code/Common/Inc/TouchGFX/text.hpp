
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
//         File : text.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX text class/tools header file
//=============================================================================
#ifndef TXT_H
#define TXT_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "widget.hpp"


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CText : public CWidget
{
private:
	touchgfx::TextArea& m_Text;

public:
	CText(touchgfx::TextArea& Text);

	virtual touchgfx::Rect getRect();
	virtual void initialize();
	virtual void getPosition(CRect& rect);
	virtual void setPosition(CRect& rect);
};


#endif   //TXT_H
