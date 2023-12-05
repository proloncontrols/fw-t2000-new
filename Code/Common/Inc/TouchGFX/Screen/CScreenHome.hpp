
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
//         File : CScreenHome.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Home screen class header file
//=============================================================================
#ifndef CSCREEN_HOME_HPP
#define CSCREEN_HOME_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <stddef.h>
#include <Screen/CScreen.hpp>
#include <CImage.hpp>
#include <CButton.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/Widgets/Box.hpp>
#include <touchgfx/Containers/Container.hpp>
#include <touchgfx/Containers/Buttons/AbstractButtonContainer.hpp>


namespace touchgfx
{

//=============================================================================
//  D E F I N E S
//-----------------------------------------------------------------------------


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CScreenHome : public CScreen
{
public:
	CScreenHome(Container& ownerContainer, GenericCallback<const AbstractButtonContainer&>& callback);

protected:
	CButton buttonSetPoints;

private:
};

}   //namespace touchgfx


#endif   //CSCREEN_HOME_HPP
