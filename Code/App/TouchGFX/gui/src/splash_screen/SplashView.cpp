
#include <gui/splash_screen/SplashView.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

#define PAGE_WIDTH    500
#define PAGE_HEIGHT   300

//    touchgfx::Box __background;
//    touchgfx::SwipeContainer swipeContainer1;
//    touchgfx::Container swipeContainer1Page1;

//    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
//
//    swipeContainer1.setXY(0, 0);
//    swipeContainer1.setSwipeCutoff(50);
//    swipeContainer1.setEndSwipeElasticWidth(50);
//
//    swipeContainer1Page1.setWidth(250);
//    swipeContainer1Page1.setHeight(250);
//    swipeContainer1.add(swipeContainer1Page1);
//    swipeContainer1.setSelectedPage(0);
//
//    add(__background);
//    add(swipeContainer1);

SplashView::SplashView()
{
//	remove(__background);
//	Screen::container.setPosition(CLIENT_X, CLIENT_Y, CLIENT_WIDTH, CLIENT_HEIGHT);
//    __background.setPosition(0, 0, CLIENT_WIDTH, CLIENT_HEIGHT);
//    __background.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//	add(__background);

//	container.setPosition(24, 24, PAGE_WIDTH, PAGE_HEIGHT);
//
//	containerClient.setPosition(0, 0, PAGE_WIDTH, PAGE_HEIGHT);
//	containerClient.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
//	container.add(containerClient);
//
//    box1.setPosition(24, 24, 350, 200);
//    box1.setColor(touchgfx::Color::getColorFromRGB(100, 0, 0));
//	container.add(box1);
//
//	add(container);




//	swipe.setXY(24, 24);
//	swipe.setSwipeCutoff(10);
//	swipe.setEndSwipeElasticWidth(10);
//
//    page1.setWidth(500);
//	page1.setHeight(250);
//
//    box1.setPosition(24, 24, 500, 250);
//    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
//    page1.add(box1);
//
//    swipe.add(page1);
//	swipe.setSelectedPage(0);
//
//	add(swipe);














//	swipe.setPosition(CLIENT_X, CLIENT_Y, CLIENT_WIDTH, CLIENT_HEIGHT);
//	swipe.setXY(24, 0);
//	swipe.setPageIndicatorBitmaps(touchgfx::Bitmap(BITMAP_DOT_INDICATOR_LARGE_NORMAL_ID), touchgfx::Bitmap(BITMAP_DOT_INDICATOR_LARGE_HIGHLIGHT_ID));
//    swipe.setPageIndicatorXY(100, 610);
//    swipe.setPageIndicatorXY(292, 610);
//	swipe.setSwipeCutoff(50);
//	swipe.setEndSwipeElasticWidth(50);





















//	swipePageBackground.setPosition(0, 0, PAGE_WIDTH, PAGE_HEIGHT);
//	swipePage.add(swipePageBackground);
//
//	swipe.add(swipePage);
//
//	swipe.initialize((Rotation)CFG.Dta.ScrOrientation, 0, 0, PAGE_WIDTH, PAGE_HEIGHT);
//    add(swipe);










//	swipe.initialize(0, 0, PAGE_WIDTH, PAGE_HEIGHT, INDICATOR_BOTTOM_CENTER, (Rotation)CFG.Dta.ScrOrientation);



//	swipe.setPosition(0, 0, PAGE_WIDTH, PAGE_HEIGHT, (Rotation)CFG.Dta.ScrOrientation);

//    splashPageBackground.setPosition(0, 0, PAGE_WIDTH, PAGE_HEIGHT);
//	splashPageBackground.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//	splashPage.add(splashPageBackground);
//	swipe.add(splashPage);





//	back.setWidthHeight(500, 300);
//	back.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//	backPage.setWidth(back.getWidth());
//	backPage.setHeight(back.getHeight());
//
//	textArea1.setXY(0, 0);
//    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
//    textArea1.setLinespacing(0);
//    textArea1Buffer[0] = 0;
//    textArea1.setWildcard(textArea1Buffer);
//    textArea1.resizeToCurrentText();
//    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1OTR));
//
//	backPage.add(back);
//	backPage.add(textArea1);
//
//	swipe.add(backPage);
//    add(swipe);






//	int Len = textArea1.getTextWidth();
//	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", "Test");
////	textArea1.invalidate();
//	Len = textArea1.getTextWidth();
//	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", "Test001");
////	textArea1.invalidate();
//	Len = textArea1.getTextWidth();
//
//
//	if(Len)
//		Len++;
//
//
//
//	swipe.setXY(0, 0, (Rotation)CFG.Dta.ScrOrientation);
//
////	back.setPosition(0, 0, 500, 300);
//	back.setWidthHeight(500, 300);
//	back.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//	backPage.setWidth(back.getWidth());
//	backPage.setHeight(back.getHeight());
//
////	back.setXY(0, 0);
//	backPage.add(back);
//	swipe.add(backPage);
//
//
//
//
//
//
//
////	swipe.setPosition(CLIENT_X, CLIENT_Y, 500, CLIENT_HEIGHT, (Rotation)CFG.Dta.ScrOrientation);
////	swipe.setPageIndicatorBitmaps(touchgfx::Bitmap(BITMAP_DOT_INDICATOR_LARGE_NORMAL_ID), touchgfx::Bitmap(BITMAP_DOT_INDICATOR_LARGE_HIGHLIGHT_ID));
//
////	back.setPosition(CLIENT_X, CLIENT_Y, 500, CLIENT_HEIGHT-200);
////	back.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//
////	backPage.setWidth(500);
////	backPage.setHeight(CLIENT_HEIGHT);
//
////	back.setXY(0, 100);
////	backPage.add(back);
////	swipe.add(backPage);
//
//
////	back2.setPosition(CLIENT_X, CLIENT_Y, 500, CLIENT_HEIGHT-200);
////	back2.setColor(touchgfx::Color::getColorFromRGB(150, 75, 75));
////
////	backPage2.setWidth(500);
////	backPage2.setHeight(CLIENT_HEIGHT);
////
////	back2.setXY(0, 100);
////	backPage2.add(back2);
////	swipe.add(backPage2);
//
//
////	swipe.setPageIndicatorPosition(INDICATOR_TOP_RIGHT);
//
//    add(swipe);




//    swipe.setPageIndicatorBitmaps(touchgfx::Bitmap(BITMAP_DOT_INDICATOR_LARGE_NORMAL_ID), touchgfx::Bitmap(BITMAP_DOT_INDICATOR_LARGE_HIGHLIGHT_ID));
//    swipe.setSwipeCutoff(50);
//    swipe.setEndSwipeElasticWidth(50);
//
//
//
//	swipePageSplash.setWidth(672);
//	swipePageSplash.setHeight(672);
//
//	splash.setXY(0, 0);
//	swipePageSplash.add(splash);
//	swipe.add(swipePageSplash);
//
//	swipePageHome.setWidth(672);
//	swipePageHome.setHeight(672);
//
//	home.setXY(0, 0);
//	swipePageHome.add(home);
//	swipe.add(swipePageHome);
//
//	swipe.setSelectedPage(1);
//
////	swipe.setPageIndicatorY(610);
//







////	swipe.setXY(24, 0);
//	swipe.setPosition(SCREEN_OFFSET, 0, SCREEN_HEIGHT, SCREEN_HEIGHT);
//	swipe.setPageIndicatorBitmaps(touchgfx::Bitmap(BITMAP_DOT_INDICATOR_LARGE_NORMAL_ID), touchgfx::Bitmap(BITMAP_DOT_INDICATOR_LARGE_HIGHLIGHT_ID));
//	swipe.setSwipeCutoff(50);
//	swipe.setEndSwipeElasticWidth(50);
//
//	swipePageBlue.setWidth(swipe.getHeight());
//	swipePageBlue.setHeight(swipe.getWidth());
////	swipePageBlue.setWidth(swipe.getWidth());
////	swipePageBlue.setHeight(swipe.getHeight());
//
//	blue.setXY(0, 0);
//	swipePageBlue.add(blue);
//	swipe.add(swipePageBlue);
//
//	swipePageRed.setWidth(swipe.getHeight());
//	swipePageRed.setHeight(swipe.getWidth());
////	swipePageRed.setWidth(swipe.getWidth());
////	swipePageRed.setHeight(swipe.getHeight());
//
//	red.setXY(0, 0);
//	swipePageRed.add(red);
//	swipe.add(swipePageRed);
//
////    swipe.setSelectedPage(1);
//
//	swipe.setPageIndicatorY(610);
//
//	add(swipe);

////	swipe.setPosition(CLIENT_X, CLIENT_Y, CLIENT_WIDTH, CLIENT_HEIGHT);
//    swipe.setXY(24, 0);
//    swipe.setPageIndicatorBitmaps(touchgfx::Bitmap(BITMAP_DOT_INDICATOR_LARGE_NORMAL_ID), touchgfx::Bitmap(BITMAP_DOT_INDICATOR_LARGE_HIGHLIGHT_ID));
////    swipe.setPageIndicatorXY(100, 610);
////    swipe.setPageIndicatorXY(292, 610);
//    swipe.setSwipeCutoff(50);
//    swipe.setEndSwipeElasticWidth(50);
//
//    swipePageSplash.setWidth(672);
//    swipePageSplash.setHeight(672);
//
//    splash.setXY(0, 0);
//    swipePageSplash.add(splash);
//    swipe.add(swipePageSplash);
//
//    swipePageHome.setWidth(672);
//    swipePageHome.setHeight(672);
//
//    home.setXY(0, 0);
//    swipePageHome.add(home);
//    swipe.add(swipePageHome);
//
//    swipe.setSelectedPage(1);

//    swipe.setPageIndicatorY(610);

//    add(swipe);
}

void SplashView::setupScreen()
{
	SplashViewBase::setupScreen();

//	splash.initialize();
//    home.initialize();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}

void SplashView::OnScreenTransitionEnd()
{
	presenter->PostSystemReady();
}
