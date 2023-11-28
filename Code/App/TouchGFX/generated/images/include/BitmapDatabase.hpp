// Generated by imageconverter. Please, do not edit!

#ifndef TOUCHGFX_BITMAPDATABASE_HPP
#define TOUCHGFX_BITMAPDATABASE_HPP

#include <touchgfx/hal/Types.hpp>
#include <touchgfx/Bitmap.hpp>

const uint16_t BITMAP_HUMIDITY_30X30_ID = 0;
const uint16_t BITMAP_MENU_BUTTON_ID = 1;
const uint16_t BITMAP_OUTSIDE_24X24_ID = 2;
const uint16_t BITMAP_SETTING_ID = 3;
const uint16_t BITMAP_SETTING_DARK2_ID = 4;

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance();
uint16_t getInstanceSize();
} // namespace BitmapDatabase

#endif // TOUCHGFX_BITMAPDATABASE_HPP
