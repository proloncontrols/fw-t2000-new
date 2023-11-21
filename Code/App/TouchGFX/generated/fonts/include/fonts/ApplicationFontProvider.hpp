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
    static const touchgfx::FontId T2000_METERLARGE = 0;
    static const touchgfx::FontId T2000_METERMEDIUM = 1;
    static const touchgfx::FontId T2000_METERSMALL = 2;
    static const touchgfx::FontId T2000_METERTINY = 3;
};

struct TypographyFontIndex
{
    static const touchgfx::FontId T2000_METERLARGE = 0;  // AvenirNext_Medium_06_220_4bpp
    static const touchgfx::FontId T2000_METERMEDIUM = 1; // AvenirNext_Medium_06_180_4bpp
    static const touchgfx::FontId T2000_METERSMALL = 2;  // AvenirNext_Regular_08_70_4bpp
    static const touchgfx::FontId T2000_METERTINY = 3;   // AvenirNext_Medium_06_22_4bpp
    static const uint16_t NUMBER_OF_FONTS = 4;
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
