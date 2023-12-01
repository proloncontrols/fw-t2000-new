
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
//         File : CCanvas.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Screen starting point class header file
//=============================================================================
#ifndef CCANVAS_HPP
#define CCANVAS_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/Color.hpp>
#include <touchgfx/Widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>


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
class CCanvas
{
public:
	CCanvas(Container& ownerContainer);
	void setBackgroundColor(colortype newColor);
	void showFrame();

protected:
	Container* owner;

private:
	Box frame;
	Box client;
};

}   //namespace touchgfx


#endif   //CCANVAS_HPP
