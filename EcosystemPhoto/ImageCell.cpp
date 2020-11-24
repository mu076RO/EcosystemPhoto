#include "ImageCell.h"

ImageCell::ImageCell()
{
}

ImageCell::ImageCell(Point pos, String path) :BaseCell(pos, path)
{
}

void ImageCell::setTexture()
{
	_texture = Texture(_path);	//画像の取得

	reshapeTexture();
}

void ImageCell::update()
{
	//クリックされたら画像ビューアを立ち上げ
	if (_rect.movedBy(0, _scrollY).mouseOver() == true && MouseL.down() == true)
	{
		ShellExecute(NULL, L"open", _path.toWstr().c_str(), NULL, NULL, SW_SHOW);
	}
}
