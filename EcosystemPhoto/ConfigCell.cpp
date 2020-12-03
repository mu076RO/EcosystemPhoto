#include "ConfigCell.h"

ConfigCell::ConfigCell(): _size(800,64)
{
	_top = 0;
}

ConfigCell::ConfigCell(String discription, int top, int height): _size(800, height), _top(top)
{
	_discription = discription;
}

void ConfigCell::draw()
{
	Line(Point(0, _top), Point(800, _top)).draw(Palette::Black);
}

int ConfigCell::bottom()
{
	return _top + _size.y;
}

bool ConfigCell::boolConfig()
{
	return false;
}
