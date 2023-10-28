
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
//         File : image.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX image class/tools implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "image.hpp"


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CImage::placeOnScreen()
{
	touchgfx::Rect* CurRect = getCurrentRect();
    touchgfx::Bitmap ImageBit = m_Mapper.getBitmap();

    float AngleZ = 0.0;
	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
		AngleZ = SCREEN_ANGLE;

	m_Mapper.setPosition(CurRect->x, CurRect->y, CurRect->width, CurRect->height);
    float NewBitmapX = (((float)CurRect->width / 2.0) - ((float)ImageBit.getWidth() / 2.0));
    float NewBitmapY = (((float)CurRect->height / 2.0) - ((float)ImageBit.getHeight() / 2.0));
    m_Mapper.setBitmapPosition((float)NewBitmapX, (float)NewBitmapY);
    m_Mapper.setOrigo((float)(CurRect->width / 2), (float)(CurRect->height / 2), 1000.0);
    m_Mapper.setCamera((float)(CurRect->width / 2), (float)(CurRect->height / 2));
    m_Mapper.setAngles(0.0, -0.0, AngleZ);
};
