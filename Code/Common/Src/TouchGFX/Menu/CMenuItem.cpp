
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
//         File : CMenuItem.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Menu item class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Menu/CMenuItem.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
CMenuItem::CMenuItem()
{
	Container::setWidthHeight(itemWidth, itemHeight);
	background.setWidthHeight(*this);
    background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(background);

//    line.setBitmap(touchgfx::Bitmap(BITMAP_MENU_LINE_GRAY_494X494X3_ID));
//    line.setXY(0, itemHeight - lineHeight);
//    add(line);

//    button.initialize(2, (itemHeight - lineHeight - buttonHeight) / 2, buttonHeight, BITMAP_MENU_BUTTON_ID, BITMAP_MENU_BUTTON_ID, T_MENU_BUTTON, 32, touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(75, 75, 75));
//    button.setTextPosition(30, 4);
//    add(button);
}

void CMenuItem::setText(char* newText)
{
	button.setText(newText);
}

void CMenuItem::setAction(GenericCallback<const AbstractButtonContainer&>& callback)
{
	button.setAction(callback);
}

CButton* CMenuItem::getButton()
{
	return &button;
}

}   //namespace touchgfx
