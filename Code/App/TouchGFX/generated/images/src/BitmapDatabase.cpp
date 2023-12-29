// 4.20.0 0x7bd1ed39
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_cooling_on_576x576[]; // BITMAP_COOLING_ON_576X576_ID = 0, Size: 576x576 pixels
extern const unsigned char image_home_60x60[]; // BITMAP_HOME_60X60_ID = 1, Size: 60x60 pixels
extern const unsigned char image_humidity_30x30[]; // BITMAP_HUMIDITY_30X30_ID = 2, Size: 30x30 pixels
extern const unsigned char image_menu__selected_496x496x76[]; // BITMAP_MENU__SELECTED_496X496X76_ID = 3, Size: 496x496 pixels
extern const unsigned char image_menu_button_496x496x76[]; // BITMAP_MENU_BUTTON_496X496X76_ID = 4, Size: 496x496 pixels
extern const unsigned char image_menu_line_gray_494x494x4[]; // BITMAP_MENU_LINE_GRAY_494X494X4_ID = 5, Size: 494x494 pixels
extern const unsigned char image_menu_line_white_496x496x6[]; // BITMAP_MENU_LINE_WHITE_496X496X6_ID = 6, Size: 496x496 pixels
extern const unsigned char image_outside_24x24[]; // BITMAP_OUTSIDE_24X24_ID = 7, Size: 24x24 pixels
extern const unsigned char image_prolon_178x178[]; // BITMAP_PROLON_178X178_ID = 8, Size: 178x178 pixels
extern const unsigned char image_prolonlogo470x470[]; // BITMAP_PROLONLOGO470X470_ID = 9, Size: 470x470 pixels
extern const unsigned char image_return_50x50[]; // BITMAP_RETURN_50X50_ID = 10, Size: 50x50 pixels
extern const unsigned char image_setting[]; // BITMAP_SETTING_ID = 11, Size: 50x50 pixels
extern const unsigned char image_setting_dark2[]; // BITMAP_SETTING_DARK2_ID = 12, Size: 50x50 pixels
extern const unsigned char image_snowflake_50x50[]; // BITMAP_SNOWFLAKE_50X50_ID = 13, Size: 50x50 pixels
extern const unsigned char image_standby_mode_58x58[]; // BITMAP_STANDBY_MODE_58X58_ID = 14, Size: 58x58 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_cooling_on_576x576, 0, 576, 576, 116, 109, 344, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 344, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_home_60x60, 0, 60, 60, 36, 28, 15, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_humidity_30x30, 0, 30, 30, 4, 8, 12, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_menu__selected_496x496x76, 0, 496, 496, 28, 1, 440, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 72, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_menu_button_496x496x76, 0, 496, 496, 28, 1, 440, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 71, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_menu_line_gray_494x494x4, 0, 494, 494, 0, 0, 494, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_menu_line_white_496x496x6, 0, 496, 496, 0, 0, 496, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 5, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_outside_24x24, 0, 24, 24, 8, 6, 9, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 7, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_prolon_178x178, 0, 178, 178, 0, 0, 0, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 0, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_prolonlogo470x470, 0, 470, 470, 155, 15, 21, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 45, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_return_50x50, 0, 50, 50, 0, 9, 11, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 12, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_setting, 0, 50, 50, 16, 42, 19, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_setting_dark2, 0, 50, 50, 16, 42, 19, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_snowflake_50x50, 0, 50, 50, 23, 1, 4, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 48, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_standby_mode_58x58, 0, 58, 58, 3, 20, 12, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 28, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
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
