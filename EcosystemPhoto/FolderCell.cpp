#include "FolderCell.h"

FolderCell::FolderCell()
{
}

FolderCell::FolderCell(Point pos, String path) :BaseCell(pos, path)
{
	_reloadFlag = false;
}

void FolderCell::setTexture()
{
	_texture = Texture(Emoji(U"📁"));

	reshapeTexture();
}

void FolderCell::update()
{
	//クリックされたら画像ビューアを立ち上げ
	if (_rect.movedBy(0, _scrollY).mouseOver() == true && MouseL.down() == true)
	{
		_reloadFlag = true;
	}
	else
		_reloadFlag = false;
}

bool FolderCell::reloadFlag()
{
	return _reloadFlag;
}
