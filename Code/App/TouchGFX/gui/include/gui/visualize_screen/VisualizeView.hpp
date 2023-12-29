#ifndef VISUALIZEVIEW_HPP
#define VISUALIZEVIEW_HPP

#include <gui_generated/visualize_screen/VisualizeViewBase.hpp>
#include <gui/visualize_screen/VisualizePresenter.hpp>

#include <Menu/Visualize/CMenuVisualize.hpp>

class VisualizeView : public VisualizeViewBase
{
public:
    VisualizeView();
    virtual ~VisualizeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    CMenuVisualize menu = CMenuVisualize(container, buttonCallback);

private:
    touchgfx::Callback<VisualizeView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // VISUALIZEVIEW_HPP
