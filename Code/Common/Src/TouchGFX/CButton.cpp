
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
#include <stdlib.h>
#include <string.h>
#include <CButton.hpp>
#include <touchgfx/Color.hpp>
#include <CDisplay.hpp>


namespace touchgfx
{

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//void CButton::addTo(Container& c)
//{
////	dsp.add(c, *this);
////	dsp.add(*this, *imgReleased);
////	dsp.add(*this, *imgPressed);
////	if(text)
////		dsp.add(*this, *text);
//}
//
////-----------------------------------------------------------------------------
//void CButton::initialize(int16_t x, int16_t y, int16_t width, int16_t height)
//{
//	Container::setPosition(x, y, width, height);
//}
//
////-----------------------------------------------------------------------------
//void CButton::initialize(int16_t x, int16_t y, int16_t touchHeight, Bitmap released, Bitmap pressed)
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
////	add(*imgReleased);
//
//	image = touchgfx::Bitmap(pressed);
//	imgPressed = new CImage;
//	imgPressed->setBitmap(image);
//	imgPressed->setXY(0, 0);
//	imgPressed->setVisible(false);
////	add(*imgPressed);
//}
//
////-----------------------------------------------------------------------------
//void CButton::initialize(int16_t x, int16_t y, int16_t touchHeight, Bitmap released, Bitmap pressed, const TypedText& textType, int16_t textMaxLen, colortype textReleased, colortype textPressed)
//{
//	initialize(x, y, touchHeight, released, pressed);
//
//	textBuffer = (Unicode::UnicodeChar*)calloc(textMaxLen + 1, sizeof(Unicode::UnicodeChar));   //+1 = null termination character
//
//	text = new TextAreaWithOneWildcard;
//	text->setWildcard(textBuffer);
//	text->setTypedText(textType);
//	text->setColor(textReleased);
////	add(*text);
//
//	textColorReleased = textReleased;
//	textColorPressed = textPressed;
//}
//
////-----------------------------------------------------------------------------
//void CButton::setText(const char* newText)
//{
//	Unicode::fromUTF8((uint8_t*)newText, textBuffer, strlen(newText));
//	text->resizeToCurrentText();
//}
//
////-----------------------------------------------------------------------------
//void CButton::setTextPosition(int16_t x, int16_t y)
//{
//	text->setXY(x, y);
//}
//
////-----------------------------------------------------------------------------
//void CButton::setData(uint32_t newData)
//{
//	data = newData;
//}
//
////-----------------------------------------------------------------------------
//uint32_t CButton::getData()
//{
//	return data;
//}
//
////-----------------------------------------------------------------------------
//void CButton::handleClickEvent(const ClickEvent& event)
//{
//    bool wasPressed = getPressed();
//    bool newPressedValue = (event.getType() == ClickEvent::PRESSED);
//    if((newPressedValue && !wasPressed) || (!newPressedValue && wasPressed))
//    {
//    	if(newPressedValue)
//    	{
//    		if(imgReleased)
//    			imgReleased->setVisible(false);
//    		if(imgPressed)
//    			imgPressed->setVisible(true);
//        	if(text)
//        		text->setColor(textColorPressed);
//    	}
//    	else
//    	{
//    		if(imgReleased)
//    			imgReleased->setVisible(true);
//    		if(imgPressed)
//    			imgPressed->setVisible(false);
//        	if(text)
//        		text->setColor(textColorReleased);
//    	}
//        setPressed(newPressedValue);
//        invalidate();
//    }
//    if(wasPressed && (event.getType() == ClickEvent::RELEASED))
//        executeAction();
//}

}   //namespace touchgfx
