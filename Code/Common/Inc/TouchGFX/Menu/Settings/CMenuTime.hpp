
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
//         File : CMenuTime.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Options time format selection menu class header file
//=============================================================================
#ifndef CMENU_TIME_HPP
#define CMENU_TIME_HPP


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
class CMenuTime : public CMenu
{
	static const int menuItemsCount = 2;
	CMenuItem menuItems[menuItemsCount];

public:
	CMenuTime(Container& owner, GenericCallback<const AbstractButtonContainer&>& callback)
             :CMenu(owner, callback)
	{
		previous = ScreenId::ScreenOptions;

		setTitle(T_MENU_TIME_TITLE);

		menuItems[0].setButtonText(T_MENU_TIME_STANDARD);
		menuItems[1].setButtonText(T_MENU_TIME_INTERNATIONAL);

		setItems(menuItems, menuItemsCount, callback);

		transpose();
	}
};

}   //namespace touchgfx


#endif   //CMENU_TIME_HPP
