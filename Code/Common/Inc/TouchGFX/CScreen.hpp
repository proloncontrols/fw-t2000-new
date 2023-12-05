
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
#include <CImage.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/Widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>


//=============================================================================
//  D I S P L A Y   C L I E N T   L A Y O U T
//-----------------------------------------------------------------------------
// Thermostat orientation (portrait)
//
//    Screen orientation (landscape)
//    -------------------------------------   ---
//    |    ---------------------------    |   --- 12
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |  Available Client Area  |    |   648
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    ---------------------------    |   --- 12
//    -------------------------------------   ---
//
//    |-36-|---------- 648 ----------|-36-|
//    |--------------- 720 ---------------|


namespace touchgfx
{

//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define CLIENT_SIZE     648   //Client area is square
#define FRAME_COLOR_R   35
#define FRAME_COLOR_G   35
#define FRAME_COLOR_B   35


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CScreen
{
public:
	CScreen(Container& ownerContainer);

	void setBackgroundColor(colortype newColor);
	void addToClient(Drawable& d);
	void showFrame();

protected:
	Container client;
	Box clientBackground;

private:
	Box frame;
};

}   //namespace touchgfx


#endif   //CSCREEN_HPP
