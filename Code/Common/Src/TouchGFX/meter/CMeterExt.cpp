
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
//         File : CMeterExt.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Exterior temperature meter class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <math.h>
#include <meter/CMeterExt.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CMeterExt::CMeterExt()
{
	addInteger(intPrecision, intCharSpacingRation, touchgfx::TypedText(intText), colorR, colorG, colorB);
	addUnit(unitCText, unitFText, colorR, colorG, colorB);
	addImage(imageId);

	Container::setHeight(touchgfx::TypedText(intText).getFont()->getFontHeight());
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CMeterExt::display(double value, bool celsius)
{
	double intDoubleValue;
	double decDoubleValue = modf(value, &intDoubleValue);
	(void)decDoubleValue;

	int16_t intValue = (int16_t)intDoubleValue;

	integer->display(intValue);
	integer->setXY(0, 0);

	if(celsius)
		unit->setTypedText(touchgfx::TypedText(unitTempC));
	else
		unit->setTypedText(touchgfx::TypedText(unitTempF));
	unit->setXY(integer->getWidth(), Container::getHeight() - integer->getMaxGlyphHeight() - (unit->getTypedText().getFont()->getFontHeight() - unit->getTypedText().getFont()->getGlyph(unit->getTypedText().getText()[0])->top()));

	image->setXY(integer->getWidth(), Container::getHeight() - image->getHeight());
	image->setBitmap(touchgfx::Bitmap(imageId));

	Container::setWidth(integer->getWidth() + MAX(unit->getWidth(), image->getWidth()));
	resizeBackground();
}

}   //namespace touchgfx
