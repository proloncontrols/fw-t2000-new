#ifndef CONTAINERSPLASH_HPP
#define CONTAINERSPLASH_HPP

#include <gui_generated/containers/containerSplashBase.hpp>

#include <CWidgets.hpp>

enum splashWidgets
{
	splashImageProlon,
	splashTextNewText,
	splashButton,
	splashCount
};

class containerSplash : public containerSplashBase
{
public:
    containerSplash();
    virtual ~containerSplash() {}

    virtual void initialize();

private:
    CWidgets* widgets;
    CButtonCustom* button;

    touchgfx::Callback<containerSplash, const touchgfx::AbstractButtonContainer&> buttonCallback;

    void buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // CONTAINERSPLASH_HPP
