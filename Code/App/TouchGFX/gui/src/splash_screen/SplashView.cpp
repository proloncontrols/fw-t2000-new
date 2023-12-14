#include <gui/splash_screen/SplashView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <CDisplay.hpp>

SplashView::SplashView()
{
	if(dsp.orientation == CDisplay::PORTRAIT)
		__background.setPosition(0, 0, 672, 720);

	add(txt1);
	txt1 = "-21";
	dsp.setXY(txt1, 50, 50);

	add(txt2);
	txt2 = ".5";
	Rect r = dsp.getPosition(txt1);
	dsp.setXY(txt2, r.x + r.width, r.y + (r.height - txt2.getHeight()) + txt2.getBaseline());

	add(str);
    str = "TestStringWithAnAppliedEdgé2";
	dsp.setXY(str, 1, 500);
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}
