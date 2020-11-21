#pragma once
#include <Siv3D.hpp>
#include "DEFINE.h"

class ExtensionSelecter
{
private:
	JSONReader _extensionData;

	Array<String> _allExtensions;	//�S�Ă̊g���q��
	Array<String> _extensions;	//�L���Ȋg���q�̔z��
	Array<bool> _checkFlags;	//�g���q���L����
	int _member;	//�g���q�̐�

	bool _reloadFlag;	//�摜�Z���̃����[�h�t���O

	const Point MERGIN = Point(16, 16);	//����
	const Point SIZE = Point(96, 32);	//�傫��

private:
	void setCheck();
	void loadExtensions();

	void setExtensions();	//�L���Ȋg���q�̍X�V

public:
	ExtensionSelecter();

	void update();	//�`�挓�X�V

	Array<String> extensions();	//�L���Ȋg���q��Ԃ�
	bool reloadFlag();	//�摜�Z���̃����[�h�t���O
};
