#include <gui/splash_screen/SplashView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <CDisplay.hpp>

static bool celsius = true;
static float temp = -10.0;

SplashView::SplashView()
{
	if(dsp.orientation == CDisplay::PORTRAIT)
		__background.setPosition(0, 0, 672, 720);

	add(tempInt);
	tempInt.update(temp, celsius);
	tempInt.setX((container.getWidth() - tempInt.getWidth()) / 2);
	tempInt.setY(100);
	tempInt.invalidate();

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
	temp += 0.1;
	tempInt.update(temp, celsius);
	tempInt.setXY((container.getWidth() - tempInt.getWidth()) / 2, 100);
	tempInt.invalidate();

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
