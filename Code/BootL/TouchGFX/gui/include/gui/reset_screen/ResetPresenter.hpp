#ifndef RESETPRESENTER_HPP
#define RESETPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ResetView;

class ResetPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ResetPresenter(ResetView& v);

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

    virtual ~ResetPresenter() {};

    void PostSystemReset();

private:
    ResetPresenter();

    ResetView& view;
};

#endif // RESETPRESENTER_HPP
