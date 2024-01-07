
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
//         File : CMenuAboutMe.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : About me menu class header file
//=============================================================================
#ifndef CMENU_ABOUT_ME_HPP
#define CMENU_ABOUT_ME_HPP


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
class CMenuAboutme : public CMenu
{
public:
	CMenuAboutme(Container& owner, GenericCallback<const AbstractButtonContainer&>& callback)
//    :CMenu(owner, callback)
	            :CMenu(owner, NULL, 1)
	{
		setTitle(T_MENU_ABOUT_ME_TITLE);

		transpose();
	}
};

}   //namespace touchgfx


#endif   //CMENU_ABOUT_ME_HPP
