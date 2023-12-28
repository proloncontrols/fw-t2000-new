
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
#include <CApp.hpp>
#include <CImage.hpp>
#include <CLabel.hpp>
#include <Screen/CScreen.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/widgets/Box.hpp>
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
	CImage* imgReleased;
	CImage* imgPressed;
	CLabel* text;

	colortype textColorReleased;
	colortype textColorPressed;
	uint32_t data;   //User defined general purpose data associated with button
	ScreenId ownerScreenId;
	ScreenId gotoScreenId;

	void validateText();

protected:
	virtual void handleClickEvent(const ClickEvent& event);

public:
	CButton();

	void setBitmaps(Bitmap released, Bitmap pressed);
	void setTouchHeight(int16_t touchHeight);

	void setText(const TypedText& textType);
	void setTextPosition(int16_t x, int16_t y);
	void setTextColors(colortype textReleased, colortype textPressed);

	void setData(uint32_t newData);
	uint32_t getData();

	void setOwnerScreenId(ScreenId id);

	void setGotoScreenId(ScreenId id);
	ScreenId getGotoScreenId();

	void transpose();
};

}   //namespace touchgfx


#endif   //CBUTTON_HPP
