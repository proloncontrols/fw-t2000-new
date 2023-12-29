#ifndef ABOUTMEPRESENTER_HPP
#define ABOUTMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AboutmeView;

class AboutmePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AboutmePresenter(AboutmeView& v);

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

    virtual ~AboutmePresenter() {};

private:
    AboutmePresenter();

    AboutmeView& view;
};

#endif // ABOUTMEPRESENTER_HPP
