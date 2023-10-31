/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SPLASHVIEWBASE_HPP
#define SPLASHVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterARGB8888.hpp>

class SplashViewBase : public touchgfx::View<SplashPresenter>
{
public:
    SplashViewBase();
    virtual ~SplashViewBase() {}
    virtual void setupScreen();
    virtual void afterTransition();

    /*
     * Virtual Action Handlers
     */
    virtual void OnScreenTransitionEnd()
    {
        // Override and implement this function in Splash
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
    touchgfx::TextureMapper imgProlon;
    touchgfx::Line ClientLineTop;
    touchgfx::PainterARGB8888 ClientLineTopPainter;
    touchgfx::Line ClientLineLeft;
    touchgfx::PainterARGB8888 ClientLineLeftPainter;
    touchgfx::Line ClientLineRight;
    touchgfx::PainterARGB8888 ClientLineRightPainter;
    touchgfx::Line ClientLineBottom;
    touchgfx::PainterARGB8888 ClientLineBottomPainter;

private:

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 10800;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // SPLASHVIEWBASE_HPP
