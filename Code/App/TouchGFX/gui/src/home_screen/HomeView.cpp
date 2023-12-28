#include <gui/home_screen/HomeView.hpp>

HomeView::HomeView()
         :buttonCallback(this, &HomeView::onButtonClicked)
{
}

void HomeView::setupScreen()
{
    HomeViewBase::setupScreen();
}

void HomeView::tearDownScreen()
{
    HomeViewBase::tearDownScreen();
}

void HomeView::onButtonClicked(const AbstractButtonContainer& src)
{
	application().gotoScreen(((CButton*)&src)->getGotoScreenId());
}
