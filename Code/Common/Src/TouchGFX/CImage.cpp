
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
void CImage::setImage(BitmapId id)
{
	setBitmap(id);

	setWidthHeight(getWidth()+1, getHeight()+1);   //Increase container to make sure the image fits since its position is (1.0, 1.0)
	setBitmapPosition(1.0f, 1.0f);

	if(dsp.orientation == CDisplay::LANDSCAPE)
	    setAngles(0.0f, 0.0f, zAngleLandscape);

	if(dsp.orientation == CDisplay::PORTRAIT)
	    setAngles(0.0f, 0.0f, zAnglePortrait);

	setScale(1.0f);
    setOrigo((float)(getWidth()/2), (float)(getHeight()/2), 1000.0f);
	setCameraDistance(1000.0f);
	setCamera(getWidth()/2, getHeight()/2);
	setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);
}

//-----------------------------------------------------------------------------
void CImage::render()
{
	dsp.setPosition(*this, *this);
}

}   //namespace touchgfx
