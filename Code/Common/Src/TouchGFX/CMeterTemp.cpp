
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
//         File : CMeterTemp.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Temperature meter class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CMeterTemp.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CMeterTemp::CMeterTemp(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& textLarge, const TypedText& textSmall)
	: CMeter()
{
//	unit.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
//	unitBuffer[0] = 0;
//	unit.setWildcard(unitBuffer);
//    unit.setTypedText(textSmall);
//    add(unit);

//	CMeter::initialize(colorRed, colorGreen, colorBlue, textLarge, textSmall);
//	for(int i = 0; i < METER_UNIT_MAX_CHAR; i++)
//	{
//		unit[i].getWidget().setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
//		unit[i].getBuffer()[0] = 0;
//		unit[i].getWidget().setWildcard(unit[i].getBuffer());
//		unit[i].getWidget().setTypedText(textSmall);
//		add(unit[i].getWidget());
//	}
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeterTemp::display(double newValue, bool celsius)
{
	CMeter::display(newValue);

	unit[0].setDigit(167);      //°
	if(celsius)
		unit[1].setDigit(67);   //C
	else
		unit[1].setDigit(70);   //F



//	int16_t top;
//	int16_t width;
//	const GlyphNode* glyph;
//
//	CMeter::display(value);
//
//	if(celsius)
//		Unicode::fromUTF8((uint8_t*)"°C", unitBuffer, 2);
//	else
//		Unicode::fromUTF8((uint8_t*)"°F", unitBuffer, 2);
//
//	glyph = unit.getTypedText().getFont()->getGlyph(unitBuffer[0]);
//	width = glyph->width() + glyph->left;
//	glyph = unit.getTypedText().getFont()->getGlyph(unitBuffer[1]);
//	width += glyph->width() + glyph->left;
//	unit.setWidth(width);
//
//	top = unit.getTypedText().getFont()->getFontHeight() - glyph->top();
//	unit.setXY(getDotX(), top);
//	curBaseline = getHeight() - top;
//	CMeter::setBaseline(curBaseline);
//
//	setWidth(MAX(getWidth(), unit.getX()+unit.getWidth()+firstCharLeftWidth));
//	background.setPosition(*this);
}

}   //namespace touchgfx


























