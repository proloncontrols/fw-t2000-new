#include <gui/splash_screen/SplashView.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>

SplashView::SplashView()
{
//	image = new CImage(textureMapper1);

	if(application().orientation == SCREEN_PORTRAIT)
	{
	    remove(__background);
	    __background.setPosition(0, 0, 672, 720);
	    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	    add(__background);
	}

	img.setBitmap(Bitmap(BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_LARGE_HIGHLIGHT_ID));
	img.setXY(0, 0);

	add(img);

//    textureMapper1.setXY(38, 330);
//    textureMapper1.setBitmap(touchgfx::Bitmap(BITMAP_PROLON_LOGO_4_ID));
//    textureMapper1.setWidth(521);
//    textureMapper1.setHeight(180);
//    textureMapper1.setBitmapPosition(26.0f, 26.0f);
//    textureMapper1.setScale(0.7f);
//    textureMapper1.setCameraDistance(1000.0f);
//    textureMapper1.setOrigo(90.0f, 90.0f, 1000.0f);
//    textureMapper1.setCamera(260.5f, 90.0f);
//    textureMapper1.setAngles(0.0f, 0.0f, -1.57f);
//    textureMapper1.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);
//
//    add(textureMapper1);





//    //This is used to view the actual client area only (can be removed)
//    client.setPosition(application().originX, application().originY, 672, 672);
//    client.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
//    client.setAlpha(127);
//    add(client);
//
//    //Initialize swipe container origin (absolute coordinates) and size (relative to origin)
////    swipe.initialize(application().originX + 24, application().originY + 24, 500, 250);
//    swipe.initialize(application().originX + 24, application().originY + 24, 500, 250, INDICATOR_BOTTOM_CENTER, BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_SMALL_NORMAL_ID, BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_SMALL_HIGHLIGHT_ID);
//    swipe.setSwipeCutoff(50);
//    swipe.setEndSwipeElasticWidth(50);
//
//    //Pages MUST be added to container before they can be populated with widgets.
//    //They get their size initialized at that point.
//    //Before that, they cannot hold any widgets.
//    swipe.addPage(swipePage1);
//    swipe.addPage(swipePage2);
//
//    box1.setPosition(swipePage1.client.x, swipePage1.client.y, swipePage1.client.width, swipePage1.client.height);
//    box1.setColor(touchgfx::Color::getColorFromRGB(100, 0, 0));
//    box3.setPosition(24, 24, 150, 75);
//    box3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
//    swipePage1.add(box1);
//    swipePage1.addToClient(box3);
//
//    box2.setPosition(swipePage2.client.x, swipePage2.client.y, swipePage2.client.width, swipePage2.client.height);
//    box2.setColor(touchgfx::Color::getColorFromRGB(100, 100, 0));
//    box4.setPosition(24, 24, 75, 150);
//    box4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
//    swipePage2.add(box2);
//    swipePage2.addToClient(box4);
//
//    swipe.setSelectedPage(0);
//    add(swipe);
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}
