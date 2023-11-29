
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
//         File : CMenu.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Menu class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <string.h>
#include <CScreen.hpp>
#include <Menu/CMenu.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/TypedText.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
CMenu::CMenu(char* menuTitle, bool menuAsRoot, CMenuItem* menuItems, int menuItemCount, GenericCallback<const AbstractButtonContainer&>& menuCallback)
{
	Container::setWidthHeight(624, 624);

	background.setWidthHeight(*this);
    background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(background);

    home.initialize(0, 0, 0, BITMAP_HOME_ID, BITMAP_HOME_ID);
    home.setAction(menuCallback);
	add(home);

    logo.setBitmap(BITMAP_PROLON_176X176_ID);
	logo.setXY((Container::getWidth() - logo.getBitmap().getWidth()) /2 , 0);
	add(logo);

    back.initialize(Container::getWidth() - Bitmap(BITMAP_RETURN_50X50_ID).getWidth(), 0, 0, BITMAP_RETURN_50X50_ID, BITMAP_RETURN_50X50_ID);
    back.setAction(menuCallback);
    back.setVisible(!menuAsRoot);
	add(back);

	titleBuffer = (Unicode::UnicodeChar*)calloc(strlen(menuTitle) + 1, sizeof(Unicode::UnicodeChar));   //+1 = null termination character
	title.setWildcard(titleBuffer);
	title.setTypedText(T_MENU_TITLE);
    title.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	Unicode::fromUTF8((uint8_t*)menuTitle, titleBuffer, strlen(menuTitle));
	title.resizeToCurrentText();
	title.setXY((Container::getWidth() - title.getWidth()) / 2, 60);
	add(title);

	line.setBitmap(BITMAP_MENU_LINE_WHITE_496X496X5_ID);
	line.setXY((Container::getWidth() - line.getBitmap().getWidth()) / 2, title.getY() + title.getHeight() + 5);
	add(line);

	items.setDirection(SOUTH);
	items.setXY(line.getX(), line.getY() + 5 + 10);   //5 = line thickness, 10 = space after line
	for(int i = 0; i < menuItemCount; i++)
	{
		menuItems[i].getButton().setId(buttonUser + i);
		menuItems[i].setAction(menuCallback);
		items.add(menuItems[i]);
	}
	add(items);
}

//-----------------------------------------------------------------------------
ButtonId CMenu::getButtonId(const touchgfx::AbstractButtonContainer& src)
{
	if(&src == &home)
		return buttonHome;

	if(&src == &back)
		return buttonBack;

	return buttonUser;
}

}   //namespace touchgfx

































