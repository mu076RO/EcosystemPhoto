#pragma once
#include <Siv3D.hpp>
#include "DEFINE.h"

class FolderSelecter
{
private:
	FilePath _path;	//���݃p�X
	FilePath _basePath;	//���p�X�i����ȏ��̃p�X���Q�ƕs�j

	bool _reloadFlag;	//�摜�Z���̃����[�h�t���O

	const Point MERGIN = Point(800-96-16, 16);	//��
	const Point SIZE = Point(96, 32);	//�T�C�Y

private:
	void loadPath();	//���E���݃p�X�̓ǂݍ���

public:
	FolderSelecter();

	void update();	//���݃t�H���_�̍X�V

	bool reloadFlag();	//�摜�Z���̃����[�h�t���O
	FilePath path();
};

