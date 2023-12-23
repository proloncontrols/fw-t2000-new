
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
#include <CDisplay.hpp>
#include <Menu/CMenu.hpp>
#include <Menu/CMenuItem.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMenu::CMenu(Container& owner, GenericCallback<const AbstractButtonContainer&>& callback)
      :CScreen(owner)
{
	client.add(home);
	home.setXY(1, 1);
	home.setBitmaps(homeImageReleased, homeImagePressed);
	home.setAction(callback);
	home.setData(CMenu::buttonHome);

	client.add(back);
	back.setBitmaps(backImageReleased, backImagePressed);
	back.setAction(callback);
	back.setXY(client.getWidth() - back.getWidth(), 1);
	back.setData(CMenu::buttonBack);

	client.add(logo);
	logo.setBitmap(logoImage);
	logo.setXY((client.getWidth() - logo.getWidth()) / 2, 1);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMenu::setTitle(const TypedText& textType)
{
	client.add(title);
	title.setTypedText(textType);
	title.setColor(Color::getColorFromRGB(titleColorR, titleColorG, titleColorB));
	title.setXY((client.getWidth() - title.getWidth()) / 2, 60);

	client.add(line);
	line.setBitmap(lineImage);
	line.setXY((client.getWidth() - line.getWidth()) / 2, title.getY() + title.getHeight() + 5);
}

//-----------------------------------------------------------------------------
void CMenu::setItems(CMenuItem* itemsList, int itemsCount, GenericCallback<const AbstractButtonContainer&>& callback)
{
	client.add(items);
	items.setDirection(SOUTH);
	items.setXY(line.getX(), line.getY() + 6 + 10);   //6 = line thickness, 10 = space after line

	for(int i = 0; i < itemsCount; i++)
	{
		itemsList[i].getButton()->setAction(callback);
		itemsList[i].getButton()->setData(i);
		items.add(itemsList[i]);
	}
}

//-----------------------------------------------------------------------------
void CMenu::transpose()
{
	if(dsp.orientation != CDisplay::NATIVE)
	{
		home.transpose();
		back.transpose();
		logo.transpose();
		title.transpose();
		line.transpose();

		dsp.transpose(items);
		CMenuItem* item = (CMenuItem*)items.getFirstChild();
		while(item)
		{
			item->transpose();
			item = (CMenuItem*)item->getNextSibling();
		}
	}

	client.invalidate();
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
//void CMenu::initialize(const char* newTitle, CMenuItem* itemsList, int itemsCount, GenericCallback<const AbstractButtonContainer&>& callback)
//{
////	client.add(home);
////	home.initialize(1, 1, 0, homeImageReleased, homeImagePressed);
////	home.setAction(callback);
////	home.setData(CMenu::buttonHome);
////
////	client.add(logo);
////	logo.setImage(logoImage);
////	logo.setXY((client.getWidth() - logo.getWidth()) / 2, 1);
////
////	client.add(back);
////	back.initialize(1, 1, 0, backImageReleased, backImagePressed);
////	back.setAction(callback);
////	back.setXY(client.getWidth() - back.getWidth(), 1);
////	back.setData(CMenu::buttonBack);
////
////	client.add(title);
////	title.initialize(titleText, titleColorR, titleColorG, titleColorB);
////	title = newTitle;
////	title.setXY((client.getWidth() - title.getWidth()) / 2, 60);
////
////	client.add(line);
////	line.setImage(titleLine);
////	line.setXY((client.getWidth() - line.getWidth()) / 2, title.getY() + title.getHeight() + 5);
////
////	client.add(items);
////	items.setDirection(SOUTH);
////	items.setXY(line.getX(), line.getY() + 6 + 10);   //6 = line thickness, 10 = space after line
////	dsp.setPosition(items, items);
////
////	for(int i = 0; i < itemsCount; i++)
////	{
////		itemsList[i].getButton()->setData(CMenu::buttonUser + i);
////		itemsList[i].setAction(callback);
//////		itemsList[i].render();
////		items.add(itemsList[i]);
////	}
////
////	client.add(scroll);
////	scroll.setXY(items);
////	scroll.setWidth(items.getWidth());
////	scroll.setHeight(client.getHeight() - items.getHeight());
////    scroll.setScrollbarsColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
////	scroll.add(items);
////
////	home.render();
////	logo.render();
////	back.render();
////	title.render();
////	line.render();
//
////	client.add(home);
////	home.setXY(1, 1);
//////	home.initialize(1, 1, 0, homeImageReleased, homeImagePressed);
////	home.setBitmaps(homeImageReleased, homeImagePressed);
////	home.setAction(callback);
////	home.setData(CMenu::buttonHome);
//
//	client.add(logo);
////	logo.setImage(logoImage);
//	logo.setXY((client.getWidth() - logo.getWidth()) / 2, 1);
//
//	client.add(back);
////	back.initialize(1, 1, 0, backImageReleased, backImagePressed);
//	back.setAction(callback);
//	back.setXY(client.getWidth() - back.getWidth(), 1);
//	back.setData(CMenu::buttonBack);
//
//	client.add(title);
//	//title.initialize(titleText, titleColorR, titleColorG, titleColorB);
//	//title = newTitle;
//	title.setXY((client.getWidth() - title.getWidth()) / 2, 60);
//
//	client.add(line);
////	line.setImage(titleLine);
//	line.setXY((client.getWidth() - line.getWidth()) / 2, title.getY() + title.getHeight() + 5);
//
//	items.setDirection(SOUTH);
//	items.setXY(0, 0);
//	for(int i = 0; i < itemsCount; i++)
//	{
//		itemsList[i].getButton()->setData(CMenu::buttonUser + i);
//		itemsList[i].setButtonAction(callback);
//		items.add(itemsList[i]);
//	}
//
//	scroll.setXY(line.getX(), line.getY() + 6 + 10);   //6 = line thickness, 10 = space after line
//	scroll.setWidth(items.getWidth() + 40);
//	scroll.setHeight(client.getHeight() - scroll.getY());
//
//	scroll.enableHorizontalScroll(false);
////	scroll.setMaxVelocity(10);
//	scroll.setScrollThreshold(5);
////	scroll.setScrollDurationSpeedup(0);
////	scroll.setScrollDurationSlowdown(0);
//
//    scroll.setScrollbarsColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
//    scroll.setScrollbarWidth(10);
//    scroll.setScrollbarsPermanentlyVisible(true);
//    scroll.setScrollbarsVisible(true);
//	scroll.add(items);
//	client.add(scroll);
//
////	home.render();
////	logo.render();
////	back.render();
////	title.render();
////	line.render();
//}

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

}   //namespace touchgfx

































