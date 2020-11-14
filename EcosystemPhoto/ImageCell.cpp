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

	TextureAsset::Register(_path, _path, AssetParameter::LoadAsync());	//�񓯊��摜�ǂݍ���
}

ImageCell::~ImageCell()
{
}

void ImageCell::setTexture()
{
	Point size = TextureAsset(_path).size();	//�摜�T�C�Y�̎擾

	if (size.y > size.x)	//�c�Ɖ��̑傫��	�傫�������g�Ɏ��܂�悤�ɕό`
	{
		_texture = TextureAsset(_path).scaled((double)(SIZE.y - CELL_MERGIN.y * 2) / size.y);
		//_texture = TextureAsset(_path)(Point(0, 0), Point(size.y, size.y)).scaled((double)(SIZE.y - CELL_MERGIN.y * 2) / size.y);
	}
	else
	{
		_texture = TextureAsset(_path).scaled((double)(SIZE.x - CELL_MERGIN.x * 2) / size.x);
		//_texture = TextureAsset(_path)(Point(0, 0), Point(size.x, size.x)).scaled((double)(SIZE.x - CELL_MERGIN.x * 2) / size.x);
	}

	//	�A�Z�b�g�̓R�s�[�ς݂Ȃ̂ŊJ��
	TextureAsset(_path).release();
	TextureAsset::Unregister(_path);
}

void ImageCell::draw()
{
	//_rect.drawFrame(1, Palette::Black);
	_imageRect.drawFrame(1, Palette::Black);	//�g�`��

	if (TextureAsset::IsReady(_path) == true && _texture.texture.isEmpty() == true)	//�A�Z�b�g�ǂݍ��݊��������Ƃ��摜�Z�b�g�i���̂݁j
		setTexture();

	if (_texture.texture.isEmpty() != true)	//�摜�Z�b�g���ꂽ��摜�`��
		_texture.drawAt(_imageRect.center());

	_nameRect.draw();	//���O�g�`��
	FontAsset(U"16")(_name).drawAt(_imageRect.bottomCenter(),Palette::Black);	//���O�`��
}
