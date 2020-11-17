#pragma once
#include <Siv3D.hpp>

class ScrollPage
{
private:
	double _scroll;
	double _bottomY;

	const double SPEED;

public:
	ScrollPage();

	void setBottomY(double bottomY);
	void update();

	double scroll();
};
