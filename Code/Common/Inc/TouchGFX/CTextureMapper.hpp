
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
//         File : CTextureMapper.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX TextureMapper widget class/tools header file
//=============================================================================
#ifndef WIDGET_TEXTUREMAPPER_HPP
#define WIDGET_TEXTUREMAPPER_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CWidget.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CTextureMapper : public CWidget
{
public:
	CTextureMapper(TextureMapper& mapper);

	virtual void position();
	virtual void getPosition(Rect& rect);
	virtual void setPosition(Rect& rect);

private:
	TextureMapper& m_Mapper;
};

}   //namespace touchgfx


#endif   //WIDGET_TEXTUREMAPPER_HPP

