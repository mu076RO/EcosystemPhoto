#include "ScrollPage.h"

ScrollPage::ScrollPage() : SPEED(50)
{
	_scroll = 0;
}

void ScrollPage::setBottomY(double bottomY)
{
	_bottomY = bottomY;
}

void ScrollPage::update()
{
	_scroll -= SPEED * Mouse::Wheel();
}

double ScrollPage::scroll()
{
	return _scroll;
}
