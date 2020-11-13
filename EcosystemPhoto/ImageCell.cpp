#include "ImageCell.h"

ImageCell::ImageCell()
{
}

ImageCell::ImageCell(Point pos, String path)
{
	_rect = Rect(pos * SIZE + MERGIN, SIZE);

	_imageRect = Rect(pos * SIZE + MERGIN + Point(8, 8), SIZE - Point(16, 16));

	_path = path;
	_name = FileSystem::FileName(path);
}

void ImageCell::draw()
{
	//_rect.drawFrame(1, Palette::Black);
	_imageRect.drawFrame(1, Palette::Black);

	FontAsset(U"16")(_name).drawAt(_imageRect.bottomCenter(),Palette::Black);
}
