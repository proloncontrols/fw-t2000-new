/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#ifndef TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
#define TOUCHGFX_APPLICATIONFONTPROVIDER_HPP

#include <touchgfx/FontManager.hpp>

namespace touchgfx
{
class FlashDataReader;
}

struct Typography
{
    static const touchgfx::FontId DEFAULT = 0;
    static const touchgfx::FontId LARGE = 1;
    static const touchgfx::FontId SMALL = 2;
    static const touchgfx::FontId T2000_METERLARGE = 3;
    static const touchgfx::FontId T2000_METERMEDIUM = 4;
    static const touchgfx::FontId T2000_METERSMALL = 5;
    static const touchgfx::FontId T2000_METERTINY = 6;
};

struct TypographyFontIndex
{
    static const touchgfx::FontId DEFAULT = 0;           // verdana_20_4bpp
    static const touchgfx::FontId LARGE = 1;             // verdana_40_4bpp
    static const touchgfx::FontId SMALL = 2;             // verdana_10_4bpp
    static const touchgfx::FontId T2000_METERLARGE = 3;  // AvenirNext_Medium_06_220_4bpp
    static const touchgfx::FontId T2000_METERMEDIUM = 4; // AvenirNext_Medium_06_180_4bpp
    static const touchgfx::FontId T2000_METERSMALL = 5;  // AvenirNext_Regular_08_70_4bpp
    static const touchgfx::FontId T2000_METERTINY = 6;   // AvenirNext_Medium_06_22_4bpp
    static const uint16_t NUMBER_OF_FONTS = 7;
};

class ApplicationFontProvider : public touchgfx::FontProvider
{
public:
    virtual touchgfx::Font* getFont(touchgfx::FontId typography);

    static void setFlashReader(touchgfx::FlashDataReader* /*flashReader*/)
    {
    }

    static touchgfx::FlashDataReader* getFlashReader()
    {
        return 0;
    }
};

#endif // TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
