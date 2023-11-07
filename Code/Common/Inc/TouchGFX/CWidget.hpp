
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
//         File : CWidget.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX widget class/tools header file
//=============================================================================
#ifndef WIDGET_HPP
#define WIDGET_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/widgets/Widget.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/buttons/BoxWithBorderButtonStyle.hpp>
#include <touchgfx/containers/buttons/ClickButtonTrigger.hpp>

#include "cfg.h"


namespace touchgfx
{

//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define SCREEN_WIDTH      720
#define SCREEN_HEIGHT     672
#define SCREEN_ANGLE      (-1.572f)   //Used for TextureMapper widget's Z angle
#define SCREEN_OFFSET     24
#define CLIENT_OFFSET     24
//
//
// Thermostat portrait orientation
//
//    Screen (landscape)
//    -------------------------------------   ---
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |     Client (square)     |    |   672
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    -------------------------------------   ---
//
//    |-24-|---------- 672 ----------|-24-|
//    |--------------- 720 ---------------|
//
//
//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CWidget
{
public:
	CWidget(Widget& widget) {};
	CWidget(BoxWithBorderButtonStyle< ClickButtonTrigger >& button) {};

	virtual void position() = 0;
	virtual void getPosition(Rect& rect) = 0;
	virtual void setPosition(Rect& rect) = 0;

protected:
	Rect curRect;

	Rect& getRect(const Rect& rect);
};

}   //namespace touchgfx


#endif   //WIDGET_HPP






























