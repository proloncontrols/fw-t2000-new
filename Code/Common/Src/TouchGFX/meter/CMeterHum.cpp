
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
//         File : CMeterHum.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Humidity meter class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <Meter/CMeterHum.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
//CMeterHum::CMeterHum()
//{
////	addInteger(intPrecision, intCharSpacingRation, touchgfx::TypedText(intText), colorR, colorG, colorB);
////	addUnit(unitText, colorR, colorG, colorB);
////	addImage(imageId);
//
////	Container::setHeight(touchgfx::TypedText(intText).getFont()->getFontHeight());
//}
//
//
////=============================================================================
////  M E T H O D S
////-----------------------------------------------------------------------------
//void CMeterHum::display(double value)
//{
//	double intDoubleValue;
//	double decDoubleValue = modf(value, &intDoubleValue);
//	(void)decDoubleValue;
//
//	int16_t intValue = (int16_t)abs(intDoubleValue);
//
//	integer->display(intValue);
//	integer->setXY(0, 0);
////	unit->setXY(integer->getWidth(), Container::getHeight() - integer->getMaxGlyphHeight() - (unit->getTypedText().getFont()->getFontHeight() - unit->getTypedText().getFont()->getGlyph(unit->getTypedText().getText()[0])->top()));
//
////	image->setXY(integer->getWidth(), Container::getHeight() - image->getHeight());
////	image->setBitmap(touchgfx::Bitmap(imageId));
//
////	Container::setWidth(integer->getWidth() + MAX(unit->getWidth(), image->getWidth()));
//	resizeBackground();
//}

}   //namespace touchgfx
