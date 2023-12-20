
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
//         File : CButton.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Button class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <CButton.hpp>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{
//#define SHOW_BACKGROUND
//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CButton::CButton()
{
	background = NULL;
	imgReleased = NULL;
	imgPressed = NULL;
	text = NULL;

#ifdef SHOW_BACKGROUND
	background = new Box;
	background->setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
	add(*background);
#endif
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CButton::initialize(int16_t x, int16_t y, int16_t width, int16_t height)
{
	Container::setPosition(x, y, width, height);

#ifdef SHOW_BACKGROUND
	background->setWidthHeight(*this);
#endif
}

//-----------------------------------------------------------------------------
void CButton::initialize(int16_t x, int16_t y, int16_t touchHeight, Bitmap released, Bitmap pressed)
{
	imgReleased = new CImage;
	imgReleased->setImage(released);
	imgReleased->setXY(0, 0);
	imgReleased->setVisible(true);
	add(*imgReleased);

	imgPressed = new CImage;
	imgPressed->setImage(released);
	imgPressed->setXY(0, 0);
	imgPressed->setVisible(false);
	add(*imgPressed);

	Container::setXY(x, y);
	Container::setWidth(imgReleased->getWidth());
	if(touchHeight != 0)
		Container::setHeight(touchHeight);                //Touch area is the image visible area only (rectangle)
	else
		Container::setHeight(imgReleased->getHeight());   //Touch area is the entire image area, visible and not visible (square)

	imgReleased->render();
	imgPressed->render();

#ifdef SHOW_BACKGROUND
	background->setWidthHeight(*this);
#endif
}

//-----------------------------------------------------------------------------
void CButton::initialize(int16_t x, int16_t y, int16_t touchHeight, Bitmap released, Bitmap pressed, const TypedText& textType, colortype textReleased, colortype textPressed)
{
	initialize(x, y, touchHeight, released, pressed);

	text = new CString;
	text->initialize(textType, Color::getRed(textReleased), Color::getGreen(textReleased), Color::getBlue(textReleased));
	add(*text);

	textColorReleased = textReleased;
	textColorPressed = textPressed;

#ifdef SHOW_BACKGROUND
	background->setWidthHeight(*this);
#endif
}

//-----------------------------------------------------------------------------
void CButton::setText(const char* newText)
{
	*text = newText;
	text->resizeToCurrentText();
}

//-----------------------------------------------------------------------------
void CButton::setTextPosition(int16_t x, int16_t y)
{
	text->setXY(x, y);
}

//-----------------------------------------------------------------------------
void CButton::setData(uint32_t newData)
{
	data = newData;
}

//-----------------------------------------------------------------------------
uint32_t CButton::getData()
{
	return data;
}

//-----------------------------------------------------------------------------
void CButton::render()
{
	dsp.setPosition(*this, *this);
	if(imgReleased)
		imgReleased->render();
	if(imgPressed)
		imgPressed->render();
	if(text)
		text->render();
	Container::invalidate();
}

//-----------------------------------------------------------------------------
void CButton::handleClickEvent(const ClickEvent& event)
{
	bool wasPressed = getPressed();
	bool newPressedValue = (event.getType() == ClickEvent::PRESSED);
	if((newPressedValue && !wasPressed) || (!newPressedValue && wasPressed))
	{
		if(newPressedValue)
		{
			if(imgReleased)
				imgReleased->setVisible(false);
			if(imgPressed)
				imgPressed->setVisible(true);
			if(text)
				text->setColor(textColorPressed);
		}
		else
		{
			if(imgReleased)
				imgReleased->setVisible(true);
			if(imgPressed)
				imgPressed->setVisible(false);
			if(text)
				text->setColor(textColorReleased);
		}

		if(imgReleased)
			imgReleased->invalidate();
		if(imgPressed)
			imgPressed->invalidate();
		if(text)
			text->invalidate();

		setPressed(newPressedValue);
	}
	if(wasPressed && (event.getType() == ClickEvent::RELEASED))
		executeAction();
}

}   //namespace touchgfx
