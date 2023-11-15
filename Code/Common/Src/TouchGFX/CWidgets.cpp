
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
//         File : CWidgets.cpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX widget container class implementation file
//=============================================================================


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <CWidgets.hpp>
#include <CScreen.hpp>


namespace touchgfx
{

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void rotateBox(Box& box)
{
	if(getScrDir() == SCR_PORTRAIT)
	{
		Rect rect = box.getRect();
		box.setPosition(rect.x, rect.y, rect.height, rect.width);
	}
}

//-----------------------------------------------------------------------------
void rotateTextureMapper(TextureMapper& mapper)
{
	if(getScrDir() == SCR_PORTRAIT)
	{
	    Bitmap image = mapper.getBitmap();
	    float newBitmapX = (mapper.getWidth()/2 - image.getWidth()/2);
	    float newBitmapY = (mapper.getHeight()/2 - image.getHeight()/2);
	    mapper.setBitmapPosition(newBitmapX, newBitmapY);
	    mapper.setOrigo(mapper.getWidth()/2, mapper.getHeight()/2, 1000.0f);
	    mapper.setAngles(0.0f, 0.0f, TEXTUREMAPPER_270_ANGLE_Z);
	}
}

////=============================================================================
////  C O N S T R U C T O R S
////-----------------------------------------------------------------------------
//CWidgets::CWidgets(int size, Rotation rotation)
//{
//	m_Size = size;
//	m_List = (CWidget**)malloc(sizeof(CWidget*) * size);
//	curRotation = rotation;
//}
//
//
////=============================================================================
////  M E T H O D S
////-----------------------------------------------------------------------------
//CWidget* CWidgets::get(int index)
//{
//	if(index < m_Size)
//		return m_List[index];
//	return NULL;
//}
//
////-----------------------------------------------------------------------------
//void CWidgets::set(int index, CWidget* widget)
//{
//	if(index < m_Size)
//	{
//		widget->curRotation = curRotation;
//		m_List[index] = widget;
//	}
//}
//
////-----------------------------------------------------------------------------
//void CWidgets::position()
//{
//    for(int i = 0; i < m_Size; i++)
//    	m_List[i]->position();
//}

}   //namespace touchgfx
