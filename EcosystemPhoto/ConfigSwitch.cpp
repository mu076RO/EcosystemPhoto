#include "ConfigSwitch.h"

ConfigSwitch::ConfigSwitch() :ConfigCell()
{
	_checkFlag = false;
}

ConfigSwitch::ConfigSwitch(String discription, String configElem, int top, int height): ConfigCell(discription, top, height)
{
	_configElem = configElem;
	_checkFlag = false;
}

void ConfigSwitch::update()
{
	SimpleGUI::CheckBox(_checkFlag, U"", Point(800-16-32, _top + 16), 48);
}

void ConfigSwitch::draw()
{
	ConfigCell::draw();
	FontAsset(U"16")(_discription).draw(16, _top + 16, Palette::Black);
}

int ConfigSwitch::height()
{
	return 64;
}
