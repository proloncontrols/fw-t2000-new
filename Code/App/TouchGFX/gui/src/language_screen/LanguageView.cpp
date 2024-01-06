#include <gui/language_screen/LanguageView.hpp>

LanguageView::LanguageView()
             :buttonCallback(this, &LanguageView::onButtonClicked)
{

}

void LanguageView::setupScreen()
{
    LanguageViewBase::setupScreen();

    programmedSelection = 0;   //This is the value retrieved from E2 (model)
    menu.setSelection(programmedSelection);
}

void LanguageView::tearDownScreen()
{
	LanguageViewBase::tearDownScreen();

	int currentSelection = menu.getSelection();
	if(currentSelection != programmedSelection)
	{
		//New language selected. System restart required.
		//Ask user to restart or not.
		//If yes, save new selection to E2 (model) then restart
	}
}

void LanguageView::onButtonClicked(uint32_t param1, uint32_t param2)
{
	(void)param2;
	application().gotoScreen(ScreenId(param1));
}
