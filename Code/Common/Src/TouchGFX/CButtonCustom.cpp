
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
//         File : CButtonCustom.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Custom button widget class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <cfg.h>
#include <CWidget.hpp>
#include <CButtonCustom.hpp>
#include <touchgfx/Color.hpp>

namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CButtonCustom::CButtonCustom(int16_t x, int16_t y, int16_t width, int16_t height, TextureMapper* imageReleased, TextureMapper* imagePressed)
	: imgReleased(imageReleased),
	  imgPressed(imagePressed)
{
	setAlpha(0);   //To see through original button background artifacts
	setBoxWithBorderPosition(0, 0, width, height);
    setBorderSize(0);   //No border

	float angleZ = 0.0;
	if(CFG.Dta.ScrOrientation == CfgScrOrientL)
	    setPosition(x, y, width, height);
	else
	{
		setPosition(y, SCREEN_HEIGHT - x - width, height, width);
		angleZ = SCREEN_ANGLE;
	}
	Rect rect = getRect();

	Bitmap image = imgReleased->getBitmap();
	imgReleased->setPosition(rect.x, rect.y, rect.width, rect.height);
	float newBitmapX = (((float)rect.width / 2.0) - ((float)image.getWidth() / 2.0));
	float newBitmapY = (((float)rect.height / 2.0) - ((float)image.getHeight() / 2.0));
	imgReleased->setBitmapPosition((float)newBitmapX, (float)newBitmapY);
	imgReleased->setOrigo((float)(rect.width / 2), (float)(rect.height / 2), 1000.0);
	imgReleased->setCamera((float)(rect.width / 2), (float)(rect.height / 2));
	imgReleased->setAngles(0.0, -0.0, angleZ);
	imgReleased->setVisible(true);

	image = imgPressed->getBitmap();
	imgPressed->setPosition(rect.x, rect.y, rect.width, rect.height);
	newBitmapX = (((float)rect.width / 2.0) - ((float)image.getWidth() / 2.0));
	newBitmapY = (((float)rect.height / 2.0) - ((float)image.getHeight() / 2.0));
	imgPressed->setBitmapPosition((float)newBitmapX, (float)newBitmapY);
	imgPressed->setOrigo((float)(rect.width / 2), (float)(rect.height / 2), 1000.0);
	imgPressed->setCamera((float)(rect.width / 2), (float)(rect.height / 2));
	imgPressed->setAngles(0.0, -0.0, angleZ);
	imgPressed->setVisible(false);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CButtonCustom::handleClickEvent(const ClickEvent& event)
{
    bool wasPressed = getPressed();
    bool newPressedValue = (event.getType() == ClickEvent::PRESSED);
    if ((newPressedValue && !wasPressed) || (!newPressedValue && wasPressed))
    {
    	if(newPressedValue)
    	{
        	imgReleased->setVisible(false);
        	imgPressed->setVisible(true);
    	}
    	else
    	{
        	imgReleased->setVisible(true);
        	imgPressed->setVisible(false);
    	}
        setPressed(newPressedValue);
        invalidate();
    }
    if (wasPressed && (event.getType() == ClickEvent::RELEASED))
    {
        executeAction();
    }
}

}   //namespace touchgfx
