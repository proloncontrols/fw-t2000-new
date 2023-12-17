
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
//         File : CGauge.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Gauge display base class header file
//=============================================================================
#ifndef CGAUGE_HPP
#define CGAUGE_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stddef.h>
#include <CText.hpp>
#include <CLabel.hpp>
#include <CImage.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
//This class is not meant to be called directly. Derive from it.
class CGauge : public Container
{
public:
	CGauge();

	void invalidate();

protected:
//	Box background;
	CText* integer = NULL;
	CText* decimal = NULL;
	CLabel* unitC = NULL;
	CLabel* unitF = NULL;
	CLabel* unitP = NULL;
	CImage* image = NULL;
};

}   //namespace touchgfx


#endif   //CGAUGE_HPP
