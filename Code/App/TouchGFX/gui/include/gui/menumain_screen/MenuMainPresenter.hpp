#ifndef MENUMAINPRESENTER_HPP
#define MENUMAINPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MenuMainView;

class MenuMainPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MenuMainPresenter(MenuMainView& v);

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

    virtual ~MenuMainPresenter() {};

private:
    MenuMainPresenter();

    MenuMainView& view;
};

#endif // MENUMAINPRESENTER_HPP
