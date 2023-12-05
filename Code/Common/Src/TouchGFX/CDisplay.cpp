
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
//void CDisplay::setPosition(Drawable& d)
//{
//	int16_t newX;
//	int16_t newY;
//	int16_t newW;
//	int16_t newH;
//
//	if(orientation == LANDSCAPE)
//	{
//		newX = NATIVE_WIDTH - d.getWidth() - 1;
//		newY = NATIVE_HEIGHT - d.getHeight() - 1;
//		newW = d.getWidth();
//		newH = d.getHeight();
//	}
//	else
//	{
//		newX = NATIVE_WIDTH - d.getHeight() - 1;
//		newY = d.getX() + 1;
//		newW = d.getHeight();
//		newH = d.getWidth();
//	}
//
//	d.setPosition(newX, newY, newW, newH);
//}

void CDisplay::setPosition(Drawable& d)
{
	int16_t newX;
	int16_t newY;
	int16_t newW;
	int16_t newH;

	if(orientation == LANDSCAPE)
	{
		newX = d.getParent()->getWidth() - d.getWidth() - 1;
		newY = d.getParent()->getHeight() - d.getHeight() - 1;
		newW = d.getWidth();
		newH = d.getHeight();
	}
	else
	{
//		newX = NATIVE_WIDTH - d.getHeight() - 1;
//		newY = d.getX() + 1;
//		newW = d.getHeight();
//		newH = d.getWidth();
	}

	d.setPosition(newX, newY, newW, newH);
}

}   //namespace touchgfx




























