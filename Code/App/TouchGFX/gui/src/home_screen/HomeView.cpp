#include <gui/home_screen/HomeView.hpp>

HomeView::HomeView()
         :buttonCallback(this, &HomeView::onButtonClicked)
{
}

void HomeView::setupScreen()
{
    HomeViewBase::setupScreen();
//    screen.previous = presenter->getPreviousScreen();
}

void HomeView::tearDownScreen()
{
    HomeViewBase::tearDownScreen();
//    presenter->setPreviousScreen(screen.id);
}

void HomeView::onButtonClicked(const AbstractButtonContainer& src)
{
	application().gotoScreen(((CButton*)&src)->getGotoScreenId());
}
