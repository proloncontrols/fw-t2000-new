#include <gui/splash_screen/SplashView.hpp>

#include "cfg.h"
#include "image.hpp"

SplashView::SplashView()
{
    List[0] = new CImage(imgProlon);
}

void SplashView::setupScreen()
{
    SplashViewBase::setupScreen();
    updateScreen();
}

void SplashView::tearDownScreen()
{
    SplashViewBase::tearDownScreen();
}

void SplashView::OnScreenTransitionEnd()
{
	presenter->PostSystemReady();
}

//-----------------------------------------------------------------------------
void SplashView::updateScreen()
{
    for(int i = 0; i < SPLASH_WIDGET_COUNT; i++)
    {
    	List[i]->placeOnScreen();
    }
}
