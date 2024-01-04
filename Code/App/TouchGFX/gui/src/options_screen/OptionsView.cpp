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
//	     if(id == ButtonId::ButtonUser)   application().gotoScreen(ScreenId::ScreenLanguage);
//	else if(id == ButtonId::ButtonUser+1) application().gotoScreen(ScreenId::ScreenUnit);
//	else if(id == ButtonId::ButtonUser+2) application().gotoScreen(ScreenId::ScreenTime);
//	else if(id == ButtonId::ButtonUser+3) application().gotoScreen(ScreenId::ScreenOrientation);
//	}
	(void)param2;
	application().gotoScreen(ScreenId(param1));
}
