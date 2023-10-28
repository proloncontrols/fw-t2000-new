#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

#include "widget.hpp"

#define  MAIN_WIDGET_COUNT   15

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
    CWidget* List[MAIN_WIDGET_COUNT];

private:
    void updateScreen();
};

#endif // MAINVIEW_HPP
