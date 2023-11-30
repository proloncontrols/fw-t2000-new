#ifndef SETPOINTSPRESENTER_HPP
#define SETPOINTSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SetPointsView;

class SetPointsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SetPointsPresenter(SetPointsView& v);

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

    virtual ~SetPointsPresenter() {};

private:
    SetPointsPresenter();

    SetPointsView& view;
};

#endif // SETPOINTSPRESENTER_HPP
