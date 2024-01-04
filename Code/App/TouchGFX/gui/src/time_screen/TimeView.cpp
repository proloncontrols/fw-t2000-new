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

void TimeView::onButtonClicked(uint32_t param1, uint32_t param2)
{
//	ButtonId id = menu.getButtonId(src);
//
//	if(id == ButtonId::ButtonHome)
//		application().gotoScreen(ScreenId::ScreenHome);
//
//	else if(id == ButtonId::ButtonBack)
//		application().gotoScreen(menu.previous);
//
//	else
//	{
//	}
}
