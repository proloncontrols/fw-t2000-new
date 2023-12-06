#include <gui/splash_screen/SplashView.hpp>

SplashView::SplashView()
           :buttonCallback(this, &SplashView::onButtonClick)
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

void SplashView::onButtonClick(const touchgfx::AbstractButtonContainer& src)
{
}
