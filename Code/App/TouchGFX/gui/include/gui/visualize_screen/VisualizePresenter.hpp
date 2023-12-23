#ifndef VISUALIZEPRESENTER_HPP
#define VISUALIZEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class VisualizeView;

class VisualizePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    VisualizePresenter(VisualizeView& v);

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

    virtual ~VisualizePresenter() {};

private:
    VisualizePresenter();

    VisualizeView& view;
};

#endif // VISUALIZEPRESENTER_HPP
