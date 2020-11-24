#pragma once
#include <Siv3d.hpp>
#include <windows.h>
#include "DEFINE.h"

class BaseCell
{
protected:
	TextureRegion _texture;	//�T���l�C��
	FilePath _path;	//�摜�p�X
	String _name;	//�摜���O

	Rect _rect;	//��ԊO�g
	Rect _imageRect;	//�摜�g
	Rect _nameRect;	//���O�g
	double _scrollY;	//�X�N���[������y���l

	Point WINDOW_MERGIN = Point(16, 64);	//�E�B���h�E�̗]��
	Point IMAGE_MERGIN = Point(8, 8);	//�Z���̗]��
	Point SIZE = Point(128, 128);	//�傫��

public:
	BaseCell();
	BaseCell(Point pos, String path);

	virtual ~BaseCell();

	void setScroll(double scroll);	//�X�N���[���l�̔��f
	virtual void setTexture() {};
	void reshapeTexture();	//�摜�̐ݒ�

	virtual void update();
	void draw();	//�`��

	double bottomY();	//��ӂ��擾
	FilePath path();
	virtual bool reloadFlag();
};

