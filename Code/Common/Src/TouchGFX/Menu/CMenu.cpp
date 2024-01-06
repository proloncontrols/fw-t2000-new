
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
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
#include <stdlib.h>
#include <CDisplay.hpp>
#include <Menu/CMenu.hpp>
#include <Menu/CMenuItem.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMenu::CMenu(Container& owner, int itemsCount)
      :CScreen(owner),
	   itemsCount(itemsCount),
	   itemsCounter(0)
{
	client.add(logo);
	logo.setBitmap(logoImage);
	logo.setXY((client.getWidth() - logo.getWidth()) / 2, 1);

	client.add(home);
	home.setXY(1, 1);
	home.setBitmaps(homeImageReleased, homeImagePressed);
	home.setId(ButtonId::ButtonHome);
	home.setGotoScreenId(ScreenId::ScreenHome);

	client.add(back);
	back.setBitmaps(backImageReleased, backImagePressed);
	back.setXY(client.getWidth() - back.getWidth(), 1);
	back.setId(ButtonId::ButtonBack);

	client.add(line);
	line.setBitmap(lineImage);
	line.setXY((client.getWidth() - line.getWidth()) / 2, titleTextPosY + titleTextHeight + 23);

	client.add(list);
	list.setDirection(SOUTH);
	list.setXY(line.getX(), line.getY() + titleLineThickness + titleLineSpacing);

	items = (CMenuItem**)malloc(sizeof(CMenuItem*) * itemsCount);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMenu::setTitle(const TypedText& textType)
{
	client.add(title);
	title.setTypedText(textType);
	title.setColor(Color::getColorFromRGB(titleColorR, titleColorG, titleColorB));
	title.setXY((client.getWidth() - title.getWidth()) / 2, titleTextPosY);
}

//-----------------------------------------------------------------------------
void CMenu::addItem(CMenuItem* newItem)
{
	if(itemsCounter < itemsCount)
	{
		newItem->setData(itemsCounter);   //To indicate index in list (used in radio menus)
		items[itemsCounter++] = newItem;
		list.add(*newItem);
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

		dsp.transpose(list);
		CMenuItem* item = (CMenuItem*)list.getFirstChild();
		while(item)
		{
			item->transpose();
			item = (CMenuItem*)item->getNextSibling();
		}
	}

	client.invalidate();
}

}   //namespace touchgfx
