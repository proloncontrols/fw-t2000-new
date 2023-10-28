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

    List[0]  = new CImage(CoolingImage);
    List[1]  = new CImage(FlakeImage);
    List[2]  = new CImage(StandbyImage);
    List[3]  = new CImage(LogoImage);
    List[4]  = new CImage(DropImage);
    List[5]  = new CImage(ExtTempImage);
    List[6]  = new CImage(SettingsImage);

    List[7]  = new CText(TempUnitText);
    List[8]  = new CText(TempEntText);
    List[9]  = new CText(TempFrcText);
    List[10] = new CText(HumPercentText);
    List[11] = new CText(HumText);
    List[12] = new CText(ExtTempUnitText);
    List[13] = new CText(ExtTempText);

    List[14] = new CButton(SettingsButton);
}

//-----------------------------------------------------------------------------
void MainView::setupScreen()
{
    MainViewBase::setupScreen();
    updateScreen();
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
    updateScreen();
	invalidate();
}

//-----------------------------------------------------------------------------
void MainView::updateScreen()
{
    for(int i = 0; i < MAIN_WIDGET_COUNT; i++)
    {
    	List[i]->placeOnScreen();
    }
}










































