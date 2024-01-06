
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
CMenuItem::CMenuItem(Mode newMode)
{
	setWidthHeight(itemWidth, itemHeight);

	add(line);
	line.setXY(0, itemHeight - lineHeight);
	line.setBitmap(lineImage);

	if(newMode == ModeList)
	{
		btnData = NULL;
		btnList = new CButton;
		add(*btnList);
		btnList->setXY(2, (itemHeight - lineHeight - buttonHeight) / 2);
		btnList->setBitmaps(buttonImage, buttonImage);
		btnList->setTouchHeight(76);
		btnList->setTextPosition(30, 4);
		btnList->setTextColors(Color::getColorFromRGB(buttonTextColorReleasedR, buttonTextColorReleasedG, buttonTextColorReleasedB),
							   Color::getColorFromRGB(buttonTextColorPressedR, buttonTextColorPressedG, buttonTextColorPressedB));
	}
	else
	{
		btnList = NULL;
		btnData = new CButtonToggle;
		add(*btnData);
		btnData->setXY(2, (itemHeight - lineHeight - buttonHeight) / 2);
		btnData->setBitmaps(buttonImage, buttonImageSelected);
		btnData->setTouchHeight(76);
		btnData->setTextPosition(30, 4);
		btnData->setTextColors(Color::getColorFromRGB(buttonTextColorReleasedR, buttonTextColorReleasedG, buttonTextColorReleasedB),
							   Color::getColorFromRGB(buttonTextColorPressedR, buttonTextColorPressedG, buttonTextColorPressedB));
	}
}

//-----------------------------------------------------------------------------
CMenuItem::CMenuItem(Mode newMode, const TypedText& textType)
          :CMenuItem(newMode)
{
	if(btnList)
		btnList->setText(textType);
	else
		btnData->setText(textType);
}

//-----------------------------------------------------------------------------
CMenuItem::CMenuItem(Mode newMode, const TypedText& textType, ScreenId nextId)
          :CMenuItem(newMode, textType)
{
	if(btnList)
		btnList->setGotoScreenId(nextId);
	else
		btnData->setGotoScreenId(nextId);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMenuItem::setInternalAction(GenericCallback<const AbstractButtonContainer&>& callback)
{
	if(btnList)
		btnList->setAction(callback);
	else
		btnData->setAction(callback);
}

//-----------------------------------------------------------------------------
ScreenId CMenuItem::getNextScreenId()
{
	if(btnList)
		return btnList->getGotoScreenId();
	return btnData->getGotoScreenId();
}

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
void CMenuItem::setState(bool state)
{
	if(btnData)
		btnData->setState(state);
}
bool CMenuItem::getState()
{
	if(btnData)
		return btnData->getState();
	return false;
}

//-----------------------------------------------------------------------------
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
