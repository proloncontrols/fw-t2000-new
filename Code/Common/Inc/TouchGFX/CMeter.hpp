
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
//         File : CMeter.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Meter base class header file
//=============================================================================
#ifndef CMETER_HPP
#define CMETER_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CString.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CMeter : public Container
{
public:
	CMeter();
	void setBackgroundColor(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue);

protected:
	CString* integer;
	CString* decimal;
	void resizeBackground();

private:
	touchgfx::Box background;
};

}   //namespace touchgfx


#endif   //CMETER_HPP
