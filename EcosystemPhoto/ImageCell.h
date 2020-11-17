#pragma once
#include <Siv3d.hpp>
#include <windows.h>

class ImageCell
{
private:
	TextureRegion _texture;	//�T���l�C��
	String _path;	//�摜�p�X
	String _name;	//�摜���O

	Rect _rect;	//��ԊO�g
	Rect _imageRect;	//�摜�g
	Rect _nameRect;	//���O�g
	double _scrollY;	//�X�N���[������y���l

	Point WINDOW_MERGIN = Point(16, 64);	//�E�B���h�E�̗]��
	Point CELL_MERGIN = Point(8, 8);	//�Z���̗]��
	Point SIZE = Point(128, 128);	//�傫��

public:
	ImageCell();
	ImageCell(Point pos, String path);

	~ImageCell();

	void setScroll(double scroll);	//�X�N���[���l�̔��f
	void setTexture();	//�摜�̐ݒ�

	void update();
	void draw();	//�`��

	double bottomY();	//��ӂ��擾
};

