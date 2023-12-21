
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
//         File : CMenu.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Menu base class header file
//=============================================================================
#ifndef CMENU_HPP
#define CMENU_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CImage.hpp>
#include <CButton.hpp>
#include <CString.hpp>
#include <Screen/CScreen.hpp>
#include <BitmapDatabase.hpp>
#include <Menu/CMenuItem.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <touchgfx/Containers/Listlayout.hpp>
#include <touchgfx/Containers/ScrollableContainer.hpp>

namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenu : public CScreen
{
	const BitmapId homeImageReleased = BITMAP_HOME_ID;
	const BitmapId homeImagePressed = BITMAP_HOME_ID;

	const BitmapId backImageReleased = BITMAP_RETURN_50X50_ID;
	const BitmapId backImagePressed = BITMAP_RETURN_50X50_ID;

	const BitmapId logoImage = BITMAP_PROLON_178X178_ID;

	const uint8_t titleColorR = 255;
	const uint8_t titleColorG = 255;
	const uint8_t titleColorB = 255;
	const TypedTextId titleText = T_MENU_TITLE;
	const BitmapId titleLine = BITMAP_MENU_LINE_WHITE_496X496X6_ID;

	CButton home;
	CButton back;
	CImage logo;
	CImage line;
	ListLayout items;
	ScrollableContainer scroll;

protected:
	CString title;

//	void addTitle(const char* newTitle);
//	void addItems(CMenuItem* ItemList, int itemCount, GenericCallback<const AbstractButtonContainer&>& callback);
	void initialize(const char* newTitle, CMenuItem* itemsList, int itemsCount, GenericCallback<const AbstractButtonContainer&>& callback);

public:
	typedef enum {
		buttonNone = -3,
		buttonHome = -2,
		buttonBack = -1,
		buttonUser =  0
	} ButtonId;

	CMenu(Container& ownerContainer, GenericCallback<const AbstractButtonContainer&>& callback);

	CMenu::ButtonId getButtonId(const AbstractButtonContainer& src);


//	void render();

//public:
//	CMenu(char* menuTitle, bool menuAsRoot, CMenuItem* menuItems, int menuItemsCount, GenericCallback<const AbstractButtonContainer&>& menuCallback);
//	ButtonId getButtonId(const touchgfx::AbstractButtonContainer& src);
//
//private:
//	touchgfx::Box background;
//	CButton home;
//	CButton back;
//	CImage logo;
//	CImage line;
//	TextAreaWithOneWildcard title;
//	Unicode::UnicodeChar* titleBuffer = NULL;
//	ListLayout items;
};

}   //namespace touchgfx


#endif   //CMENU_HPP
