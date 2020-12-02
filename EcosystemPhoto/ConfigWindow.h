#pragma once
#include <Siv3D.hpp>

class ConfigWindow
{
private:
	bool _determineFlag;

public:
	ConfigWindow();

	void update();
	void draw();

	bool determineFlag();
};

