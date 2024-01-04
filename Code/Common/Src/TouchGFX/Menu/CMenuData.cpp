
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
//         File : CMenuData.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Data menu base class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Menu/CMenuData.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMenuData::CMenuData(Container& owner, GenericCallback<uint32_t, uint32_t>& extCallback)
		  :CMenu(owner),
		   internalCallback(this, &CMenuData::internalButtonClicked),
		   externalCallback(&extCallback)
{
	home.setAction(internalCallback);
	back.setAction(internalCallback);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMenuData::setItems(CMenuItemData* itemsList, int itemsCount)
{
	client.add(items);
	items.setDirection(SOUTH);
	items.setXY(line.getX(), line.getY() + 6 + 10);   //6 = line thickness, 10 = space after line

	for(int i = 0; i < itemsCount; i++)
	{
		itemsList[i].setInternalAction(internalCallback);
		itemsList[i].setData(i);
		items.add(itemsList[i]);
	}
}

//-----------------------------------------------------------------------------
void CMenuData::internalButtonClicked(const AbstractButtonContainer& src)
{
	externalCallback->execute((uint32_t)&src, 0);
}

}   //namespace touchgfx
