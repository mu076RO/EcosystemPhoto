#pragma once
#include <Siv3D.hpp>

class FolderChoiceButton
{
private:
	const Point MERGIN = Point(800-96-16, 16);	//��
	const Point SIZE = Point(96, 32);	//�T�C�Y

public:
	FolderChoiceButton();

	bool update(String* path, String base);	//���݃t�H���_�̍X�V
};

