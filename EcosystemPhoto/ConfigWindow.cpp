#include "ConfigWindow.h"

ConfigWindow::ConfigWindow()
{
	_determineFlag = false;
}

void ConfigWindow::update()
{
	if (MouseR.down() == true)
		_determineFlag = true;
}

void ConfigWindow::draw()
{
}

bool ConfigWindow::determineFlag()
{
	return _determineFlag;
}
