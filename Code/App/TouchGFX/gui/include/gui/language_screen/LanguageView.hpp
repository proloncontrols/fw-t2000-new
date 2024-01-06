#ifndef LANGUAGEVIEW_HPP
#define LANGUAGEVIEW_HPP

#include <gui_generated/language_screen/LanguageViewBase.hpp>
#include <gui/language_screen/LanguagePresenter.hpp>
#include <Menu/Settings/CMenuLanguage.hpp>

class LanguageView : public LanguageViewBase
{
    CMenuLanguage menu = CMenuLanguage(container, buttonCallback);
    touchgfx::Callback<LanguageView, uint32_t, uint32_t> buttonCallback;
    void onButtonClicked(uint32_t, uint32_t);

public:
    LanguageView();
    virtual ~LanguageView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LANGUAGEVIEW_HPP
