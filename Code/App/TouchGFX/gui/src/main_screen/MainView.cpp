#include <gui/main_screen/MainView.hpp>

#include "math.h"
#include "stdio.h"
#include "framework.h"
#include "ui.h"

MainView::MainView()
{
	lineClientLeft.setVisible(false);
	lineClientTop.setVisible(false);
	lineClientRight.setVisible(false);
	lineClientBottom.setVisible(false);

    FEA_PlaceTexture(textureLogo);
    FEA_PlaceTexture(textureCooling);
    FEA_PlaceTexture(textureFlake);
    FEA_PlaceTexture(textureStandby);
    FEA_PlaceTexture(textureExtTemp);
    FEA_PlaceTexture(textureDrop);

    FEA_PlaceText(txtTempEnt);
    FEA_PlaceText(txtTempFrc);
    FEA_PlaceText(txtTempUnit);
    FEA_PlaceText(txtExtTemp);
    FEA_PlaceText(txtExtTempUnit);
    FEA_PlaceText(txtHum);
    FEA_PlaceText(txtHumPercent);

    FEA_PlaceButtonFlex(flexSettings);
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
	Unicode::fromUTF8((uint8_t*)Tmp, txtTempEntBuffer, sizeof(txtTempEntBuffer));
	txtTempEnt.invalidate();

	sprintf(Tmp, "%d", (int)Fractional);
	Unicode::fromUTF8((uint8_t*)Tmp, txtTempFrcBuffer, sizeof(txtTempFrcBuffer));
	txtTempFrc.invalidate();
}

void MainView::DisplayTemp(uint8_t* Temp)
{
//	char Str[UI_TEXT_STRING_LENGTH];

//	Unicode::fromUTF8((uint8_t*)Str, txtTempBuffer, sizeof(txtTempBuffer));
	Unicode::fromUTF8(Temp, txtTempEntBuffer, sizeof(txtTempEntBuffer));
	txtTempEnt.invalidate();
}

void MainView::function1()
{
	UI_ScreenSwitchCplt();
}













































