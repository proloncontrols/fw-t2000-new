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
		application().gotoScreen(FrontendApplication::ScreenId::Options);

	else if(id == CMenu::buttonUser+1)
		application().gotoScreen(FrontendApplication::ScreenId::AboutMe);

	else if(id == CMenu::buttonUser+2)
		application().gotoScreen(FrontendApplication::ScreenId::Visualize);

	else if(id == CMenu::buttonUser+3)
		application().gotoScreen(FrontendApplication::ScreenId::Device);
}
