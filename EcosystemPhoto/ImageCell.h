#pragma once
#include <Siv3d.hpp>

class ImageCell
{
private:
	TextureRegion _texture;
	String _path;

public:
	ImageCell();

	void draw();
};

