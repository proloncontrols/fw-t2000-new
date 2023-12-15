#include <gui/splash_screen/SplashView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <CDisplay.hpp>

//static int16_t tmp = 50;

SplashView::SplashView()
{
	if(dsp.orientation == CDisplay::PORTRAIT)
		__background.setPosition(0, 0, 672, 720);

//	add(txt1);
//	txt1 = "-21";
//	dsp.setXY(txt1, tmp, 50);
//
//	add(txt2);
//	txt2 = ".5";
//	Rect r = dsp.getPosition(txt1);
//	dsp.setXY(txt2, r.x + r.width, r.y + (r.height - txt2.getHeight()) + txt2.getBaseline());

//	add(str);
//    str = "TestStringWithAnAppliedEdgé2";
//	dsp.setXY(str, 1, 500);

//	add(temp);
//	dsp.setXY(temp, 50, 50);
//	temp.init();
	dsp.setXY(temp, 50, 50);
	temp.update(-21, true);
//	dsp.setXY(temp, tmp, 100);
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
//	invalidate();
//
//	tmp += 50;
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
