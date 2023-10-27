#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

#include "ui_virtual.hpp"

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
    WidgetEx* CoolingImageEx    = new TextureMapperEx(CoolingImage);
    WidgetEx* FlakeImageEx      = new TextureMapperEx(FlakeImage);
    WidgetEx* StandbyImageEx    = new TextureMapperEx(StandbyImage);
    WidgetEx* LogoImageEx       = new TextureMapperEx(LogoImage);
    WidgetEx* DropImageEx       = new TextureMapperEx(DropImage);
    WidgetEx* ExtTempImageEx    = new TextureMapperEx(ExtTempImage);
    WidgetEx* SettingsImageEx   = new TextureMapperEx(SettingsImage);

    WidgetEx* TempUnitTextEx    = new TextAreaEx(TempUnitText);
    WidgetEx* TempEntTextEx     = new TextAreaEx(TempEntText);
    WidgetEx* TempFrcTextEx     = new TextAreaEx(TempFrcText);
    WidgetEx* HumPercentTextEx  = new TextAreaEx(HumPercentText);
    WidgetEx* HumTextEx         = new TextAreaEx(HumText);
    WidgetEx* ExtTempUnitTextEx = new TextAreaEx(ExtTempUnitText);
    WidgetEx* ExtTempTextEx     = new TextAreaEx(ExtTempText);

    WidgetEx* SettingsButtonEx  = new ButtonEx(SettingsButton);
};

#endif // MAINVIEW_HPP
