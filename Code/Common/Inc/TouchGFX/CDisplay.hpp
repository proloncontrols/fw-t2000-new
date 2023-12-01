
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
//         File : CDisplay.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Display parameters header file
//=============================================================================
#ifndef CDISPLAY_HPP
#define CDISPLAY_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/hal/Types.hpp>


namespace touchgfx
{

//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------
#define NATIVE_WIDTH    720
#define NATIVE_HEIGHT   672
#define CLIENT_SIZE     648   //Client is square

// Thermostat orientation (portrait)
//
//    Screen orientation (landscape)
//    -------------------------------------   ---
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    | NU |  Available Client area  | NU |   672
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    |    |                         |    |    |
//    -------------------------------------   ---
//
//    |-24-|---------- 672 ----------|-24-|
//    |--------------- 720 ---------------|


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CDisplay
{
public:
	enum Orientation {
		LANDSCAPE,
		PORTRAIT
	};

	struct Area {
		int16_t x;
		int16_t y;
		int16_t width;
		int16_t height;
		int16_t middle;
	};

public:
	void initialize(Orientation orient, int16_t clientSize);
	Orientation orientation;
	Area native;
	Area client;
};


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
#ifndef CDISPLAY_GLOBAL
extern CDisplay Display;
#else
CDisplay Display;
#endif

}   //namespace touchgfx


#endif   //CDISPLAY_HPP
