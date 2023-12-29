#ifndef LANGUAGEPRESENTER_HPP
#define LANGUAGEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LanguageView;

class LanguagePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LanguagePresenter(LanguageView& v);

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

    virtual ~LanguagePresenter() {};

private:
    LanguagePresenter();

    LanguageView& view;
};

#endif // LANGUAGEPRESENTER_HPP
