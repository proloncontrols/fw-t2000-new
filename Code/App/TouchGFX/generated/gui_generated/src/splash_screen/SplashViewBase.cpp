/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/splash_screen/SplashViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SplashViewBase::SplashViewBase()
{

    __background.setPosition(0, 0, 720, 672);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 720, 672);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    btnButton270.setXY(0, 0);
    btnButton270.setVisible(false);
    btnButton270.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_270_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_270_ID));
    btnButton270.setLabelText(touchgfx::TypedText(T___SINGLEUSE_YRZ9));
    btnButton270.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    btnButton270.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    btnButton270.setLabelRotation(TEXT_ROTATE_270);

    imgProlon.setXY(24, 146);
    imgProlon.setBitmap(touchgfx::Bitmap(BITMAP_PROLON_LOGO_4_ID));
    imgProlon.setWidth(672);
    imgProlon.setHeight(190);
    imgProlon.setBitmapPosition(16.0f, 3.0f);
    imgProlon.setScale(0.75f);
    imgProlon.setCameraDistance(1000.0f);
    imgProlon.setOrigo(336.0f, 95.0f, 1000.0f);
    imgProlon.setCamera(336.0f, 95.0f);
    imgProlon.setAngles(0.0f, 0.0f, 0.0f);
    imgProlon.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);

    add(__background);
    add(box1);
    add(btnButton270);
    add(imgProlon);
}

void SplashViewBase::setupScreen()
{

}

//Called when the screen transition ends
void SplashViewBase::afterTransition()
{
    //ScreenTransitionEnd
    //When screen transition ends call virtual function
    //Call OnScreenTransitionEnd
    OnScreenTransitionEnd();
}
