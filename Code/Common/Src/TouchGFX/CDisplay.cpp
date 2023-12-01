
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
void CDisplay::initialize(Orientation orient, int16_t nativeWidth, int16_t nativeHeight, int16_t clientWidth, int16_t clientHeight)
{
	orientation = orient;

	native.x = 0;
	native.y = 0;
	native.width = nativeWidth;
	native.height = nativeHeight;

	if(orientation == LANDSCAPE)
	{
		client.x = (nativeWidth - clientWidth) / 2;
		client.y = (nativeHeight - clientHeight) / 2;
	}
	else
	{
		client.x = (nativeHeight - clientHeight) / 2;
		client.y = (nativeWidth - clientWidth) / 2;
	}
	client.width = clientWidth;
	client.height = clientHeight;
}

//-----------------------------------------------------------------------------
CDisplay::Orientation CDisplay::getOrientation()
{
	return orientation;
}

//-----------------------------------------------------------------------------
const Rect& CDisplay::getNative()
{
	return native;
}

//-----------------------------------------------------------------------------
const Rect& CDisplay::getClient()
{
	return client;
}

}   //namespace touchgfx
