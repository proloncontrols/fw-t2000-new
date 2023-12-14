
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
//         File : CContainer.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Rotating container class header file
//=============================================================================
#ifndef CCONTAINER_HPP
#define CCONTAINER_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/Containers/Container.hpp>
#include <CDisplay.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CContainer : public Container
{
public:
	CContainer()
	{
		nativeX = Container::getX();
		nativeY = Container::getY();
	}

	void add(Drawable& d)
	{
		Container::add(d);

		if(dsp.orientation != CDisplay::NATIVE)
		{
		}
	}

	int16_t nativeX = 0;
	int16_t nativeY = 0;
};

}   //namespace touchgfx


#endif   //CCONTAINER_HPP
