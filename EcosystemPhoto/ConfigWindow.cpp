#include "ConfigWindow.h"
#include "ConfigSwitch.h"

ConfigWindow::ConfigWindow()
{
	_determineFlag = false;

	_recursive = std::unique_ptr<ConfigCell>(new ConfigSwitch(U"サブフォルダの画像を表示する", 0, 64));
	_folderRecursive = std::unique_ptr<ConfigCell>(new ConfigSwitch(U"サブフォルダを表示する", _recursive->bottom(), 64));
}

void ConfigWindow::setConfig()
{
	JSONWriter json;

	json.startObject();
	json.key(U"recursive").writeBool(_recursive->boolConfig());
	json.key(U"recFolder").writeBool(_folderRecursive->boolConfig());
	json.endObject();

	json.save(DEFINE::DATAFOLDERPATH + U"config.json");
}

void ConfigWindow::update()
{
	if (MouseR.down() == true)
	{
		setConfig();

		_determineFlag = true;
	}

	_recursive->update();
	_folderRecursive->update();
}

void ConfigWindow::draw()
{
	_recursive->draw();
	_folderRecursive->draw();
}

bool ConfigWindow::determineFlag()
{
	return _determineFlag;
}
