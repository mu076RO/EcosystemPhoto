#pragma once
#include <Siv3D.hpp>
#include "DEFINE.h"

class FolderSelecter
{
private:
	FilePath _path;	//現在パス
	FilePath _basePath;	//基底パス（これ以上上のパスを参照不可）

	bool _reloadFlag;	//画像セルのリロードフラグ

	const Point MERGIN = Point(800-96-16, 16);	//空白
	const Point SIZE = Point(96, 32);	//サイズ

private:
	void loadPath();	//基底・現在パスの読み込み

public:
	FolderSelecter();

	void update();	//現在フォルダの更新

	bool reloadFlag();	//画像セルのリロードフラグ
	FilePath path();
};

