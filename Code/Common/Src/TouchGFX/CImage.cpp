
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
//         File : CImage.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Cmage class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CImage.hpp>
#include <CDisplay.hpp>


namespace touchgfx
{

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CImage::transpose()
{
//	setScale(1.0f);
//    setOrigo((float)(getWidth()/2), (float)(getHeight()/2), 1000.0f);
//	setCameraDistance(1000.0f);
//	setCamera(getWidth()/2, getHeight()/2);
//	setRenderingAlgorithm(TextureMapper::NEAREST_NEIGHBOR);
//
//	if(dsp.orientation == CDisplay::NATIVE)
//	{
//		setBitmapPosition(1.0f, 1.0f);
//		setWidthHeight(getWidth()+1, getHeight()+1);       //Resize container to fit image offset according to mapper angle
//		setAngles(0.0f, 0.0f, 0.0f);
//	}
//	else
//	{
//		if(dsp.orientation == CDisplay::LANDSCAPE)
//		{
//			setBitmapPosition(-1.0f, 1.0f);
//			setWidthHeight(getWidth()-1, getHeight()+1);   //Resize container to fit image offset according to mapper angle
//		    setAngles(0.0f, 0.0f, zAngleLandscape);
//		}
//
//		if(dsp.orientation == CDisplay::PORTRAIT)
//		{
//			setBitmapPosition(-1.0f, -1.0f);
//			setWidthHeight(getWidth()-1, getHeight()-1);   //Resize container to fit image offset according to mapper angle
//		    setAngles(0.0f, 0.0f, zAnglePortrait);
//		}
//
//		dsp.transpose(*this);
//	}
//
//	invalidate();

	setBitmapPosition(0.0f, 0.0f);
	setScale(1.0f);
    setOrigo((float)(getWidth()/2), (float)(getHeight()/2), 1000.0f);
	setCameraDistance(1000.0f);
	setCamera((float)(getWidth()/2), (float)(getHeight()/2));
	setRenderingAlgorithm(TextureMapper::NEAREST_NEIGHBOR);

	setAngles(0.0f, 0.0f, 0.0f);
	if(dsp.orientation != CDisplay::NATIVE)
	{
		if(dsp.orientation == CDisplay::LANDSCAPE)
		    setZAngle(zAngleLandscape);

		if(dsp.orientation == CDisplay::PORTRAIT)
		    setZAngle(zAnglePortrait);

		dsp.transpose(*this);
	}

	invalidate();
}

}   //namespace touchgfx




















