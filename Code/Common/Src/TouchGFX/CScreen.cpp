
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
	frame.setPosition(ownerContainer);
	ownerContainer.add(frame);

	client.setPosition((NATIVE_WIDTH - CLIENT_SIZE) / 2, (NATIVE_HEIGHT - CLIENT_SIZE) / 2, CLIENT_SIZE, CLIENT_SIZE);
	ownerContainer.add(client);

	clientBackground.setPosition(0, 0, CLIENT_SIZE, CLIENT_SIZE);
	clientBackground.setColor(Color::getColorFromRGB(0, 0, 0));
	add(clientBackground);




//	owner = &ownerContainer;
//
//	ownerContainer.setPosition(0, 0, NATIVE_WIDTH, NATIVE_HEIGHT);
//	frame.setPosition(ownerContainer);
//	owner->add(frame);
//
//	client.setPosition((NATIVE_WIDTH - CLIENT_SIZE) / 2, (NATIVE_HEIGHT - CLIENT_SIZE) / 2, CLIENT_SIZE, CLIENT_SIZE);
//	clientBackground.setPosition(client);
//	add(clientBackground);
//	owner->add(client);

//	setBackgroundColor(Color::getColorFromRGB(0, 0, 0));

//	owner->add(frame);
//	owner->add(client);

//	logo.setBitmap(Bitmap(BITMAP_PROLON_178X178_ID));
//	logo.setXY(0, 0);
//	add(logo);
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
 	dsp.setPosition(d);
}

//-----------------------------------------------------------------------------
void CScreen::showFrame()
{
	frame.setColor(Color::getColorFromRGB(FRAME_COLOR_R, FRAME_COLOR_G, FRAME_COLOR_B));
}

}   //namespace touchgfx






























