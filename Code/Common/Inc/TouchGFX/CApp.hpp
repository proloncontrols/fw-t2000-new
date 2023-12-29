
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
//         File : CApp.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Application constants class header file
//=============================================================================
#ifndef CAPP_HPP
#define CAPP_HPP


//=============================================================================
//  E N U M S
//-----------------------------------------------------------------------------
namespace touchgfx
{

typedef enum {
	ScreenNone,
	//-----
	ScreenHome,
	//-----
	ScreenSettings,
		ScreenOptions,
			ScreenLanguage,
			ScreenUnit,
		ScreenAboutme,
		ScreenVisualize,
		ScreenDevice,
	//-----
	ScreenSetpoints
} ScreenId;

typedef enum {
	ButtonNone = -3,
	ButtonHome = -2,
	ButtonBack = -1,
	ButtonUser =  0
} ButtonId;

}   //namespace touchgfx


#endif   //CAPP_HPP
