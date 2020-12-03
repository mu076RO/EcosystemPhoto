#pragma once
#include <Siv3D.hpp>
#include "ConfigCell.h"

class ConfigWindow
{
private:
	bool _determineFlag;
	std::unique_ptr<ConfigCell> _recursive;

public:
	ConfigWindow();

	void update();
	void draw();

	bool determineFlag();
};

