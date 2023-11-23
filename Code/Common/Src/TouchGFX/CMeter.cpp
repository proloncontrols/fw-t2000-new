
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
//         File : CMeter.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Meter class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <CMeter.hpp>


namespace touchgfx
{

//void CMeter::display(double value)
//{
//	char formatStr[5];
//	char formatPrecision[3];
//
//
//	double intValue;
//	double decValue = modf(value, &intValue);
//
//
//	strcpy(formatStr, "%.");
//	sprintf(formatPrecision, "%dd", integer->getCapacity());
//	strcat(formatStr, formatPrecision);
//
//
//
//
//
//
//
//
//
//
////	if((newValue < -999.9) || (newValue > 999.9))
////		newValue = 0.0;
////
////	char strValue[METER_VALUE_MAX_CHAR + 1];
////	sprintf(strValue, "%.1f", newValue);
////
////	int strLength = strlen(strValue);
////	if(integralOnly)
////		strLength -= 2;
////
////	int newWidth = 0;
////	char* strPtr = &strValue[strLength - 1];
////	CDigit* dspPtr = &value[METER_VALUE_MAX_CHAR - 1];
////	const GlyphNode* glyph;
////	for(int i = 0; i < strLength; i++)
////	{
////		dspPtr->setDigit(*strPtr);
//////		tmp1 = dspPtr->getWidget().getHeight();
//////		Container::setHeight(dspPtr->getWidget().getHeight());
////		glyph = dspPtr->getGlyph();
////		dspPtr->getWidget().setWidth(glyph->left + glyph->width());
////		leftMostCharacterLeftWidth = glyph->left;
////		newWidth += dspPtr->getWidget().getWidth();
////		strPtr--;
////		dspPtr--;
////	}
////	setWidth(newWidth + leftMostCharacterLeftWidth * 2);
////
////	dspPtr = &value[METER_VALUE_MAX_CHAR - 1];
////	for(int i = 0; i < strLength; i++)
////	{
////		newWidth -= dspPtr->getWidget().getWidth();
////		tmp1 = Container::getHeight();
////		tmp2 = dspPtr->getWidget().getHeight();
//////		dspPtr->getWidget().setXY(newWidth, Container::getHeight() - dspPtr->getFont()->getFontHeight());
////		dspPtr->getWidget().setXY(newWidth, Container::getHeight() - dspPtr->getWidget().getHeight());
//////		dspPtr->getWidget().setXY(newWidth, 0);
//////		dspPtr->getWidget().setBaselineY(getHeight() - (getHeight() / BASELINE_OFFSET_PERCENT));
////		dspPtr--;
////	}
////
////	if(curUnit != METER_UNIT_NONE)
////	{
////		int16_t x;
////		int16_t y;
////		getUnitXY(x, y);
////		unit.setXY(x + leftMostCharacterLeftWidth, y);
////		setWidth(MAX(getWidth(), unit.getX() + unit.getWidth() + leftMostCharacterLeftWidth));
////	}
////
////	background.setPosition(0, 0, getWidth(), getHeight());
//}

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMeter::CMeter()
{
	add(background);
	background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
}

void CMeter::setBackgroundColor(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue)
{
	background.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
}

void CMeter::resizeBackground()
{
	background.setWidthHeight(*this);
}





CMeterInt::CMeterInt()
{
	integer = new CString(intString, intPrecision, touchgfx::TypedText(intText), colorR, colorG, colorB);
	integer->setCharSpacingRatio(intCharSpacingRation);
	add(*integer);

	dot.setColor(touchgfx::Color::getColorFromRGB(colorR, colorG, colorB));
	dot.setTypedText(touchgfx::TypedText(dotText));
	add(dot);

	decimal = new CString(decString, decPrecision, touchgfx::TypedText(decText), colorR, colorG, colorB);
	decimal->setCharSpacingRatio(decCharSpacingRation);
	add(*decimal);

	Container::setHeight(MAX(touchgfx::TypedText(intText).getFont()->getFontHeight(), touchgfx::TypedText(decText).getFont()->getFontHeight()));
}

void CMeterInt::display(double value)
{
	double intDoubleValue;
	double decDoubleValue = modf(value, &intDoubleValue);

	int intValue = (int)intDoubleValue;
	int decValue = (int)(decDoubleValue * pow(10.0, (double)decPrecision));

	char strInteger[intPrecision + 1];
	char strDecimal[decPrecision + 1];

	sprintf(strInteger, "%d", intValue);
	sprintf(strDecimal, "%d", decValue);

	integer->setText(strInteger);
	decimal->setText(strDecimal);

	Container::setWidth(integer->getWidth() + dot.getWidth() + decimal->getWidth());

	integer->setXY(0, Container::getHeight() - integer->getHeight());

	dot.setXY(integer->getWidth(), Container::getHeight() - dot.getHeight());

	decimal->setXY(integer->getWidth() + dot.getWidth(), Container::getHeight() - decimal->getHeight());

	resizeBackground();





//	char strValue[1 + intPrecision + 1 + decPrecision + 1];   //Maximum value string length -> "-100.0\0"

//	char str[intPrecision];

//	for(int i = strlen(strValue) - 1; i >= 0; i--)
//	{
//
//	}


//	sprintf(strValue, "%.1f", value);

//	char* strPtr = &strValue[strLength - 1];

//	char strInteger[intPrecision];
//	char strdecimal[decPrecision];
}

////=============================================================================
////  D E F I N E S
////-----------------------------------------------------------------------------
//
//
////=============================================================================
////  C O N S T R U C T I O N
////-----------------------------------------------------------------------------
////CMeter::CMeter()
////{
////	add(background);
////	background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
////}
//
//CMeterInt::CMeterInt()
//{
//	add(background);
//	background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//
//	add(minusText);
//	minusText.setWildcard(minusBuffer);
//	minusText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	minusText.setTypedText(touchgfx::TypedText(minusType));
//
//	add(integerText);
//	integerText.setWildcard(integerBuffer);
//	integerText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	integerText.setTypedText(touchgfx::TypedText(integerType));
//
//	add(dotText);
//	dotText.setWildcard(dotBuffer);
//	dotText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	dotText.setTypedText(touchgfx::TypedText(dotType));
//
//	add(decimalText);
//	decimalText.setWildcard(decimalBuffer);
//	decimalText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	decimalText.setTypedText(touchgfx::TypedText(decimalType));
//
//	add(unitText);
//	unitText.setWildcard(unitBuffer);
//	unitText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	unitText.setTypedText(touchgfx::TypedText(unitType));
//}
//
//CMeterSet::CMeterSet()
//{
//	add(background);
//	background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//
//	add(minusText);
//	minusText.setWildcard(minusBuffer);
//	minusText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	minusText.setTypedText(touchgfx::TypedText(minusType));
//
//	add(integerText);
//	integerText.setWildcard(integerBuffer);
//	integerText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	integerText.setTypedText(touchgfx::TypedText(integerType));
//
//	add(dotText);
//	dotText.setWildcard(dotBuffer);
//	dotText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	dotText.setTypedText(touchgfx::TypedText(dotType));
//
//	add(decimalText);
//	decimalText.setWildcard(decimalBuffer);
//	decimalText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	decimalText.setTypedText(touchgfx::TypedText(decimalType));
//
//	add(unitText);
//	unitText.setWildcard(unitBuffer);
//	unitText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	unitText.setTypedText(touchgfx::TypedText(unitType));
//}
//
//CMeterExt::CMeterExt()
//{
//	add(background);
//	background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//
//	add(minusText);
//	minusText.setWildcard(minusBuffer);
//	minusText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	minusText.setTypedText(touchgfx::TypedText(minusType));
//
//	add(integerText);
//	integerText.setWildcard(integerBuffer);
//	integerText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	integerText.setTypedText(touchgfx::TypedText(integerType));
//
//	add(unitText);
//	unitText.setWildcard(unitBuffer);
//	unitText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	unitText.setTypedText(touchgfx::TypedText(unitType));
//}
//
//CMeterHum::CMeterHum()
//{
//	add(background);
//	background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//
//	add(integerText);
//	integerText.setWildcard(integerBuffer);
//	integerText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	integerText.setTypedText(touchgfx::TypedText(integerType));
//
//	add(unitText);
//	unitText.setWildcard(unitBuffer);
//	unitText.setColor(touchgfx::Color::getColorFromRGB(ColorR, ColorG, ColorB));
//	unitText.setTypedText(touchgfx::TypedText(unitType));
//}
//
//
//
//
//
//
//
//
//
//
//
//
//////-----------------------------------------------------------------------------
////CMeterTemp::CMeterTemp()
////{
////	minusText.setTypedText(touchgfx::TypedText(T_METER_HUGE_MINUS));
////	minusText.setColor(touchgfx::Color::getColorFromRGB(COLOR_R, COLOR_G, COLOR_B));
////
////	integerText.setTypedText(touchgfx::TypedText(T_METER_HUGE));
////	integerText.setColor(touchgfx::Color::getColorFromRGB(COLOR_R, COLOR_G, COLOR_B));
////
////	dotText.setTypedText(touchgfx::TypedText(T_METER_MEDIUM_DOT));
////	dotText.setColor(touchgfx::Color::getColorFromRGB(COLOR_R, COLOR_G, COLOR_B));
////
////	decimalText.setTypedText(touchgfx::TypedText(T_METER_MEDIUM));
////	decimalText.setColor(touchgfx::Color::getColorFromRGB(COLOR_R, COLOR_G, COLOR_B));
////}
//
//
////=============================================================================
////  M E T H O D S
////-----------------------------------------------------------------------------
////void CMeter::setValue(double value)
////{
////	if((value < -999.9) || (value > 999.9))
////		value = 0.0;
////}
//
//
//
//
//
//
//
//
//
//
//
//////void CMeter::initialize(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& text)
//////{
//////	withFractional = false;
//////
//////	background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//////	add(background);
//////
//////	for(int i = 0; i < METER_VALUE_MAX_CHAR; i++)
//////	{
//////		value[i].getWidget().setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
//////		value[i].getBuffer()[0] = 0;
//////		value[i].getWidget().setWildcard(value[i].getBuffer());
//////		value[i].getWidget().setTypedText(text);
//////		add(value[i].getWidget());
//////	}
//////
//////	for(int i = 0; i < METER_UNIT_MAX_CHAR; i++)
//////	{
//////		unit[i].getWidget().setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
//////		unit[i].getBuffer()[0] = 0;
//////		unit[i].getWidget().setWildcard(unit[i].getBuffer());
//////		unit[i].getWidget().setTypedText(textSmall);
//////		add(unit[i].getWidget());
//////	}
//////
//////	setHeight(text.getFont()->getFontHeight());
//////}
//////
//////void CMeter::initialize(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& textLarge, const TypedText& textSmall)
//////{
//////	initialize(colorRed, colorGreen, colorBlue, textLarge);
//////	value[METER_VALUE_MAX_CHAR - 1].getWidget().setTypedText(textSmall);
//////	value[METER_VALUE_MAX_CHAR - 2].getWidget().setTypedText(textSmall);
//////	setHeight(MAX(textLarge.getFont()->getFontHeight(), textSmall.getFont()->getFontHeight()));
//////
//////	withFractional = true;
//////}
////int16_t tmp1;
////int16_t tmp2;
////int16_t tmp3;
////
////void CMeter::initialize(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& textLarge, const TypedText& textSmall, bool integral)
////{
////	integralOnly = integral;
////
////	background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
////	add(background);
////
////	for(int i = 0; i < METER_VALUE_MAX_CHAR; i++)
////	{
////		value[i].getWidget().setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
//////		value[i].getBuffer()[0] = 0;
////		value[i].getWidget().setWildcard(value[i].getBuffer());
////		value[i].getWidget().setTypedText(textLarge);
////		add(value[i].getWidget());
////	}
////	if(!integralOnly)
////	{
////		value[METER_VALUE_MAX_CHAR - 1].getWidget().setTypedText(textSmall);
////		value[METER_VALUE_MAX_CHAR - 2].getWidget().setTypedText(textSmall);
////	}
////
////	unit.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
//////	unitBuffer[0] = 0;
////	unit.setWildcard(unitBuffer);
////	unit.setTypedText(textSmall);
////	add(unit);
////
////	tmp1 = textLarge.getFont()->getFontHeight();
////	tmp2 = textSmall.getFont()->getFontHeight();
////
////	Container::setHeight(MAX(textLarge.getFont()->getFontHeight(), textSmall.getFont()->getFontHeight()));
////}
////
//////-----------------------------------------------------------------------------
////void CMeter::setUnit(MeterUnit newUnit)
////{
////	curUnit = newUnit;
////
////	switch(curUnit)
////	{
////		case METER_UNIT_NONE:
////			unitBuffer[0] = 0;
////		break;
////
////		case METER_UNIT_CELSIUS:
////			Unicode::fromUTF8((uint8_t*)"°C", unitBuffer, 2);
////		break;
////
////		case METER_UNIT_FAHRENHEIT:
////			Unicode::fromUTF8((uint8_t*)"°F", unitBuffer, 2);
////		break;
////
////		case METER_UNIT_HUMIDITY:
////			Unicode::fromUTF8((uint8_t*)"%", unitBuffer, 1);
////		break;
////	}
////	unit.resizeToCurrentText();
////}
////
//////-----------------------------------------------------------------------------
////void CMeter::display(double newValue)
////{
////	if((newValue < -999.9) || (newValue > 999.9))
////		newValue = 0.0;
////
////	char strValue[METER_VALUE_MAX_CHAR + 1];
////	sprintf(strValue, "%.1f", newValue);
////
////	int strLength = strlen(strValue);
////	if(integralOnly)
////		strLength -= 2;
////
////	int newWidth = 0;
////	char* strPtr = &strValue[strLength - 1];
////	CDigit* dspPtr = &value[METER_VALUE_MAX_CHAR - 1];
////	const GlyphNode* glyph;
////	for(int i = 0; i < strLength; i++)
////	{
////		dspPtr->setDigit(*strPtr);
//////		tmp1 = dspPtr->getWidget().getHeight();
//////		Container::setHeight(dspPtr->getWidget().getHeight());
////		glyph = dspPtr->getGlyph();
////		dspPtr->getWidget().setWidth(glyph->left + glyph->width());
////		leftMostCharacterLeftWidth = glyph->left;
////		newWidth += dspPtr->getWidget().getWidth();
////		strPtr--;
////		dspPtr--;
////	}
////	setWidth(newWidth + leftMostCharacterLeftWidth * 2);
////
////	dspPtr = &value[METER_VALUE_MAX_CHAR - 1];
////	for(int i = 0; i < strLength; i++)
////	{
////		newWidth -= dspPtr->getWidget().getWidth();
////		tmp1 = Container::getHeight();
////		tmp2 = dspPtr->getWidget().getHeight();
//////		dspPtr->getWidget().setXY(newWidth, Container::getHeight() - dspPtr->getFont()->getFontHeight());
////		dspPtr->getWidget().setXY(newWidth, Container::getHeight() - dspPtr->getWidget().getHeight());
//////		dspPtr->getWidget().setXY(newWidth, 0);
//////		dspPtr->getWidget().setBaselineY(getHeight() - (getHeight() / BASELINE_OFFSET_PERCENT));
////		dspPtr--;
////	}
////
////	if(curUnit != METER_UNIT_NONE)
////	{
////		int16_t x;
////		int16_t y;
////		getUnitXY(x, y);
////		unit.setXY(x + leftMostCharacterLeftWidth, y);
////		setWidth(MAX(getWidth(), unit.getX() + unit.getWidth() + leftMostCharacterLeftWidth));
////	}
////
////	background.setPosition(0, 0, getWidth(), getHeight());
////}
////
//////-----------------------------------------------------------------------------
////void CMeter::getUnitXY(int16_t& x, int16_t& y)
////{
////	CDigit* dspPtr = &value[METER_VALUE_MAX_CHAR - 3];
////
////	if(integralOnly)
////		x = getWidth();
////	else
////		x = dspPtr->getWidget().getX() + dspPtr->getWidget().getWidth();
////
////	y = dspPtr->getFont()->getFontHeight() - dspPtr->getGlyph()->top() - (unit.getTypedText().getFont()->getFontHeight() - unit.getTypedText().getFont()->getGlyph(unitBuffer[0])->top());
////}
////
//////-----------------------------------------------------------------------------
////char CMeter::CDigit::getDigit()
////{
////	uint8_t digit;
////	Unicode::toUTF8(buffer, &digit, 1);
////	return (char)digit;
////}
////
//////-----------------------------------------------------------------------------
////void CMeter::CDigit::setDigit(char digit)
////{
////	Unicode::fromUTF8((uint8_t*)&digit, buffer, 1);
////	widget.resizeToCurrentText();
////}
////
//////-----------------------------------------------------------------------------
////const Font* CMeter::CDigit::getFont()
////{
////	return widget.getTypedText().getFont();
////}
////
//////-----------------------------------------------------------------------------
////const GlyphNode* CMeter::CDigit::getGlyph()
////{
////	return getFont()->getGlyph(buffer[0]);
////}
////
//////-----------------------------------------------------------------------------
////touchgfx::TextAreaWithOneWildcard& CMeter::CDigit::getWidget()
////{
////	return widget;
////}
////
//////-----------------------------------------------------------------------------
////touchgfx::Unicode::UnicodeChar* CMeter::CDigit::getBuffer()
////{
////	return buffer;
////}

}   //namespace touchgfx
