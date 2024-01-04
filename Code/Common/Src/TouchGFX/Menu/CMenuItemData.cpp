
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
//         File : CMenuItemData.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Data menu item class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Menu/CMenuItemData.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
CMenuItemData::CMenuItemData()
{
	btnData = new CButtonToggle;
	add(*btnData);
	btnData->setXY(2, (itemHeight - lineHeight - buttonHeight) / 2);
	btnData->setBitmaps(buttonImage, buttonImageSelected);
	btnData->setTouchHeight(76);
	btnData->setTextPosition(30, 4);
	btnData->setTextColors(Color::getColorFromRGB(buttonTextColorReleasedR, buttonTextColorReleasedG, buttonTextColorReleasedB),
						   Color::getColorFromRGB(buttonTextColorPressedR, buttonTextColorPressedG, buttonTextColorPressedB));
}

const CButtonToggle* CMenuItemData::getButton()
{
	return btnData;
}

void CMenuItemData::setState(bool newState)
{
	btnData->setState(newState);
}

bool CMenuItemData::getState()
{
	return btnData->getState();
}

}   //namespace touchgfx
