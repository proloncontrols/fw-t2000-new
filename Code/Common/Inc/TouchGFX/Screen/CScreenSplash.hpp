
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
//-----------------------------------------------------------------------------
//         File : CScreenSplash.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Splash screen class header file
//=============================================================================
#ifndef CSCREEN_SPLASH_HPP
#define CSCREEN_SPLASH_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <BitmapDatabase.hpp>
#include <Screen/CScreen.hpp>
#include <CImage.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CScreenSplash : public CScreen
{
	CImage logo;

public:
	static const int SplashTime = 20;   //Splash screen display time (20 = 1 second)

	CScreenSplash(Container& owner)
                 :CScreen(owner)
	{
		client.add(logo);
		logo.setBitmap(BITMAP_PROLONLOGO470X470_ID);
		logo.setXY((client.getWidth() - logo.getWidth()) / 2, 130);
		logo.transpose();
	}
};

}   //namespace touchgfx


#endif   //CSCREEN_SPLASH_HPP
