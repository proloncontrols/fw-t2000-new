
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
//         File : CGaugeTempInt.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Interior temperature gauge display class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <Gauge/CGaugeTempInt.hpp>
#include <CDisplay.hpp>

#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
//CGaugeTempInt::CGaugeTempInt()
//{
//	integer = new CText(integerPrecision, integerSpacingRatio, TypedText(integerText), colorR, colorG, colorB);
//	add(*integer);
//
//	decimal = new CText(decimalPrecision, decimalSpacingRatio, TypedText(decimalText), colorR, colorG, colorB);
//	add(*decimal);
//
//	unitC = new CText(unitPrecision, unitSpacingRatio, TypedText(unitTextC), colorR, colorG, colorB);
//	add(*unitC);
//
//	unitF = new CText(unitPrecision, unitSpacingRatio, TypedText(unitTextF), colorR, colorG, colorB);
//	add(*unitF);
//}


////=============================================================================
////  M E T H O D S
////-----------------------------------------------------------------------------
//void CGaugeTempInt::init()
//{
////	integer = new CText(integerPrecision, integerSpacingRatio, TypedText(integerText), colorR, colorG, colorB);
////	add(*integer);
////
////	decimal = new CText(decimalPrecision, decimalSpacingRatio, TypedText(decimalText), colorR, colorG, colorB);
////	add(*decimal);
////
////	unitC = new CText(unitPrecision, unitSpacingRatio, TypedText(unitTextC), colorR, colorG, colorB);
////	add(*unitC);
////
////	unitF = new CText(unitPrecision, unitSpacingRatio, TypedText(unitTextF), colorR, colorG, colorB);
////	add(*unitF);
//}
//
//void CGaugeTempInt::addTo(Container& c)
//{
//}
//
//void CGaugeTempInt::update(float temp, bool celsius)
//{
//////	CText* unit = unitC;
//////	if(!celsius)
//////		unit = unitF;
//////
//////	double intDoubleValue;
//////	double decDoubleValue = modf(temp, &intDoubleValue);
//////
//////	int16_t intValue = (int16_t)intDoubleValue;
//////	int16_t decValue = (int16_t)abs((decDoubleValue * pow(10.0, (double)decimalPrecision)));
////
////	*integer = "-21";
////	dsp.setXY(*integer, 1, 1);
////
////	*decimal = ".5";
////	Rect r = dsp.getPosition(*integer);
////	dsp.setXY(*decimal, r.x + r.width, r.y + (r.height - decimal->getHeight()) + decimal->getBaseline());
////
////	Container::setWidth(integer->getWidth() + decimal->getWidth());
////	Container::setHeight(integer->getHeight());
////
////
////
////
////
////
////
////
//////	integer->display(intValue);
//////	decimal->display(decValue);
////
//////	integer->setXY(0, 0);
//////	dot->setXY(integer->getWidth(), Container::getHeight() - dot->getHeight());
//////	decimal->setXY(integer->getWidth() + dot->getWidth(),  Container::getHeight() - decimal->getHeight());
////
//////	if(celsius)
//////		unit->setTypedText(touchgfx::TypedText(unitTempC));
//////	else
//////		unit->setTypedText(touchgfx::TypedText(unitTempF));
//////	unit->setXY(integer->getWidth(), Container::getHeight() - integer->getMaxGlyphHeight() - (unit->getTypedText().getFont()->getFontHeight() - unit->getTypedText().getFont()->getGlyph(unit->getTypedText().getText()[0])->top()));
////
//////	Container::setWidth(integer->getWidth() + MAX(unit->getWidth(), dot->getWidth() + decimal->getWidth()));
//////	resizeBackground();
//}

}   //namespace touchgfx






































