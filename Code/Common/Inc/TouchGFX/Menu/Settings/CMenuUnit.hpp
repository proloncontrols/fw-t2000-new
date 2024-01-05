
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
//         File : CMenuUnits.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Options temperature units selection  menu class header file
//=============================================================================
#ifndef CMENU_UNITS_HPP
#define CMENU_UNITS_HPP


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
class CMenuUnit : public CMenu
{
	static const int menuItemsCount = 2;
//	CMenuItem menuItems[menuItemsCount];

public:
//	CMenuUnit(Container& owner, GenericCallback<const AbstractButtonContainer&>& callback)
	CMenuUnit(Container& owner, GenericCallback<uint32_t, uint32_t>& callback)
//    :CMenu(owner, callback)
	                 :CMenu(owner, menuItemsCount)
	{
////		previous = ScreenId::ScreenOptions;
//
//		setTitle(T_MENU_UNIT_TITLE);
//
//		menuItems[0].setText(T_MENU_UNIT_CELSIUS);
//		menuItems[1].setText(T_MENU_UNIT_FAHRENHEIT);
//
////		setItems(menuItems, menuItemsCount, callback);
//
//		transpose();
	}
};

}   //namespace touchgfx


#endif   //CMENU_UNITS_HPP
