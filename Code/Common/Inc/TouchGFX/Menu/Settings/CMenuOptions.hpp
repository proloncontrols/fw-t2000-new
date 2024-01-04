
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
//         File : CMenuOptions.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Options menu class header file
//=============================================================================
#ifndef CMENU_OPTIONS_HPP
#define CMENU_OPTIONS_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Menu/CMenuList.hpp>
#include <Menu/CMenuItemList.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenuOptions : public CMenuList
{
	static const int menuItemsCount = 4;
	CMenuItemList menuItems[menuItemsCount];

public:
	CMenuOptions(Container& owner, GenericCallback<uint32_t, uint32_t>& callback)
	            :CMenuList(owner, callback)
	{
//		previous = ScreenId::ScreenSettings;

		setTitle(T_MENU_OPTIONS_TITLE);

		menuItems[0].setText(T_MENU_OPTIONS_LANGUAGE);
		menuItems[0].setNextScreenId(ScreenId::ScreenLanguage);

		menuItems[1].setText(T_MENU_OPTIONS_UNIT);
		menuItems[1].setNextScreenId(ScreenId::ScreenUnit);

		menuItems[2].setText(T_MENU_OPTIONS_TIME);
		menuItems[2].setNextScreenId(ScreenId::ScreenTime);

		menuItems[3].setText(T_MENU_OPTIONS_ORIENTATION);
		menuItems[3].setNextScreenId(ScreenId::ScreenOrientation);

		setItems(menuItems, menuItemsCount);

		transpose();

		back.setGotoScreenId(ScreenId::ScreenSettings);
	}
};

}   //namespace touchgfx


#endif   //CMENU_OPTIONS_HPP
