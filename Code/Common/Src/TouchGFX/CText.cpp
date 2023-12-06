
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
//         File : CText.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Text class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <string.h>
#include <CText.hpp>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CText::CText(int initialLength)
{
	curLength = initialLength;
	buffer = (Unicode::UnicodeChar*)calloc(curLength + 1, sizeof(Unicode::UnicodeChar));   //+1 = null termination character
	setWildcard(buffer);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CText::setXY(int16_t x, int16_t y)
{
	if(dsp.orientation == CDisplay::LANDSCAPE)
		setRotation(TEXT_ROTATE_180);
	else
		setRotation(TEXT_ROTATE_90);

	TextAreaWithOneWildcard::setXY(x, y);
}

//-----------------------------------------------------------------------------
void CText::setText(const char* newText)
{
	int newLen = strlen(newText);

	if(newLen > curLength)
	{
		free(buffer);
		buffer = (Unicode::UnicodeChar*)malloc((newLen + 1) * sizeof(Unicode::UnicodeChar));   //+1 = null termination character
	}
	curLength = newLen;

	memset(buffer, 0, curLength * sizeof(Unicode::UnicodeChar));
	Unicode::fromUTF8((uint8_t*)newText, buffer, strlen(newText));
	resizeToCurrentText();
}






//void CText::initialize(int16_t x, int16_t y, int16_t width, int16_t height)
//{
//	Container::setPosition(x, y, width, height);
//}
//
////-----------------------------------------------------------------------------
//void CText::initialize(int16_t x, int16_t y, int16_t touchHeight, Bitmap released, Bitmap pressed)
//{
//	Bitmap image = touchgfx::Bitmap(released);     //Both released and pressed images are assumed to have the same size
//
//	Container::setXY(x, y);
//	Container::setWidth(image.getWidth());
//	if(touchHeight != 0)
//		Container::setHeight(touchHeight);         //Touch area is the image visible area only (rectangle)
//	else
//		Container::setHeight(image.getHeight());   //Touch area is the entire image area, visible and not visible (square)
//
//	imgReleased = new CImage;
//	imgReleased->setBitmap(image);
//	imgReleased->setXY(0, 0);
//	imgReleased->setVisible(true);
//	add(*imgReleased);
//
//	image = touchgfx::Bitmap(pressed);
//	imgPressed = new CImage;
//	imgPressed->setBitmap(image);
//	imgPressed->setXY(0, 0);
//	imgPressed->setVisible(false);
//	add(*imgPressed);
//}
//
////-----------------------------------------------------------------------------
//void CText::initialize(int16_t x, int16_t y, int16_t touchHeight, Bitmap released, Bitmap pressed, const TypedText& textType, int16_t textMaxLen, colortype textReleased, colortype textPressed)
//{
//	initialize(x, y, touchHeight, released, pressed);
//
//	textBuffer = (Unicode::UnicodeChar*)calloc(textMaxLen + 1, sizeof(Unicode::UnicodeChar));   //+1 = null termination character
//
//	text = new TextAreaWithOneWildcard;
//	text->setWildcard(textBuffer);
//	text->setTypedText(textType);
//	text->setColor(textReleased);
//	add(*text);
//
//	textColorReleased = textReleased;
//	textColorPressed = textPressed;
//}
//
////-----------------------------------------------------------------------------
//void CText::setTextPosition(int16_t x, int16_t y)
//{
//	text->setXY(x, y);
//}

}   //namespace touchgfx
