
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
//         File : CButton.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Button base class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CButton.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

CButton::CButton()
{
}

void CButton::initialize(int16_t x, int16_t y, int16_t width, int16_t height)
{
	Container::setPosition(x, y, width, height);
}

//Both released and pressed images are assumed to have the same size.
//If touchHeight is 0, button touch area covers the whole image height.
//Different than 0 specifies the touch area height (used when button images are rectangular).
void CButton::initialize(int16_t x, int16_t y, int16_t touchHeight, BitmapId released, BitmapId pressed)
{
	Bitmap image = touchgfx::Bitmap(released);

	Container::setXY(x, y);
	Container::setWidth(image.getWidth());
	if(touchHeight != 0)
		Container::setHeight(touchHeight);
	else
		Container::setHeight(image.getHeight());

    imgReleased = new TextureMapper();
    add(*imgReleased);
	imgReleased->setXY(0, 0);
	imgReleased->setBitmap(image);
	imgReleased->setWidth(image.getWidth());
	imgReleased->setHeight(image.getHeight());
	imgReleased->setBitmapPosition(0.0f, 0.0f);
	imgReleased->setScale(1.0f);
	imgReleased->setCameraDistance(1000.0f);
	imgReleased->setOrigo((float)(image.getWidth() / 2), (float)(image.getHeight() / 2), 1000.0f);
	imgReleased->setCamera((float)(image.getWidth() / 2), (float)(image.getHeight() / 2));
	imgReleased->setAngles(0.0f, 0.0f, 0.0f);
	imgReleased->setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);
	imgReleased->setVisible(true);

	image = touchgfx::Bitmap(released);
	imgPressed = new TextureMapper();
    add(*imgPressed);
	imgPressed->setXY(0, 0);
	imgPressed->setBitmap(touchgfx::Bitmap(pressed));
	imgPressed->setWidth(image.getWidth());
	imgPressed->setHeight(image.getHeight());
	imgPressed->setBitmapPosition(0.0f, 0.0f);
	imgPressed->setScale(1.0f);
	imgPressed->setCameraDistance(1000.0f);
	imgPressed->setOrigo((float)(image.getWidth() / 2), (float)(image.getHeight() / 2), 1000.0f);
	imgPressed->setCamera((float)(image.getWidth() / 2), (float)(image.getHeight() / 2));
	imgPressed->setAngles(0.0f, 0.0f, 0.0f);
	imgPressed->setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);
	imgPressed->setVisible(false);
}

void CButton::handleClickEvent(const ClickEvent& event)
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






























