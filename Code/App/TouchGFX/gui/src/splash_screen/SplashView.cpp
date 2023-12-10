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

//	md1 = new CGaugeDigit(T_METER_HUGE, 255, 255, 255);
//	md1->setXY(100, 100);
//	md1->setDigit('1');
//	md1->addTo(container);

//	gv1 = new CGaugeValue(4, 15, T_METER_HUGE, 255, 255, 255);
//	gv1->setXY(100, 100);
//	gv1->update(-21);
//	gv1->addTo(container);





//	dig.setXY(100, 100);
//	dig.setDigit('1');
//	dig.addTo(container);

//	val = new CValue(4, 15, T_METER_HUGE, 255, 255, 255);
//	val->setXY(100, 100);
//	val->update(-21);
//	val->addTo(container);

	temp.setXY(100, 100);
	temp.update(-21.5, true);
	temp.addTo(container);

	txt1.setXY(0, 500);
    txt1 = "TestStringWithAnAppliedEdge2";
    txt1.addTo(container);

//    txt2 = "°C";
////	txt2.setXYToTopLine(val->getX() + val->getWidth(), val->getY() + val->getTopLine());
////	txt2.setXY(val->getX() + val->getWidth(), val->getY() + val->getTopLine());
//    txt2.setXY(val->getX() + val->getWidth(), val->getY() + txt2.getTypedText().getFont()->getFontHeight() - txt2.getTextMaxHeight());
//    txt2.addTo(container);
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}
