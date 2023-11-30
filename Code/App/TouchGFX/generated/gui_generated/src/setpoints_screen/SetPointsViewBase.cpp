/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/setpoints_screen/SetPointsViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>

SetPointsViewBase::SetPointsViewBase()
{

    __background.setPosition(0, 0, 720, 672);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    swipeContainer1.setXY(48, 24);
    swipeContainer1.setPageIndicatorBitmaps(touchgfx::Bitmap(BITMAP_BLUE_PAGEINDICATOR_DOT_INDICATOR_SMALL_NORMAL_ID), touchgfx::Bitmap(BITMAP_BLUE_PAGEINDICATOR_DOT_INDICATOR_SMALL_HIGHLIGHT_ID));
    swipeContainer1.setPageIndicatorXY(297, 600);
    swipeContainer1.setSwipeCutoff(50);
    swipeContainer1.setEndSwipeElasticWidth(50);

    swipeContainer1Page1.setWidth(624);
    swipeContainer1Page1.setHeight(624);

    setpointCool1.setXY(-48, -24);
    swipeContainer1Page1.add(setpointCool1);
    swipeContainer1.add(swipeContainer1Page1);

    swipeContainer1Page2.setWidth(624);
    swipeContainer1Page2.setHeight(624);

    setpointHeat1.setXY(-48, -24);
    swipeContainer1Page2.add(setpointHeat1);
    swipeContainer1.add(swipeContainer1Page2);
    swipeContainer1.setSelectedPage(0);

    add(__background);
    add(swipeContainer1);
}

void SetPointsViewBase::setupScreen()
{
    setpointCool1.initialize();
    setpointHeat1.initialize();
}