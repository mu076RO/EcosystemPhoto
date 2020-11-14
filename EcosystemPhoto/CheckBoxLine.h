#pragma once
#include <Siv3D.hpp>

class CheckBoxLine
{
private:
	Array<String> _extensions;	//拡張子名
	Array<bool> _checkFlags;	//拡張子が有効か
	int _member;	//拡張子の数

	Array<String> _validExtensions;	//有効な拡張子の配列

	const Point MERGIN = Point(16, 16);	//合間
	const Point SIZE = Point(96, 32);	//大きさ

public:
	CheckBoxLine();

	void setValidExtensions(Array<String>* extensions);	//有効な拡張子の更新

	bool update(Array<String>* extensions);	//reloadするときtrue

	Array<String> extensions();
};
