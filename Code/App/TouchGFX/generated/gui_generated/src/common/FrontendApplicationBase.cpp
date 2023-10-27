/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <new>
#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <platform/driver/lcd/LCD32bpp.hpp>
#include <gui/splash_screen/SplashView.hpp>
#include <gui/splash_screen/SplashPresenter.hpp>
#include <gui/clear_screen/ClearView.hpp>
#include <gui/clear_screen/ClearPresenter.hpp>
#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

using namespace touchgfx;

FrontendApplicationBase::FrontendApplicationBase(Model& m, FrontendHeap& heap)
    : touchgfx::MVPApplication(),
      transitionCallback(),
      frontendHeap(heap),
      model(m)
{
    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_LANDSCAPE);
    touchgfx::Texts::setLanguage(GB);
    reinterpret_cast<touchgfx::LCD32bpp&>(touchgfx::HAL::lcd()).enableTextureMapperAll();
}

/*
 * Screen Transition Declarations
 */

// Splash

void FrontendApplicationBase::gotoSplashScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoSplashScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoSplashScreenNoTransitionImpl()
{
    touchgfx::makeTransition<SplashView, SplashPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
