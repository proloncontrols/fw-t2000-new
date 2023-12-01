
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
//         File : CCanvas.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Screen starting point class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CCanvas.hpp>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>


namespace touchgfx
{

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
CCanvas::CCanvas(Container& ownerContainer)
{
	owner = &ownerContainer;

	Rect r = Display.getNative();
	ownerContainer.setPosition(r.x, r.y, r.width, r.height);
	frame.setPosition(ownerContainer);

	r = Display.getClient();
	client.setPosition(r.x, r.y, r.width, r.height);

	setBackgroundColor(Color::getColorFromRGB(0, 0, 0));

	owner->add(frame);
	owner->add(client);
}

//-----------------------------------------------------------------------------
void CCanvas::setBackgroundColor(colortype color)
{
	frame.setColor(color);
	client.setColor(color);
}

//-----------------------------------------------------------------------------
void CCanvas::showFrame()
{
	frame.setColor(Color::getColorFromRGB(FRAME_COLOR_R, FRAME_COLOR_G, FRAME_COLOR_B));
}

}   //namespace touchgfx
