
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
//  D E F I N E S
//-----------------------------------------------------------------------------
#define Z_ANGLE_LANDSCAPE   -3.142f
#define Z_ANGLE_PORTRAIT     1.565f


//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CImage::CImage(BitmapId id)
{
	setBitmap(id);

	if(dsp.orientation == CDisplay::LANDSCAPE)
	    setAngles(0.0f, 0.0f, Z_ANGLE_LANDSCAPE);

	if(dsp.orientation == CDisplay::PORTRAIT)
	    setAngles(0.0f, 0.0f, Z_ANGLE_PORTRAIT);

	setScale(1.0f);
	setBitmapPosition(0.0f, 0.0f);
    setOrigo((float)(getWidth()/2), (float)(getHeight()/2), 1000.0f);
	setCameraDistance(1000.0f);
	setCamera(getWidth()/2, getHeight()/2);
	setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);
}

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CImage::render()
{
	dsp.setPosition(*this, *this);
}

}   //namespace touchgfx
