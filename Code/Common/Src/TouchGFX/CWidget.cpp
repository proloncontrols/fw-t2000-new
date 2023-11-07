
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
//         File : CWidget.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX widgets class/tools implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "CWidget.hpp"


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
//CWidget::CWidget(Widget& widget)
//{
//}

//CWidget::CWidget(Button& button)
//{
//}

//-----------------------------------------------------------------------------
//CWidget::CWidget(BoxWithBorderButtonStyle< ClickButtonTrigger >& button)
//{
//}

//-----------------------------------------------------------------------------
Rect& CWidget::getRect(const Rect& rect)
{
	int16_t curX = rect.x;
	int16_t curY = rect.y;
	int16_t curW = rect.width;
	int16_t curH = rect.height;

	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
	{
		curX = rect.y;
		curY = SCREEN_HEIGHT - rect.x - rect.width;
		curW = rect.height;
		curH = rect.width;
	}

	curRect.x = curX;
	curRect.y = curY;
	curRect.width = curW;
	curRect.height = curH;

	return curRect;
}

}
