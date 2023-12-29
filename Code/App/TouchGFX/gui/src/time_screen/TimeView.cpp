#include <gui/time_screen/TimeView.hpp>

TimeView::TimeView()
         :buttonCallback(this, &TimeView::onButtonClicked)
{

}

void TimeView::setupScreen()
{
    TimeViewBase::setupScreen();
}

void TimeView::tearDownScreen()
{
    TimeViewBase::tearDownScreen();
}

void TimeView::onButtonClicked(const touchgfx::AbstractButtonContainer& src)
{
	ButtonId id = menu.getButtonId(src);

	if(id == ButtonId::ButtonHome)
		application().gotoScreen(ScreenId::ScreenHome);

	else if(id == ButtonId::ButtonBack)
		application().gotoScreen(menu.previous);

	else
	{
	}
}
