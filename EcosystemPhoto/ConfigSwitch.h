#pragma once
#include "ConfigCell.h"

class ConfigSwitch :
	public ConfigCell
{
private:
	String _configElem;
	bool _checkFlag;

public:
	ConfigSwitch();
	ConfigSwitch(String discription, String configElem, int top, int height);

	void update();
	void draw();

	int height();
};

