
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
//         File : CTextureMapper.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX TextureMapper class/tools implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "CTextureMapper.hpp"


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CTextureMapper::CTextureMapper(TextureMapper& mapper)
    : CWidget(mapper),
	  m_Mapper(mapper)
{
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CTextureMapper::position()
{
	Rect rect = getCurRect(m_Mapper.getRect());
	Bitmap image = m_Mapper.getBitmap();
	float angleZ = 0.0;
	if(CFG.Dta.ScrOrientation == CfgScrOrientP)
		angleZ = SCREEN_ANGLE;

	m_Mapper.setPosition(rect.x, rect.y, rect.width, rect.height);
	float newBitmapX = (((float)rect.width / 2.0) - ((float)image.getWidth() / 2.0));
	float newBitmapY = (((float)rect.height / 2.0) - ((float)image.getHeight() / 2.0));
	m_Mapper.setBitmapPosition((float)newBitmapX, (float)newBitmapY);
	m_Mapper.setOrigo((float)(rect.width / 2), (float)(rect.height / 2), 1000.0);
	m_Mapper.setCamera((float)(rect.width / 2), (float)(rect.height / 2));
	m_Mapper.setAngles(0.0, -0.0, angleZ);
};

//-----------------------------------------------------------------------------
void CTextureMapper::getPosition(Rect& rect)
{
};

//-----------------------------------------------------------------------------
void CTextureMapper::setPosition(Rect& rect)
{
};

}   //namespace touchgfx
