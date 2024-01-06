
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
//         File : CMenuCheck.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Check box style data selection menu class header file
//=============================================================================
#ifndef CMENU_CHECK_HPP
#define CMENU_CHECK_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Menu/CMenu.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenuCheck : public CMenu
{
    Callback<CMenuCheck, const AbstractButtonContainer&> internalCallback;
    GenericCallback<uint32_t, uint32_t>* externalCallback;

    void internalButtonClicked(const AbstractButtonContainer& src)
    {
    }

public:
	CMenuCheck(Container& owner, GenericCallback<uint32_t, uint32_t>& extCallback, int itemsCount)
	          :CMenu(owner, itemsCount),
	           internalCallback(this, &CMenuCheck::internalButtonClicked),
	           externalCallback(&extCallback)
	{
		home.setAction(internalCallback);
		back.setAction(internalCallback);
	}

	virtual void addItem(CMenuItem* newItem)
	{
		CMenu::addItem(newItem);
		newItem->setInternalAction(internalCallback);
	}
};

}   //namespace touchgfx


#endif   //CMENU_CHECK_HPP
