
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
#include <stddef.h>
#include <CImage.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/Color.hpp>
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


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CScreen
{
//public:
//	CScreen(Container& ownerContainer, bool wLogo);
//
//	void setBackgroundColor(colortype newColor);
////	void addToClient(Drawable& d);
//	void showFrame();
//
//protected:
//	Container client;
//	Box clientBackground;
//
//private:
//	static const int16_t clientWidth  = 648;
//	static const int16_t clientHeight = 648;
//
//	static const uint8_t frameColorR = 35;
//	static const uint8_t frameColorG = 35;
//	static const uint8_t frameColorB = 35;
//
////	static const BitmapId bitmap = BITMAP_PROLON_178X178_ID;
//
//	Box frame;
//	CImage* logo = NULL;
};

}   //namespace touchgfx


#endif   //CSCREEN_HPP

























