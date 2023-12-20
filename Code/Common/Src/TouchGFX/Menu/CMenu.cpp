
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
//  Description : Menu base class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stddef.h>
#include <string.h>
#include <CDisplay.hpp>
#include <Menu/CMenu.hpp>
#include <touchgfx/Color.hpp>
//#include <BitmapDatabase.hpp>
//#include <touchgfx/TypedText.hpp>
//#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMenu::CMenu(Container& ownerContainer, GenericCallback<const AbstractButtonContainer&>& callback)
      :CScreen(ownerContainer)
{
//	client.add(home);
//	home.initialize(1, 1, 0, homeImageReleased, homeImagePressed);
//	home.setAction(callback);
//	home.setData(CMenu::buttonHome);
//	home.render();
//
//	client.add(logo);
//	logo.setImage(logoImage);
//	logo.setXY((client.getWidth() - logo.getWidth()) / 2, 1);
//	logo.render();
//
//	client.add(back);
//	back.initialize(1, 1, 0, backImageReleased, backImagePressed);
//	back.setAction(callback);
//	back.setXY(client.getWidth() - back.getWidth(), 1);
//	back.setData(CMenu::buttonBack);
//	back.render();
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//void CMenu::addTitle(const char* newTitle)
//{
//	client.add(title);
//	title.initialize(titleText, titleColorR, titleColorG, titleColorB);
//	title = newTitle;
//	title.setXY((client.getWidth() - title.getWidth()) / 2, 60);
//
//	client.add(line);
//	line.setImage(titleLine);
//	line.setXY((client.getWidth() - line.getWidth()) / 2, title.getY() + title.getHeight() + 5);
//
//	title.render();   //Title rendering is done here because line position is based on title position
//	line.render();
//}
//
////-----------------------------------------------------------------------------
//void CMenu::addItems(CMenuItem* itemsList, int itemsCount, GenericCallback<const AbstractButtonContainer&>& callback)
//{
//	for(int i = 0; i < itemsCount; i++)
//	{
//		itemsList[i].getButton().setData(CMenu::buttonUser + i);
//		itemsList[i].setAction(callback);
//		items.add(itemsList[i]);
//	}
//}

//-----------------------------------------------------------------------------
void CMenu::initialize(const char* newTitle, CMenuItem* itemsList, int itemsCount, GenericCallback<const AbstractButtonContainer&>& callback)
{
	client.add(home);
	home.initialize(1, 1, 0, homeImageReleased, homeImagePressed);
	home.setAction(callback);
	home.setData(CMenu::buttonHome);

	client.add(logo);
	logo.setImage(logoImage);
	logo.setXY((client.getWidth() - logo.getWidth()) / 2, 1);

	client.add(back);
	back.initialize(1, 1, 0, backImageReleased, backImagePressed);
	back.setAction(callback);
	back.setXY(client.getWidth() - back.getWidth(), 1);
	back.setData(CMenu::buttonBack);

	client.add(title);
	title.initialize(titleText, titleColorR, titleColorG, titleColorB);
	title = newTitle;
	title.setXY((client.getWidth() - title.getWidth()) / 2, 60);

	client.add(line);
	line.setImage(titleLine);
	line.setXY((client.getWidth() - line.getWidth()) / 2, title.getY() + title.getHeight() + 5);

	client.add(items);
	items.setDirection(SOUTH);
	items.setXY(line.getX(), line.getY() + 6 + 10);   //6 = line thickness, 10 = space after line
	dsp.setPosition(items, items);

	for(int i = 0; i < itemsCount; i++)
	{
		itemsList[i].getButton()->setData(CMenu::buttonUser + i);
		itemsList[i].setAction(callback);
//		itemsList[i].render();
		items.add(itemsList[i]);
	}

	home.render();
	logo.render();
	back.render();
	title.render();
	line.render();
}

//-----------------------------------------------------------------------------
CMenu::ButtonId CMenu::getButtonId(const AbstractButtonContainer& src)
{
	if(&src == &home)
		return CMenu::buttonHome;

	if(&src == &back)
		return CMenu::buttonBack;

	CMenuItem* item = (CMenuItem*)items.getFirstChild();
	while(item)
	{
		CButton* button = item->getButton();
		if(&src == button)
			return (CMenu::ButtonId)button->getData();
		item = (CMenuItem*)item->getNextSibling();
	}

	return CMenu::buttonNone;
}





//void CMenu::render()
//{
//	if(home)
//		home->render();
//	logo.render();
//	back.render();
//}

//CMenu::CMenu(char* menuTitle, bool menuAsRoot, CMenuItem* menuItems, int menuItemsCount, GenericCallback<const AbstractButtonContainer&>& menuCallback)
//{
//	Container::setWidthHeight(624, 624);
//
//	background.setWidthHeight(*this);
//    background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
//    add(background);
//
////    home.initialize(0, 0, 0, BITMAP_HOME_ID, BITMAP_HOME_ID);
////    home.setAction(menuCallback);
////	add(home);
//
////    logo.setBitmap(BITMAP_PROLON_176X176_ID);
////	logo.setXY((Container::getWidth() - logo.getBitmap().getWidth()) /2 , 0);
////	add(logo);
//
////    back.initialize(Container::getWidth() - Bitmap(BITMAP_RETURN_50X50_ID).getWidth(), 0, 0, BITMAP_RETURN_50X50_ID, BITMAP_RETURN_50X50_ID);
////    back.setAction(menuCallback);
////    back.setVisible(!menuAsRoot);
////	add(back);
//
//	titleBuffer = (Unicode::UnicodeChar*)calloc(strlen(menuTitle) + 1, sizeof(Unicode::UnicodeChar));   //+1 = null termination character
//	title.setWildcard(titleBuffer);
////	title.setTypedText(T_MENU_TITLE);
//    title.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
//	Unicode::fromUTF8((uint8_t*)menuTitle, titleBuffer, strlen(menuTitle));
//	title.resizeToCurrentText();
//	title.setXY((Container::getWidth() - title.getWidth()) / 2, 60);
//	add(title);
//
////	line.setBitmap(BITMAP_MENU_LINE_WHITE_496X496X5_ID);
////	line.setXY((Container::getWidth() - line.getBitmap().getWidth()) / 2, title.getY() + title.getHeight() + 5);
////	add(line);
//
//	items.setDirection(SOUTH);
//	items.setXY(line.getX(), line.getY() + 5 + 10);   //5 = line thickness, 10 = space after line
//	for(int i = 0; i < menuItemsCount; i++)
//	{
//		menuItems[i].getButton()->setData(buttonUser + i);
//		menuItems[i].setAction(menuCallback);
//		items.add(menuItems[i]);
//	}
//	add(items);
//}
//
////-----------------------------------------------------------------------------
//ButtonId CMenu::getButtonId(const touchgfx::AbstractButtonContainer& src)
//{
//	if(&src == &home)
//		return buttonHome;
//
//	if(&src == &back)
//		return buttonBack;
//
//	CMenuItem* item = (CMenuItem*)items.getFirstChild();
//	while(item)
//	{
//		CButton* button = item->getButton();
//		if(&src == button)
//			return (ButtonId)button->getData();
//		item = (CMenuItem*)item->getNextSibling();
//	}
//
//	return buttonNone;
//}

}   //namespace touchgfx

































