
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
//  Description : Menu base class header file
//=============================================================================
#ifndef CMENU_HPP
#define CMENU_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CImage.hpp>
#include <CButton.hpp>
#include <Menu/CMenuItem.hpp>
#include <Screen/CScreen.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Containers/Listlayout.hpp>
#include <touchgfx/Containers/ScrollableContainer.hpp>

namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMenu : public CScreen
{
	const uint8_t titleColorR = 255;
	const uint8_t titleColorG = 255;
	const uint8_t titleColorB = 255;

	const BitmapId homeImageReleased = BITMAP_HOME_ID;
	const BitmapId homeImagePressed = BITMAP_HOME_ID;
	const BitmapId backImageReleased = BITMAP_RETURN_50X50_ID;
	const BitmapId backImagePressed = BITMAP_RETURN_50X50_ID;
	const BitmapId logoImage = BITMAP_PROLON_178X178_ID;
	const BitmapId lineImage = BITMAP_MENU_LINE_WHITE_496X496X6_ID;

	CImage logo;
	CImage line;
	ListLayout items;
	ScrollableContainer scroll;

protected:
	CButton home;
	CButton back;
	CLabel title;

	void setTitle(const TypedText& textType);
	void setItems(CMenuItem* itemsList, int itemsCount, GenericCallback<const AbstractButtonContainer&>& callback);

public:
	typedef enum {
		buttonNone = -3,
		buttonHome = -2,
		buttonBack = -1,
		buttonUser =  0
	} ButtonId;

	CMenu(Container& owner, GenericCallback<const AbstractButtonContainer&>& callback);

	ButtonId getButtonId(const AbstractButtonContainer& src);
	void transpose();
};

}   //namespace touchgfx


#endif   //CMENU_HPP
