
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
#include <CButton.hpp>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CButton::CButton()
{
	imgReleased = NULL;
	imgPressed = NULL;
	text = NULL;
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CButton::setBitmaps(Bitmap released, Bitmap pressed)
{
	imgReleased = new CImage;
	imgReleased->setBitmap(released);
	imgReleased->setVisible(true);
	imgReleased->setXY(0, 0);
	add(*imgReleased);

	imgPressed = new CImage;
	imgPressed->setBitmap(released);
	imgPressed->setVisible(false);
	imgPressed->setXY(0, 0);
	add(*imgPressed);

	text = new CLabel;
	add(*text);

	setTouchHeight(0);
}

//-----------------------------------------------------------------------------
void CButton::setTouchHeight(int16_t touchHeight)
{
	setWidth(imgReleased->getWidth());
	if(touchHeight != 0)
		setHeight(touchHeight);
	else
		setHeight(imgReleased->getHeight());
}

//-----------------------------------------------------------------------------
void CButton::setText(const TypedText& textType)
{
//	if(!text)
//	{
//		text = new CLabel;
//		add(*text);
//	}
	text->setLinespacing(0);
	text->setTypedText(textType);
//	text->setWidth(600);
//	text->resizeToCurrentText();
}

//-----------------------------------------------------------------------------
void CButton::setTextPosition(int16_t x, int16_t y)
{
//	if(!text)
//	{
//		text = new CLabel;
//		add(*text);
//	}
	text->setXY(x, y);
}

//-----------------------------------------------------------------------------
void CButton::setTextColors(colortype textReleased, colortype textPressed)
{
//	if(!text)
//	{
//		text = new CLabel;
//		add(*text);
//	}
	text->setColor(textReleased);

	textColorReleased = textReleased;
	textColorPressed = textPressed;
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
void CButton::transpose()
{
	if(dsp.orientation != CDisplay::NATIVE)
	{
		dsp.transpose(*this);
		if(imgReleased)
			imgReleased->transpose();
		if(imgPressed)
			imgPressed->transpose();
		if(text)
			text->transpose();
	}

	invalidate();
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

		invalidate();

		setPressed(newPressedValue);
	}
	if(wasPressed && (event.getType() == ClickEvent::RELEASED))
		executeAction();
}

}   //namespace touchgfx
