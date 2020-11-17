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

void ImageCell::setScroll(double scroll)
{
	_scrollY = scroll;
}

void ImageCell::setTexture()
{
	_texture = Texture(_path);	//画像の取得
	Point size = _texture.texture.size();	//画像サイズの取得

	if (size.y > size.x)	//縦と横の大きさ	大きい方が枠に収まるように変形
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
	//クリックされたら画像ビューアを立ち上げ
	if (_rect.movedBy(0, _scrollY).mouseOver() == true && MouseL.down() == true)
	{
		ShellExecute(NULL, L"open", _path.toWstr().c_str(), NULL, NULL, SW_SHOW);
	}
}

void ImageCell::draw()
{
	//画面内にあったら描画
	if (Scene::Rect().intersects(_rect.movedBy(0,_scrollY)) == true)
	{
		//_rect.drawFrame(1, Palette::Black);
		_imageRect.movedBy(0,_scrollY).drawFrame(1, Palette::Black);	//枠描画

		_texture.drawAt(_imageRect.center()+Vec2(0,_scrollY));

		_nameRect.movedBy(0,_scrollY).draw();	//名前枠描画
		FontAsset(U"16")(_name).drawAt(_imageRect.bottomCenter() + Vec2(0, _scrollY), Palette::Black);	//名前描画
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
