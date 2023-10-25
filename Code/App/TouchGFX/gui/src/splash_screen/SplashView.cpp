#include <gui/splash_screen/SplashView.hpp>

SplashView::SplashView()
{
    FEA_PlaceTexture(imgProlon);
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
