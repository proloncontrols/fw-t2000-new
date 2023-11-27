#include <gui/splash_screen/SplashView.hpp>
//#include <BitmapDatabase.hpp>
#include <CWidgets.hpp>
//#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

#include <meter/CMeter.hpp>
#include <BitmapDatabase.hpp>

SplashView::SplashView()
           :buttonCallback(this, &SplashView::buttonCallbackHandler)
{
//	__background.setColor(touchgfx::Color::getColorFromRGB(10, 70, 25));
	rotateBox(__background);

////	swipe.initialize(cnvScrX(24), cnvScrY(24), 624, 624, INDICATOR_BOTTOM_CENTER, BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_SMALL_NORMAL_ID, BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_SMALL_HIGHLIGHT_ID);
////	swipe.showBackground();
////	swipe.setSwipeCutoff(50);
////	swipe.setEndSwipeElasticWidth(50);
////
////	swipe.addPage(swipePage1);
////	tempInside.setXY(0, 0);
////	swipePage1.add(tempInside);
//
//
//
////	add(text);
////	text.setXY(50, 50);
////	text.setFont(touchgfx::TypedText(T_T2000_METER_SMALL));
////	text.setFontColorBack(75, 75, 75);
////	text.setFontColorFore(186, 188, 190);
////	text.setText((char*)"-31.8°C");
//
////	add(ch);
////	ch.setXY(30, 30);
////	ch.setFont(touchgfx::TypedText(T_T2000_METER_LARGE));
////	ch.setFontColor(186, 188, 190);
////	ch.setChar('3');
//
//
//
////	add(meterText);
////	meterText.initialize(meterString, 4, touchgfx::TypedText(T_T2000_METER_LARGE), 186, 188, 190);
////	meterText.setXY(50, 50);
////	meterText.setColorBack(75, 75, 75);
////	meterText.setCharSpacingRatio(15);
////	meterText.setText((char*)"-33");
////
////	add(meterText2);
////	meterText2.initialize(meterString2, 2, touchgfx::TypedText(T_T2000_METER_SMALL), 186, 188, 190);
////	meterText2.setXY(meterText.getX() + meterText.getWidth(), meterText.getY() + (meterText.getHeight() - meterText2.getHeight()));
////	meterText2.setColorBack(75, 75, 75);
////	meterText2.setCharSpacingRatio(15);
////	meterText2.setText((char*)".8");
////
////	add(meterText3);
////	meterText3.initialize(meterString3, 2, touchgfx::TypedText(T_T2000_METER_SMALL), 186, 188, 190);
////	meterText3.setXY(meterText.getX() + meterText.getWidth(), meterText.getY());
////	meterText3.setColorBack(75, 75, 75);
////	meterText3.setCharSpacingRatio(15);
////	meterText3.setText((char*)"°C");
//
////	add(tL);
////	tL.initialize(touchgfx::TypedText(T_METER_LARGE), 186, 188, 190);
////	tL.setText("33");
////	tL.setXY(0, 0);
////
////	add(tP);
////	tP.initialize(touchgfx::TypedText(T_METER_SMALL_DOT), 186, 188, 190);
////	tP.setText(".");
////	tP.setXY(tL.getWidth(), tL.getHeight() - tP.getHeight());
////
////	add(tS);
////	tS.initialize(touchgfx::TypedText(T_METER_SMALL), 186, 188, 190);
////	tS.setText("012345");
////	tS.setXY(tL.getWidth() + tP.getWidth(), tL.getHeight() - tS.getHeight());
//
//
//
//
////	s1 = new CString(a1, ARRAY1_SIZE, touchgfx::TypedText(T_METER_HUGE_DIGITS), 186, 188, 190);
//////	s1.initialize(a1, ARRAY1_SIZE, touchgfx::TypedText(T_METER_SMALL), 186, 188, 190);
////	s1->setColorBack(75, 75, 75);
//////	s1->setCharSpacingRatio(5);
////	s1->setText("0123456789");
////	s1->setXY(50, 50);
////	add(*s1);
//
////	add(mi);
////	mi.setXY(50, 50);
////	mi.setBackgroundColor(75, 75, 75);
////	mi.display(-30.1, false);
//
////	add(se);
////	se.setXY(50, 300);
////	se.setBackgroundColor(75, 75, 75);
////	se.display(-20.8, false);
//
//
//
//
//
////	mv = new CMeterValue(4, 15, touchgfx::TypedText(T_METER_HUGE_DIGITS), 186, 188, 190);
////	mv->setXY(50, 50);
//////	mv->setBackgroundColor(75, 75, 75);
////	mv->display(100);
////	add(*mv);
//
//	m1.setXY(50, 50);
////	m1.setBackgroundColor(75, 75, 75);
//	m1.display(-33.8, false);
//	add(m1);
//
//	m2.setXY(50, 300);
////	m2.setBackgroundColor(75, 75, 75);
//	m2.display(-24.6, true);
//	add(m2);
//
//	m3.setXY(50, 480);
////	m3.setBackgroundColor(75, 75, 75);
//	m3.display(-6, true);
//	add(m3);
//
//	m4.setXY(50, 580);
////	m4.setBackgroundColor(75, 75, 75);
//	m4.display(72);
//	add(m4);
//
//
//
//
////	b1.setXY(400, 400);
//	b1.setPosition(400, 400, 200, 200);
////	b1.setBitmaps(BITMAP_SETTING_ID, BITMAP_SETTING_DARK2_ID);
//    b1.setAction(buttonCallback);
//	add(b1);
//
//
//
//
////	meter.setXY(0, 0);
////	meter.initialize(186, 188, 190, touchgfx::TypedText(T_T2000_METER_MEDIUM), touchgfx::TypedText(T_T2000_METER_SMALL), false);
////	meter.setUnit(METER_UNIT_FAHRENHEIT);
////	meter.display(-31.8);
////	add(meter);
////
////	meter2.setXY(0, 300);
////	meter2.initialize(186, 188, 190, touchgfx::TypedText(T_T2000_METER_LARGE), touchgfx::TypedText(T_T2000_METER_SMALL), false);
////	meter2.setUnit(METER_UNIT_CELSIUS);
////	meter2.display(-31.8);
////	add(meter2);
//
////	MeterTempExt.setXY(0, 0);
////	MeterTempExt.display(-33, true);
////	add(MeterTempExt);
////	MeterTempExt.setXY(0, 0);
////	MeterTempExt.display(-33.8, true);
////	add(MeterTempExt);
//
//
//
////	img1.setBitmap(touchgfx::Bitmap(BITMAP_COOLINGON_560X560_ID));
////	img1.setXY(swipePage1.getWidth()/2 - img1.getWidth()/2, 0);
////	swipePage1.add(img1);
//
////	swipe.addPage(swipePage2);
////	img2.setBitmap(touchgfx::Bitmap(BITMAP_ECOON_560X560_ID));
////	img2.setXY(swipePage2.getWidth()/2 - img2.getWidth()/2, 0);
////	swipePage2.add(img2);
////
////	swipe.addPage(swipePage3);
////	img3.setBitmap(touchgfx::Bitmap(BITMAP_HEATINGON_560X560_ID));
////	img3.setXY(swipePage3.getWidth()/2 - img3.getWidth()/2, 0);
////	swipePage3.add(img3);
////
////	swipe.setSelectedPage(0);
////	add(swipe);
//
//
//
//
//
//
////	img.setXY(cnvScrX(56), cnvScrY(56));
////	img.setBitmap(touchgfx::Bitmap(BITMAP_COOLINGON_560X560_ID));
////	add(img);
//
//
//
//
//
////    //This is used to view the actual client area only (can be removed)
////    client.setPosition(application().originX, application().originY, 672, 672);
////    client.setColor(touchgfx::Color::getColorFromRGB(75, 75, 75));
////    client.setAlpha(127);
////    add(client);
////
////    //Initialize swipe container origin (absolute coordinates) and size (relative to origin)
//////    swipe.initialize(application().originX + 24, application().originY + 24, 500, 250);
////    swipe.initialize(application().originX + 24, application().originY + 24, 500, 250, INDICATOR_BOTTOM_CENTER, BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_SMALL_NORMAL_ID, BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_SMALL_HIGHLIGHT_ID);
////    swipe.setSwipeCutoff(50);
////    swipe.setEndSwipeElasticWidth(50);
////
////    //Pages MUST be added to container before they can be populated with widgets.
////    //They get their size initialized at that point.
////    //Before that, they cannot hold any widgets.
////    swipe.addPage(swipePage1);
////    swipe.addPage(swipePage2);
////
////    box1.setPosition(swipePage1.client.x, swipePage1.client.y, swipePage1.client.width, swipePage1.client.height);
////    box1.setColor(touchgfx::Color::getColorFromRGB(100, 0, 0));
////    box3.setPosition(24, 24, 150, 75);
////    box3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
////    swipePage1.add(box1);
////    swipePage1.addToClient(box3);
////
////    box2.setPosition(swipePage2.client.x, swipePage2.client.y, swipePage2.client.width, swipePage2.client.height);
////    box2.setColor(touchgfx::Color::getColorFromRGB(100, 100, 0));
////    box4.setPosition(24, 24, 75, 150);
////    box4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
////    swipePage2.add(box2);
////    swipePage2.addToClient(box4);
////
////    swipe.setSelectedPage(0);
////    add(swipe);

//	b1.setXY(25, 25);
//	b1.setBitmaps(BITMAP_MENU_BUTTON_ID, BITMAP_MENU_BUTTON_ID);
//	b1.setHeight(72);
//	b1.setAction(buttonCallback);
//	add(b1);
//	rotateDrawable(b1);

//	b2.setXY(25, 150);
//	b2.setBitmaps(BITMAP_MENU_BUTTON_ID, BITMAP_MENU_BUTTON_ID);
//	b2.setHeight(72);
//	b2.setAction(buttonCallback);
//	add(b2);
//	rotateDrawable(b2);

	b1.initialize(25, 25, 400, 400);
	b1.setAction(buttonCallback);
	add(b1);
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}

//int tmp = 0;
void SplashView::buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
//	if(&src == &b1)
//	{
//		tmp = 1;
//	}

//	if(&src == &b2)
//	{
//		tmp = 2;
//	}
}

void SplashView::OnTransitionEnd()
{
//	EVT_Event_t Evt;
//
//	Evt.Group = EVT_GROUP_GFX;
//	Evt.Event = EVT_GFX_READY;
//	EVT_PostToApp(&Evt);


//	EVT_PostToApp(EVT_GROUP_GFX, EVT_GFX_READY, EVT_DATA_TYPE_NONE, NULL);
}





























