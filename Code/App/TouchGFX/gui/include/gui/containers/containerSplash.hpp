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

protected:

private:
    CWidgets* widgets;

    CButtonCustom* Button;

    touchgfx::Callback<containerSplashBase, const touchgfx::AbstractButtonContainer&> ButtonCallback;
};

#endif // CONTAINERSPLASH_HPP
