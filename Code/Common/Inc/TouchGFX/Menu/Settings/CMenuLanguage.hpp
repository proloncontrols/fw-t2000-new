
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
//         File : CMenuLanguage.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Options language selection menu class header file
//=============================================================================
#ifndef CMENU_LANGUAGE_HPP
#define CMENU_LANGUAGE_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Menu/CMenuData.hpp>
#include <Menu/CMenuItemData.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenuLanguage : public CMenuData
{
	static const int menuItemsCount = 2;
	CMenuItemData menuItems[menuItemsCount];

public:
	CMenuLanguage(Container& owner, GenericCallback<uint32_t, uint32_t>& callback)
	             :CMenuData(owner, callback)
	{
		setTitle(T_MENU_LANGUAGE_TITLE);

		menuItems[0].setText(T_MENU_LANGUAGE_ENGLISH);
		menuItems[1].setText(T_MENU_LANGUAGE_FRENCH);

		setItems(menuItems, menuItemsCount);

		transpose();

		back.setGotoScreenId(ScreenId::ScreenOptions);
	}
};

}   //namespace touchgfx


#endif   //CMENU_LANGUAGE_HPP
