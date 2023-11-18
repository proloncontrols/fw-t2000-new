
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
//  Description : TouchGFX widget class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <CMeter.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CMeter::CMeter(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue, const TypedText& textLarge, const TypedText& textSmall)
{
	displayFractional = false;

	setHeight(MAX(textLarge.getFont()->getFontHeight(), textSmall.getFont()->getFontHeight()));

	background.setPosition(*this);
	background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
	add(background);

	for(int i = 0; i < DISPLAY_LENGTH; i++)
	{
		displayString[i].widget.setXY(0, 0);
		displayString[i].widget.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
	    displayString[i].widget.setLinespacing(0);
	    displayString[i].buffer[0] = 0;
	    displayString[i].widget.setWildcard(displayString[i].buffer);
	    displayString[i].widget.resizeToCurrentText();
	    displayString[i].widget.setTypedText(textLarge);
	    add(displayString[i].widget);
	}
    displayString[DISPLAY_LENGTH-1].widget.setTypedText(textSmall);
    displayString[DISPLAY_LENGTH-2].widget.setTypedText(textSmall);









//	setWidth(100);
//	setHeight(textLarge.getFont()->getFontHeight());
//
//	background.setPosition(*this);
//	background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//	add(background);
//
//    txtSign.setXY(0, 0);
//    txtSign.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
//    txtSign.setLinespacing(0);
//    txtSignBuffer[0] = 0;
//    txtSign.setWildcard(txtSignBuffer);
//    txtSign.resizeToCurrentText();
//    txtSign.setTypedText(textLarge);
//    txtSign.setBaselineY(txtSign.getHeight()-10);
//    add(txtSign);
//
//    for(int i = 0; i < INTEGRAL_WEIGHT; i++)
//    {
//    	txtIntegral[i].setXY(0, 0);
//    	txtIntegral[i].setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
//    	txtIntegral[i].setLinespacing(0);
//    	txtIntegralBuffer[0][i] = 0;
//    	txtIntegral[i].setWildcard(txtIntegralBuffer[i]);
//    	txtIntegral[i].resizeToCurrentText();
//    	txtIntegral[i].setTypedText(textLarge);
//
////    	txtIntegral[i].setBaselineY(textLarge.getFont()->getFontHeight() - 10);
//    	txtIntegral[i].setBaselineY(txtIntegral[i].getHeight()-10);
//
//        add(txtIntegral[i]);
//    }
//
////    txtIntegralHundreds.setXY(0, 0);
////    txtIntegralHundreds.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
////    txtIntegralHundreds.setLinespacing(0);
////    txtIntegralHundredsBuffer[0] = 0;
////    txtIntegralHundreds.setWildcard(txtIntegralHundredsBuffer);
////    txtIntegralHundreds.resizeToCurrentText();
////    txtIntegralHundreds.setTypedText(text);
////    add(txtIntegralHundreds);
////
////    txtIntegralTenths.setXY(0, 0);
////    txtIntegralTenths.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
////    txtIntegralTenths.setLinespacing(0);
////    txtIntegralTenthsBuffer[0] = 0;
////    txtIntegralTenths.setWildcard(txtIntegralTenthsBuffer);
////    txtIntegralTenths.resizeToCurrentText();
////    txtIntegralTenths.setTypedText(text);
////    add(txtIntegralTenths);
////
////    txtIntegralUnits.setXY(0, 0);
////    txtIntegralUnits.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
////    txtIntegralUnits.setLinespacing(0);
////    txtIntegralUnitsBuffer[0] = 0;
////    txtIntegralUnits.setWildcard(txtIntegralUnitsBuffer);
////    txtIntegralUnits.resizeToCurrentText();
////    txtIntegralUnits.setTypedText(text);
////    add(txtIntegralUnits);
//
//    txtDot.setXY(0, 200);
//    txtDot.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
//    txtDot.setLinespacing(0);
//    txtDotBuffer[0] = 0;
//    txtDot.setWildcard(txtDotBuffer);
//    txtDot.resizeToCurrentText();
//    txtDot.setTypedText(textSmall);
//    txtDot.setBaselineY(txtDot.getHeight()-10);
//    add(txtDot);
//
//    txtDot.setXY(0, 200);
//    txtFractional.setColor(touchgfx::Color::getColorFromRGB(colorRed, colorGreen, colorBlue));
//    txtFractional.setLinespacing(0);
//    txtFractionalBuffer[0] = 0;
//    txtFractional.setWildcard(txtFractionalBuffer);
//    txtFractional.resizeToCurrentText();
//    txtFractional.setTypedText(textSmall);
//    txtFractional.setBaselineY(txtFractional.getHeight()-10);
//    add(txtFractional);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeter::display(double value)
{
	int strLength;
	int virtualWidth;
	int firstCharLeft;
	char* strPtr;
	DisplayChar* dspPtr;
	const GlyphNode* glyph;
	char strValue[DISPLAY_LENGTH + 1];


	if((value < -999.9) || (value > 999.9))
		value = 0.0;

	sprintf(strValue, "%.1f", value);
	strLength = strlen(strValue);
	if(!displayFractional)
		strLength -= 2;

	virtualWidth = 0;
	strPtr = &strValue[strLength - 1];
	dspPtr = &displayString[DISPLAY_LENGTH - 1];
	for(int i = 0; i < strLength; i++)
	{
		Unicode::fromUTF8((uint8_t*)strPtr, dspPtr->buffer, 1);
		glyph = dspPtr->widget.getTypedText().getFont()->getGlyph(dspPtr->buffer[0]);
		dspPtr->widget.setWidth(glyph->left + glyph->width());
		firstCharLeft = glyph->left;
		virtualWidth += dspPtr->widget.getWidth();
		strPtr--;
		dspPtr--;
	}
	setWidth(virtualWidth + firstCharLeft);

	dspPtr = &displayString[DISPLAY_LENGTH - 1];
	for(int i = 0; i < strLength; i++)
	{
		virtualWidth -= dspPtr->widget.getWidth();
		dspPtr->widget.setXY(virtualWidth, getHeight() - dspPtr->widget.getTypedText().getFont()->getFontHeight());
		dspPtr->widget.setBaselineY(dspPtr->widget.getHeight() - 10);
		dspPtr->widget.invalidate();
		dspPtr--;
	}



//	for(strIdx = strLength-1; strIdx >= 0; strIdx--)
//	{
//		dspChrPtr = &displayString[strIdx + DISPLAY_LENGTH - strLength];
//
//		bufIdx = strIdx + DISPLAY_LENGTH - strLength;
//		Unicode::fromUTF8((uint8_t*)&strValue[strIdx], displayString[bufIdx].buffer, 1);
//		glyph = displayString[bufIdx].widget.getTypedText().getFont()->getGlyph(displayString[bufIdx].buffer[0]);
//		displayString[bufIdx].widget.setWidth(glyph->left + glyph->width());
//		virtualWidth += displayString[bufIdx].widget.getWidth();
//	}
//
//	setWidth(virtualWidth);
//
//	for(bufIdx = DISPLAY_LENGTH-1; bufIdx >= 0; bufIdx--)
//	{
//		virtualWidth -= displayString[bufIdx].widget.getWidth();
//		displayString[bufIdx].widget.setXY(virtualWidth, getHeight() - displayString[bufIdx].widget.getTypedText().getFont()->getFontHeight());
//		displayString[bufIdx].widget.invalidate();
//	}

	background.setPosition(*this);



//	for(int i = strLength-1; i >= 0; i--)
//	{
//		Unicode::fromUTF8((uint8_t*)&strValue[i], displayString[i].buffer, 1);
//		glyph = displayString[i].widget.getTypedText().getFont()->getGlyph(displayString[i].buffer[0]);
//		displayString[i].widget.setWidth(glyph->left + glyph->width());
//		virtualWidth += displayString[i].widget.getWidth();
//	}
//
//	setWidth(virtualWidth);
//
//	for(int i = endOfString; i >= 0; i--)
//	{
//		virtualWidth -= displayString[i].widget.getWidth();
//		displayString[i].widget.setXY(virtualWidth, getHeight() - displayString[i].widget.getTypedText().getFont()->getFontHeight());
//		displayString[i].widget.invalidate();
//	}
//
//	background.setPosition(*this);






//	double tmpIntegral;
//	double tmpFractional = modf(value, &tmpIntegral);
//
//	bool negativeValue = false;
//	if(tmpIntegral < 0.0)
//		negativeValue = true;
//
//	int16_t integral = abs((int16_t)tmpIntegral);
//	int16_t fractional = abs((int16_t)(tmpFractional * 10.0));
//
//	int16_t totalWidth = 0;
//	char buffer[2];
//
////	const Font* font;
////	const GlyphNode* glyph;
//
//	if(displayFractional)
//	{
//		sprintf(buffer, "%.1d", fractional);
//		Unicode::fromUTF8((uint8_t*)buffer, txtFractionalBuffer, 1);
//		font = txtFractional.getTypedText().getFont();
//		glyph = font->getGlyph(txtFractional.getWildcard1()[0]);
//		txtFractional.setWidth(glyph->left + glyph->width());
//		totalWidth += txtFractional.getWidth();
//
//		Unicode::fromUTF8((uint8_t*)".", txtDotBuffer, 1);
//		font = txtDot.getTypedText().getFont();
//		glyph = font->getGlyph(txtDot.getWildcard1()[0]);
//		txtDot.setWidth(glyph->left + glyph->width());
//		totalWidth += txtDot.getWidth();
//	}
//
//	char strIntegral[INTEGRAL_WEIGHT+1];
//	sprintf(strIntegral, "%d", integral);
//    for(int i = (int)strlen(strIntegral)-1; i >= 0; i--)
//    {
//		Unicode::fromUTF8((uint8_t*)&strIntegral[i], &txtIntegralBuffer[i][0], 1);
//		font = txtIntegral[i].getTypedText().getFont();
//		glyph = font->getGlyph(txtIntegral[i].getWildcard1()[0]);
//		txtIntegral[i].setWidth(glyph->left + glyph->width());
//		totalWidth += txtIntegral[i].getWidth();
//    }
//
//	if(negativeValue)
//	{
//		Unicode::fromUTF8((uint8_t*)"-", txtSignBuffer, 1);
//		font = txtSign.getTypedText().getFont();
//		glyph = font->getGlyph(txtSign.getWildcard1()[0]);
//		txtSign.setWidth(glyph->left + glyph->width());
//		totalWidth += txtSign.getWidth();
//	}
//
//	setWidth(totalWidth);
//
//	if(displayFractional)
//	{
//		totalWidth -= txtFractional.getWidth();
////		txtFractional.setX(totalWidth);
////		txtFractional.setXY(totalWidth, getHeight()-txtFractional.getHeight()-5);
////		txtFractional.setXY(totalWidth, getHeight()-txtIntegral[0].getHeight()-txtFractional.getHeight());
//		txtFractional.setXY(totalWidth, getHeight() - txtFractional.getTypedText().getFont()->getFontHeight());
//		txtFractional.invalidate();
//
//		totalWidth -= txtDot.getWidth();
////		txtDot.setX(totalWidth);
////		txtDot.setXY(totalWidth, getHeight()-txtDot.getHeight()-5);
////		txtDot.setXY(totalWidth, getHeight()-txtIntegral[0].getHeight()-txtDot.getHeight());
//		txtDot.setXY(totalWidth, getHeight() - txtFractional.getTypedText().getFont()->getFontHeight());
//		txtDot.invalidate();
//	}
//
//    for(int i = INTEGRAL_WEIGHT-1; i >= 0; i--)
//    {
//    	if(txtIntegral[i].getWildcard1()[0] != 0)
//    	{
//    		totalWidth -= txtIntegral[i].getWidth();
//    		txtIntegral[i].setX(totalWidth);
//    		txtIntegral[i].invalidate();
//    	}
//    }
//
//    if(negativeValue)
//	{
//		totalWidth -= txtSign.getWidth();
//		txtSign.setX(totalWidth);
//		txtSign.invalidate();
//	}
//
//	background.setPosition(*this);









	//	static int16_t tst = 22;
	//	static int16_t tst2 = 77;
	//
	//	char tmp[4];
	//
	//	//Temperature unit selection
	//	int16_t temp = Env->TempC;
	//	if(CFG.Dta.TempUnit == CfgEnvTempF)
	//		temp = Env->TempF;
	//
	//	//Room temperature
	//	double integral;
	//	double fractional = modf((double)temp / 100.0, &integral) * 10.0;
	//	sprintf(tmp, "%d", (int)integral);
	//	Unicode::fromUTF8((uint8_t*)tmp, TempEntTextBuffer, sizeof(TempEntTextBuffer));
	//	TempEntText.resizeToCurrentTextWithAlignment();
	//	TempEntText.invalidate();
	//	sprintf(tmp, "%d", (int)fractional);
	//	Unicode::fromUTF8((uint8_t*)tmp, TempFrcTextBuffer, sizeof(TempFrcTextBuffer));
	//	TempFrcText.resizeToCurrentTextWithAlignment();
	//
	//	//Exterior temperature
	//	tst *= -1;
	//	sprintf(tmp, "%d", (int)tst);
	//	extTemp.
	//	Unicode::fromUTF8((uint8_t*)tmp, ExtTempTextBuffer, sizeof(ExtTempTextBuffer));
	//	ExtTempText.resizeToCurrentTextWithAlignment();
	//
	//	CRect refRect;
	//	CWidget* ref = Widgets->get(mainTxtExtTemp);
	//	ref->getPosition(refRect);
	//
	//	CRect dstRect;
	//	CWidget* dst = Widgets->get(mainTxtExtTempUnit);
	//	dst->getPosition(dstRect);
	//	dstRect.x = refRect.x + refRect.width;
	//	dst->setPosition(dstRect);
	//
	//	dst = Widgets->get(mainImgExtTemp);
	//	dst->getPosition(dstRect);
	//	dstRect.x = refRect.x + refRect.width;
	//	dst->setPosition(dstRect);
	//
	//	//Humidity
	//	tst2 *= -1;
	//	sprintf(tmp, "%d", (int)tst2);
	////	sprintf(tmp, "%d", (int)(Env->HumP / 100));
	//	Unicode::fromUTF8((uint8_t*)tmp, HumTextBuffer, sizeof(HumTextBuffer));
	//	HumText.resizeToCurrentTextWithAlignment();
	//	HumText.invalidate();
	//
	//	ref = Widgets->get(mainTxtHum);
	//	ref->getPosition(refRect);
	//
	//	dst = Widgets->get(mainTxtHumPercent);
	//	dst->getPosition(dstRect);
	//	dstRect.x = refRect.x + refRect.width;
	//	dst->setPosition(dstRect);
	//
	//	dst = Widgets->get(mainImgDrop);
	//	dst->getPosition(dstRect);
	//	dstRect.x = refRect.x + refRect.width;
	//	dst->setPosition(dstRect);
	//
	//	invalidate();
}

}   //namespace touchgfx



















































