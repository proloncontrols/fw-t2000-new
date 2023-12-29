#ifndef ORIENTATIONVIEW_HPP
#define ORIENTATIONVIEW_HPP

#include <gui_generated/orientation_screen/OrientationViewBase.hpp>
#include <gui/orientation_screen/OrientationPresenter.hpp>
#include <Menu/Settings/CMenuOrientation.hpp>

class OrientationView : public OrientationViewBase
{
    CMenuOrientation menu = CMenuOrientation(container, buttonCallback);
    touchgfx::Callback<OrientationView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void onButtonClicked(const touchgfx::AbstractButtonContainer& src);

public:
    OrientationView();
    virtual ~OrientationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ORIENTATIONVIEW_HPP
