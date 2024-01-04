
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
//         File : CMenuItemData.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Data menu item class header file
//=============================================================================
#ifndef CMENU_ITEM_DATA_HPP
#define CMENU_ITEM_DATA_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Menu/CMenuItem.hpp>
#include <Menu/CMenuItemData.hpp>
#include <BitmapDatabase.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenuItemData : public CMenuItem
{
	const BitmapId buttonImageSelected = BITMAP_MENU_SELECTED_496X496X76_ID;

public:
	CMenuItemData();

	const CButtonToggle* getButton();
	void setState(bool newState);
	bool getState();
};

}   //namespace touchgfx


#endif   //CMENU_ITEM_DATA_HPP
