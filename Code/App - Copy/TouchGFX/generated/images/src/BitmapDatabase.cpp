// 4.20.0 0xb2de4592
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_coolingon_560x560[]; // BITMAP_COOLINGON_560X560_ID = 0, Size: 560x560 pixels
extern const unsigned char image_dark_pageindicator_dot_indicator_small_highlight[]; // BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_SMALL_HIGHLIGHT_ID = 1, Size: 15x15 pixels
extern const unsigned char image_dark_pageindicator_dot_indicator_small_normal[]; // BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_SMALL_NORMAL_ID = 2, Size: 15x15 pixels
extern const unsigned char image_drop_30x30[]; // BITMAP_DROP_30X30_ID = 3, Size: 30x30 pixels
extern const unsigned char image_ecoon_560x560[]; // BITMAP_ECOON_560X560_ID = 4, Size: 560x560 pixels
extern const unsigned char image_heatingon_560x560[]; // BITMAP_HEATINGON_560X560_ID = 5, Size: 560x560 pixels
extern const unsigned char image_outside_24x24[]; // BITMAP_OUTSIDE_24X24_ID = 6, Size: 24x24 pixels
extern const unsigned char image_prolon_176x176[]; // BITMAP_PROLON_176X176_ID = 7, Size: 176x176 pixels
extern const unsigned char image_setting50x50[]; // BITMAP_SETTING50X50_ID = 8, Size: 50x50 pixels
extern const unsigned char image_snowflake_50x50[]; // BITMAP_SNOWFLAKE_50X50_ID = 9, Size: 50x50 pixels
extern const unsigned char image_standbymode_60x60[]; // BITMAP_STANDBYMODE_60X60_ID = 10, Size: 60x60 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_coolingon_560x560, 0, 560, 560, 109, 99, 341, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 347, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_dark_pageindicator_dot_indicator_small_highlight, 0, 15, 15, 3, 3, 9, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 9, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_dark_pageindicator_dot_indicator_small_normal, 0, 15, 15, 3, 3, 9, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 9, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_drop_30x30, 0, 30, 30, 4, 8, 12, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_ecoon_560x560, 0, 560, 560, 114, 107, 332, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 337, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_heatingon_560x560, 0, 560, 560, 114, 101, 332, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 343, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_outside_24x24, 0, 24, 24, 7, 8, 11, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 5, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_prolon_176x176, 0, 176, 176, 0, 0, 0, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 0, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_setting50x50, 0, 50, 50, 16, 42, 19, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_snowflake_50x50, 0, 50, 50, 23, 1, 4, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 47, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_standbymode_60x60, 0, 60, 60, 4, 30, 12, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 27, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase