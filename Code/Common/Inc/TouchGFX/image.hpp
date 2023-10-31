
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
//         File : image.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX image class/tools header file
//=============================================================================
#ifndef IMG_H
#define IMG_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "widget.hpp"


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CImage : public CWidget
{
private:
	touchgfx::TextureMapper& m_Mapper;

public:
	CImage(touchgfx::TextureMapper& Mapper);

	virtual touchgfx::Rect getRect();
	virtual void initialize();
	virtual void getPosition(CRect& rect);
	virtual void setPosition(CRect& rect);
};


#endif   //IMG_H
