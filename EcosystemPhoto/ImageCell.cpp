#include "ImageCell.h"

ImageCell::ImageCell()
{
}

ImageCell::ImageCell(Point pos, String path)
{
	_rect = Rect(pos * SIZE + WINDOW_MERGIN, SIZE);
	_imageRect = Rect(pos * SIZE + WINDOW_MERGIN + IMAGE_MERGIN, SIZE - IMAGE_MERGIN * 2);
	_nameRect = RectF(pos * SIZE + WINDOW_MERGIN + IMAGE_MERGIN + Vec2(0, 6.5 * SIZE.y / 8), (SIZE - IMAGE_MERGIN * 2) / Point(1, 8) );

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
	_texture = Texture(_path);	//�摜�̎擾
	Point size = _texture.texture.size();	//�摜�T�C�Y�̎擾

	if (size.y > size.x)	//�c�Ɖ��̑傫��	�傫�������g�Ɏ��܂�悤�ɕό`
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

void ImageCell::update()
{
	//�N���b�N���ꂽ��摜�r���[�A�𗧂��グ
	if (_rect.movedBy(0, _scrollY).mouseOver() == true && MouseL.down() == true)
	{
		ShellExecute(NULL, L"open", _path.toWstr().c_str(), NULL, NULL, SW_SHOW);
	}
}

void ImageCell::draw()
{
	Rect movedRect = _rect.movedBy(0, _scrollY);
	//��ʓ��ɂ�������`��
	if (Scene::Rect().intersects(movedRect) == true)
	{
		Rect movedImageRect = _imageRect.movedBy(0, _scrollY);
		movedImageRect.drawFrame(1, Palette::Black);	//�g�`��

		_texture.drawAt(movedImageRect.center());

		_nameRect.movedBy(0,_scrollY).draw();	//���O�g�`��
		FontAsset(U"16")(_name).drawAt(movedImageRect.bottomCenter(), Palette::Black);	//���O�`��
	}

	if (movedRect.mouseOver() == true)
	{
		movedRect.draw(Color(255, 255, 255, 64));
	}
}

double ImageCell::bottomY()
{
	return _rect.pos.y;
}
