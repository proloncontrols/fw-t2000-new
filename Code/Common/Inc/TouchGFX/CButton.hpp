
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
//  Description : Button base class header file
//=============================================================================
#ifndef CBUTTON_HPP
#define CBUTTON_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/AbstractButton.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
// Steps to follow in order to implement a button with its event handler
//
//   Header file
//     1- Include this file
//     2- In the protected section of the screen class, declare the button:
//          CButton b1;
//     3- In the private section of the screen class, declare the following:
//        - The callback:
//            touchgfx::Callback<xxxxView, const touchgfx::AbstractButton&> buttonCallback;
//              where xxxx = scaeen name
//        - The callback handler:
//            void buttonCallbackHandler(const touchgfx::AbstractButton& src);
//
//   Implementation file
//     1- From the screen constructor, call the base constructor:
//        xxxxView::xxxxView()
//                 :buttonCallback(this, &xxxxView::buttonCallbackHandler)
//            where xxxx = scaeen name
//	   2- Still in the constructor, initialize the button:
//          b1.setXY(x, y);
//          b1.setBitmaps(button_released_image_id, button_pressed_image_id);
//          b1.setAction(buttonCallback);
//          add(b1);
//     3- Implement the callback function:
//          void SplashView::buttonCallbackHandler(const touchgfx::AbstractButton& src)
//          {
//          }
//
//   NOTE: To add other buttons to the screen, repeat only step 2 in both header and implementation files

class CButton : public Button
{
	//This class is empty.
	//It is declared for the sole purpose of documenting the steps on how to use it
};


//Kept as a possible future reference
//-----------------------------------
//class CButtonCustom : public BoxWithBorderButtonStyle< ClickButtonTrigger >
//{
//public:
//	CButtonCustom(int16_t x, int16_t y, int16_t width, int16_t height, TextureMapper* imageReleased, TextureMapper* imagePressed);
//
//    virtual void handleClickEvent(const ClickEvent& event) override;
//
//private:
//    TextureMapper* imgReleased;
//    TextureMapper* imgPressed;
//};

}   //namespace touchgfx


#endif   //CBUTTON_HPP
