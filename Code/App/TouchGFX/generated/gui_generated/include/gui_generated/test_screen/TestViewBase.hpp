/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TESTVIEWBASE_HPP
#define TESTVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/test_screen/TestPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>

class TestViewBase : public touchgfx::View<TestPresenter>
{
public:
    TestViewBase();
    virtual ~TestViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::Container extTemp;
    touchgfx::Box box2;
    touchgfx::TextArea txtTemp;
    touchgfx::TextureMapper imgTemp;
    touchgfx::TextArea txtUnit;

private:

};

#endif // TESTVIEWBASE_HPP