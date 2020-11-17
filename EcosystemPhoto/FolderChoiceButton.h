#pragma once
#include <Siv3D.hpp>

class FolderChoiceButton
{
private:
	const Point MERGIN = Point(800-96-16, 16);	//空白
	const Point SIZE = Point(96, 32);	//サイズ

public:
	FolderChoiceButton();

	bool update(String* path, String base);	//現在フォルダの更新
};

