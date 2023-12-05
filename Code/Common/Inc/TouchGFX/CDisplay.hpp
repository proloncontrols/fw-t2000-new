
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
//  G L O B A L S
//-----------------------------------------------------------------------------
#ifndef CDISPLAY_GLOBAL
#define CDISPLAY_EXTERN   extern
#else
#define CDISPLAY_EXTERN
#endif


//=============================================================================
//  D I S P L A Y   N A T I V E   L A Y O U T
//-----------------------------------------------------------------------------
// Thermostat orientation (portrait)
//
//    Screen orientation (landscape)
//    -------------------------------------   ---
//    |(0,0)                              |    |
//    |                                   |    |
//    |                                   |    |
//    |                                   |    |
//    |                                   |    |
//    |                                   |    |
//    |              Display              |   672
//    |                                   |    |
//    |                                   |    |
//    |                                   |    |
//    |                                   |    |
//    |                                   |    |
//    |                                   |    |
//    -------------------------------------   ---
//
//    |--------------- 720 ---------------|


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CDisplay
{
public:
	enum Orientation {
		LANDSCAPE,   //Physical display is rotated 180° due to temperature/humidity sensor location
		PORTRAIT     //Physical display is rotated 270° due to temperature/humidity sensor location
	} orientation;
};


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
CDISPLAY_EXTERN CDisplay dsp;

}   //namespace touchgfx


#endif   //CDISPLAY_HPP
