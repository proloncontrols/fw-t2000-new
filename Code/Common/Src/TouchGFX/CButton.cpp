
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

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CButton::initialize(int16_t x, int16_t y, int16_t width, int16_t height)
{
	Container::setPosition(x, y, width, height);
}

//-----------------------------------------------------------------------------
void CButton::initialize(int16_t x, int16_t y, int16_t touchHeight, BitmapId released, BitmapId pressed)
{
	Bitmap image = touchgfx::Bitmap(released);     //Both released and pressed images are assumed to have the same size

	Container::setXY(x, y);
	Container::setWidth(image.getWidth());
	if(touchHeight != 0)
		Container::setHeight(touchHeight);         //Touch area is the image visible area (rectangle)
	else
		Container::setHeight(image.getHeight());   //Touch area is the entire image area, visible and not visible (square)

	imgReleased = new CImage;
	imgReleased->setBitmap(image);
	imgReleased->setXY(0, 0);
	imgReleased->setWidth(image.getWidth());
	imgReleased->setHeight(image.getHeight());
	imgReleased->setVisible(true);
	add(*imgReleased);

	image = touchgfx::Bitmap(pressed);
	imgPressed = new CImage;
	imgPressed->setBitmap(image);
	imgPressed->setXY(0, 0);
	imgPressed->setWidth(image.getWidth());
	imgPressed->setHeight(image.getHeight());
	imgPressed->setVisible(false);
	add(*imgPressed);
}

//-----------------------------------------------------------------------------
void CButton::handleClickEvent(const ClickEvent& event)
{
    bool wasPressed = getPressed();
    bool newPressedValue = (event.getType() == ClickEvent::PRESSED);
    if((newPressedValue && !wasPressed) || (!newPressedValue && wasPressed))
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
    if(wasPressed && (event.getType() == ClickEvent::RELEASED))
        executeAction();
}

}   //namespace touchgfx
