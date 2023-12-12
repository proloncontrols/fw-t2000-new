
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
#include <Screen/CScreen.hpp>
#include <CDisplay.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CScreen::CScreen(Container& ownerContainer, bool wLogo)
{
	frame.setPosition(ownerContainer);
	ownerContainer.add(frame);

	client.setPosition((ownerContainer.getWidth() - clientWidth) / 2, (ownerContainer.getHeight() - clientHeight) / 2, clientWidth, clientHeight);
	ownerContainer.add(client);

	clientBackground.setPosition(0, 0, client.getWidth(), client.getHeight());
	clientBackground.setColor(Color::getColorFromRGB(0, 0, 0));
//	addToClient(clientBackground);
	dsp.add(client, clientBackground);

	if(wLogo)
	{
		logo = new CImage();
//		logo->setBitmap(Bitmap(bitmap));
		logo->setXY((client.getWidth() / 2) - (logo->getWidth() / 2), 0);
//		addToClient(*logo);
		dsp.add(client, *logo);
	}
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CScreen::setBackgroundColor(colortype color)
{
	frame.setColor(color);
	clientBackground.setColor(color);
}

////-----------------------------------------------------------------------------
//void CScreen::addToClient(Drawable& d)
//{
//	client.add(d);
//
//	int16_t newX = d.getParent()->getWidth() - d.getWidth() - d.getX();
//	int16_t newY = d.getParent()->getHeight() - d.getHeight() - d.getY();
//	int16_t newW = d.getWidth();
//	int16_t newH = d.getHeight();
//
//	d.setPosition(newX, newY, newW, newH);
//}

//-----------------------------------------------------------------------------
void CScreen::showFrame()
{
	frame.setColor(Color::getColorFromRGB(frameColorR, frameColorG, frameColorB));
}

}   //namespace touchgfx























