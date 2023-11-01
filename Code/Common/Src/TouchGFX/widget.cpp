
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
CWidget::CWidget(touchgfx::Widget& widget)
{
	pRect = widget.getRect();
	createRect270deg();
//	rotate270deg(pRect);

//	cRect.x      = widget.getRect().x - CLIENT_ORIGIN_X;
//	cRect.y      = widget.getRect().y - CLIENT_ORIGIN_Y;
//	cRect.width  = widget.getRect().width;
//	cRect.height = widget.getRect().height;

//	screenToClient((CRect&)widget.getRect());

//	vRect = widget.getRect();
//	RectP = widget.getRect();
//	RectL = widget.getRect();
//	convertRectTo270deg(RectL);
}

//-----------------------------------------------------------------------------
CWidget::CWidget(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& button)
{
	pRect = button.getRect();
	createRect270deg();
//	rotate270deg(pRect);

//	cRect.x      = button.getRect().x - CLIENT_ORIGIN_X;
//	cRect.y      = button.getRect().y - CLIENT_ORIGIN_Y;
//	cRect.width  = button.getRect().width;
//	cRect.height = button.getRect().height;

//	screenToClient((CRect&)button.getRect());

//	vRect = button.getRect();
//	RectP = button.getRect();
//	RectL = button.getRect();
//	convertRectTo270deg(RectL);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//CRect* CWidget::getRect()
//{
////	CRect rect = Rect;
////
////	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
////		convertRectTo270deg(rect);
////
////	return &rect;
//
////	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
////		return &RectP;
////	return &RectL;
//	return NULL;
//}

//-----------------------------------------------------------------------------
//int16_t CWidget::getX()
//{
////	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
////	   return Rect->x;
////	return SCREEN_HEIGHT - Rect->y;
//	return 0;
//}
//
//void CWidget::setX(int16_t x)
//{
////	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
////		Rect->x = x;
////	Rect->y = SCREEN_HEIGHT - x;
//}


//-----------------------------------------------------------------------------
//void CWidget::setPosition(CRect& rect)
//{
//}

//void CWidget::getPosition(CRect& rect)
//{
//	rect.x = rectNew.x;
//	rect.y = rectNew.y;
//	rect.width = rectNew.width;
//	rect.height = rectNew.height;
//}


//=============================================================================
//  P R I V A T E S
//-----------------------------------------------------------------------------
CRect& CWidget::getVRect()
{
	return vRect;
}

//-----------------------------------------------------------------------------
void CWidget::formatRect()
{
//	fRect = vRect;
//	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//		convertRectTo270deg(fRect);
}

//-----------------------------------------------------------------------------
void CWidget::getRect(CRect& rect)
{
	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
		rect = vRect;
	else
	{
	}
}

//-----------------------------------------------------------------------------
void CWidget::setRect(CRect& rect)
{
	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
		vRect = rect;
	else
	{
		vRect.x      = rect.y + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);
		vRect.y      = SCREEN_HEIGHT - (rect.x + rect.width) + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);
		vRect.width  = rect.height;
		vRect.height = rect.width;
	}
}

//-----------------------------------------------------------------------------
//void CWidget::convertRectTo270deg(CRect& rect)
//{
//	int16_t NewX      = rect.y + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);                                  //Becomes the Y coordinate of the rotated screen
//	int16_t NewY      = SCREEN_HEIGHT - (rect.x + rect.width) + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);   //Becomes the X coordinate of the rotated screen
//	int16_t NewWidth  = rect.height;
//	int16_t NewHeight = rect.width;
//
//	rect.x      = NewX;        //Apply new 270 degrees parameters
//	rect.y      = NewY;        //
//	rect.width  = NewWidth;    //
//	rect.height = NewHeight;   //
//}
//void CWidget::convertRectTo270deg(touchgfx::Rect& Rect)
//{
//	int16_t NewX      = Rect.y + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);                                  //Becomes the Y coordinate of the rotated screen
//	int16_t NewY      = SCREEN_HEIGHT - (Rect.x + Rect.width) + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);   //Becomes the X coordinate of the rotated screen
//	int16_t NewWidth  = Rect.height;
//	int16_t NewHeight = Rect.width;
//
//	Rect.x      = NewX;        //Apply new 270 degrees parameters
//	Rect.y      = NewY;        //
//	Rect.width  = NewWidth;    //
//	Rect.height = NewHeight;   //
//}

//-----------------------------------------------------------------------------
void CWidget::screenToClient(CRect& rect)
//void CWidget::screenToClient(const touchgfx::Rect& rect)
{
	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
		rect.x -= SCREEN_OFFSET;
	else
	{
		int16_t newX = SCREEN_HEIGHT - (rect.y + rect.height);
		int16_t newY = rect.x - SCREEN_OFFSET;
		int16_t newWidth = rect.height;
		int16_t newHeight = rect.width;
		rect.x = newX;
		rect.y = newY;
		rect.width = newWidth;
		rect.height = newHeight;
	}

//	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//	{
//		rect.x -= CLIENT_ORIGIN_X;
//		rect.y -= CLIENT_ORIGIN_Y;
//	}
//	else
//	{
//		int16_t newX = rect.y + rect.height + CLIENT_OFFSET - SCREEN_HEIGHT;
//		int16_t newY = rect.x - CLIENT_ORIGIN_X + CLIENT_OFFSET;
//		int16_t newWidth = rect.height;
//		int16_t newHeight = rect.width;
//		rect.x = newX;
//		rect.y = newY;
//		rect.width = newWidth;
//		rect.height = newHeight;
//	}

//	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//	{
//		cRect.x      = rect.x - CLIENT_ORIGIN_X;
//		cRect.y      = rect.y - CLIENT_ORIGIN_Y;
//		cRect.width  = rect.width;
//		cRect.height = rect.height;
//	}
//	else
//	{
//		cRect.x      = rect.y - CLIENT_ORIGIN_Y;
//		cRect.y      = rect.x - CLIENT_ORIGIN_X;
//		cRect.width  = rect.height;
//		cRect.height = rect.width;
//	}
}

//-----------------------------------------------------------------------------
void CWidget::clientToScreen(CRect& rect)
{
	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
		rect.x += SCREEN_OFFSET;
	else
	{
		int16_t newX = SCREEN_OFFSET + rect.y;
		int16_t newY = SCREEN_HEIGHT - SCREEN_FRAME - rect.x;
		int16_t newWidth = rect.height;
		int16_t newHeight = rect.width;
		rect.x = newX;
		rect.y = newY;
		rect.width = newWidth;
		rect.height = newHeight;
	}

//	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//	{
//		rect.x += CLIENT_ORIGIN_X;
//		rect.y += CLIENT_ORIGIN_Y;
//	}
//	else
//	{
//		int16_t newX = SCREEN_OFFSET_X + rect.y;
//		int16_t newY = SCREEN_HEIGHT - SCREEN_FRAME - rect.width;
//		int16_t newWidth = rect.height;
//		int16_t newHeight = rect.width;
//		rect.x = newX;
//		rect.y = newY;
//		rect.width = newWidth;
//		rect.height = newHeight;
//	}

//	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
//	{
//		rect.x      = cRect.x + CLIENT_ORIGIN_X;   //New x
//		rect.y      = cRect.y + CLIENT_ORIGIN_Y;   //New y
//		rect.width  = cRect.width;                 //New width
//		rect.height = cRect.height;                //New height
//	}
//	else
//	{
//		rect.y      = SCREEN_HEIGHT - cRect.x;     //New x
//		rect.x      = CLIENT_ORIGIN_X + cRect.y;   //New y
//		rect.height = cRect.width;                 //New width
//		rect.width  = cRect.height;                //New height
//	}
}

//-----------------------------------------------------------------------------
CRect* CWidget::getCurRect()
{
	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
		return &pRect;
	return &lRect;
}

//-----------------------------------------------------------------------------
void CWidget::createRect270deg()
{
	lRect.x = SCREEN_OFFSET + pRect.y;
	lRect.y = SCREEN_HEIGHT + SCREEN_OFFSET - pRect.x - pRect.width;
	lRect.width = pRect.height;
	lRect.height = pRect.width;
}

//void CWidget::rotate270deg(CRect& rect)
//{
//	int16_t NewX      = rect.y + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);                                  //Becomes the Y coordinate of the rotated screen
//	int16_t NewY      = SCREEN_HEIGHT - (rect.x + rect.width) + ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2);   //Becomes the X coordinate of the rotated screen
//	int16_t NewWidth  = rect.height;
//	int16_t NewHeight = rect.width;
//
//	lRect.x      = NewX;        //Apply new 270 degrees parameters
//	lRect.y      = NewY;        //
//	lRect.width  = NewWidth;    //
//	lRect.height = NewHeight;   //
//}
















































