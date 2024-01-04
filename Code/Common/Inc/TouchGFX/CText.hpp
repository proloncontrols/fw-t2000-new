
//=============================================================================
//         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
//         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
//         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
//         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
//         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
//         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
//
//                        (c) Copyright  2022-2024
//-----------------------------------------------------------------------------
//         File : CText.hpp
//         Date : -----------
//       Author : Jean-Francois Barriere
//-----------------------------------------------------------------------------
//  Description : Manipulated text class header file
//=============================================================================
#ifndef CTEXT_HPP
#define CTEXT_HPP


//=============================================================================
//  I N C L U D E S
//-----------------------------------------------------------------------------
#include <touchgfx/TypedText.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/Containers/Container.hpp>


namespace touchgfx
{

//=============================================================================
//  C L A S S E S
//-----------------------------------------------------------------------------
class CText : public Container
{
public:
	CText(int newMaxLength, int newSpacingRatio, const TypedText& newType, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);

	void operator=(const char* newText);
	void render();
	int16_t getBaseline();
	int getLength();

public:
	class CDigit : public Container
	{
	public:
		CDigit(const TypedText& newType, uint8_t newColorR, uint8_t newColorG, uint8_t newColorB);

		void setDigit(const char newDigit);
		void render();
		const Font* getFont();
		const GlyphNode* getGlyph();

	private:
//		Box background;
		TextAreaWithOneWildcard area;
		Unicode::UnicodeChar buffer[2];
	};

private:
//	Box background;
	int maxLength;
	int curLength;
	CDigit** digits;
	int16_t spacingWidth;
	TypedText type;
};

}   //namespace touchgfx


#endif   //CTEXT_HPP
