#pragma once
#include <Siv3D.hpp>

class SettingWindow
{
private:
	bool _determineFlag;

public:
	SettingWindow();

	void update();
	void draw();

	bool determineFlag();
};

