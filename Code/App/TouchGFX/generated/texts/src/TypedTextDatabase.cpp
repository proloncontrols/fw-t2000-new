/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <touchgfx/TypedText.hpp>
#include <fonts/GeneratedFont.hpp>
#include <texts/TypedTextDatabase.hpp>

extern touchgfx::GeneratedFont& getFont_AvenirNext_Regular_08_220_4bpp();
extern touchgfx::GeneratedFont& getFont_AvenirNext_Regular_08_80_4bpp();
extern touchgfx::GeneratedFont& getFont_AvenirNext_Regular_08_50_4bpp();
extern touchgfx::GeneratedFont& getFont_AvenirNext_Regular_08_150_4bpp();
extern touchgfx::GeneratedFont& getFont_AvenirNext_Regular_08_54_4bpp();
extern touchgfx::GeneratedFont& getFont_AvenirNext_Regular_08_34_4bpp();
extern touchgfx::GeneratedFont& getFont_AvenirNext_Regular_08_24_4bpp();

const touchgfx::Font* touchgfx_fonts[] = {
    &(getFont_AvenirNext_Regular_08_220_4bpp()),
    &(getFont_AvenirNext_Regular_08_80_4bpp()),
    &(getFont_AvenirNext_Regular_08_50_4bpp()),
    &(getFont_AvenirNext_Regular_08_150_4bpp()),
    &(getFont_AvenirNext_Regular_08_54_4bpp()),
    &(getFont_AvenirNext_Regular_08_34_4bpp()),
    &(getFont_AvenirNext_Regular_08_24_4bpp())
};

extern const touchgfx::TypedText::TypedTextData typedText_database_DEFAULT[];
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
const touchgfx::TypedText::TypedTextData typedText_database_DEFAULT[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    { 2, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 0, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 1, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 2, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 2, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 4, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 5, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 5, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 1, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 6, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 6, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 6, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR }
};

TEXT_LOCATION_FLASH_PRAGMA
const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    typedText_database_DEFAULT
};

namespace TypedTextDatabase
{
const touchgfx::TypedText::TypedTextData* getInstance(touchgfx::LanguageId id)
{
    return typedTextDatabaseArray[id];
}

uint16_t getInstanceSize()
{
    return sizeof(typedText_database_DEFAULT) / sizeof(touchgfx::TypedText::TypedTextData);
}

const touchgfx::Font** getFonts()
{
    return touchgfx_fonts;
}

const touchgfx::Font* setFont(touchgfx::FontId fontId, const touchgfx::Font* font)
{
    const touchgfx::Font* old = touchgfx_fonts[fontId];
    touchgfx_fonts[fontId] = font;
    return old;
}

void resetFont(touchgfx::FontId fontId)
{
    switch (fontId)
    {
    case 0:
        touchgfx_fonts[0] = &(getFont_AvenirNext_Regular_08_220_4bpp());
        break;
    case 1:
        touchgfx_fonts[1] = &(getFont_AvenirNext_Regular_08_80_4bpp());
        break;
    case 2:
        touchgfx_fonts[2] = &(getFont_AvenirNext_Regular_08_50_4bpp());
        break;
    case 3:
        touchgfx_fonts[3] = &(getFont_AvenirNext_Regular_08_150_4bpp());
        break;
    case 4:
        touchgfx_fonts[4] = &(getFont_AvenirNext_Regular_08_54_4bpp());
        break;
    case 5:
        touchgfx_fonts[5] = &(getFont_AvenirNext_Regular_08_34_4bpp());
        break;
    case 6:
        touchgfx_fonts[6] = &(getFont_AvenirNext_Regular_08_24_4bpp());
        break;
    }
}
} // namespace TypedTextDatabase
