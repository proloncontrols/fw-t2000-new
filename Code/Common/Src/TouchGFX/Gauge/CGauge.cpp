
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
//         File : CGauge.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Gauge display base class implementation file
//=============================================================================


//=============================================================================
//  S W I T C H E S
//-----------------------------------------------------------------------------
//#define CMETER_WITH_BACKGROUND   //Uncomment to apply a background to widget (for debug purposes only)


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Gauge/CGauge.hpp>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CGauge::CGauge()
{
	background.setColor(Color::getColorFromRGB(dsp.devBackgroundColorR, dsp.devBackgroundColorG, dsp.devBackgroundColorB));
	add(background);
}


////=============================================================================
////  M E T H O D S
////-----------------------------------------------------------------------------
//void CMeter::addTo(Container& c)
//{
////	dsp.add(c, *this);
//
////	if(integer)   dsp.add(*this, *integer);
////	if(decimal)   dsp.add(*this, *decimal);
////	if(unit)      dsp.add(*this, *unit);
////	if(dot)       dsp.add(*this, *dot);
////	if(image)     dsp.add(*this, *image);
//}
//
////-----------------------------------------------------------------------------
//void CGauge::addInteger(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
//{
//	integer = new CText(newPrecision, newSpacingRatio, TypedText(newTypedText), newColorR, newColorG, newColorB);
//	add(*integer);
//}

////-----------------------------------------------------------------------------
//void CGauge::addDecimal(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
//{
//	decimal = new CText(newPrecision, newSpacingRatio, TypedText(newTypedText), newColorR, newColorG, newColorB);
//	add(*decimal);
//}

////-----------------------------------------------------------------------------
//void CMeter::addUnit(const TypedText& newTypedTextC, const TypedText& newTypedTextF, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
//{
////	unit = new TextArea;
////	unit = new CText(2);
////	unit->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
//	unitTempC = newTypedTextC;
//	unitTempF = newTypedTextF;
////	add(*unit);
//}

//void CGauge::addUnit(const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
//{
//	unit = new CText(newPrecision, newSpacingRatio, TypedText(newTypedText), newColorR, newColorG, newColorB);
//	add(*unit);
//}

////-----------------------------------------------------------------------------
//void CMeter::addDot(const TypedText& newTypedText, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB)
//{
////	dot = new TextArea;
////	dot = new CText(1);
////	dot->setColor(touchgfx::Color::getColorFromRGB(newColorR, newColorG, newColorB));
////	dot->setTypedText(touchgfx::TypedText(newTypedText));
////	add(*dot);
//}
//
////-----------------------------------------------------------------------------
//void CMeter::addImage(const Bitmap& bmp)
//{
//	image = new CImage;
//	image->setBitmap(bmp);
////	add(*image);
//}
//
////-----------------------------------------------------------------------------
//void CMeter::resizeBackground()
//{
//#ifdef CMETER_WITH_BACKGROUND
//	background.setWidthHeight(*this);
//#endif
//}
//
//
//
//
//
////=============================================================================
////  C O N S T R U C T I O N
////-----------------------------------------------------------------------------

}   //namespace touchgfx
