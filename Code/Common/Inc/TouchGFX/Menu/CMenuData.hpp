
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
//         File : CMenuData.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Data menu base class header file
//=============================================================================
#ifndef CMENU_DATA_HPP
#define CMENU_DATA_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Menu/CMenu.hpp>
#include <Menu/CMenuItemData.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenuData : public CMenu
{
    Callback<CMenuData, const AbstractButtonContainer&> internalCallback;
    GenericCallback<uint32_t, uint32_t>* externalCallback;

    void internalButtonClicked(const AbstractButtonContainer& src);

public:
	CMenuData(Container& owner, GenericCallback<uint32_t, uint32_t>& extCallback);

	void setItems(CMenuItemData* itemsList, int itemsCount);
};

}   //namespace touchgfx


#endif   //CMENU_DATA_HPP
