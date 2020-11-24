#include "BaseCell.h"

BaseCell::BaseCell()
{
}

BaseCell::BaseCell(Point pos, String path)
{
	_rect = Rect(pos * SIZE + WINDOW_MERGIN, SIZE);
	_imageRect = Rect(pos * SIZE + WINDOW_MERGIN + IMAGE_MERGIN, SIZE - IMAGE_MERGIN * 2);
	_nameRect = RectF(pos * SIZE + WINDOW_MERGIN + IMAGE_MERGIN + Vec2(0, 6.5 * SIZE.y / 8), (SIZE - IMAGE_MERGIN * 2) / Point(1, 8) );

	_path = path;
	_name = FileSystem::FileName(path);
}

BaseCell::~BaseCell()
{
}

void BaseCell::setScroll(double scroll)
{
	_scrollY = scroll;
}

void BaseCell::reshapeTexture()
{
	Point size = _texture.texture.size();	//画像サイズの取得

	if (size.y > size.x)	//縦と横の大きさ	大きい方が枠に収まるように変形
	{
		_texture = _texture.scaled((double)(SIZE.y - IMAGE_MERGIN.y * 2) / size.y);
		//_texture = TextureAsset(_path)(Point(0, 0), Point(size.y, size.y)).scaled((double)(SIZE.y - CELL_MERGIN.y * 2) / size.y);
	}
	else
	{
		_texture = _texture.scaled((double)(SIZE.x - IMAGE_MERGIN.x * 2) / size.x);
		//_texture = TextureAsset(_path)(Point(0, 0), Point(size.x, size.x)).scaled((double)(SIZE.x - CELL_MERGIN.x * 2) / size.x);
	}
}

void BaseCell::update()
{
}

void BaseCell::draw()
{
	Rect movedRect = _rect.movedBy(0, _scrollY);
	//画面内にあったら描画
	if (Scene::Rect().intersects(movedRect) == true)
	{
		Rect movedImageRect = _imageRect.movedBy(0, _scrollY);
		Rect movedNameRect = _nameRect.movedBy(0, _scrollY).draw();	//名前枠描画
		movedImageRect.drawFrame(1, Palette::Black);	//枠描画

		_texture.drawAt(movedImageRect.center());

		movedNameRect.draw();
		FontAsset(U"16")(_name).draw(movedNameRect.stretched(0, DEFINE::fontSize/2), Palette::Black);	//名前描画
	}

	if (movedRect.mouseOver() == true)
	{
		movedRect.draw(Color(255, 255, 255, 64));
	}
}

double BaseCell::bottomY()
{
	return _rect.pos.y;
}
