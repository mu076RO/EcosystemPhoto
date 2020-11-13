#pragma once
#include <Siv3d.hpp>

class ImageCell
{
private:
	//TextureRegion _texture;
	String _path;
	String _name;

	Rect _rect;
	Rect _imageRect;

	Point MERGIN = Point(16, 64);
	Point SIZE = Point(128, 128);

public:
	ImageCell();
	ImageCell(Point pos, String path);

	void draw();
};

