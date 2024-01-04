
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
//-----------------------------------------------------------------------------
//         File : CScreen.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Screen starting point class header file
//=============================================================================
#ifndef CSCREEN_HPP
#define CSCREEN_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CApp.hpp>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/Widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>


//=============================================================================
//  C L I E N T   D I S P L A Y   L A Y O U T
//-----------------------------------------------------------------------------
// Thermostat orientation (portrait)
//
//    Screen orientation (landscape)
//    -------------------------------------   ---     ---
//    |    ---------------------------    |   --- 12   |
//    |    |                         |    |    |       |
//    |    |                         |    |    |       |
//    |    |                         |    |    |       |
//    |    |                         |    |    |       |
//    |    |                         |    |    |       |
//    |    |  Available Client Area  |    |   648     672
//    |    |                         |    |    |       |
//    |    |                         |    |    |       |
//    |    |                         |    |    |       |
//    |    |                         |    |    |       |
//    |    |                         |    |    |       |
//    |    ---------------------------    |   --- 12   |
//    -------------------------------------   ---     ---
//
//    |-36-|---------- 648 ----------|-36-|
//    |--------------- 720 ---------------|


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define NATIVE_WIDTH    720
#define NATIVE_HEIGHT   672
#define CLIENT_SIZE     648   //Client area is square


namespace touchgfx
{
#define SHOW_FRAME
//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CScreen
{
	Box frame;
	Box background;
	Container& container;

public:
	Container client;
//	ScreenId previous;

	CScreen(Container& owner)
	       :container(owner)
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
};

}   //namespace touchgfx


#endif   //CSCREEN_HPP
