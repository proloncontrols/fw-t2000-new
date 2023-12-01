
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
#include <CScreen.hpp>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>


namespace touchgfx
{

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
CScreen::CScreen(Container& ownerContainer, bool wLogo)
{
	owner = &ownerContainer;

	ownerContainer.setPosition(Display.native.x, Display.native.y, Display.native.width, Display.native.height);
	frame.setPosition(ownerContainer);

	client.setPosition(Display.client.x, Display.client.y, Display.client.width, Display.client.height);
	clientBackground.setPosition(0, 0, Display.client.width, Display.client.height);
	add(clientBackground);

	setBackgroundColor(Color::getColorFromRGB(0, 0, 0));

	owner->add(frame);
	owner->add(client);

	logo.setBitmap(Bitmap(BITMAP_PROLON_176X176_ID));
	logo.setXY(Display.client.middle - logo.getWidth()/2, 0);
	add(logo);
}

//-----------------------------------------------------------------------------
void CScreen::setBackgroundColor(colortype color)
{
	frame.setColor(color);
	clientBackground.setColor(color);
}

//-----------------------------------------------------------------------------
void CScreen::add(Drawable& d)
{
	client.add(d);
}

//-----------------------------------------------------------------------------
void CScreen::showFrame()
{
	frame.setColor(Color::getColorFromRGB(FRAME_COLOR_R, FRAME_COLOR_G, FRAME_COLOR_B));
}

}   //namespace touchgfx
