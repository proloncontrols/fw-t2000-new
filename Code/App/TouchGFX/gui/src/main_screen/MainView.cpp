#include <gui/main_screen/MainView.hpp>
#include <ui_virtual.hpp>

#include "math.h"
#include "stdio.h"

#include "cfg.h"
#include "image.hpp"
#include "text.hpp"
#include "button.hpp"

//-----------------------------------------------------------------------------
MainView::MainView()
{
	ClientLineTop.setVisible(false);
	ClientLineLeft.setVisible(false);
	ClientLineRight.setVisible(false);
	ClientLineBottom.setVisible(false);

	Widgets = new CWidgets(mainCount);

//	Widgets->set(mainImgCooling,     new CImage(CoolingImage));
//	Widgets->set(mainImgFlake,       new CImage(FlakeImage));
//	Widgets->set(mainImgStandby,     new CImage(StandbyImage));
//	Widgets->set(mainImgLogo,        new CImage(LogoImage));
//	Widgets->set(mainImgDrop,        new CImage(DropImage));
//	Widgets->set(mainImgExtTemp,     new CImage(ExtTempImage));
//	Widgets->set(mainImgSettings,    new CImage(SettingsImage));
//
//	Widgets->set(mainTxtTempUnit,    new CText(TempUnitText));
//	Widgets->set(mainTxtTempInt,     new CText(TempEntText));
//	Widgets->set(mainTxtTempFrc,     new CText(TempFrcText));
//	Widgets->set(mainTxtHumPercent,  new CText(HumPercentText));
//	Widgets->set(mainTxtHum,         new CText(HumText));
//	Widgets->set(mainTxtExtTempUnit, new CText(ExtTempUnitText));
//	Widgets->set(mainTxtExtTemp,     new CText(ExtTempText));
//
//	Widgets->set(mainBtnSettings,    new CButton(SettingsButton));
}

//-----------------------------------------------------------------------------
void MainView::setupScreen()
{
    MainViewBase::setupScreen();
    Widgets->updateScreen();
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
	Widgets->updateScreen();
	invalidate();
}










































