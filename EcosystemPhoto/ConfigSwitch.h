#pragma once
#include "ConfigCell.h"

class ConfigSwitch :
	public ConfigCell
{
private:
	bool _checkFlag;

public:
	ConfigSwitch();
	ConfigSwitch(String discription, int top, int height);

	void update();
	void draw();

	int height();

	bool boolConfig();
};

