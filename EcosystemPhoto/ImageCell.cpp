#include "ImageCell.h"

ImageCell::ImageCell()
{
	_texture = TextureAsset(U"default");
}

ImageCell::ImageCell(Point pos, String path)
{
	_rect = Rect(pos * SIZE + WINDOW_MERGIN, SIZE);
	_imageRect = Rect(pos * SIZE + WINDOW_MERGIN + CELL_MERGIN, SIZE - CELL_MERGIN * 2);
	_nameRect = RectF(pos * SIZE + WINDOW_MERGIN + CELL_MERGIN + Vec2(0, 6.5 * SIZE.y / 8), (SIZE - CELL_MERGIN * 2) / Point(1, 8) );

	_path = path;
	_name = FileSystem::FileName(path);

	_texture = TextureAsset(U"default");

	setTexture();
}

void ImageCell::setTexture()
{
	Texture texture(_path);
	Point size = texture.size();

	if (size.y > size.x)
	{
		_texture = texture(Point(0,0), Point(size.x, size.x)).scaled((double)(SIZE.x - CELL_MERGIN.x * 2) / size.x);
	}
	else
	{
		_texture = texture(Point(0, 0), Point(size.y, size.y)).scaled((double)(SIZE.y - CELL_MERGIN.y * 2) / size.y);
	}
}

void ImageCell::draw()
{
	//_rect.drawFrame(1, Palette::Black);
	_imageRect.drawFrame(1, Palette::Black);
	_texture.drawAt(_imageRect.center());

	_nameRect.draw();
	FontAsset(U"16")(_name).drawAt(_imageRect.bottomCenter(),Palette::Black);
}
