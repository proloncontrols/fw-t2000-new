
#include <touchgfx/hal/Types.hpp>

namespace touchgfx
{

class CRect
{
public:
	int16_t x;
	int16_t y;
	int16_t width;
	int16_t height;

	CRect(Rect& rect);
	CRect(int16_t x, int16_t y, int16_t width, int16_t height);

	void operator=(Rect& rect);
	void operator=(CRect& rect);
};

}
