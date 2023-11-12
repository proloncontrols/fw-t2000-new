#include <gui/splash_screen/SplashView.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>

SplashView::SplashView()
{
    __background.setPosition(0, 0, 720, 672);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    //This is used to view the actual client area only (can be removed)
    client.setPosition(24, 0, 672, 672);
    client.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
    add(client);

    //Initialize swipe container origin (absolute coordinates) and size (relative to origin)
//    swipe.initialize(48, 24, 500, 250);
    swipe.initialize(48, 24, 500, 250, INDICATOR_TOP_CENTER, BITMAP_BLUE_PAGEINDICATOR_DOT_INDICATOR_SMALL_NORMAL_ID, BITMAP_BLUE_PAGEINDICATOR_DOT_INDICATOR_SMALL_HIGHLIGHT_ID);
    swipe.setSwipeCutoff(50);
    swipe.setEndSwipeElasticWidth(50);

    //Pages MUST be added to container before they are populated
    //They get their size initialized at that point
    //Before that, they cannot hold any other components
    swipe.addPage(swipePage1);
    swipe.addPage(swipePage2);

    box1.setPosition(swipePage1.client.x, swipePage1.client.y, swipePage1.client.width, swipePage1.client.height);
    box1.setColor(touchgfx::Color::getColorFromRGB(100, 0, 0));
    box3.setPosition(24, 24, 150, 75);
    box3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    swipePage1.add(box1);
    swipePage1.addToClient(box3);

    box2.setPosition(swipePage2.client.x, swipePage2.client.y, swipePage2.client.width, swipePage2.client.height);
    box2.setColor(touchgfx::Color::getColorFromRGB(100, 100, 0));
    box4.setPosition(24, 24, 75, 150);
    box4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    swipePage2.add(box2);
    swipePage2.addToClient(box4);

    swipe.setSelectedPage(0);
    add(swipe);

//    __background.setPosition(0, 0, 720, 672);
//    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
//    add(__background);
//
//    //This is used to view the actual client area only (can be removed)
//    client.setPosition(24, 0, 672, 672);
//    client.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//    add(client);
//
//    //Initialize swipe container origin (absolute coordinates) and size (relative to origin)
//    swipe.initialize(48, 24, 500, 250, INDICATOR_TOP_CENTER, BITMAP_BLUE_PAGEINDICATOR_DOT_INDICATOR_SMALL_NORMAL_ID, BITMAP_BLUE_PAGEINDICATOR_DOT_INDICATOR_SMALL_HIGHLIGHT_ID);
//    swipe.setSwipeCutoff(50);
//    swipe.setEndSwipeElasticWidth(50);
//
//    swipe.addPage(swipePage1);   //Page MUST be added to container before it is populated (it gets sized at that point)
//    box1.setPosition(0, 0, 100, 50);
//    box1.setColor(touchgfx::Color::getColorFromRGB(100, 0, 0));
//    swipePage1.add(box1);
//
//    swipe.addPage(swipePage2);
//    box2.setPosition(50, 50, 50, 100);
//    box2.setColor(touchgfx::Color::getColorFromRGB(100, 0, 0));
//    swipePage2.add(box2);
//
//    swipe.setSelectedPage(0);
//    add(swipe);
//
//    Rect rect = swipe.getClientRect();
//    box3.setPosition(rect.x, rect.y, rect.width, rect.height);
//    box3.setColor(touchgfx::Color::getColorFromRGB(100, 100, 0));
//    swipePage1.insert(&box1, box3);
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}
