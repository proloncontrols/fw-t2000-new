#include <gui/splash_screen/SplashView.hpp>

#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>

#include "cfg.h"
#include "image.hpp"

SplashView::SplashView()
{
//	Widgets = new CWidgets(splashCount);

//	Widgets->set(splashImgProlon, new CImage(imgProlon));

    swipeContainer11.setXY(24, 0);
    swipeContainer11.setWidth(672);
//    swipeContainer11.setXY(0, 0);
    swipeContainer11.setPageIndicatorBitmaps(touchgfx::Bitmap(BITMAP_DOT_INDICATOR_LARGE_NORMAL_ID), touchgfx::Bitmap(BITMAP_DOT_INDICATOR_LARGE_HIGHLIGHT_ID));
    swipeContainer11.setPageIndicatorXY(316, 20);
    swipeContainer11.setSwipeCutoff(50);
    swipeContainer11.setEndSwipeElasticWidth(50);

    swipeContainer1Page1.setWidth(672);
//    swipeContainer1Page1.setWidth(720);
    swipeContainer1Page1.setHeight(672);

    box1.setPosition(0, 0, 672, 672);
//    box1.setPosition(0, 0, 720, 672);
    box1.setColor(touchgfx::Color::getColorFromRGB(122, 117, 13));
    swipeContainer1Page1.add(box1);
    swipeContainer11.add(swipeContainer1Page1);

    swipeContainer1Page2.setWidth(672);
//    swipeContainer1Page2.setWidth(720);
    swipeContainer1Page2.setHeight(672);

    box2.setPosition(0, 0, 672, 672);
//    box2.setPosition(0, 0, 720, 672);
    box2.setColor(touchgfx::Color::getColorFromRGB(21, 112, 9));
    swipeContainer1Page2.add(box2);
    swipeContainer11.add(swipeContainer1Page2);
    swipeContainer11.setSelectedPage(1);

    add(swipeContainer11);
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
//    Widgets->place();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}

void SplashView::OnScreenTransitionEnd()
{
	presenter->PostSystemReady();
}

//void SplashView::handleClickEvent(const ClickEvent& evt)
//{
//
//}
