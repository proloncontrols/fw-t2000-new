/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MAINVIEWBASE_HPP
#define MAINVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterARGB8888.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/mixins/FadeAnimator.hpp>

class MainViewBase : public touchgfx::View<MainPresenter>
{
public:
    MainViewBase();
    virtual ~MainViewBase() {}
    virtual void setupScreen();
    virtual void afterTransition();

    /*
     * Virtual Action Handlers
     */
    virtual void function1()
    {
        // Override and implement this function in Main
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::Line ClientLineBottom;
    touchgfx::PainterARGB8888 ClientLineBottomPainter;
    touchgfx::Line ClientLineRight;
    touchgfx::PainterARGB8888 ClientLineRightPainter;
    touchgfx::Line ClientLineTop;
    touchgfx::PainterARGB8888 ClientLineTopPainter;
    touchgfx::Line ClientLineLeft;
    touchgfx::PainterARGB8888 ClientLineLeftPainter;
    touchgfx::TextureMapper CoolingImage;
    touchgfx::TextureMapper FlakeImage;
    touchgfx::TextureMapper StandbyImage;
    touchgfx::TextureMapper LogoImage;
    touchgfx::TextureMapper DropImage;
    touchgfx::TextArea TempUnitText;
    touchgfx::FadeAnimator< touchgfx::TextAreaWithOneWildcard > TempFrcText;
    touchgfx::TextAreaWithOneWildcard TempEntText;
    touchgfx::TextArea HumPercentText;
    touchgfx::TextAreaWithOneWildcard HumText;
    touchgfx::TextArea ExtTempUnitText;
    touchgfx::TextAreaWithOneWildcard ExtTempText;
    touchgfx::TextureMapper ExtTempImage;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  SettingsButton;
    touchgfx::TextureMapper SettingsImage;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEMPFRCTEXT_SIZE = 3;
    touchgfx::Unicode::UnicodeChar TempFrcTextBuffer[TEMPFRCTEXT_SIZE];
    static const uint16_t TEMPENTTEXT_SIZE = 4;
    touchgfx::Unicode::UnicodeChar TempEntTextBuffer[TEMPENTTEXT_SIZE];
    static const uint16_t HUMTEXT_SIZE = 4;
    touchgfx::Unicode::UnicodeChar HumTextBuffer[HUMTEXT_SIZE];
    static const uint16_t EXTTEMPTEXT_SIZE = 4;
    touchgfx::Unicode::UnicodeChar ExtTempTextBuffer[EXTTEMPTEXT_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MainViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 10800;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // MAINVIEWBASE_HPP
