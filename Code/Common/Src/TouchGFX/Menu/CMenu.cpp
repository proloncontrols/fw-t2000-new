
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
CMenu::CMenu(Container& owner)
      :CScreen(owner)
{
	client.add(logo);
	logo.setBitmap(logoImage);
	logo.setXY((client.getWidth() - logo.getWidth()) / 2, 1);

	client.add(home);
	home.setXY(1, 1);
	home.setBitmaps(homeImageReleased, homeImagePressed);
	home.setData(ButtonId::ButtonHome);

	client.add(back);
	back.setBitmaps(backImageReleased, backImagePressed);
	back.setXY(client.getWidth() - back.getWidth(), 1);
	back.setData(ButtonId::ButtonBack);
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

//-----------------------------------------------------------------------------
ButtonId CMenu::getButtonId(const AbstractButtonContainer& src)
{
	if(&src == &home)
		return ButtonId::ButtonHome;

	if(&src == &back)
		return ButtonId::ButtonBack;

	CMenuItem* item = (CMenuItem*)items.getFirstChild();
	while(item)
	{
//		CButton* button = (CButton*)item->getButton();
//		if(&src == button)
//			return (ButtonId)button->getData();
//		item = (CMenuItem*)item->getNextSibling();
	}

	return ButtonId::ButtonNone;
}

}   //namespace touchgfx
