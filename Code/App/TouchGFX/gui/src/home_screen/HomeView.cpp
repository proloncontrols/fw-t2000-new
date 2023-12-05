#include <gui/home_screen/HomeView.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <Screen/CScreen.hpp>

HomeView::HomeView()
         :buttonCallback(this, &HomeView::onButtonClick)
{
//	screen.setButtonClick(buttonCallback);
//	screen.initialize(container, buttonCallback);
//	screen.showFrame();
	screen = new CScreenHome(container, buttonCallback);
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
}
