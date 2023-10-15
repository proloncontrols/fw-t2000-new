#include <gui/main_screen/MainView.hpp>

#include "stdio.h"

MainView::MainView()
{

}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();
    prgTransfer.setVisible(false);
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::OnScreenTransitionEnd()
{
	presenter->PostSystemReady();
}

void MainView::DisplayVersion(uint16_t Version)
{
	char Str[16];

	sprintf(Str, "%d.%d.%d.%d", ((Version >> 12) & 0xF), ((Version >> 8) & 0xF), ((Version >> 4) & 0xF), (Version & 0xF));
	Unicode::fromUTF8((uint8_t*)Str, txtVersionBuffer, sizeof(txtVersionBuffer));
	txtVersion.invalidate();
}

void MainView::ProgressInitialize(uint32_t Steps)
{
	prgTransfer.setRange(0, Steps, Steps, 0);
	prgTransfer.setValue(0);
    prgTransfer.setVisible(true);
	prgTransfer.invalidate();
}

void MainView::ProgressIncrement()
{
	int Min, Max, Value;

	prgTransfer.getRange(Min, Max);
	Value = prgTransfer.getValue();
	if(Value < Max)
	{
		prgTransfer.setValue(Value + 1);
		prgTransfer.invalidate();
	}
}
