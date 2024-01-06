#include <gui/options_screen/OptionsView.hpp>

OptionsView::OptionsView()
            :buttonCallback(this, &OptionsView::onButtonClicked)
{

}

void OptionsView::setupScreen()
{
    OptionsViewBase::setupScreen();
}

void OptionsView::tearDownScreen()
{
    OptionsViewBase::tearDownScreen();
}

void OptionsView::onButtonClicked(uint32_t param1, uint32_t param2)
{
	(void)param2;
	application().gotoScreen(ScreenId(param1));
}
