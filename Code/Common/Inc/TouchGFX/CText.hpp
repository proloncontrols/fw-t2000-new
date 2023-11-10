
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
//         File : CText.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX text widget class header file
//=============================================================================
#ifndef WIDGET_TEXT_HPP
#define WIDGET_TEXT_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CWidget.hpp>
#include <touchgfx/widgets/TextArea.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CText : public CWidget
{
public:
	CText(TextArea& text);

	virtual void position();
	virtual void getPosition(Rect& rect);
	virtual void setPosition(Rect& rect);

private:
	TextArea& m_Text;
};

}   //namespace touchgfx


#endif   //WIDGET_TEXT_HPP
