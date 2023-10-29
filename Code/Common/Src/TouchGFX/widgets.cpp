
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
//         File : widgets.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX widget container class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include "stdlib.h"
#include "widgets.hpp"


//=============================================================================
//  C O N S T R U C T O R S
//-----------------------------------------------------------------------------
CWidgets::CWidgets(int size)
{
	m_Size = size;
	m_List = (CWidget**)malloc(sizeof(CWidget*) * size);
}


//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void CWidgets::set(int index, CWidget* widget)
{
	if(index < m_Size)
		m_List[index] = widget;
}

//-----------------------------------------------------------------------------
CWidget* CWidgets::get(int index)
{
	if(index < m_Size)
		return m_List[index];
	return NULL;
}

//-----------------------------------------------------------------------------
void CWidgets::updateScreen()
{
    for(int i = 0; i < m_Size; i++)
    {
    	m_List[i]->placeOnScreen();
    }
}

//CWidget* CWidgets::operator=(CWidget* Widget)
//{
//	return Widget;
//}

CWidget& CWidgets::operator[](int Index)
{
//	if(Index < m_Size)
		return *(m_List[Index]);
//	return NULL;
}
