
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
//         File : CScreen.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Screen starting point class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CDisplay.hpp>
#include <Screen/CScreen.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{
#define SHOW_FRAME
//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CScreen::CScreen(Container& ownerContainer)
		:container(ownerContainer)
{
	container.removeAll();

	if(dsp.orientation != CDisplay::PORTRAIT)
		container.setPosition(0, 0, NATIVE_WIDTH, NATIVE_HEIGHT);
	else
		container.setPosition(0, 0, NATIVE_HEIGHT, NATIVE_WIDTH);

	frame.setPosition(container);
#ifdef SHOW_FRAME
	frame.setColor(Color::getColorFromRGB(dsp.devFrameColorR, dsp.devFrameColorG, dsp.devFrameColorB));
#else
	frame.setColor(Color::getColorFromRGB(0, 0, 0));
#endif
	container.add(frame);

	client.setPosition((frame.getWidth() - CLIENT_SIZE) / 2, (frame.getHeight() - CLIENT_SIZE) / 2, CLIENT_SIZE, CLIENT_SIZE);
	container.add(client);

	background.setWidthHeight(client);
	background.setColor(Color::getColorFromRGB(0, 0, 0));
	client.add(background);
}

}   //namespace touchgfx
