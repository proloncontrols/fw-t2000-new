
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

	client.setPosition((ownerContainer.getWidth() - CLIENT_SIZE) / 2, (ownerContainer.getHeight() - CLIENT_SIZE) / 2, CLIENT_SIZE, CLIENT_SIZE);
	ownerContainer.add(client);

	clientBackground.setPosition(0, 0, client.getWidth(), client.getHeight());
	clientBackground.setColor(Color::getColorFromRGB(0, 0, 0));
	addToClient(clientBackground);

	if(wLogo)
	{
		logo = new CImage();
		logo->setBitmap(Bitmap(bitmap));
		logo->setXY((client.getWidth() / 2) - (logo->getWidth() / 2), 0);
		addToClient(*logo);
	}
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
//void CScreen::setButtonClick(GenericCallback<const AbstractButtonContainer&>& callback)
//{
//	buttonCallback = &callback;
//}

//-----------------------------------------------------------------------------
void CScreen::setBackgroundColor(colortype color)
{
	frame.setColor(color);
	clientBackground.setColor(color);
}

//-----------------------------------------------------------------------------
void CScreen::addToClient(Drawable& d)
{
	int16_t newX;
	int16_t newY;
	int16_t newW;
	int16_t newH;

	client.add(d);

	if(dsp.orientation == CDisplay::LANDSCAPE)
	{
		newX = d.getParent()->getWidth() - d.getWidth() - d.getX() - 1;
		newY = d.getParent()->getHeight() - d.getHeight() - d.getY() - 1;
		newW = d.getWidth();
		newH = d.getHeight();
	}
	else
	{
		newX = d.getParent()->getWidth() - d.getHeight() - 1;
		newY = d.getX() + 1;
		newW = d.getHeight();
		newH = d.getWidth();
	}

	d.setPosition(newX, newY, newW, newH);
}

//-----------------------------------------------------------------------------
void CScreen::showFrame()
{
	frame.setColor(Color::getColorFromRGB(FRAME_COLOR_R, FRAME_COLOR_G, FRAME_COLOR_B));
}

}   //namespace touchgfx
