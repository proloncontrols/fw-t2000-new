#include <gui/main_screen/MainView.hpp>

#include "math.h"
#include "stdio.h"
#include "framework.h"
#include "ui.h"

MainView::MainView()
{
    FEA_PlaceText(txtTempEnt);
    FEA_PlaceText(txtTempFrc);
//    FEA_PlaceButtonIcon(btnUp);
//    FEA_PlaceButtonIcon(btnDn);

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

	float Temp = Env->TempC;
	if(CFG.Dta.TempUnit == CfgEnvTempF)
		Temp = Env->TempF;

	float Integral;
	float Fractional = modf(Temp, &Integral) * 10.0;

	sprintf(Tmp, "%d", (int)Integral);
	Unicode::fromUTF8((uint8_t*)Tmp, txtTempEntBuffer, sizeof(txtTempEntBuffer));
	txtTempEnt.invalidate();

	sprintf(Tmp, "%d", (int)Fractional);
	Unicode::fromUTF8((uint8_t*)Tmp, txtTempFrcBuffer, sizeof(txtTempFrcBuffer));
	txtTempFrc.invalidate();




//	float Temp = Env->TempC;
//	if(CFG.Dta.TempUnit == CfgEnvTempF)
//		Temp = Env->TempF;
//
//	int Integral = (int)Temp;
//	char Tmp[4];
//	sprintf(Tmp, "%.1f", (float)Temp - (float)Integral);
//	strcpy(Tmp, strstr("0.", Tmp));
//	int Fractional = atoi(Tmp);
//
//	sprintf(Tmp, "%d", Integral);
//	Unicode::fromUTF8((uint8_t*)Tmp, txtTempEntBuffer, sizeof(txtTempEntBuffer));
//	txtTempEnt.invalidate();
//
//	sprintf(Tmp, "%d", Fractional);
//	Unicode::fromUTF8((uint8_t*)Tmp, txtTempFrcBuffer, sizeof(txtTempFrcBuffer));
//	txtTempFrc.invalidate();
}

void MainView::DisplayTemp(uint8_t* Temp)
{
//	char Str[UI_TEXT_STRING_LENGTH];

//	Unicode::fromUTF8((uint8_t*)Str, txtTempBuffer, sizeof(txtTempBuffer));
	Unicode::fromUTF8(Temp, txtTempEntBuffer, sizeof(txtTempEntBuffer));
	txtTempEnt.invalidate();
}














































