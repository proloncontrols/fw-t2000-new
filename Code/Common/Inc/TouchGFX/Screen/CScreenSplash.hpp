
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
#include <Screen/CScreen.hpp>
#include <CImage.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CScreenSplash : public CScreen
{
public:
	CScreenSplash(Container& owner);

private:
	CImage logo;
};

}   //namespace touchgfx


#endif   //CSCREEN_SPLASH_HPP
