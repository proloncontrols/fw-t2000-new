
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
#include <Menu/CMenuList.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenuSettings : public CMenuList
{
	static const int menuItemsCount = 4;

public:
	CMenuSettings(Container& owner, GenericCallback<uint32_t, uint32_t>& callback)
	             :CMenuList(owner, callback, menuItemsCount)
	{
		home.setVisible(false);
		back.setGotoScreenId(ScreenId::ScreenHome);

		setTitle(T_MENU_SETTINGS_TITLE);
		addItem(new CMenuItem(T_MENU_SETTINGS_OPTIONS, ScreenId::ScreenOptions));
		addItem(new CMenuItem(T_MENU_SETTINGS_ABOUTME, ScreenId::ScreenAboutme));
		addItem(new CMenuItem(T_MENU_SETTINGS_VISUALIZE, ScreenId::ScreenVisualize));
		addItem(new CMenuItem(T_MENU_SETTINGS_DEVICE, ScreenId::ScreenDevice));

		transpose();
	}
};

}   //namespace touchgfx


#endif   //CMENU_SETTINGS_HPP
