#include "CheckBoxLine.h"

CheckBoxLine::CheckBoxLine()
{
	//拡張子ファイルの設定
	JSONReader extensionData(U"extension.json");

	//ファイルあり
	if (extensionData.isEmpty() != true)
	{
		_extensions = extensionData[U"extension"].getArray<String>();
	}
	//ファイルなし
	else
	{
		//拡張子ファイルの初期化
		JSONWriter extensionData;
		extensionData.startObject();
		{
			extensionData.key(U"extension").writeArray<String>({ U"jpg",U"png",U"gif" });
		}
		extensionData.endObject();
		extensionData.save(U"extension.json");

		_extensions = { U"jpg",U"png",U"gif" };
	}

	//チェックボックス要素の初期化
	_member = _extensions.size();
	_checkFlags.resize(_member);

	for (auto& checkFlag : _checkFlags)
		checkFlag = false;
}

void CheckBoxLine::setValidExtensions(Array<String>* extensions)
{
	_validExtensions.clear();
	//チェックが入っている拡張子を採用
	for (size_t i = 0; i < _member; i++)
		if (_checkFlags[i] == true)
			_validExtensions.push_back(_extensions[i]);

	*extensions = _validExtensions;
}

bool CheckBoxLine::update(Array<String>* extensions)
{
	bool reloadFlag = false;
	for (size_t i = 0; i < _member; i++)
		if (SimpleGUI::CheckBox(_checkFlags[i], _extensions[i], Vec2(MERGIN.x + SIZE.x * i, MERGIN.y), SIZE.x-MERGIN.x) == true)
		{
			setValidExtensions(extensions);	//どれかの拡張子の有効が変更されたら拡張子を更新
			reloadFlag = true;
		}

	return reloadFlag;
}

Array<String> CheckBoxLine::extensions()
{
	return _validExtensions;
}
