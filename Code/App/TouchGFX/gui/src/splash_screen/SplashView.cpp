#include <gui/splash_screen/SplashView.hpp>
//#include <texts/TextKeysAndLanguages.hpp>
//#include <CDisplay.hpp>
//#include <BitmapDatabase.hpp>
//#include <touchgfx/Color.hpp>

//static bool celsius = true;
//static float temp = -21;
//static float tempIn = -10.3;
//static int16_t tempSt = -1000;
//static uint8_t humidity = 0;

SplashView::SplashView()
//           :buttonCallback(this, &SplashView::buttonCallbackHandler)
{
//	if(dsp.orientation == CDisplay::PORTRAIT)
//		__background.setPosition(0, 0, 672, 720);

//	screen.client.add(tempInt);
//	tempInt.update(0, celsius);
//	tempInt.setXY((screen.client.getWidth() - tempInt.getWidth()) / 2, 50);
//	tempInt.render();

////	add(tempSet);
////	tempSet.update(tempSt, celsius);
////	tempSet.setXY((container.getWidth() - tempSet.getWidth()) / 2, 320);
////	tempSet.invalidate();
//
////	add(tempExt);
////	tempExt.update((int16_t)temp, celsius);
////	tempExt.setXY(100, 500);
////	tempExt.invalidate();
//
//	add(hum);
//	hum.update(0);
//	hum.setXY(500, 500);
//	hum.render();
//
//	add(btn);
//	btn.initialize(50, 300, 76, BITMAP_MENU_BUTTON_496X496X76_ID, BITMAP_MENU_BUTTON_496X496X76_ID, T_MENU_BUTTON, Color::getColorFromRGB(255, 255, 255), Color::getColorFromRGB(200, 20, 20));
//	btn.setText("About me");
//	btn.setTextPosition(30, 4);
//	btn.setAction(buttonCallback);
//	btn.render();

//	screen.client.add(item);
//	item.setXY((screen.client.getWidth() - item.getWidth()) / 2, 300);
//	item.setText((char*)"About me");
//	item.setAction(buttonCallback);
//	item.render();

//    add(img);
//    img.setImage(BITMAP_MENU_LINE_GRAY_494X494X3_ID);
//	img.setXY(50, 25);
//	img.render();

//	img.addTo(container);
//	img.setImage(BITMAP_MENU_BUTTON_496X496X76_ID);
//	img.setXY(10, 10);







//	img.setImage(BITMAP_MENU_BUTTON_496X496X76_ID);
//	dsp.setXY(img, 10, 10);
//	dsp.addTo(img, container);
//
//	dsp.setPosition(container2, dsp.getX(img)+img.getWidth()+20, 20, 150, 400);
//	dsp.addTo(container2, container);
//
//	box.setColor(Color::getColorFromRGB(CDisplay::devBackgroundColorR, CDisplay::devBackgroundColorG, CDisplay::devBackgroundColorB));
//	dsp.setPosition(box, 0, 0, container2.getWidth(), container2.getHeight());
//	dsp.addTo(box, container2);
//
//	box2.setColor(Color::getColorFromRGB(0, 0, 0));
//	dsp.setPosition(box2, 20, 20, 50, 300);
//	dsp.addTo(box2, container2);
//
//	Texts::setLanguage(1);
//	str.initialize(T_MENU_TITLE_SETTINGS, 255, 255, 255);
//	dsp.setXY(str, 1, 1);
//	dsp.addTo(str, container);

//	Texts::setLanguage(1);
//	add(btn);
//	btn.setXY(20, 20);
//	btn.setBitmaps(BITMAP_MENU_BUTTON_496X496X76_ID, BITMAP_MENU_BUTTON_496X496X76_ID);
//	btn.setTouchHeight(76);
//	btn.setText(T_MENU_BUTTON_SETTINGS);
//	btn.setTextColors(Color::getColorFromRGB(255, 255, 255), Color::getColorFromRGB(200, 20, 20));
//	btn.setTextPosition(30, 4);
//	btn.setAction(buttonCallback);
//	btn.transpose();


//	add(lbl);
//	lbl.setXY(50, 50);
//	lbl.setTypedText(T_MENU_BUTTON_SETTINGS);
//	lbl.setColor(Color::getColorFromRGB(255, 255, 255));
//	lbl.invalidate();

//	add(item);
//	item.setXY(50, 50);
//	item.setButtonText(T_MENU_BUTTON_SETTINGS);
//	item.setButtonAction(buttonCallback);
//	item.transpose();

}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}

void SplashView::updateEnvironment(ENV_Readings_t* Env)
{
//	tempInt.update((float)(Env->TempC)/100.0, celsius);
//	tempInt.setXY((screen.client.getWidth() - tempInt.getWidth()) / 2, 50);
//	tempInt.render();
//
////	hum.update(Env->HumP/100);
////	hum.setXY(500, 500);
////	hum.render();
//
//	invalidate();
}

void SplashView::moveIt()
{
//	temp += 1;
//	tempIn += 0.1;
//	tempSt += 50;
//	humidity += 1;
//
//	tempInt.update(tempIn, celsius);
//	tempInt.setXY((screen.client.getWidth() - tempInt.getWidth()) / 2, 50);
//	tempInt.invalidate();
//
//	tempSet.update(tempSt, celsius);
//	tempSet.setXY((container.getWidth() - tempSet.getWidth()) / 2, 320);
//	tempSet.invalidate();
//
//	celsius = !celsius;
//	tempExt.update((int16_t)temp, celsius);
//	tempExt.setXY(100, 500);
//	tempExt.invalidate();
//
//	hum.update(humidity);
//	hum.setXY(500, 500);
//	hum.invalidate();
//
//	invalidate();
}

//int tmp = 0;
//void SplashView::buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
//{
//	CMenu::ButtonId id = menu.getButtonId(src);
//
//	if(id)
//	{
//		tmp++;
//	}
//}








































