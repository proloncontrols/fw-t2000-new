
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
//         File : CScreenHome.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Home screen class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Screen/CScreenHome.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>
#include <CDisplay.hpp>


namespace touchgfx
{

//=============================================================================
//  C O N S T R U C T I O N
//-----------------------------------------------------------------------------
CScreenHome::CScreenHome(Container& ownerContainer, GenericCallback<const AbstractButtonContainer&>& callback)
            :CScreen(ownerContainer, true)
{
//	imageCooling.setBitmap(imageCoolingId);
	imageCooling.setXY(client.getWidth()/2 - imageCooling.getWidth()/2, 50);
//	addToClient(imageCooling);
//	dsp.addToContainer(client, imageCooling);
	imageCooling.add(client);

//	buttonSettings.initialize(client.getWidth() - Bitmap(buttonSettingsImageReleasedId).getWidth(), 0, 0, buttonSettingsImageReleasedId, buttonSettingsImagePressedId);
	buttonSettings.setData(CScreenHome::BUTTON_SETTINGS);
	buttonSettings.setAction(callback);
//	addToClient(buttonSettings);
//	dsp.add(client, buttonSettings);
	buttonSettings.addTo(client);

	buttonSetPoints.initialize(client.getWidth()/2 - buttonSetPointsSize/2, client.getHeight()/2 - buttonSetPointsSize/2, buttonSetPointsSize, buttonSetPointsSize);
	buttonSetPoints.setData(CScreenHome::BUTTON_SETPOINTS);
	buttonSetPoints.setAction(callback);
//	addToClient(buttonSetPoints);
	dsp.add(client, buttonSetPoints);

	meterInt.setXY(0, 0);
	meterInt.display(-21.5, true);
//	addToClient(meterInt);
//	dsp.add(client, meterInt);
	meterInt.addTo(client);
//	client.add(meterInt);
}

}   //namespace touchgfx
