
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
//         File : ui_virtual.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : User-Intrerface widget virtual manipulation implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "ui_virtual.hpp"
#include "cfg.h"


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
//#define UIV_SCREEN_WIDTH      720
//#define UIV_SCREEN_HEIGHT     672
//#define UIV_SCREEN_ANGLE    (-1.572f)


//=============================================================================
//  P R O T O T Y P E S
//-----------------------------------------------------------------------------
//static void UIV_rotateRect270deg(touchgfx::Rect& Rect);


//=============================================================================
//  M E T H O D E S
//-----------------------------------------------------------------------------
void UIV_placeText(touchgfx::TextArea& Text)
{
//	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//	{
//		touchgfx::Rect TextRect = Text.getAbsoluteRect();
//
//		UIV_rotateRect270deg(TextRect);
//		Text.setPosition(TextRect.x, TextRect.y, TextRect.width, TextRect.height);
//		Text.setRotation(touchgfx::TEXT_ROTATE_270);
//	}
}

//-----------------------------------------------------------------------------
void UIV_placeTexture(touchgfx::TextureMapper& Image)
{
//    if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//    {
//	    touchgfx::Bitmap ImageBit  = Image.getBitmap();
//    	touchgfx::Rect   ImageRect = Image.getAbsoluteRect();
//
//    	UIV_rotateRect270deg(ImageRect);
//    	Image.setPosition(ImageRect.x, ImageRect.y, ImageRect.width, ImageRect.height);
//	    float NewBitmapX = (((float)ImageRect.width / 2.0f) - ((float)ImageBit.getWidth() / 2.0f));
//	    float NewBitmapY = (((float)ImageRect.height / 2.0f) - ((float)ImageBit.getHeight() / 2.0f));
//	    Image.setBitmapPosition((float)NewBitmapX, (float)NewBitmapY);
//	    Image.setOrigo((float)(ImageRect.width / 2), (float)(ImageRect.height / 2), 1000.0f);
//	    Image.setCamera((float)(ImageRect.width / 2), (float)(ImageRect.height / 2));
//	    Image.setAngles(0.0f, -0.0f, UIV_SCREEN_ANGLE);
//    }
}

//-----------------------------------------------------------------------------
void UIV_placeButtonFlex(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& Button)
{
//    if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//    {
//    	touchgfx::Rect ButtonRect = Button.getRect();
//    	UIV_rotateRect270deg(ButtonRect);
//    	Button.setPosition(ButtonRect.x, ButtonRect.y, ButtonRect.width, ButtonRect.height);
//    }
}


//=============================================================================
//  P R I V A T E S
//-----------------------------------------------------------------------------
//static void UIV_rotateRect270deg(touchgfx::Rect& Rect)
//{
////	int NewX = Rect.y + ((UIV_SCREEN_WIDTH - UIV_SCREEN_HEIGHT) / 2);                                      //Becomes the Y coordinate of the rotated screen
////	int NewWidth = Rect.height;
////	int NewY = UIV_SCREEN_HEIGHT - (Rect.x + Rect.width) + ((UIV_SCREEN_WIDTH - UIV_SCREEN_HEIGHT) / 2);   //Becomes the X coordinate of the rotated screen
////	int NewHeight = Rect.width;
////
////	Rect.x = NewX;             //Apply new 270 degrees parameters
////	Rect.y = NewY;             //
////	Rect.width = NewWidth;     //
////	Rect.height = NewHeight;   //
//}



























