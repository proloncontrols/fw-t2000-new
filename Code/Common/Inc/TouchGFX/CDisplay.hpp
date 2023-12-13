
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


#include <touchgfx/Drawable.hpp>
#include <touchgfx/Containers/Container.hpp>


//=============================================================================
//  N A T I V E   D I S P L A Y   L A Y O U T
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
		NATIVE,      //Physical display is set to native orientation (0°) used for development/testing pusposes
		LANDSCAPE,   //Physical display is rotated 180° due to temperature/humidity sensor location
		PORTRAIT     //Physical display is rotated 270° due to temperature/humidity sensor location
	} orientation;

	static const uint8_t devBackgroundColorR = 140; //86;
	static const uint8_t devBackgroundColorG = 80;  //86;
	static const uint8_t devBackgroundColorB = 140; //90;

//	void add(Container& c, Drawable& d);
	void setX(Drawable& d, int16_t x);
	void setY(Drawable& d, int16_t y);
	void setXY(Drawable& d, int16_t x, int16_t y);
//	void Render(Drawable& d);
	const Rect& getPosition(Drawable& d);

private:
	Rect r;
};


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
CDISPLAY_EXTERN CDisplay dsp;

}   //namespace touchgfx


#endif   //CDISPLAY_HPP



























