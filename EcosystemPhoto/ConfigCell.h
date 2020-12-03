#pragma once
#include <Siv3D.hpp>

class ConfigCell
{
protected:
	int _top;
	const Point _size;
	String _discription;

public:
	ConfigCell();
	ConfigCell(String discription, int top, int height);

	virtual void update() {};
	virtual void draw();

	virtual int bottom();

	virtual bool boolConfig();
};

