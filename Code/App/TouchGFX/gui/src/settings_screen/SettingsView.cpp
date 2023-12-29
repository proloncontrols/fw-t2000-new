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

void SettingsView::onButtonClicked(const touchgfx::AbstractButtonContainer& src)
{
	ButtonId id = menu.getButtonId(src);

	if(id == ButtonId::ButtonHome)
		application().gotoScreen(ScreenId::ScreenHome);

	else
	{
		     if(id == ButtonId::ButtonUser)   application().gotoScreen(ScreenId::ScreenOptions);
		else if(id == ButtonId::ButtonUser+1) application().gotoScreen(ScreenId::ScreenAboutme);
		else if(id == ButtonId::ButtonUser+2) application().gotoScreen(ScreenId::ScreenVisualize);
		else if(id == ButtonId::ButtonUser+3) application().gotoScreen(ScreenId::ScreenDevice);
	}
}
