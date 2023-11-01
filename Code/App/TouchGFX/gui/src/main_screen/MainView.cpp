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

	Widgets->set(mainImgCooling,     new CImage(CoolingImage));
	Widgets->set(mainImgFlake,       new CImage(FlakeImage));
	Widgets->set(mainImgStandby,     new CImage(StandbyImage));
	Widgets->set(mainImgLogo,        new CImage(LogoImage));
	Widgets->set(mainImgDrop,        new CImage(DropImage));
	Widgets->set(mainImgExtTemp,     new CImage(ExtTempImage));
	Widgets->set(mainImgSettings,    new CImage(SettingsImage));

	Widgets->set(mainTxtTempUnit,    new CText(TempUnitText));
	Widgets->set(mainTxtTempInt,     new CText(TempEntText));
	Widgets->set(mainTxtTempFrc,     new CText(TempFrcText));
	Widgets->set(mainTxtHumPercent,  new CText(HumPercentText));
	Widgets->set(mainTxtHum,         new CText(HumText));
	Widgets->set(mainTxtExtTempUnit, new CText(ExtTempUnitText));
	Widgets->set(mainTxtExtTemp,     new CText(ExtTempText));

	Widgets->set(mainBtnSettings,    new CButton(SettingsButton));
}

//-----------------------------------------------------------------------------
void MainView::setupScreen()
{
    MainViewBase::setupScreen();
    Widgets->place();
}

//-----------------------------------------------------------------------------
void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

//-----------------------------------------------------------------------------
void MainView::DisplayEnv(ENV_Readings_t* Env)
{
	static int16_t tst = 22;
	static int16_t tst2 = 77;

	char tmp[4];

	//Temperature unit selection
	int16_t temp = Env->TempC;
	if(CFG.Dta.TempUnit == CfgEnvTempF)
		temp = Env->TempF;

	//Room temperature
	double integral;
	double fractional = modf((double)temp / 100.0, &integral) * 10.0;
	sprintf(tmp, "%d", (int)integral);
	Unicode::fromUTF8((uint8_t*)tmp, TempEntTextBuffer, sizeof(TempEntTextBuffer));
	TempEntText.resizeToCurrentTextWithAlignment();
	TempEntText.invalidate();
	sprintf(tmp, "%d", (int)fractional);
	Unicode::fromUTF8((uint8_t*)tmp, TempFrcTextBuffer, sizeof(TempFrcTextBuffer));
	TempFrcText.resizeToCurrentTextWithAlignment();

	//Exterior temperature
	tst *= -1;
	sprintf(tmp, "%d", (int)tst);
	Unicode::fromUTF8((uint8_t*)tmp, ExtTempTextBuffer, sizeof(ExtTempTextBuffer));
	ExtTempText.resizeToCurrentTextWithAlignment();

	CRect refRect;
	CWidget* ref = Widgets->get(mainTxtExtTemp);
	ref->getPosition(refRect);

	CRect dstRect;
	CWidget* dst = Widgets->get(mainTxtExtTempUnit);
	dst->getPosition(dstRect);
	dstRect.x = refRect.x + refRect.width;
	dst->setPosition(dstRect);

	dst = Widgets->get(mainImgExtTemp);
	dst->getPosition(dstRect);
	dstRect.x = refRect.x + refRect.width;
	dst->setPosition(dstRect);

	//Humidity
	tst2 *= -1;
	sprintf(tmp, "%d", (int)tst2);
//	sprintf(tmp, "%d", (int)(Env->HumP / 100));
	Unicode::fromUTF8((uint8_t*)tmp, HumTextBuffer, sizeof(HumTextBuffer));
	HumText.resizeToCurrentTextWithAlignment();
	HumText.invalidate();

	ref = Widgets->get(mainTxtHum);
	ref->getPosition(refRect);

	dst = Widgets->get(mainTxtHumPercent);
	dst->getPosition(dstRect);
	dstRect.x = refRect.x + refRect.width;
	dst->setPosition(dstRect);

	dst = Widgets->get(mainImgDrop);
	dst->getPosition(dstRect);
	dstRect.x = refRect.x + refRect.width;
	dst->setPosition(dstRect);

	invalidate();
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
	Widgets->place();
	invalidate();
}










































