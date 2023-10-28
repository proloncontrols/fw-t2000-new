
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
//         File : widget.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX widget class/tools implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "widget.hpp"


//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CWidget::CWidget(touchgfx::Widget& Widget)
{
	RectP = Widget.getRect();
	RectL = Widget.getRect();
	convertRectTo270deg(RectL);
}

//-----------------------------------------------------------------------------
CWidget::CWidget(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& Button)
{
	RectP = Button.getRect();
	RectL = Button.getRect();
	convertRectTo270deg(RectL);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
touchgfx::Rect* CWidget::getCurrentRect()
{
	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
		return &RectL;
	else
		return &RectP;
}


//=============================================================================
//  P R I V A T E S
//-----------------------------------------------------------------------------
void CWidget::convertRectTo270deg(touchgfx::Rect& Rect)
{
	int NewX = Rect.y + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);                                  //Becomes the Y coordinate of the rotated screen
	int NewWidth = Rect.height;
	int NewY = SCREEN_HEIGHT - (Rect.x + Rect.width) + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);   //Becomes the X coordinate of the rotated screen
	int NewHeight = Rect.width;

	Rect.x = NewX;             //Apply new 270 degrees parameters
	Rect.y = NewY;             //
	Rect.width = NewWidth;     //
	Rect.height = NewHeight;   //
}
