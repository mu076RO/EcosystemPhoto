#include "SettingWindow.h"

SettingWindow::SettingWindow()
{
	_determineFlag = false;
}

void SettingWindow::update()
{
	if (MouseR.down() == true)
		_determineFlag = true;
}

void SettingWindow::draw()
{
}

bool SettingWindow::determineFlag()
{
	return _determineFlag;
}
