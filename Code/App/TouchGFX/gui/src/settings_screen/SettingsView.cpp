#include <gui/settings_screen/SettingsView.hpp>

SettingsView::SettingsView()
             :buttonCallback(this, &SettingsView::buttonCallbackHandler)
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

void SettingsView::buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
	CMenu::ButtonId id = menu.getButtonId(src);

	if(id == CMenu::buttonUser)
		application().gotoOptionsScreenNoTransition();

	else if(id == CMenu::buttonUser+1)
		application().gotoAboutMeScreenNoTransition();

	else if(id == CMenu::buttonUser+2)
		application().gotoVisualizeScreenNoTransition();

	else if(id == CMenu::buttonUser+3)
		application().gotoDeviceScreenNoTransition();
}
