#include <gui/splash_screen/SplashView.hpp>

#include "cfg.h"
#include "image.hpp"

SplashView::SplashView()
{
	Widgets = new CWidgets(splashCount);


	CWidget* Tmp = Widgets->get(splashImgProlon);


//	Widgets[splashImgProlon] = new CImage(imgProlon);
//	CWidget* Tmp = Widgets[splashImgProlon];
//	CWidget* Tmp = Widgets->operator[](splashImgProlon);



//	Widgets[splashImgProlon] = 0; //new CImage(imgProlon);
	Widgets->set(splashImgProlon, new CImage(imgProlon));
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
    Widgets->updateScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}

void SplashView::OnScreenTransitionEnd()
{
	presenter->PostSystemReady();
}
