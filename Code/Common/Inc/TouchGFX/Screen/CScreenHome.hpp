
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
//         File : CScreenHome.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Home screen class header file
//=============================================================================
#ifndef CSCREEN_HOME_HPP
#define CSCREEN_HOME_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stddef.h>
#include <Screen/CScreen.hpp>
#include <touchgfx/Containers/Buttons/AbstractButtonContainer.hpp>
#include <CButton.hpp>
#include <CImage.hpp>
#include <Meter/CMeterInt.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CScreenHome : public CScreen
{
public:
	enum Buttons {
		BUTTON_SETTINGS,
		BUTTON_SETPOINTS
	};

	CScreenHome(Container& ownerContainer, GenericCallback<const AbstractButtonContainer&>& callback);

protected:
	CButton buttonSettings;
	CButton buttonSetPoints;
	CImage imageCooling;
	CMeterInt meterInt;

private:
	static const int16_t buttonSetPointsSize = 200;

//	static const int16_t buttonSettingsImageReleasedId = BITMAP_SETTING_ID;
//	static const int16_t buttonSettingsImagePressedId  = BITMAP_SETTING_DARK2_ID;

//	static const int16_t imageCoolingId = BITMAP_COOLINGON_ID;
};

}   //namespace touchgfx


#endif   //CSCREEN_HOME_HPP
