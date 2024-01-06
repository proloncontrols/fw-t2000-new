#include <gui/language_screen/LanguageView.hpp>

LanguageView::LanguageView()
             :buttonCallback(this, &LanguageView::onButtonClicked)
{

}

void LanguageView::setupScreen()
{
    LanguageViewBase::setupScreen();
    menu.setSelection(0);
}

void LanguageView::tearDownScreen()
{
	LanguageViewBase::tearDownScreen();
	menu.getSelection();
}

void LanguageView::onButtonClicked(uint32_t param1, uint32_t param2)
{
	(void)param2;
	application().gotoScreen(ScreenId(param1));
}
