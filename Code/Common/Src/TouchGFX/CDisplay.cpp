
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
void CDisplay::setX(Drawable& d, int16_t x)
{
	if(orientation == NATIVE)
		d.setX(x);
	else
//		d.setX(d.getParent()->getWidth() - x - d.getWidth());
		d.setX(d.getParent()->getWidth() - x);
}

//-----------------------------------------------------------------------------
void CDisplay::setY(Drawable& d, int16_t y)
{
	if(orientation == NATIVE)
		d.setY(y);
	else
//		d.setY(d.getParent()->getHeight() - y - d.getHeight());
		d.setY(d.getParent()->getHeight() - y);
}

//-----------------------------------------------------------------------------
void CDisplay::setXY(Drawable& d, int16_t x, int16_t y)
{
	CDisplay::setX(d, x);
	CDisplay::setY(d, y);
}

//-----------------------------------------------------------------------------
int16_t CDisplay::getX(Drawable& d)
{
	if(orientation == NATIVE)
		return d.getX();
	else
//		return d.getParent()->getWidth() - d.getWidth() - d.getX();
		return d.getParent()->getWidth() - d.getX();
}

//-----------------------------------------------------------------------------
int16_t CDisplay::getY(Drawable& d)
{
	if(orientation == NATIVE)
		return d.getY();
	else
//		return d.getParent()->getHeight() - d.getHeight() - d.getY();
		return d.getParent()->getHeight() - d.getY();
}



void CDisplay::setWidth(Drawable& d, int16_t width)
{
	d.setWidth(width);
	if(orientation != NATIVE)
		d.setX(d.getX() - width);
}

void CDisplay::setHeight(Drawable& d, int16_t height)
{
	d.setHeight(height);
	if(orientation != NATIVE)
		d.setY(d.getY() - height);
}

void CDisplay::setWidthHeight(Drawable& d, int16_t width, int16_t height)
{
	CDisplay::setWidth(d, width);
	CDisplay::setHeight(d, height);
}

void CDisplay::setWidthHeight(Drawable& d, Drawable& from)
{
	CDisplay::setWidthHeight(d, from.getWidth(), from.getHeight());
}

int16_t CDisplay::getWidth(Drawable& d)
{
	return d.getWidth();
}

int16_t CDisplay::getHeight(Drawable& d)
{
	return d.getHeight();
}

}



































