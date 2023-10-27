#include <gui/main_screen/MainView.hpp>
#include <ui_virtual.hpp>

#include "math.h"
#include "stdio.h"

#include "cfg.h"

//-----------------------------------------------------------------------------
MainView::MainView()
{
	ClientLineTop.setVisible(false);
	ClientLineLeft.setVisible(false);
	ClientLineRight.setVisible(false);
	ClientLineBottom.setVisible(false);

//	CoolingImageEx->placeOnScreen();
//	LogoImageEx->placeOnScreen();
//	FlakeImageEx->placeOnScreen();
//	StandbyImageEx->placeOnScreen();
//	DropImageEx->placeOnScreen();
//	ExtTempImageEx->placeOnScreen();
//	SettingsImageEx->placeOnScreen();
//
//	TempUnitTextEx->placeOnScreen();
//	TempEntTextEx->placeOnScreen();
//	TempFrcTextEx->placeOnScreen();
//	HumPercentTextEx->placeOnScreen();
//	HumTextEx->placeOnScreen();
//	ExtTempUnitTextEx->placeOnScreen();
//	ExtTempTextEx->placeOnScreen();
//
//	SettingsButtonEx->placeOnScreen();

//	UIV_placeTexture(LogoImage);
//	UIV_placeTexture(CoolingImage);
//	UIV_placeTexture(FlakeImage);
//	UIV_placeTexture(StandbyImage);
//	UIV_placeTexture(DropImage);

//	UIV_placeText(TempEntText);
//	UIV_placeText(TempFrcText);
//	UIV_placeText(TempUnitText);

//	UIV_placeText(HumText);
//	UIV_placeText(HumPercentText);

//	UIV_placeText(ExtTempUnitText);
//	UIV_placeText(ExtTempText);
//	UIV_placeTexture(ExtTempImage);

//	UIV_placeButtonFlex(SettingsButton);
//	UIV_placeTexture(SettingsImage);
}

//-----------------------------------------------------------------------------
void MainView::setupScreen()
{
    MainViewBase::setupScreen();

	CoolingImageEx->placeOnScreen();
	LogoImageEx->placeOnScreen();
	FlakeImageEx->placeOnScreen();
	StandbyImageEx->placeOnScreen();
	DropImageEx->placeOnScreen();
	ExtTempImageEx->placeOnScreen();
	SettingsImageEx->placeOnScreen();

	TempUnitTextEx->placeOnScreen();
	TempEntTextEx->placeOnScreen();
	TempFrcTextEx->placeOnScreen();
	HumPercentTextEx->placeOnScreen();
	HumTextEx->placeOnScreen();
	ExtTempUnitTextEx->placeOnScreen();
	ExtTempTextEx->placeOnScreen();

	SettingsButtonEx->placeOnScreen();
}

//-----------------------------------------------------------------------------
void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

//-----------------------------------------------------------------------------
void MainView::DisplayEnv(ENV_Readings_t* Env)
{
	static int16_t Tst = 22;

	char Tmp[4];

	//Temperature unit selection
	int16_t Temp = Env->TempC;
	if(CFG.Dta.TempUnit == CfgEnvTempF)
		Temp = Env->TempF;

	//Room temperature
	double Integral;
	double Fractional = modf((double)Temp / 100.0, &Integral) * 10.0;
	sprintf(Tmp, "%d", (int)Integral);
	Unicode::fromUTF8((uint8_t*)Tmp, TempEntTextBuffer, sizeof(TempEntTextBuffer));
	TempEntText.resizeToCurrentTextWithAlignment();
	TempEntText.invalidate();
	sprintf(Tmp, "%d", (int)Fractional);
	Unicode::fromUTF8((uint8_t*)Tmp, TempFrcTextBuffer, sizeof(TempFrcTextBuffer));
	TempFrcText.resizeToCurrentTextWithAlignment();
	TempFrcText.invalidate();

	//Exterior temperature
	Tst *= -1;
	sprintf(Tmp, "%d", (int)Tst);
	Unicode::fromUTF8((uint8_t*)Tmp, ExtTempTextBuffer, sizeof(ExtTempTextBuffer));
	ExtTempText.resizeToCurrentTextWithAlignment();
	ExtTempText.invalidate();
	ExtTempUnitText.setX(ExtTempText.getX() + ExtTempText.getTextWidth());   //Maybe getWidth() instead
	ExtTempUnitText.invalidate();
	ExtTempImage.setX(ExtTempUnitText.getX());
	ExtTempImage.invalidate();

	//Humidity
	sprintf(Tmp, "%d", (int)(Env->HumP / 100));
	Unicode::fromUTF8((uint8_t*)Tmp, HumTextBuffer, sizeof(HumTextBuffer));
	HumText.resizeToCurrentTextWithAlignment();
	HumText.invalidate();
	HumPercentText.setX(HumText.getX() + HumText.getWidth());
	HumPercentText.invalidate();
	DropImage.setX(HumPercentText.getX());
	DropImage.invalidate();
}

//-----------------------------------------------------------------------------
void MainView::function1()
{
	UI_ScreenSwitchCplt();
}

//-----------------------------------------------------------------------------
void MainView::OnSettingsButton()
{
	CFG.Dta.ScrOrientation ^= 1;

	CoolingImageEx->placeOnScreen();
	LogoImageEx->placeOnScreen();
	FlakeImageEx->placeOnScreen();
	StandbyImageEx->placeOnScreen();
	DropImageEx->placeOnScreen();
	ExtTempImageEx->placeOnScreen();
	SettingsImageEx->placeOnScreen();

	TempUnitTextEx->placeOnScreen();
	TempEntTextEx->placeOnScreen();
	TempFrcTextEx->placeOnScreen();
	HumPercentTextEx->placeOnScreen();
	HumTextEx->placeOnScreen();
	ExtTempUnitTextEx->placeOnScreen();
	ExtTempTextEx->placeOnScreen();

	SettingsButtonEx->placeOnScreen();

	invalidate();
}












































