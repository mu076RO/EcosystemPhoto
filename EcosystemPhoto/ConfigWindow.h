#pragma once
#include <Siv3D.hpp>
#include "ConfigCell.h"
#include "DEFINE.h"

class ConfigWindow
{
private:
	bool _isRecursive;

	bool _determineFlag;
	std::unique_ptr<ConfigCell> _recursive;
	std::unique_ptr<ConfigCell> _folderRecursive;

public:
	ConfigWindow();

	void setConfig();
	void update();
	void draw();

	bool determineFlag();
};

