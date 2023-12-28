
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
//         File : CMenuSettings.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Settings menu class header file
//=============================================================================
#ifndef CMENU_SETTINGS_HPP
#define CMENU_SETTINGS_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Menu/CMenu.hpp>
#include <Menu/CMenuItem.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenuSettings : public CMenu
{
	static const int menuItemsCount = 4;
	CMenuItem menuItems[menuItemsCount];

public:
	CMenuSettings(Container& owner, GenericCallback<const AbstractButtonContainer&>& callback)
	             :CMenu(owner, callback)
	{
		setTitle(T_MENU_SETTINGS_TITLE);

		menuItems[0].setButtonText(T_MENU_SETTINGS_OPTIONS);
		menuItems[0].setButtonGotoScreenId(ScreenId::ScreenOptions);

		menuItems[1].setButtonText(T_MENU_SETTINGS_ABOUT_ME);
		menuItems[1].setButtonGotoScreenId(ScreenId::ScreenAboutme);

		menuItems[2].setButtonText(T_MENU_SETTINGS_VISUALIZE);
		menuItems[2].setButtonGotoScreenId(ScreenId::ScreenVisualize);

		menuItems[3].setButtonText(T_MENU_SETTINGS_DEVICE);
		menuItems[3].setButtonGotoScreenId(ScreenId::ScreenDevice);

		setItems(menuItems, menuItemsCount, callback);

		transpose();

		back.setVisible(false);
	}
};

}   //namespace touchgfx


#endif   //CMENU_SETTINGS_HPP
