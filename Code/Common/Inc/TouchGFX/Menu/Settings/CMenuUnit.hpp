
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
//  Description : Temperature units selection menu class header file
//=============================================================================
#ifndef CMENU_UNITS_HPP
#define CMENU_UNITS_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Menu/CMenuRadio.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenuUnit : public CMenuRadio
{
	static const int menuItemsCount = 2;

public:
	CMenuUnit(Container& owner, GenericCallback<uint32_t, uint32_t>& callback)
	         :CMenuRadio(owner, callback, menuItemsCount)
	{
		back.setGotoScreenId(ScreenId::ScreenOptions);

		setTitle(T_MENU_UNIT_TITLE);
		addItem(new CMenuItem(CMenuItem::ModeRadio, T_MENU_UNIT_CELSIUS));
		addItem(new CMenuItem(CMenuItem::ModeRadio, T_MENU_UNIT_FAHRENHEIT));

		transpose();
	}
};

}   //namespace touchgfx


#endif   //CMENU_UNITS_HPP
