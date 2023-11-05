
#ifndef CCONTAINER_HPP
#define CCONTAINER_HPP


#include <touchgfx/containers/Container.hpp>


namespace touchgfx
{

#define SCREEN_WIDTH    720
#define SCREEN_HEIGHT   672
#define SCREEN_ANGLE    (-1.572f)   //TextureMapper widget's Z angle
#define SCREEN_OFFSET   24


class CContainer : public Container
{
//public:
//	CContainer(touchgfx::Widget& widget);
//	CWidget(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >& button);
//
//	virtual void place() = 0;
//	virtual void getPosition(CRect& rect) = 0;
//	virtual void setPosition(CRect& rect) = 0;
};

}


#endif   //CCONTAINER_HPP
