
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
//         File : CScreenLogo.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Screen with company logo class header file
//=============================================================================
#ifndef CSCREEN_LOGO_HPP
#define CSCREEN_LOGO_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CScreen.hpp>
#include <CImage.hpp>
#include <touchgfx/Bitmap.hpp>
#include <BitmapDatabase.hpp>


namespace touchgfx
{

//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define LOGO_BITMAP   BITMAP_PROLON_178X178_ID


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CScreenLogo : public CScreen
{
public:
	CScreenLogo(Container& ownerContainer);

private:
	static const BitmapId bitmap = LOGO_BITMAP;

	CImage logo;
};

}   //namespace touchgfx


#endif   //CSCREEN_LOGO_HPP



































