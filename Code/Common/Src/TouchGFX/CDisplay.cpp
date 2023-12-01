
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
void CDisplay::initialize(Orientation orient, int16_t clientSize)
{
//	orientation = orient;
//
//	native.x = 0;
//	native.y = 0;
//	native.width = NATIVE_WIDTH;
//	native.height = NATIVE_HEIGHT;
//
//	client.x = (NATIVE_WIDTH - clientSize) / 2;
//	client.y = (NATIVE_HEIGHT - clientSize) / 2;
//	if(orientation == PORTRAIT)
//	{
//		client.x = (NATIVE_HEIGHT - clientSize) / 2;
//		client.y = (NATIVE_WIDTH - clientSize) / 2;
//		native.width = NATIVE_HEIGHT;
//		native.height = NATIVE_WIDTH;
//	}
//	client.width = clientSize;
//	client.height = clientSize;
//
//	middle = clientSize / 2;

//	orientation = orient;
//
//	if(orientation == LANDSCAPE)
//	{
//		native.x = 0;
//		native.y = 0;
//		native.width = NATIVE_WIDTH;
//		native.height = NATIVE_HEIGHT;
//
//		client.x = (NATIVE_WIDTH - clientSize) / 2;
//		client.y = (NATIVE_HEIGHT - clientSize) / 2;
//		client.width = clientSize;
//		client.height = clientSize;
//	}
//	else
//	{
//		native.x = 0;
//		native.y = 0;
//		native.width = NATIVE_HEIGHT;
//		native.height = NATIVE_WIDTH;
//
//		client.x = (NATIVE_HEIGHT - clientSize) / 2;
//		client.y = (NATIVE_WIDTH - clientSize) / 2;
//		client.width = clientSize;
//		client.height = clientSize;
//	}
//
//	middle = clientSize / 2;

	orientation = orient;

	native.x = 0;
	native.y = 0;
	if(orientation == LANDSCAPE)
	{
		native.width = NATIVE_WIDTH;
		native.height = NATIVE_HEIGHT;
		client.x = (NATIVE_WIDTH - clientSize) / 2;
		client.y = (NATIVE_HEIGHT - clientSize) / 2;
	}
	else
	{
		native.width = NATIVE_HEIGHT;
		native.height = NATIVE_WIDTH;
		client.x = (NATIVE_HEIGHT - clientSize) / 2;
		client.y = (NATIVE_WIDTH - clientSize) / 2;
	}
	client.width = clientSize;
	client.height = clientSize;
	client.middle = clientSize / 2;
}

}   //namespace touchgfx


























