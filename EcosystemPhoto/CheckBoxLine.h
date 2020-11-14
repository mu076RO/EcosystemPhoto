#pragma once
#include <Siv3D.hpp>

class CheckBoxLine
{
private:
	Array<String> _extensions;	//�g���q��
	Array<bool> _checkFlags;	//�g���q���L����
	int _member;	//�g���q�̐�

	Array<String> _validExtensions;	//�L���Ȋg���q�̔z��

	const Point MERGIN = Point(16, 16);	//����
	const Point SIZE = Point(96, 32);	//�傫��

public:
	CheckBoxLine();

	void setValidExtensions(Array<String>* extensions);	//�L���Ȋg���q�̍X�V

	bool update(Array<String>* extensions);	//reload����Ƃ�true

	Array<String> extensions();
};
