#include "ImageCell.h"

ImageCell::ImageCell()
{
}

ImageCell::ImageCell(Point pos, String path)
{
	_rect = Rect(pos * SIZE + WINDOW_MERGIN, SIZE);
	_imageRect = Rect(pos * SIZE + WINDOW_MERGIN + CELL_MERGIN, SIZE - CELL_MERGIN * 2);
	_nameRect = RectF(pos * SIZE + WINDOW_MERGIN + CELL_MERGIN + Vec2(0, 6.5 * SIZE.y / 8), (SIZE - CELL_MERGIN * 2) / Point(1, 8) );

	_path = path;
	_name = FileSystem::FileName(path);

	TextureAsset::Register(_path, _path, AssetParameter::LoadAsync());
}

ImageCell::~ImageCell()
{
}

void ImageCell::setTexture()
{
	Point size = TextureAsset(_path).size();

	if (size.y > size.x)
	{
		_texture = TextureAsset(_path).scaled((double)(SIZE.y - CELL_MERGIN.y * 2) / size.y);
		//_texture = TextureAsset(_path)(Point(0, 0), Point(size.y, size.y)).scaled((double)(SIZE.y - CELL_MERGIN.y * 2) / size.y);
	}
	else
	{
		_texture = TextureAsset(_path).scaled((double)(SIZE.x - CELL_MERGIN.x * 2) / size.x);
		//_texture = TextureAsset(_path)(Point(0, 0), Point(size.x, size.x)).scaled((double)(SIZE.x - CELL_MERGIN.x * 2) / size.x);
	}

	TextureAsset(_path).release();
	TextureAsset::Unregister(_path);
}

void ImageCell::draw()
{
	//_rect.drawFrame(1, Palette::Black);
	_imageRect.drawFrame(1, Palette::Black);

	if (TextureAsset::IsReady(_path) == true && _texture.texture.isEmpty() == true)
		setTexture();

	if (_texture.texture.isEmpty() != true)
		_texture.drawAt(_imageRect.center());

	_nameRect.draw();
	FontAsset(U"16")(_name).drawAt(_imageRect.bottomCenter(),Palette::Black);
}
