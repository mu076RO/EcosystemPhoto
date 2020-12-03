#include "ConfigWindow.h"
#include "ConfigSwitch.h"

ConfigWindow::ConfigWindow()
{
	_determineFlag = false;

	_recursive = std::unique_ptr<ConfigCell>(new ConfigSwitch(U"�T�u�t�H���_�̉摜��\������", U"recursive", 0, 64));
}

void ConfigWindow::update()
{
	if (MouseR.down() == true)
		_determineFlag = true;

	_recursive->update();
}

void ConfigWindow::draw()
{
	_recursive->draw();
}

bool ConfigWindow::determineFlag()
{
	return _determineFlag;
}
