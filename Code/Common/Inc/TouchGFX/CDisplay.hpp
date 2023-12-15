
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
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/Drawable.hpp>


//=============================================================================
//  D I S P L A Y   L A Y O U T S
//-----------------------------------------------------------------------------
//  Thermostat orientation (portrait)
//  Screen orientation (landscape)
//
//  ----------                                      ----------                                      ----------
//  | sensor |                                      | sensor |                                      | sensor |
//  ----------                       NATIVE         ----------                    LANDSCAPE         ----------                     PORTRAIT
//    -------------------------------------   ---     -------------------------------------   ---     -------------------------------------   ---
//    |(0,0)-->                           |    |      |                                   |    |      |                              (0,0)|    |
//    |                                   |    |      |                                   |    |      |                                |  |    |
//    |                                   |    |      |                                   |    |      |                                V  |    |
//    |                                   |    |      |                                   |    |      |                                   |    |
//    |                                   |    |      |                                   |    |      |                                   |    |
//    |                                   |    |      |                                   |    |      |                                   |    |
//    |              Display              |   672     |              Display              |   672     |              Display              |   672
//    |                                   |    |      |                                   |    |      |                                   |    |
//    |                                   |    |      |                                   |    |      |                                   |    |
//    |                                   |    |      |                                   |    |      |                                   |    |
//    |                                   |    |      |                                   |    |      |                                   |    |
//    |                                   |    |      |                                   |    |      |                                   |    |
//    |                                   |    |      |                           <--(0,0)|    |      |                                   |    |
//    -------------------------------------   ---     -------------------------------------   ---     -------------------------------------   ---
//
//    |--------------- 720 ---------------|           |--------------- 720 ---------------|           |--------------- 720 ---------------|


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CDisplay
{
public:
	enum Orientation {
		NATIVE,      //Display is natively left at 0° (used for development/testing purposes)
		LANDSCAPE,   //Display is natively left at 0° but is programmatically rotated 180° due to temperature/humidity sensor location
		PORTRAIT     //Display is natively rotated 270° and is programmatically rotated 180° due to temperature/humidity sensor location
	} orientation;

	static const uint8_t devBackgroundColorR = 140;
	static const uint8_t devBackgroundColorG = 80;
	static const uint8_t devBackgroundColorB = 140;

	void setX(Drawable& d, int16_t x);
	void setY(Drawable& d, int16_t y);
	void setXY(Drawable& d, int16_t x, int16_t y);

	int16_t getX(Drawable& d);
	int16_t getY(Drawable& d);

	void setWidth(Drawable& d, int16_t width);
	void setHeight(Drawable& d, int16_t height);
	void setWidthHeight(Drawable& d, int16_t width, int16_t height);
	void setWidthHeight(Drawable& d, Drawable& from);

	int16_t getWidth(Drawable& d);
	int16_t getHeight(Drawable& d);
};


//=============================================================================
//  G L O B A L   V A R I A B L E S
//-----------------------------------------------------------------------------
CDISPLAY_EXTERN CDisplay dsp;

}   //namespace touchgfx


#endif   //CDISPLAY_HPP





































