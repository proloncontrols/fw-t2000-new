#include <gui/splash_screen/SplashView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <CDisplay.hpp>

static bool celsius = true;
static float temp = 0;
static uint8_t humidity = 0;

SplashView::SplashView()
{
	if(dsp.orientation == CDisplay::PORTRAIT)
		__background.setPosition(0, 0, 672, 720);

//	add(tempInt);
//	tempInt.update(temp, celsius);
//	tempInt.setXY((container.getWidth() - tempInt.getWidth()) / 2, 50);
//	tempInt.invalidate();
//
//	add(tempSet);
//	tempSet.update(temp, celsius);
//	tempSet.setXY((container.getWidth() - tempSet.getWidth()) / 2, 320);
//	tempSet.invalidate();

	add(tempExt);
	tempExt.update(temp, celsius);
	tempExt.setXY((container.getWidth() - tempExt.getWidth()) / 2, 350);
	tempExt.invalidate();

	add(hum);
	hum.update(humidity);
	hum.setXY((container.getWidth() - hum.getWidth()) / 2, 500);
	hum.invalidate();

//	add(dig1);
//	dig1.setXY(50, 50);
//	dig1.setDigit('2');
//	dig1.invalidate();

//	add(txt1);
//	txt1.setXY(1, 1);
//	txt1 = "-21";
//	txt1.invalidate();
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}

void SplashView::moveIt()
{
	temp += 1;
	humidity += 1;

//	tempInt.update(temp, celsius);
//	tempInt.setXY((container.getWidth() - tempInt.getWidth()) / 2, 50);
//	tempInt.invalidate();
//
//	tempSet.update(temp, celsius);
//	tempSet.setXY((container.getWidth() - tempSet.getWidth()) / 2, 320);
//	tempSet.invalidate();

	tempExt.update(temp, celsius);
	tempExt.setXY((container.getWidth() - tempExt.getWidth()) / 2, 350);
	tempExt.invalidate();

	hum.update(humidity);
	hum.setXY((container.getWidth() - hum.getWidth()) / 2, 500);
	hum.invalidate();

	invalidate();

//
////	dsp.setXY(txt1, tmp, 50);
////	txt1.invalidate();
////
////	Rect r = dsp.getPosition(txt1);
////	dsp.setXY(txt2, r.x + r.width, r.y + (r.height - txt2.getHeight()) + txt2.getBaseline());
////	txt2.invalidate();
//
//	dsp.setXY(temp, tmp, 100);
}
