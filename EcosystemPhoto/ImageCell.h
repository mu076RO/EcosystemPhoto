#pragma once
#include <Siv3d.hpp>

class ImageCell
{
private:
	TextureRegion _texture;
	String _path;
	String _name;

	Rect _rect;
	Rect _imageRect;
	Rect _nameRect;

	Point WINDOW_MERGIN = Point(16, 64);
	Point CELL_MERGIN = Point(8, 8);
	Point SIZE = Point(128, 128);

public:
	ImageCell();
	ImageCell(Point pos, String path);

	~ImageCell();

	void setTexture();

	void draw();
};

