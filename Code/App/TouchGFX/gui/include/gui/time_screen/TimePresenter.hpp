#ifndef TIMEPRESENTER_HPP
#define TIMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TimeView;

class TimePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TimePresenter(TimeView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~TimePresenter() {};

private:
    TimePresenter();

    TimeView& view;
};

#endif // TIMEPRESENTER_HPP
