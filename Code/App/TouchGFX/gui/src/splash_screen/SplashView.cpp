#include <gui/splash_screen/SplashView.hpp>

#include "ui_virtual.hpp"
#include "cfg.h"

SplashView::SplashView()
{
	imgProlonEx->placeOnScreen();
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}

void SplashView::OnScreenTransitionEnd()
{
	presenter->PostSystemReady();
}
