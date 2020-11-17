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
	Point size = _texture.texture.size();	//‰æ‘œƒTƒCƒY‚Ìæ“¾

	if (size.y > size.x)	//c‚Æ‰¡‚Ì‘å‚«‚³	‘å‚«‚¢•û‚ª˜g‚Éû‚Ü‚é‚æ‚¤‚É•ÏŒ`
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

void ImageCell::draw()
{
	if (Scene::Rect().intersects(_rect.movedBy(0,_scrollY)) == true)
	{
		//_rect.drawFrame(1, Palette::Black);
		_imageRect.movedBy(0,_scrollY).drawFrame(1, Palette::Black);	//˜g•`‰æ

		_texture.drawAt(_imageRect.center()+Vec2(0,_scrollY));

		_nameRect.movedBy(0,_scrollY).draw();	//–¼‘O˜g•`‰æ
		FontAsset(U"16")(_name).drawAt(_imageRect.bottomCenter() + Vec2(0, _scrollY), Palette::Black);	//–¼‘O•`‰æ
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
