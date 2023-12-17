#include <gui/home_screen/HomeView.hpp>

HomeView::HomeView()
         :buttonCallback(this, &HomeView::onButtonClick)
{
//	screen = new CScreenHome(container, buttonCallback);
//	screen->showFrame();
}

void HomeView::setupScreen()
{
    HomeViewBase::setupScreen();
}

void HomeView::tearDownScreen()
{
    HomeViewBase::tearDownScreen();
}

void HomeView::onButtonClick(const touchgfx::AbstractButtonContainer& src)
{
//	uint32_t button = ((CButton&)src).getData();
//
//	if(button == CScreenHome::BUTTON_SETPOINTS)
//	{
//	}
//
//	if(button == CScreenHome::BUTTON_SETTINGS)
//	{
//	}
}
