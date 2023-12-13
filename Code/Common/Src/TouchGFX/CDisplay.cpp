
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
//         File : CDisplay.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Display parameters implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#define CDISPLAY_GLOBAL
#include <CDisplay.hpp>


namespace touchgfx
{

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//void CDisplay::add(Container& c, Drawable& d)
//{
//	c.add(d);
//
//	if(orientation != NATIVE)
//	{
//		int16_t newX = c.getWidth() - d.getWidth() - d.getX();
//		int16_t newY = c.getHeight() - d.getHeight() - d.getY();
//		int16_t newW = d.getWidth();
//		int16_t newH = d.getHeight();
//
//		d.setPosition(newX, newY, newW, newH);
//	}
//}

void CDisplay::setX(Drawable& d, int16_t x)
{
	if(dsp.orientation == CDisplay::NATIVE)
		d.setX(x);
	else
		d.setX(d.getParent()->getWidth() - x - d.getWidth());
}

void CDisplay::setY(Drawable& d, int16_t y)
{
	if(dsp.orientation == CDisplay::NATIVE)
		d.setY(y);
	else
		d.setY(d.getParent()->getHeight() - y - d.getHeight());
}

void CDisplay::setXY(Drawable& d, int16_t x, int16_t y)
{
//	if(dsp.orientation == CDisplay::NATIVE)
//		d.setXY(x, y);
//	else
//		d.setXY(d.getParent()->getWidth() - x - d.getWidth(), d.getParent()->getHeight() - y - d.getHeight());
	setX(d, x);
	setY(d, y);
}

//void CDisplay::Render(Drawable& d)
//{
//	if(orientation != NATIVE)
//		d.setXY(d.getParent()->getWidth() - d.getX(), d.getParent()->getHeight() - d.getY());
//}

const Rect& CDisplay::getPosition(Drawable& d)
{
	r = d.getRect();
	if(orientation != NATIVE)
	{
		r.x = d.getParent()->getWidth() - r.width - r.x;
		r.y = d.getParent()->getHeight() - r.height - r.y;
	}
	return r;
}

}
