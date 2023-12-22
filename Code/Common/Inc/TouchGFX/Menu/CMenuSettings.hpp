
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
	const TypedText& title = T_MENU_SETTINGS_TITLE;

	const TypedText& item0 = T_MENU_SETTINGS_OPTIONS;
	const TypedText& item1 = T_MENU_SETTINGS_ABOUT_ME;
	const TypedText& item2 = T_MENU_SETTINGS_VISUALIZE;
	const TypedText& item3 = T_MENU_SETTINGS_DEVICE;

	static const int menuItemsCount = 4;

	CMenuItem menuItems[menuItemsCount];

public:
	CMenuSettings(Container& ownerContainer, GenericCallback<const AbstractButtonContainer&>& callback);
};

}   //namespace touchgfx


#endif   //CMENU_SETTINGS_HPP
