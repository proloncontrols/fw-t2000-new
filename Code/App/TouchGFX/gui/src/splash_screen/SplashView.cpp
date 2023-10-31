#include <gui/splash_screen/SplashView.hpp>

#include "cfg.h"
#include "image.hpp"

SplashView::SplashView()
{
	ClientLineTop.setVisible(false);
	ClientLineLeft.setVisible(false);
	ClientLineRight.setVisible(false);
	ClientLineBottom.setVisible(false);

	Widgets = new CWidgets(splashCount);

	Widgets->set(splashImgProlon, new CImage(imgProlon));
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
    Widgets->update();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}

void SplashView::OnScreenTransitionEnd()
{
	presenter->PostSystemReady();
}
