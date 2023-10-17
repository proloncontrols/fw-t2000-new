#include <gui/main_screen/MainView.hpp>

#include "stdio.h"
#include "framework.h"
#include "ui.h"

MainView::MainView()
{
    FEA_PlaceText(txtTemp);
    FEA_PlaceButtonIcon(btnUp);
    FEA_PlaceButtonIcon(btnDn);

//    FEA_PlaceImage(imgProlon);
//    FEA_PlaceImage(imgGFX);

//    FEA_PlaceText(txtContext);
//    FEA_PlaceText(txtVersion);

//    FEA_PlaceButton(btnRotate);
}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}


//void MainView::DisplayVersion(uint16_t Version)
//{
//	char Str[16];

//	sprintf(Str, "%d.%d.%d.%d", ((Version >> 12) & 0xF), ((Version >> 8) & 0xF), ((Version >> 4) & 0xF), (Version & 0xF));
//	Unicode::fromUTF8((uint8_t*)Str, txtVersionBuffer, sizeof(txtVersionBuffer));
//	txtVersion.invalidate();
//}

void MainView::OnButtonRotateClick()
{
	CFG_Data.ScrOrientation ^= 1;
//	FMK_Config.ScreenOrientation ^= 1;
	CFG_Save(&CFG_Data);
    application().gotoResetScreenNoTransition();
}

void MainView::OnBtnUp()
{
//	UI_PostBtn(UiBtnTempUp);
}

void MainView::OnBtnDn()
{
//	UI_PostBtn(UiBtnTempDown);
}

void MainView::DisplayTemp(uint8_t* Temp)
{
//	char Str[UI_TEXT_STRING_LENGTH];

//	Unicode::fromUTF8((uint8_t*)Str, txtTempBuffer, sizeof(txtTempBuffer));
	Unicode::fromUTF8(Temp, txtTempBuffer, sizeof(txtTempBuffer));
	txtTemp.invalidate();
}














































