#ifndef CTNRSPLASH_HPP
#define CTNRSPLASH_HPP

#include <gui_generated/containers/ctnrSplashBase.hpp>
#include <CWidgets.hpp>

enum splashWidgets {
	splashImageProlon,
	splashTextNewText,
	splashButton,
	splashCount
};

class ctnrSplash : public ctnrSplashBase
{
public:
    ctnrSplash();
    virtual ~ctnrSplash() {}

    virtual void initialize();

private:
    CWidgets* widgets;
    CButtonCustom* button;

    touchgfx::Callback<ctnrSplash, const touchgfx::AbstractButtonContainer&> buttonCallback;

    void buttonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // CTNRSPLASH_HPP
