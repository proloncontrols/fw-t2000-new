
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
#include <touchgfx/Widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>


//=============================================================================
//  C L I E N T   D I S P L A Y   L A Y O U T
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


//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define NATIVE_WIDTH    720
#define NATIVE_HEIGHT   672
#define CLIENT_SIZE     648   //Client area is square


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CScreen
{
public:
	CScreen(Container& ownerContainer);

	Container client;

private:
	Box frame;
	Box clientBackground;
	Container& container;
};

}   //namespace touchgfx


#endif   //CSCREEN_HPP
