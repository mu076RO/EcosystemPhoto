#include "ImageCell.h"

ImageCell::ImageCell()
{
}

ImageCell::ImageCell(Point pos, String path) :BaseCell(pos, path)
{
}

void ImageCell::setTexture()
{
	_texture = Texture(_path);	//�摜�̎擾

	reshapeTexture();
}

void ImageCell::update()
{
	//�N���b�N���ꂽ��摜�r���[�A�𗧂��グ
	if (_rect.movedBy(0, _scrollY).mouseOver() == true && MouseL.down() == true)
	{
		ShellExecute(NULL, L"open", _path.toWstr().c_str(), NULL, NULL, SW_SHOW);
	}
}
