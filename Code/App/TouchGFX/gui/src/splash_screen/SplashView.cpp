#include <gui/splash_screen/SplashView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <CDisplay.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Color.hpp>

static bool celsius = true;
//static float temp = -21;
//static float tempIn = -10.3;
//static int16_t tempSt = -1000;
//static uint8_t humidity = 0;

SplashView::SplashView()
           :buttonCallback(this, &SplashView::buttonCallbackHandler)
{
	if(dsp.orientation == CDisplay::PORTRAIT)
		__background.setPosition(0, 0, 672, 720);

	add(tempInt);
	tempInt.update(0, celsius);
	tempInt.setXY((container.getWidth() - tempInt.getWidth()) / 2, 50);
	tempInt.render();

//	add(tempSet);
//	tempSet.update(tempSt, celsius);
//	tempSet.setXY((container.getWidth() - tempSet.getWidth()) / 2, 320);
//	tempSet.invalidate();

//	add(tempExt);
//	tempExt.update((int16_t)temp, celsius);
//	tempExt.setXY(100, 500);
//	tempExt.invalidate();

	add(hum);
	hum.update(0);
	hum.setXY(500, 500);
	hum.render();

	add(btn);
	btn.initialize(50, 300, 0, BITMAP_SETTING_ID, BITMAP_SETTING_DARK2_ID, T_GAUGE_TEMPERATURE_EXTERIOR_LARGE, Color::getColorFromRGB(255, 255, 255), Color::getColorFromRGB(200, 20, 20));
	btn.setText("2");
	btn.setTextPosition(1, 1);
	btn.setAction(buttonCallback);
	btn.render();
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
	tempInt.update((float)(Env->TempC)/100.0, celsius);
	tempInt.setXY((container.getWidth() - tempInt.getWidth()) / 2, 50);
	tempInt.render();

	hum.update(Env->HumP/100);
	hum.setXY(500, 500);
	hum.render();

	invalidate();
}

void SplashView::moveIt()
{
//	temp += 1;
//	tempIn += 0.1;
//	tempSt += 50;
//	humidity += 1;
//
//	tempInt.update(tempIn, celsius);
//	tempInt.setXY((container.getWidth() - tempInt.getWidth()) / 2, 50);
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

void SplashView::buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{

}
