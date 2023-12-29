#ifndef ORIENTATIONVIEW_HPP
#define ORIENTATIONVIEW_HPP

#include <gui_generated/orientation_screen/OrientationViewBase.hpp>
#include <gui/orientation_screen/OrientationPresenter.hpp>

class OrientationView : public OrientationViewBase
{
public:
    OrientationView();
    virtual ~OrientationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ORIENTATIONVIEW_HPP
