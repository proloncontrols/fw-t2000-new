
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
//         File : CImage.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Custom image class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CImage.hpp>
#include <CScreen.hpp>


namespace touchgfx
{

void CImage::setBitmap(const Bitmap& bmp)
{
	TextureMapper::setBitmap(touchgfx::Bitmap(bmp));

	if(getScrDir() == SCR_LANDSCAPE)
	{
		setBitmapPosition(0.0f, 0.0f);
		setScale(1.0f);
		setCameraDistance(1000.0f);
		setOrigo(90.0f, 90.0f, 1000.0f);
		setCamera(getWidth()/2, getHeight()/2);
		setAngles(0.0f, 0.0f, 0.0f);
		setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);
	}
	else
	{
	    Bitmap image = getBitmap();
	    float newBitmapX = (getWidth()/2 - image.getWidth()/2);
	    float newBitmapY = (getHeight()/2 - image.getHeight()/2);
	    setBitmapPosition(newBitmapX, newBitmapY);
	    setScale(1.0f);
	    setCameraDistance(1000.0f);
	    setOrigo(getWidth()/2, getHeight()/2, 1000.0f);
	    setCamera(getWidth()/2, getHeight()/2);
	    setAngles(0.0f, 0.0f, -1.572f);
	    setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);
	}
}

}   //namespace touchgfx






//
////=============================================================================
////         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
////         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
////         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
////         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
////         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
////         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
////         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
////
////                        (c) Copyright  2022-2023
////-----------------------------------------------------------------------------
////         File : CImage.cpp
////         Date : -----------
////       Author : Jean-Francois Barriere
////-----------------------------------------------------------------------------
////  Description : TouchGFX image class implementation file
////=============================================================================
//
//
////=============================================================================
////  I N C L U D E S
////-----------------------------------------------------------------------------
//#include <CImage.hpp>
//
//
//namespace touchgfx
//{
//
////=============================================================================
////  C O N S T R U C T O R S
////-----------------------------------------------------------------------------
//CImage::CImage(TextureMapper& mapper)
//	  : m_Mapper(mapper)
//{
//}
//
//
////=============================================================================
////  M E T H O D S
////-----------------------------------------------------------------------------
//void CImage::position()
//{
//	Rect rect = getCurRect(m_Mapper.getRect());
//	Bitmap image = m_Mapper.getBitmap();
//	float angleZ = 0.0;
//	if(curRotation == ROTATION_PORTRAIT)
//		angleZ = SCREEN_ANGLE;
//
//	m_Mapper.setPosition(rect.x, rect.y, rect.width, rect.height);
//	float newBitmapX = (((float)rect.width / 2.0) - ((float)image.getWidth() / 2.0));
//	float newBitmapY = (((float)rect.height / 2.0) - ((float)image.getHeight() / 2.0));
//	m_Mapper.setBitmapPosition((float)newBitmapX, (float)newBitmapY);
//	m_Mapper.setOrigo((float)(rect.width / 2), (float)(rect.height / 2), 1000.0);
//	m_Mapper.setCamera((float)(rect.width / 2), (float)(rect.height / 2));
//	m_Mapper.setAngles(0.0, -0.0, angleZ);
//};
//
////-----------------------------------------------------------------------------
//void CImage::getPosition(Rect& rect)
//{
//};
//
////-----------------------------------------------------------------------------
//void CImage::setPosition(Rect& rect)
//{
//};
//
//}   //namespace touchgfx
