#include "FolderCell.h"

FolderCell::FolderCell()
{
}

FolderCell::FolderCell(Point pos, String path) :BaseCell(pos, path)
{
}

void FolderCell::setTexture()
{
	_texture = Texture(Emoji(U"📁"));

	reshapeTexture();
}

void FolderCell::update()
{
}
