#include <gui/settings_screen/SettingsView.hpp>

SettingsView::SettingsView()
             :buttonCallback(this, &SettingsView::onButtonClicked)
{

}

void SettingsView::setupScreen()
{
    SettingsViewBase::setupScreen();
}

void SettingsView::tearDownScreen()
{
    SettingsViewBase::tearDownScreen();
}

void SettingsView::onButtonClicked(uint32_t param1, uint32_t param2)
{
	(void)param2;
	application().gotoScreen(ScreenId(param1));
}
