
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
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

typedef enum {
	buttonNone = -3,
	buttonHome = -2,
	buttonBack = -1,
	buttonUser =  0
} ButtonId;


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenuItem : public Container
{
public:
	CMenuItem();

	void setText(char* newText);
    void setAction(GenericCallback<const AbstractButtonContainer&>& callback);
    const CButton& getButton();
	void render();

private:
	const static uint8_t buttonTextColorReleasedR = 255;
	const static uint8_t buttonTextColorReleasedG = 255;
	const static uint8_t buttonTextColorReleasedB = 255;

	const static uint8_t buttonTextColorPressedR = 75;
	const static uint8_t buttonTextColorPressedG = 75;
	const static uint8_t buttonTextColorPressedB = 75;

	const static int16_t itemWidth = 500;
	const static int16_t itemHeight = 110;
	const static int16_t buttonHeight = 72;   //This is the height ot the button inside the image
	const static int16_t lineHeight = 3;      //This is the height of the separator line inside the image

	const static TypedTextId buttonTextType = T_MENU_BUTTON;
	const static BitmapId buttonImage = BITMAP_MENU_BUTTON_ID;
	const static BitmapId lineImage = BITMAP_MENU_LINE_GRAY_494X494X3_ID;

	Box background;
    CButton button;
	CImage line = CImage(lineImage);
};

}   //namespace touchgfx


#endif   //CMENU_ITEM_HPP
