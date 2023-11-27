
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

//CButton::CButton(int16_t x, int16_t y, int16_t width, int16_t height)
//{
//	add(button);
//
//	setPosition(x, y, width, height);
//	background.setPosition(*this);
//	background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//}

CButton::CButton()
{
}

void CButton::initialize(int16_t x, int16_t y, int16_t width, int16_t height)
{
}

void CButton::initialize(int16_t x, int16_t y, TextureMapper* imageReleased, TextureMapper* imagePressed)
{
}

void CButton::initialize(int16_t x, int16_t y, int16_t height, TextureMapper* imageReleased, TextureMapper* imagePressed)
{
}

void CButton::handleClickEvent(const ClickEvent& event)
{
    bool wasPressed = getPressed();
    bool newPressedValue = (event.getType() == ClickEvent::PRESSED);
    if ((newPressedValue && !wasPressed) || (!newPressedValue && wasPressed))
    {
        setPressed(newPressedValue);
        invalidate();
    }
    if (wasPressed && (event.getType() == ClickEvent::RELEASED))
    {
        executeAction();
    }
}

}   //namespace touchgfx
