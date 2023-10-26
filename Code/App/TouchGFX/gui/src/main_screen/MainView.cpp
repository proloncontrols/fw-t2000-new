#include <gui/main_screen/MainView.hpp>

#include "math.h"
#include "stdio.h"
#include "framework.h"
#include "ui.h"

MainView::MainView()
{
	ClientLineLeft.setVisible(false);
	ClientLineTop.setVisible(false);
	ClientLineRight.setVisible(false);
	ClientLineBottom.setVisible(false);

    FEA_PlaceTexture(LogoImage);
    FEA_PlaceTexture(CoolingImage);
    FEA_PlaceTexture(FlakeImage);
    FEA_PlaceTexture(StandbyImage);
    FEA_PlaceTexture(DropImage);

    FEA_PlaceText(TempEntText);
    FEA_PlaceText(TempFrcText);
    FEA_PlaceText(TempUnitText);

    FEA_PlaceText(HumText);
    FEA_PlaceText(HumPercentText);

    FEA_PlaceText(ExtTempUnitText);
    FEA_PlaceText(ExtTempText);
    FEA_PlaceTexture(ExtTempImage);

    FEA_PlaceButtonFlex(SettingsButton);
    FEA_PlaceTexture(SettingsImage);
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
	CFG.Dta.ScrOrientation ^= 1;
	CFG_Modified();
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

void MainView::DisplayEnv(ENV_Readings_t* Env)
{
	char Tmp[4];

	int16_t Temp = Env->TempC;
	if(CFG.Dta.TempUnit == CfgEnvTempF)
		Temp = Env->TempF;

	double Integral;
	double Fractional = modf((double)Temp / 100.0, &Integral) * 10.0;

	sprintf(Tmp, "%d", (int)Integral);
	Unicode::fromUTF8((uint8_t*)Tmp, TempEntTextBuffer, sizeof(TempEntTextBuffer));
	TempEntText.invalidate();

	sprintf(Tmp, "%d", (int)Fractional);
	Unicode::fromUTF8((uint8_t*)Tmp, TempFrcTextBuffer, sizeof(TempFrcTextBuffer));
	TempFrcText.invalidate();
}

void MainView::DisplayTemp(uint8_t* Temp)
{
//	char Str[UI_TEXT_STRING_LENGTH];

//	Unicode::fromUTF8((uint8_t*)Str, txtTempBuffer, sizeof(txtTempBuffer));
	Unicode::fromUTF8(Temp, TempEntTextBuffer, sizeof(TempEntTextBuffer));
	TempEntText.invalidate();
}

void MainView::function1()
{
	UI_ScreenSwitchCplt();
}













































