
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
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CImage::CImage(touchgfx::TextureMapper& Mapper)
    : CWidget(Mapper),
	  m_Mapper { Mapper }
{
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
touchgfx::Rect CImage::getRect()
{
	return m_Mapper.getRect();
}

void CImage::initialize()
{
	CRect screenRect;
	clientToScreen(screenRect);

	clientToScreen((CRect&)m_Mapper.getRect());

	touchgfx::Bitmap imageBit = m_Mapper.getBitmap();

	float angleZ = 0.0;
	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
		angleZ = SCREEN_ANGLE;

	m_Mapper.setPosition(cRect.x, cRect.y, cRect.width, cRect.height);
	float newBitmapX = (((float)cRect.width / 2.0) - ((float)imageBit.getWidth() / 2.0));
	float newBitmapY = (((float)cRect.height / 2.0) - ((float)imageBit.getHeight() / 2.0));
	m_Mapper.setBitmapPosition((float)newBitmapX, (float)newBitmapY);
	m_Mapper.setOrigo((float)(cRect.width / 2), (float)(cRect.height / 2), 1000.0);
	m_Mapper.setCamera((float)(cRect.width / 2), (float)(cRect.height / 2));
	m_Mapper.setAngles(0.0, -0.0, angleZ);

//	screenToClient(m_Mapper.getRect());

//	CRect initialRect;
//	getRect(initialRect);
//
//	touchgfx::Bitmap imageBit = m_Mapper.getBitmap();
//
//	float angleZ = 0.0;
//	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//		angleZ = SCREEN_ANGLE;
//
//	m_Mapper.setPosition(initialRect.x, initialRect.y, initialRect.width, initialRect.height);
//	float newBitmapX = (((float)initialRect.width / 2.0) - ((float)imageBit.getWidth() / 2.0));
//	float newBitmapY = (((float)initialRect.height / 2.0) - ((float)imageBit.getHeight() / 2.0));
//	m_Mapper.setBitmapPosition((float)newBitmapX, (float)newBitmapY);
//	m_Mapper.setOrigo((float)(initialRect.width / 2), (float)(initialRect.height / 2), 1000.0);
//	m_Mapper.setCamera((float)(initialRect.width / 2), (float)(initialRect.height / 2));
//	m_Mapper.setAngles(0.0, -0.0, angleZ);

//    touchgfx::Bitmap imageBit = m_Mapper.getBitmap();
//
//    float angleZ = 0.0;
//	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//		angleZ = SCREEN_ANGLE;
//
//	m_Mapper.setPosition(Rect.x, Rect.y, Rect.width, Rect.height);
//    float newBitmapX = (((float)Rect.width / 2.0) - ((float)imageBit.getWidth() / 2.0));
//    float newBitmapY = (((float)Rect.height / 2.0) - ((float)imageBit.getHeight() / 2.0));
//    m_Mapper.setBitmapPosition((float)newBitmapX, (float)newBitmapY);
//    m_Mapper.setOrigo((float)(Rect.width / 2), (float)(Rect.height / 2), 1000.0);
//    m_Mapper.setCamera((float)(Rect.width / 2), (float)(Rect.height / 2));
//    m_Mapper.setAngles(0.0, -0.0, angleZ);

//	CRect* rect = getRect();
//    touchgfx::Bitmap imageBit = m_Mapper.getBitmap();
//
//    float angleZ = 0.0;
//	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//		angleZ = SCREEN_ANGLE;
//
//	m_Mapper.setPosition(rect->x, rect->y, rect->width, rect->height);
//    float newBitmapX = (((float)rect->width / 2.0) - ((float)imageBit.getWidth() / 2.0));
//    float newBitmapY = (((float)rect->height / 2.0) - ((float)imageBit.getHeight() / 2.0));
//    m_Mapper.setBitmapPosition((float)newBitmapX, (float)newBitmapY);
//    m_Mapper.setOrigo((float)(rect->width / 2), (float)(rect->height / 2), 1000.0);
//    m_Mapper.setCamera((float)(rect->width / 2), (float)(rect->height / 2));
//    m_Mapper.setAngles(0.0, -0.0, angleZ);
};

//-----------------------------------------------------------------------------
void CImage::getPosition(CRect& rect)
{
	rect = vRect;
//	rect = m_Mapper.getRect();
};

//-----------------------------------------------------------------------------
void CImage::setPosition(CRect& rect)
{
	vRect = rect;
	formatRect();
	m_Mapper.setPosition(fRect.x, fRect.y, fRect.width, fRect.height);

//	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
//		convertRectTo270deg(rect);
//
//	m_Mapper.setPosition(rect.x, rect.y, rect.width, rect.height);
};






























