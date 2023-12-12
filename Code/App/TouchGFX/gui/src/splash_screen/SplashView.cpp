#include <gui/splash_screen/SplashView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SplashView::SplashView()
{
	if(dsp.orientation == CDisplay::PORTRAIT)
		__background.setPosition(0, 0, 672, 720);

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





//	dig0.setDigit('2');
//	dig0.setXY(1, 1);
//	dig0.addTo(container);

//	dig1.setDigit('1');
//	dig1.setXY(dig0.getWidth(), 1);
//	dig1.addTo(container);

//	dig2.setDigit('2');
//	dig2.setXY(dig1.getX()+dig1.getWidth(), 100);
//	dig2.addTo(container);
//
//	dig3.setDigit('3');
//	dig3.setXY(dig2.getX()+dig2.getWidth(), 100);
//	dig3.addTo(container);
//
//	dig4.setDigit('4');
//	dig4.setXY(dig3.getX()+dig3.getWidth(), 100);
//	dig4.addTo(container);
//
//	dig5.setDigit('5');
//	dig5.setXY(dig4.getX()+dig4.getWidth(), 100);
//	dig5.addTo(container);
//
//	dig6.setDigit('6');
//	dig6.setXY(dig5.getX()+dig5.getWidth(), 100);
//	dig6.addTo(container);

//	dig2.setDigit('5');
//	dig2.setXY(dig1.getX() + dig1.getWidth(), dig1.getY());
//	dig2.addTo(container);

//	dig3.setXY(100, 350);
//	dig3.setDigit('5');
//	dig3.setXY(dig2.getX() + dig2.getWidth(), dig2.getY() + (dig2.getHeight() - dig3.getHeight()));
//	dig3.addTo(container);

	val = new CValue(4, 15, T_GAUGE_HUGE, 255, 255, 255);
	val->update(-20);
	val->setXY(1, 1);
	val->addTo(container);

//	temp.update(20.5, true);
//	temp.setXY(100, 100);
//	temp.addTo(container);

//    txt1 = "TestStringWithAnAppliedEdge2";
//	txt1.setXY(0, 500);
//    txt1.addTo(container);

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
