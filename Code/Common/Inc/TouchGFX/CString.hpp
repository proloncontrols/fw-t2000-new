//
////=============================================================================
////         PPPPPPP   RRRRRRR    OOOOOO   LL      OOOOOO   NN    NN
////         PP    PP  RR    RR  OO    OO  LL     OO    OO  NNN   NN
////         PP    PP  RR    RR  OO    OO  LL     OO    OO  NN N  NN
////         PPPPPPP   RRRRRRR   OO    OO  LL     OO    OO  NN NN NN
////         PP        RR  RR    OO    OO  LL     OO    OO  NN  N NN
////         PP        RR   RR   OO    OO  LL     OO    OO  NN   NNN
////         PP        RR    RR   OOOOOO   LLLLLL  OOOOOO   NN    NN
////
////                        (c) Copyright  2022-2023
////-----------------------------------------------------------------------------
////         File : CString.hpp
////         Date : -----------
////       Author : Jean-Francois Barriere
////-----------------------------------------------------------------------------
////  Description : Array of CChar manipulation header file
////=============================================================================
//#ifndef CSTRING_HPP
//#define CSTRING_HPP
//
//
////=============================================================================
////  I N C L U D E S
////-----------------------------------------------------------------------------
//#include <CChar.hpp>
//#include <touchgfx/Containers/Container.hpp>
//#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
//
//
//namespace touchgfx
//{
//
////=============================================================================
////  C L A S S E S
////-----------------------------------------------------------------------------
//class CString : public Container
//{
//public:
//	CString(CChar* array, int capacity, const TypedText& textType, uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue);
//	void setCharSpacingRatio(uint8_t ratio);
//	void setText(const char* newText);
//	int16_t getMaxGlyphHeight();
//
//private:
//	CChar* strArray;
//	int16_t strCapacity;
//	uint8_t charSpacingRatio;
//	int16_t charSpacingWidth;
//	int16_t maxGlyphHeight;
//};
//
//
//
//
//
////class CMeterValue : public Container
////{
////public:
////	CMeterValue(uint8_t newPrecision, uint8_t newSpacingRatio, const TypedText& newTextType, uint8_t newColorRed, uint8_t newColorGreen, uint8_t newColorBlue);
////	void display(int16_t value);
////	int16_t getMaxGlyphHeight();
////
////protected:
////	typedef TextAreaWithOneWildcard MeterDigitWidget;
////	typedef Unicode::UnicodeChar MeterDigitBuffer[2];
////
////	class CMeterDigit
////	{
////	public:
////		MeterDigitWidget widget;
////		MeterDigitBuffer buffer = {0};
////	};
////
////private:
////	char* valueString;
////	int16_t maxGlyphHeight;
////	CMeterDigit** digits;
////	uint8_t precision;
////	uint8_t spacingRatio;   //Set to 0 for no ratio
////	TypedText textType;
////};
//
//
//
//
//
//}   //namespace touchgfx
//
//
//#endif   //CSTRING_HPP
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
