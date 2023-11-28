
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
//         File : CWidgets.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : TouchGFX widget container class header file
//=============================================================================
#ifndef WIDGETS_HPP
#define WIDGETS_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/FontManager.hpp>
#include <fonts/ApplicationFontProvider.hpp>
//#include <CWidget.hpp>
//#include <CButton.hpp>
//#include <CImage.hpp>
//#include <CText.hpp>


namespace touchgfx
{

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void rotateBox(Box& box);
void rotateTextureMapper(TextureMapper& mapper);
int16_t getStringWidth(TextArea& text, int16_t maxLength);


////=============================================================================
////  C L A S S E S
////-----------------------------------------------------------------------------
//class CWidgets
//{
//public:
//	CWidgets(int size, Rotation rotation);
//
//	CWidget* get(int index);
//	void set(int index, CWidget* widget);
//    void position();
//
//private:
//	int m_Size;
//	CWidget** m_List;
//	Rotation curRotation;
//};
//
}   //namespace touchgfx


#endif   //WIDGETS_HPP
