#ifndef UNITPRESENTER_HPP
#define UNITPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class UnitView;

class UnitPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    UnitPresenter(UnitView& v);

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

    virtual ~UnitPresenter() {};

private:
    UnitPresenter();

    UnitView& view;
};

#endif // UNITPRESENTER_HPP
