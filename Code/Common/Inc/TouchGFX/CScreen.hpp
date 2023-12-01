
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
#include <touchgfx/Color.hpp>
#include <touchgfx/Widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <CImage.hpp>


namespace touchgfx
{

//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define FRAME_COLOR_R   35
#define FRAME_COLOR_G   35
#define FRAME_COLOR_B   35


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CScreen
{
public:
	CScreen(Container& ownerContainer, bool wLogo);
	void setBackgroundColor(colortype newColor);
	void add(Drawable& d);
	void showFrame();

private:
	Container* owner;
	Container client;
	Box clientBackground;
	Box frame;
	CImage logo;
};

}   //namespace touchgfx


#endif   //CSCREEN_HPP
