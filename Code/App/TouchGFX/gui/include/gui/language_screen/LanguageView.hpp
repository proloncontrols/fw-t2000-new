#ifndef LANGUAGEVIEW_HPP
#define LANGUAGEVIEW_HPP

#include <gui_generated/language_screen/LanguageViewBase.hpp>
#include <gui/language_screen/LanguagePresenter.hpp>
#include <Menu/Settings/CMenuLanguage.hpp>

class LanguageView : public LanguageViewBase
{
    CMenuLanguage menu = CMenuLanguage(container, buttonCallback);
    touchgfx::Callback<LanguageView, const touchgfx::AbstractButtonContainer&> buttonCallback;
    void onButtonClicked(const touchgfx::AbstractButtonContainer& src);

public:
    LanguageView();
    virtual ~LanguageView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LANGUAGEVIEW_HPP
