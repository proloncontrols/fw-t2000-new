
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
//         File : CGaugeTemperature.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Temperature gauge display base class header file
//=============================================================================
#ifndef CGAUGE_TEMPERATURE_HPP
#define CGAUGE_TEMPERATURE_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <Gauge/CGauge.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CGaugeTemperature : public CGauge
{
public:
    CGaugeTemperature();

protected:
	void update(float temp, bool celsius);

	int decimalDigits;
};

}   //namespace touchgfx


#endif   //CGAUGE_TEMPERATURE_HPP