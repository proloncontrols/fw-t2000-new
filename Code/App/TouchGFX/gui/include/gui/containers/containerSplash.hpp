#ifndef CONTAINERSPLASH_HPP
#define CONTAINERSPLASH_HPP

#include <gui_generated/containers/containerSplashBase.hpp>

#include <CWidgets.hpp>

enum splashWidgets
{
	splashImageProlon,
	splashTextNewText,
//	splashButton1,
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

    CButton flexButton2;

    touchgfx::Callback<containerSplashBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
};

#endif // CONTAINERSPLASH_HPP
