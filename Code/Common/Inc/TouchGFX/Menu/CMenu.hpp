
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
//         File : CMenu.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Menu class header file
//=============================================================================
#ifndef CMENU_HPP
#define CMENU_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CImage.hpp>
#include <CButton.hpp>
#include <Menu/CMenuItem.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <touchgfx/Containers/Listlayout.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenu : public Container
{
public:
	CMenu(char* menuTitle, bool menuAsRoot, CMenuItem* menuItems, int menuItemCount, GenericCallback<const AbstractButtonContainer&>& menuCallback);
	ButtonId getButtonId(const touchgfx::AbstractButtonContainer& src);

private:
	touchgfx::Box background;
	CButton home;
	CButton back;
	CImage logo;
	CImage line;
	TextAreaWithOneWildcard title;
	Unicode::UnicodeChar* titleBuffer = NULL;
	ListLayout items;
};

}   //namespace touchgfx


#endif   //CMENU_HPP
