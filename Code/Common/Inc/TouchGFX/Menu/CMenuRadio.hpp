
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
//         File : CMenuRadio.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Radio button style data selection menu class header file
//=============================================================================
#ifndef CMENU_RADIO_HPP
#define CMENU_RADIO_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Menu/CMenu.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenuRadio : public CMenu
{
	int selection;

    Callback<CMenuRadio, const AbstractButtonContainer&> internalCallback;
    GenericCallback<uint32_t, uint32_t>* externalCallback;

    void internalButtonClicked(const AbstractButtonContainer& src)
    {
    	CButtonToggle* btn = (CButtonToggle*)&src;

    	if((btn->getId() == ButtonId::ButtonHome) || (btn->getId() == ButtonId::ButtonBack))
        	externalCallback->execute(btn->getGotoScreenId(), 0);
    	else
    	{
        	for(int i = 0; i < itemsCount; i++)
        		items[i]->setState(false);
        	btn->setState(true);
        	selection = btn->getData();
    	}
    }

public:
	CMenuRadio(Container& owner, GenericCallback<uint32_t, uint32_t>& extCallback, int itemsCount)
	          :CMenu(owner, itemsCount),
			   selection(0),
	           internalCallback(this, &CMenuRadio::internalButtonClicked),
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

	void setSelection(int newSelection)
	{
		selection = newSelection;
		items[selection]->setState(true);
	}

	int getSelection()
	{
		return selection;
	}
};

}   //namespace touchgfx


#endif   //CMENU_RADIO_HPP
