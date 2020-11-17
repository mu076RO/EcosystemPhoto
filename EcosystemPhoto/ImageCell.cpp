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
}

ImageCell::~ImageCell()
{
}

void ImageCell::setPos(double scroll)
{
	_scrollY = scroll;
}

void ImageCell::setTexture()
{
	_texture = Texture(_path);
	Point size = _texture.texture.size();	//âÊëúÉTÉCÉYÇÃéÊìæ

	if (size.y > size.x)	//ècÇ∆â°ÇÃëÂÇ´Ç≥	ëÂÇ´Ç¢ï˚Ç™ògÇ…é˚Ç‹ÇÈÇÊÇ§Ç…ïœå`
	{
		_texture = _texture.scaled((double)(SIZE.y - CELL_MERGIN.y * 2) / size.y);
		//_texture = TextureAsset(_path)(Point(0, 0), Point(size.y, size.y)).scaled((double)(SIZE.y - CELL_MERGIN.y * 2) / size.y);
	}
	else
	{
		_texture = _texture.scaled((double)(SIZE.x - CELL_MERGIN.x * 2) / size.x);
		//_texture = TextureAsset(_path)(Point(0, 0), Point(size.x, size.x)).scaled((double)(SIZE.x - CELL_MERGIN.x * 2) / size.x);
	}
}

void ImageCell::update()
{
	if (_rect.movedBy(0, _scrollY).mouseOver() == true && MouseL.down() == true)
	{
		ShellExecute(NULL, L"open", _path.toWstr().c_str(), NULL, NULL, SW_SHOW);
	}
}

void ImageCell::draw()
{
	if (Scene::Rect().intersects(_rect.movedBy(0,_scrollY)) == true)
	{
		//_rect.drawFrame(1, Palette::Black);
		_imageRect.movedBy(0,_scrollY).drawFrame(1, Palette::Black);	//ògï`âÊ

		_texture.drawAt(_imageRect.center()+Vec2(0,_scrollY));

		_nameRect.movedBy(0,_scrollY).draw();	//ñºëOògï`âÊ
		FontAsset(U"16")(_name).drawAt(_imageRect.bottomCenter() + Vec2(0, _scrollY), Palette::Black);	//ñºëOï`âÊ
	}

	if (_rect.movedBy(0,_scrollY).mouseOver() == true)
	{
		_rect.movedBy(0, _scrollY).draw(Color(255, 255, 255, 64));
	}
}

double ImageCell::bottomY()
{
	return _rect.pos.y;
}
