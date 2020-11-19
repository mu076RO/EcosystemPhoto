#pragma once
#include <Siv3D.hpp>

class FolderSelecter
{
private:
	FilePath _path;	//現在パス
	FilePath _basePath;	//基底パス（これ以上上のパスを参照不可）

	bool _reloadFlag;

	const Point MERGIN = Point(800-96-16, 16);	//空白
	const Point SIZE = Point(96, 32);	//サイズ

private:
	void loadPath();

public:
	FolderSelecter();

	void update();	//現在フォルダの更新

	bool reloadFlag();
	FilePath path();
};

