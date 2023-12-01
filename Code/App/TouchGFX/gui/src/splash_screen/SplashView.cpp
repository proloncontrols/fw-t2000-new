#include <gui/splash_screen/SplashView.hpp>
#include <CWidgets.hpp>
#include <touchgfx/Color.hpp>

#include <BitmapDatabase.hpp>
#include <Meter/CMeter.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SplashView::SplashView()
           :buttonCallback(this, &SplashView::onButtonClick)
{
	screen.showFrame();
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}

void SplashView::OnTransitionEnd()
{
}

void SplashView::onButtonClick(const touchgfx::AbstractButtonContainer& src)
{

}
