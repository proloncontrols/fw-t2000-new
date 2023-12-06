#include <gui/splash_screen/SplashView.hpp>

SplashView::SplashView()
{
	screen = new CScreen(container, true);
	screen->showFrame();
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}
