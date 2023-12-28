
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
//         File : CMenuItem.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Menu item class header file
//=============================================================================
#ifndef CMENU_ITEM_HPP
#define CMENU_ITEM_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CImage.hpp>
#include <CButton.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/Containers/Container.hpp>


namespace touchgfx
{


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenuItem : public Container
{
	const uint8_t buttonTextColorReleasedR = 255;
	const uint8_t buttonTextColorReleasedG = 255;
	const uint8_t buttonTextColorReleasedB = 255;
	const uint8_t buttonTextColorPressedR = 75;
	const uint8_t buttonTextColorPressedG = 75;
	const uint8_t buttonTextColorPressedB = 75;

	const int16_t itemWidth = 500;
	const int16_t itemHeight = 110;
	const int16_t buttonHeight = 76;   //This is the height ot the button inside the image
	const int16_t lineHeight = 4;      //This is the height of the separator line inside the image

	const BitmapId buttonImage = BITMAP_MENU_BUTTON_496X496X76_ID;
	const BitmapId lineImage = BITMAP_MENU_LINE_GRAY_494X494X4_ID;

    CButton button;
	CImage line;

public:
	CMenuItem();

	void setButtonText(const TypedText& textType);
    void setButtonAction(GenericCallback<const AbstractButtonContainer&>& callback);
    void setButtonGotoScreenId(ScreenId id);
    CButton* getButton();

    void transpose();
};

}   //namespace touchgfx


#endif   //CMENU_ITEM_HPP
