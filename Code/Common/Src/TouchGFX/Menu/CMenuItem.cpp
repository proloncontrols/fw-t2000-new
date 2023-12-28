
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
//         File : CMenuItem.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Menu item class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CDisplay.hpp>
#include <Menu/CMenuItem.hpp>
#include <touchgfx/Color.hpp>


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

	add(button);
	button.setXY(2, (itemHeight - lineHeight - buttonHeight) / 2);
	button.setBitmaps(buttonImage, buttonImage);
	button.setTouchHeight(76);
	button.setTextPosition(30, 4);
	button.setTextColors(Color::getColorFromRGB(buttonTextColorReleasedR, buttonTextColorReleasedG, buttonTextColorReleasedB),
			             Color::getColorFromRGB(buttonTextColorPressedR, buttonTextColorPressedG, buttonTextColorPressedB));
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMenuItem::setButtonText(const TypedText& textType)
{
	button.setText(textType);
}

//-----------------------------------------------------------------------------
void CMenuItem::setButtonAction(GenericCallback<const AbstractButtonContainer&>& callback)
{
	button.setAction(callback);
}

//-----------------------------------------------------------------------------
void CMenuItem::setButtonGotoScreenId(ScreenId id)
{
	button.setGotoScreenId(id);
}

//-----------------------------------------------------------------------------
CButton* CMenuItem::getButton()
{
	return &button;
}

//-----------------------------------------------------------------------------
void CMenuItem::transpose()
{
	if(dsp.orientation != CDisplay::NATIVE)
	{
		dsp.transpose(*this);
		line.transpose();
		button.transpose();
	}

	invalidate();
}

}   //namespace touchgfx
