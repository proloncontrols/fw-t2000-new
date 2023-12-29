#include <gui/splash_screen/SplashView.hpp>

SplashView::SplashView()
{
	splashTimer = CScreenSplash::SplashTime;
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}

void SplashView::handleTickEvent()
{
	SplashViewBase::handleTickEvent();

	if(splashTimer > 0)
	{
		if(--splashTimer == 0)
			application().gotoScreen(ScreenId::ScreenHome);
	}
}
