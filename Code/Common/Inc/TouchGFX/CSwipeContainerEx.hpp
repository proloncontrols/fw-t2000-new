
#include <CSwipeContainer.hpp>


namespace touchgfx
{

class CSwipeContainerEx : public CSwipeContainer
{
public:
	CSwipeContainerEx();

	void handleClickEvent(const ClickEvent& event);
};

}
