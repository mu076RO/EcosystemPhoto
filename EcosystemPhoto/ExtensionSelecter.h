#pragma once
#include <Siv3D.hpp>
#include "DEFINE.h"

class ExtensionSelecter
{
private:
	JSONReader _extensionData;

	Array<String> _allExtensions;	//全ての拡張子名
	Array<String> _extensions;	//有効な拡張子の配列
	Array<bool> _checkFlags;	//拡張子が有効か
	int _member;	//拡張子の数

	bool _reloadFlag;	//画像セルのリロードフラグ

	const Point MERGIN = Point(16, 16);	//合間
	const Point SIZE = Point(96, 32);	//大きさ

private:
	void setCheck();
	void loadExtensions();

	void setExtensions();	//有効な拡張子の更新

public:
	ExtensionSelecter();

	void update();	//描画兼更新

	Array<String> extensions();	//有効な拡張子を返す
	bool reloadFlag();	//画像セルのリロードフラグ
};
