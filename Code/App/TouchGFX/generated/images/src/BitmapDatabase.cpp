// 4.20.0 0x0f40115b
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_home[]; // BITMAP_HOME_ID = 0, Size: 60x60 pixels
extern const unsigned char image_humidity_30x30[]; // BITMAP_HUMIDITY_30X30_ID = 1, Size: 30x30 pixels
extern const unsigned char image_menu_button[]; // BITMAP_MENU_BUTTON_ID = 2, Size: 496x496 pixels
extern const unsigned char image_menu_line_gray_494x494x3[]; // BITMAP_MENU_LINE_GRAY_494X494X3_ID = 3, Size: 494x494 pixels
extern const unsigned char image_menu_line_white_496x496x5[]; // BITMAP_MENU_LINE_WHITE_496X496X5_ID = 4, Size: 496x496 pixels
extern const unsigned char image_outside_24x24[]; // BITMAP_OUTSIDE_24X24_ID = 5, Size: 24x24 pixels
extern const unsigned char image_prolon_176x176[]; // BITMAP_PROLON_176X176_ID = 6, Size: 176x176 pixels
extern const unsigned char image_return_50x50[]; // BITMAP_RETURN_50X50_ID = 7, Size: 50x50 pixels
extern const unsigned char image_setting[]; // BITMAP_SETTING_ID = 8, Size: 50x50 pixels
extern const unsigned char image_setting_dark2[]; // BITMAP_SETTING_DARK2_ID = 9, Size: 50x50 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_home, 0, 60, 60, 36, 28, 15, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_humidity_30x30, 0, 30, 30, 4, 8, 12, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_menu_button, 0, 496, 496, 28, 1, 440, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 71, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_menu_line_gray_494x494x3, 0, 494, 494, 0, 0, 494, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_menu_line_white_496x496x5, 0, 496, 496, 0, 0, 496, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 5, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_outside_24x24, 0, 24, 24, 8, 6, 9, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 7, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_prolon_176x176, 0, 176, 176, 0, 0, 0, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 0, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_return_50x50, 0, 50, 50, 0, 9, 11, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 12, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_setting, 0, 50, 50, 16, 42, 19, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_setting_dark2, 0, 50, 50, 16, 42, 19, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
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
