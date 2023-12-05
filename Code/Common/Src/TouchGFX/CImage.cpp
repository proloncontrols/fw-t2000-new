
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
#include <CDisplay.hpp>


namespace touchgfx
{

//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define ANGLE_Z_ORIENTATION_LANDSCAPE   -3.142f
#define ANGLE_Z_ORIENTATION_PORTRAIT     1.565f


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//void CImage::setBitmap(const Bitmap& bmp)
//{
//	TextureMapper::setBitmap(touchgfx::Bitmap(bmp));
//
//	if(dsp.orientation == CDisplay::LANDSCAPE)
//	{
//		setBitmapPosition(0.0f, 0.0f);
//		setOrigo(90.0f, 90.0f, 1000.0f);
//		setAngles(0.0f, 0.0f, 0.0f);
//	}
//	else
//	{
//	    Bitmap image = getBitmap();
//	    float newBitmapX = (getWidth()/2 - image.getWidth()/2);
//	    float newBitmapY = (getHeight()/2 - image.getHeight()/2);
//	    setBitmapPosition(newBitmapX, newBitmapY);
//	    setOrigo(getWidth()/2, getHeight()/2, 1000.0f);
//	    setAngles(0.0f, 0.0f, -1.572f);
//	}
//
//	setScale(1.0f);
//	setCameraDistance(1000.0f);
//	setCamera(getWidth()/2, getHeight()/2);
//	setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);
//}

//-----------------------------------------------------------------------------
void CImage::setXY(int16_t x, int16_t y)
{
	if(dsp.orientation == CDisplay::LANDSCAPE)
	{
		setBitmapPosition(1.0f, 1.0f);
		setOrigo(90.0f, 90.0f, 1000.0f);
	    setAngles(0.0f, 0.0f, ANGLE_Z_ORIENTATION_LANDSCAPE);
	}
	else
	{
	    Bitmap image = getBitmap();
	    float newBitmapX = ((getWidth()/2 - image.getWidth()/2) + 1);
	    float newBitmapY = ((getHeight()/2 - image.getHeight()/2) + 1);
	    setBitmapPosition(newBitmapX, newBitmapY);
	    setOrigo(getWidth()/2, getHeight()/2, 1000.0f);
	    setAngles(0.0f, 0.0f, ANGLE_Z_ORIENTATION_PORTRAIT);
	}

	setScale(1.0f);
	setCameraDistance(1000.0f);
	setCamera(getWidth()/2, getHeight()/2);
	setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);
}

}   //namespace touchgfx
































