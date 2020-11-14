#pragma once
#include <Siv3d.hpp>

class ImageCell
{
private:
	TextureRegion _texture;	//�T���l�C��
	String _path;	//�摜�p�X
	String _name;	//�摜���O

	Rect _rect;	//��ԊO�g
	Rect _imageRect;	//�摜�g
	Rect _nameRect;	//���O�g

	Point WINDOW_MERGIN = Point(16, 64);	//�E�B���h�E�̗]��
	Point CELL_MERGIN = Point(8, 8);	//�Z���̗]��
	Point SIZE = Point(128, 128);	//�傫��

public:
	ImageCell();
	ImageCell(Point pos, String path);

	~ImageCell();

	void setTexture();	//�摜�̐ݒ�

	void draw();	//�`��
};

