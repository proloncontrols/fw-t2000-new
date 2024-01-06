#include <gui/unit_screen/UnitView.hpp>

UnitView::UnitView()
         :buttonCallback(this, &UnitView::onButtonClicked)
{

}

void UnitView::setupScreen()
{
    UnitViewBase::setupScreen();

    programmedSelection = 0;   //This is the value retrieved from E2 (model)
    menu.setSelection(programmedSelection);
}

void UnitView::tearDownScreen()
{
    UnitViewBase::tearDownScreen();

	int currentSelection = menu.getSelection();
	if(currentSelection != programmedSelection)
	{
		//New language selected. System restart required.
		//Ask user to restart or not.
		//If yes, save new selection to E2 (model) then restart
	}
}

void UnitView::onButtonClicked(uint32_t param1, uint32_t param2)
{
	(void)param2;
	application().gotoScreen(ScreenId(param1));
}
