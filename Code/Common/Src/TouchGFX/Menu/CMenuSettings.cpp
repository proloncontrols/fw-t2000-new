
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
//         File : CMenuSettings.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Settings menu class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Menu/CMenuSettings.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMenuSettings::CMenuSettings(Container& ownerContainer, GenericCallback<const AbstractButtonContainer&>& callback)
              :CMenu(ownerContainer, callback)
{
	setTitle(title);

	menuItems[0].setButtonText(item0);
	menuItems[0].setButtonAction(callback);

	menuItems[1].setButtonText(item1);
	menuItems[1].setButtonAction(callback);

	menuItems[2].setButtonText(item2);
	menuItems[2].setButtonAction(callback);

	menuItems[3].setButtonText(item3);
	menuItems[3].setButtonAction(callback);

	setItems(menuItems, menuItemsCount);

	home.setVisible(false);
	back.setVisible(false);

	CMenu::transpose();
}

}   //namespace touchgfx
