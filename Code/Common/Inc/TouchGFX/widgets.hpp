
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
//         File : widgets.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX widget container class header file
//=============================================================================
#ifndef WGTS_H
#define WGTS_H


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "widget.hpp"


//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CWidgets
{
private:
	int m_Size;
	CWidget** m_List;

public:
	CWidgets(int size);

public:
	CWidget* get(int index);
	void set(int index, CWidget* widget);
    void update();
};


#endif   //WGTS_H
