#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <CWidget.hpp>
#include <CWidgets.hpp>
#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>


enum mainWidgets
{
	mainImgCooling,
	mainImgFlake,
	mainImgStandby,
	mainImgLogo,
	mainImgDrop,
	mainImgExtTemp,
	mainImgSettings,

	mainTxtTempUnit,
	mainTxtTempInt,
	mainTxtTempFrc,
	mainTxtHumPercent,
	mainTxtHum,
	mainTxtExtTempUnit,
	mainTxtExtTemp,

	mainBtnSettings,

	mainCount
};

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void DisplayEnv(ENV_Readings_t* Env);
    virtual void function1();
    virtual void OnSettingsButton();

protected:
    CWidgets* Widgets;
};

#endif // MAINVIEW_HPP
