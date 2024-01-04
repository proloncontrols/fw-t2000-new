
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
//         File : CMenuItem.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Menu item class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stddef.h>
#include <CDisplay.hpp>
#include <Menu/CMenuItem.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMenuItem::CMenuItem()
{
	setWidthHeight(itemWidth, itemHeight);

	add(line);
	line.setXY(0, itemHeight - lineHeight);
	line.setBitmap(lineImage);

	btnList = NULL;
	btnData = NULL;
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMenuItem::setText(const TypedText& textType)
{
	if(btnList)
		btnList->setText(textType);
	else
		btnData->setText(textType);
}

void CMenuItem::setInternalAction(GenericCallback<const AbstractButtonContainer&>& callback)
{
	if(btnList)
		btnList->setAction(callback);
	else
		btnData->setAction(callback);
}

void CMenuItem::setNextScreenId(ScreenId id)
{
	if(btnList)
		btnList->setGotoScreenId(id);
	else
		btnData->setGotoScreenId(id);
}
ScreenId CMenuItem::getNextScreenId()
{
	if(btnList)
		return btnList->getGotoScreenId();
	return btnData->getGotoScreenId();
}

void CMenuItem::setData(uint32_t data)
{
	if(btnList)
		btnList->setData(data);
	else
		btnData->setData(data);
}
uint32_t CMenuItem::getData()
{
	if(btnList)
		return btnList->getData();
	return btnData->getData();
}

void CMenuItem::transpose()
{
	if(dsp.orientation != CDisplay::NATIVE)
	{
		dsp.transpose(*this);
		line.transpose();
		if(btnList)
			btnList->transpose();
		else
			btnData->transpose();
	}

	invalidate();
}

}   //namespace touchgfx
