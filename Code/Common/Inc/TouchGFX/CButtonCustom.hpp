
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
//         File : CButtonCustom.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Custom button widget class header file
//=============================================================================
#ifndef WIDGET_BUTTON_CUSTOM_HPP
#define WIDGET_BUTTON_CUSTOM_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/containers/buttons/BoxWithBorderButtonStyle.hpp>
#include <touchgfx/containers/buttons/ClickButtonTrigger.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CButtonCustom : public BoxWithBorderButtonStyle< ClickButtonTrigger >
{
public:
	CButtonCustom(int16_t x, int16_t y, int16_t width, int16_t height, TextureMapper* imageReleased, TextureMapper* imagePressed);

    virtual void handleClickEvent(const ClickEvent& event) override;

private:
    TextureMapper* imgReleased;
    TextureMapper* imgPressed;
};

}   //namespace touchgfx


#endif   //WIDGET_BUTTON_CUSTOM_HPP
