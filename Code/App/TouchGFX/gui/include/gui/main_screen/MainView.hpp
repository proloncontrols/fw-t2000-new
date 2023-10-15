#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
//    virtual void DisplayVersion(uint16_t Version);
    virtual void OnButtonRotateClick();

    virtual void OnBtnUp();
    virtual void OnBtnDn();
    virtual void DisplayTemp(uint8_t* Temp);

protected:
};

#endif // MAINVIEW_HPP
