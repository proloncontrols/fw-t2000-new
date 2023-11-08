
#ifndef TST
#define TST

#include <touchgfx/containers/buttons/BoxWithBorderButtonStyle.hpp>
#include <touchgfx/containers/buttons/ClickButtonTrigger.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>

namespace touchgfx
{

class CButtonCustom : public BoxWithBorderButtonStyle< ClickButtonTrigger >
{
public:
	CButtonCustom();
	CButtonCustom(int16_t x, int16_t y, int16_t width, int16_t height, TextureMapper* imageReleased, TextureMapper* imagePressed);

    virtual void handleClickEvent(const ClickEvent& event) override;

    void setImages(TextureMapper* imageReleased, TextureMapper* imagePressed);

private:
    TextureMapper* imgReleased;
    TextureMapper* imgPressed;
};

}

#endif   //TST
