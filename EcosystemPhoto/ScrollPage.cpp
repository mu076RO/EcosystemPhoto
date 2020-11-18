#include "ScrollPage.h"

ScrollPage::ScrollPage() : SPEED(50), SCROLL_MERGIN(300)
{
	_scroll = 0;
}

void ScrollPage::reset(int bottomY)
{
	_scroll = 0;
	_bottomY = bottomY;
}

void ScrollPage::update()
{
	if (_scroll < SCROLL_MERGIN && Mouse::Wheel() < 0)
		_scroll -= SPEED * Mouse::Wheel();

	if (_scroll > -_bottomY + SCROLL_MERGIN && Mouse::Wheel() > 0)
		_scroll -= SPEED * Mouse::Wheel();
}

int ScrollPage::scroll()
{
	return _scroll;
}
