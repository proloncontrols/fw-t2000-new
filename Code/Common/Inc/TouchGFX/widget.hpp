
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
//         File : widget.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX widget class/tools header file
//=============================================================================
#ifndef WGT_H
#define WGT_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/widgets/Widget.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>
#include <touchgfx/containers/buttons/BoxWithBorderButtonStyle.hpp>
#include <touchgfx/containers/buttons/ClickButtonTrigger.hpp>

#include "cfg.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define SCREEN_WIDTH    720
#define SCREEN_HEIGHT   672
#define SCREEN_ANGLE    (-1.572f)   //Used for TextureMapper widget's Z angle
//
//
// Thermostat portrait orientation
//
//    LCD (landscape)
//    -------------------------------------   --- ---
//    |                                   |    24  |
//    |        -------------------        |   ---  |
//    |        |                 |        |    |   |
//    |        |                 |        |    |   |
//    |        |                 |        |    |   |
//    |        | Client (square) |        |   624 672
//    |        |                 |        |    |   |
//    |        |                 |        |    |   |
//    |        |                 |        |    |   |
//    |        -------------------        |   ---  |
//    |                                   |    24  |
//    -------------------------------------   --- ---
//
//    |-- 48 --|------ 624 ------|-- 48 --|
//    |--------------- 720 ---------------|
//
//
//The following defines are according to the thermostat orientation
#define CLIENT_OFFSET_PER   24   //Number of pixels creating an inside perimeter offset

#define CLIENT_ORIGIN_X_P   (((SCREEN_WIDTH - SCREEN_HEIGHT) / 2) + CLIENT_OFFSET_PER)
#define CLIENT_ORIGIN_Y_P   CLIENT_OFFSET_PER

#define CLIENT_ORIGIN_X_L   (SCREEN_HEIGHT - CLIENT_OFFSET_PER)
#define CLIENT_ORIGIN_Y_L   CLIENT_ORIGIN_Y_P


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CWidget
{
public:
	CWidget(touchgfx::Widget& Widget);
	CWidget(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& Button);

	virtual void placeOnScreen() = 0;   //Position widget on screen according to current orientation

protected:
	touchgfx::Rect RectP;               //Portrait rectangle
	touchgfx::Rect RectL;               //Landscape rectangle

	touchgfx::Rect* getCurrentRect();

private:
	void convertRectTo270deg(touchgfx::Rect& Rect);
};


#endif   //WGT_H

















































