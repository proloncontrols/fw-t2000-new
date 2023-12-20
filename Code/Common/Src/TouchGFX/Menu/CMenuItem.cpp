
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
#include <BitmapDatabase.hpp>


namespace touchgfx
{
//#define SHOW_BACKGROUND
//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMenuItem::CMenuItem()
{
	Container::setWidthHeight(itemWidth, itemHeight);
	background = NULL;

#ifdef SHOW_BACKGROUND
	background = new Box;
	background->setWidthHeight(*this);
	background->setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
	add(*background);
#endif

	line.setImage(lineImage);
	line.setXY(0, itemHeight - lineHeight);
	add(line);

	button.initialize(2, (itemHeight - lineHeight - buttonHeight) / 2, buttonHeight,
			          buttonImage, buttonImage,
			          buttonTextType,
					  touchgfx::Color::getColorFromRGB(buttonTextColorReleasedR, buttonTextColorReleasedG, buttonTextColorReleasedB),
					  touchgfx::Color::getColorFromRGB(buttonTextColorPressedR, buttonTextColorPressedG, buttonTextColorPressedB));
	button.setTextPosition(30, 4);
	add(button);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMenuItem::setText(char* newText)
{
	button.setTextPosition(30, 4);
	button.setText(newText);
}

//-----------------------------------------------------------------------------
void CMenuItem::setAction(GenericCallback<const AbstractButtonContainer&>& callback)
{
	button.setAction(callback);
}

//-----------------------------------------------------------------------------
const CButton& CMenuItem::getButton()
{
	return button;
}

//-----------------------------------------------------------------------------
void CMenuItem::render()
{
	dsp.setPosition(*this, *this);
	line.render();
	button.render();
	Container::invalidate();
}

}   //namespace touchgfx
