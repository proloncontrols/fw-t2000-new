/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/main_screen/MainViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


MainViewBase::MainViewBase() :
    flexButtonCallback(this, &MainViewBase::flexButtonCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 720, 672);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 720, 672);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    ClientLineBottom.setPosition(0, 0, 720, 672);
    ClientLineBottomPainter.setColor(touchgfx::Color::getColorFromRGB(99, 105, 100));
    ClientLineBottom.setPainter(ClientLineBottomPainter);
    ClientLineBottom.setStart(48, 648);
    ClientLineBottom.setEnd(672, 648);
    ClientLineBottom.setLineWidth(1);
    ClientLineBottom.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    ClientLineRight.setPosition(0, 0, 720, 672);
    ClientLineRightPainter.setColor(touchgfx::Color::getColorFromRGB(99, 105, 100));
    ClientLineRight.setPainter(ClientLineRightPainter);
    ClientLineRight.setStart(672, 24);
    ClientLineRight.setEnd(672, 648);
    ClientLineRight.setLineWidth(1);
    ClientLineRight.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    ClientLineLeft.setPosition(0, 0, 720, 672);
    ClientLineLeftPainter.setColor(touchgfx::Color::getColorFromRGB(99, 105, 100));
    ClientLineLeft.setPainter(ClientLineLeftPainter);
    ClientLineLeft.setStart(48, 24);
    ClientLineLeft.setEnd(48, 648);
    ClientLineLeft.setLineWidth(1);
    ClientLineLeft.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    ClientLineTop.setPosition(0, 0, 720, 672);
    ClientLineTopPainter.setColor(touchgfx::Color::getColorFromRGB(99, 105, 100));
    ClientLineTop.setPainter(ClientLineTopPainter);
    ClientLineTop.setStart(48, 24);
    ClientLineTop.setEnd(672, 24);
    ClientLineTop.setLineWidth(1);
    ClientLineTop.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    CoolingImage.setXY(48, 24);
    CoolingImage.setBitmap(touchgfx::Bitmap(BITMAP_COOLINGON_ID));
    CoolingImage.setWidth(624);
    CoolingImage.setHeight(624);
    CoolingImage.setBitmapPosition(24.0f, 30.0f);
    CoolingImage.setScale(1.0f);
    CoolingImage.setCameraDistance(1000.0f);
    CoolingImage.setOrigo(312.0f, 312.0f, 1000.0f);
    CoolingImage.setCamera(312.0f, 312.0f);
    CoolingImage.setAngles(0.0f, 0.0f, 0.0f);
    CoolingImage.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);

    FlakeImage.setXY(332, 440);
    FlakeImage.setBitmap(touchgfx::Bitmap(BITMAP_SNOWFLAKE_ID));
    FlakeImage.setWidth(56);
    FlakeImage.setHeight(56);
    FlakeImage.setBitmapPosition(3.0f, 2.5f);
    FlakeImage.setScale(1.0f);
    FlakeImage.setCameraDistance(1000.0f);
    FlakeImage.setOrigo(90.0f, 90.0f, 1000.0f);
    FlakeImage.setCamera(28.0f, 28.0f);
    FlakeImage.setAngles(0.0f, 0.0f, 0.0f);
    FlakeImage.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);

    StandbyImage.setXY(607, 591);
    StandbyImage.setBitmap(touchgfx::Bitmap(BITMAP_STANDBYMODE_ID));
    StandbyImage.setWidth(68);
    StandbyImage.setHeight(61);
    StandbyImage.setBitmapPosition(4.5f, 5.0f);
    StandbyImage.setScale(1.0f);
    StandbyImage.setCameraDistance(1000.0f);
    StandbyImage.setOrigo(34.0f, 30.5f, 1000.0f);
    StandbyImage.setCamera(34.0f, 30.5f);
    StandbyImage.setAngles(0.0f, 0.0f, 0.0f);
    StandbyImage.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);

    LogoImage.setXY(24, 24);
    LogoImage.setBitmap(touchgfx::Bitmap(BITMAP_PROLON_40_1_ID));
    LogoImage.setWidth(672);
    LogoImage.setHeight(28);
    LogoImage.setBitmapPosition(248.5f, 0.0f);
    LogoImage.setScale(1.0f);
    LogoImage.setCameraDistance(1000.0f);
    LogoImage.setOrigo(336.0f, 14.0f, 1000.0f);
    LogoImage.setCamera(336.0f, 14.0f);
    LogoImage.setAngles(0.0f, 0.0f, 0.0f);
    LogoImage.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);

    DropImage.setXY(48, 616);
    DropImage.setBitmap(touchgfx::Bitmap(BITMAP_HUMIDITY_ID));
    DropImage.setWidth(30);
    DropImage.setHeight(36);
    DropImage.setBitmapPosition(4.5f, 3.0f);
    DropImage.setScale(1.0f);
    DropImage.setCameraDistance(1000.0f);
    DropImage.setOrigo(15.0f, 18.0f, 1000.0f);
    DropImage.setCamera(15.0f, 18.0f);
    DropImage.setAngles(0.0f, 0.0f, 0.0f);
    DropImage.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);

    TempUnitText.setXY(436, 199);
    TempUnitText.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    TempUnitText.setLinespacing(0);
    TempUnitText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CFMA));

    TempFrcText.setXY(436, 308);
    TempFrcText.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    TempFrcText.setLinespacing(0);
    TempFrcTextBuffer[0] = 0;
    TempFrcText.setWildcard(TempFrcTextBuffer);
    TempFrcText.resizeToCurrentText();
    TempFrcText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_R2UV));

    TempEntText.setXY(435, 157);
    TempEntText.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    TempEntText.setLinespacing(0);
    TempEntTextBuffer[0] = 0;
    TempEntText.setWildcard(TempEntTextBuffer);
    TempEntText.resizeToCurrentText();
    TempEntText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_LYVN));

    HumPercentText.setXY(48, 590);
    HumPercentText.setColor(touchgfx::Color::getColorFromRGB(186, 188, 190));
    HumPercentText.setLinespacing(0);
    HumPercentText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_DBNW));

    HumText.setXY(48, 575);
    HumText.setColor(touchgfx::Color::getColorFromRGB(186, 188, 190));
    HumText.setLinespacing(0);
    HumTextBuffer[0] = 0;
    HumText.setWildcard(HumTextBuffer);
    HumText.resizeToCurrentText();
    HumText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UB3J));

    ExtTempUnitText.setXY(48, 18);
    ExtTempUnitText.setColor(touchgfx::Color::getColorFromRGB(186, 188, 190));
    ExtTempUnitText.setLinespacing(0);
    ExtTempUnitText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W88E));

    ExtTempText.setXY(48, 5);
    ExtTempText.setColor(touchgfx::Color::getColorFromRGB(186, 188, 190));
    ExtTempText.setLinespacing(0);
    ExtTempTextBuffer[0] = 0;
    ExtTempText.setWildcard(ExtTempTextBuffer);
    ExtTempText.resizeToCurrentText();
    ExtTempText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8EN3));

    ExtTempImage.setXY(48, 50);
    ExtTempImage.setBitmap(touchgfx::Bitmap(BITMAP_OUTSIDE_ID));
    ExtTempImage.setWidth(98);
    ExtTempImage.setHeight(25);
    ExtTempImage.setBitmapPosition(37.5f, 1.0f);
    ExtTempImage.setScale(1.0f);
    ExtTempImage.setCameraDistance(1000.0f);
    ExtTempImage.setOrigo(49.0f, 12.5f, 1000.0f);
    ExtTempImage.setCamera(49.0f, 12.5f);
    ExtTempImage.setAngles(0.0f, 0.0f, 0.0f);
    ExtTempImage.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);

    SettingsButton.setBoxWithBorderPosition(0, 0, 50, 50);
    SettingsButton.setBorderSize(0);
    SettingsButton.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(0, 0, 0));
    SettingsButton.setPosition(620, 25, 50, 50);
    SettingsButton.setAction(flexButtonCallback);

    SettingsImage.setXY(620, 25);
    SettingsImage.setBitmap(touchgfx::Bitmap(BITMAP_SETTING_ID));
    SettingsImage.setWidth(50);
    SettingsImage.setHeight(50);
    SettingsImage.setBitmapPosition(-0.5f, 0.0f);
    SettingsImage.setScale(1.0f);
    SettingsImage.setCameraDistance(1000.0f);
    SettingsImage.setOrigo(90.0f, 90.0f, 1000.0f);
    SettingsImage.setCamera(25.0f, 25.0f);
    SettingsImage.setAngles(0.0f, 0.0f, 0.0f);
    SettingsImage.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);

    add(__background);
    add(box1);
    add(ClientLineBottom);
    add(ClientLineRight);
    add(ClientLineLeft);
    add(ClientLineTop);
    add(CoolingImage);
    add(FlakeImage);
    add(StandbyImage);
    add(LogoImage);
    add(DropImage);
    add(TempUnitText);
    add(TempFrcText);
    add(TempEntText);
    add(HumPercentText);
    add(HumText);
    add(ExtTempUnitText);
    add(ExtTempText);
    add(ExtTempImage);
    add(SettingsButton);
    add(SettingsImage);
}

void MainViewBase::setupScreen()
{

}

//Called when the screen transition ends
void MainViewBase::afterTransition()
{
    //Interaction1
    //When screen transition ends call virtual function
    //Call function1
    function1();
}

void MainViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &SettingsButton)
    {
        //SettingsButton
        //When SettingsButton clicked call virtual function
        //Call OnSettingsButton
        OnSettingsButton();
    }
}
