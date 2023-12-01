
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
#include <stdlib.h>
#include <CWidgets.hpp>
#include <CDisplay.hpp>


namespace touchgfx
{
#define TEXTUREMAPPER_270_ANGLE_Z  -1.572f

//=============================================================================
//  M E T H O D S
//-----------------------------------------------------------------------------
void rotateBox(Box& box)
{
	if(Display.getOrientation() == CDisplay::PORTRAIT)
	{
		Rect rect = box.getRect();
		box.setPosition(rect.x, rect.y, rect.height, rect.width);
	}
}

//-----------------------------------------------------------------------------
void rotateTextureMapper(TextureMapper& mapper)
{
	if(Display.getOrientation() == CDisplay::PORTRAIT)
	{
	    Bitmap image = mapper.getBitmap();
	    float newBitmapX = (mapper.getWidth()/2 - image.getWidth()/2);
	    float newBitmapY = (mapper.getHeight()/2 - image.getHeight()/2);
	    mapper.setBitmapPosition(newBitmapX, newBitmapY);
	    mapper.setOrigo(mapper.getWidth()/2, mapper.getHeight()/2, 1000.0f);
	    mapper.setAngles(0.0f, 0.0f, TEXTUREMAPPER_270_ANGLE_Z);
	}
}

//-----------------------------------------------------------------------------
int16_t getStringWidth(TextArea& text, int16_t maxLength)
{
	uint8_t* s = (uint8_t*)malloc(maxLength);
	int16_t charCount = touchgfx::Unicode::toUTF8(text.getWildcard1(), s, maxLength) - 1;
	free(s);

	const GlyphNode* glyph;
	const Font* font = text.getTypedText().getFont();

	int16_t i = 0;
	int16_t stringLength = 0;
	do
	{
		glyph = font->getGlyph(text.getWildcard1()[i]);
		stringLength += glyph->advance();
		i++;
	}
	while(i < charCount-1);

	glyph = font->getGlyph(text.getWildcard1()[i]);
	stringLength += glyph->width();

//	for(int16_t i = 0; i < charCount-1; i++)
//	{
//		glyph = font->getGlyph(text.getWildcard1()[i]);
//		stringLength += glyph->_width;
//	}

//	int16_t l = glyph->left * 2;

	return stringLength; // - glyph->left;
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
