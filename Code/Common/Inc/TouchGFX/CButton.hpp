
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
//         File : CButton.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Button class header file
//=============================================================================
#ifndef CBUTTON_HPP
#define CBUTTON_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stddef.h>
#include <CImage.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/Containers/Buttons/AbstractButtonContainer.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
// Steps to follow in order to implement a button with its event handler
//
//   In the header file
//     1- Include this file
//     2- In the protected section of the screen class, declare the button:
//          CButton b1;
//     3- In the private section of the screen class, declare the following:
//        - The callback prototype:
//            touchgfx::Callback<xxxxView, const touchgfx::AbstractButtonContainer&> buttonCallback;
//              where xxxx = scaeen name
//        - The callback handler:
//            void buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
//
//   In the implementation file
//     1- From the screen constructor, call the base constructor:
//        xxxxView::xxxxView()
//                 :buttonCallback(this, &xxxxView::buttonCallbackHandler)
//            where xxxx = scaeen name
//	   2- Still in the constructor, initialize the button:
//	        b1.initialize(x, y, th, button_released_image_id, button_pressed_image_id);
//	        b1.setAction(buttonCallback);
//	        add(b1);
//     3- Implement the callback function:
//          void xxxxView::buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
//          {
//          }
//
//   NOTE: To add other buttons to the screen, repeat step 2 in both header and implementation files

class CButton : public AbstractButtonContainer
{
public:
	void initialize(int16_t x, int16_t y, int16_t width, int16_t height);
	void initialize(int16_t x, int16_t y, int16_t touchHeight, Bitmap released, Bitmap pressed);
	void initialize(int16_t x, int16_t y, int16_t touchHeight, Bitmap released, Bitmap pressed, const TypedText& textType, int16_t textMaxLen, colortype textReleased, colortype textPressed);

	void setText(const char* newText);
	void setTextPosition(int16_t x, int16_t y);

	void setData(uint32_t newData);
	uint32_t getData();

    virtual void handleClickEvent(const ClickEvent& event);

private:
    uint32_t data;   //User defined general purpose data associated with button

    CImage* imgReleased = NULL;
    CImage* imgPressed = NULL;

	TextAreaWithOneWildcard* text = NULL;
	Unicode::UnicodeChar* textBuffer = NULL;
	colortype textColorReleased;
	colortype textColorPressed;
};

}   //namespace touchgfx


#endif   //CBUTTON_HPP




































