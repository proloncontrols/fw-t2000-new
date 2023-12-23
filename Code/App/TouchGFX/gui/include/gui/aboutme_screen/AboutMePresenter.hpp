#ifndef ABOUTMEPRESENTER_HPP
#define ABOUTMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AboutMeView;

class AboutMePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AboutMePresenter(AboutMeView& v);

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

    virtual ~AboutMePresenter() {};

private:
    AboutMePresenter();

    AboutMeView& view;
};

#endif // ABOUTMEPRESENTER_HPP
