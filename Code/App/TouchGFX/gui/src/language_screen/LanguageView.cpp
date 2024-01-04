#include <gui/language_screen/LanguageView.hpp>

LanguageView::LanguageView()
             :buttonCallback(this, &LanguageView::onButtonClicked)
{

}

void LanguageView::setupScreen()
{
    LanguageViewBase::setupScreen();
}

void LanguageView::tearDownScreen()
{
	LanguageViewBase::tearDownScreen();
}

void LanguageView::onButtonClicked(uint32_t param1, uint32_t param2)
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
////		if(id == ButtonId::ButtonUser)
////			dsp.language = 0;
////		else
////			dsp.language = 1;
////		Texts::setLanguage(dsp.language);
////		invalidate();
//////		application().gotoScreen(menu.previous);
//	}
}
