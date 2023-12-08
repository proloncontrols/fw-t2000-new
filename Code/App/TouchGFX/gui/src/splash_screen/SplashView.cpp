#include <gui/splash_screen/SplashView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SplashView::SplashView()
{
//	screen = new CScreen(container, true);
//	screen->showFrame();

//	txt1.setTypedText(T_METER_HUGE);
//	txt1.setColorBack(86, 88, 90);
//	txt1.setXY(100, 100);
//	txt1 = (char*)"2";
//
//	txt1.addTo(container);
//
//	txt2.setTypedText(T_METER_HUGE);
//	txt2.setColorBack(86, 88, 90);
//	txt2.setXY(100 + txt1.getWidth(), 100);
//	txt2 = (char*)"1";
//
//	txt2.addTo(container);
//
//	txt3.setTypedText(T_METER_HUGE);
//	txt3.setColorBack(86, 88, 90);
//	txt3.setXY(100 + txt1.getWidth() + txt2.getWidth(), 100);
//	txt3 = (char*)"1";
//
//	txt3.addTo(container);

	md1 = new CMeterDigit(T_METER_HUGE, 255, 255, 255);
	md1->setXY(100, 100);
	*md1 = "-";
	md1->addTo(container);
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}
