#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>

#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>

#include <touchgfx/containers/buttons/ImageButtonStyle.hpp>
#include <touchgfx/containers/buttons/BoxWithBorderButtonStyle.hpp>
#include <touchgfx/containers/buttons/ClickButtonTrigger.hpp>

#include "ui.h"

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
	UI_Screen_t Screen;

    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }
    virtual void handleTickEvent();

    // Reset
    void gotoResetScreenNoTransition();

    // Main
    void gotoMainScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplication> transitionCallback;

    // Reset
    void gotoResetScreenNoTransitionImpl();

    // Main
    void gotoMainScreenNoTransitionImpl();

private:
};

void FEA_PlaceText(touchgfx::TextArea& Text);
void FEA_PlaceButtonLabel(touchgfx::ButtonWithLabel& Button);
void FEA_PlaceTexture(touchgfx::TextureMapper& Image);
void FEA_PlaceButtonFlex(touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > >& Button);

#endif // FRONTENDAPPLICATION_HPP
