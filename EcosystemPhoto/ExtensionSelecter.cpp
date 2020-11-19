#include "ExtensionSelecter.h"

void ExtensionSelecter::setCheck()
{
	Array<String> defaultExtensions;

	if (_extensionData[U"default"].isEmpty() != true)
		defaultExtensions = _extensionData[U"default"].getArray<String>();
	else
		defaultExtensions = { U"png" };

	//defaultに設定された拡張子だけチェックを入れて初期化
	for (size_t i = 0; i < _member; i++)
		if (defaultExtensions.includes(_allExtensions[i]) == true)
			_checkFlags[i] = true;
		else
			_checkFlags[i] = false;

	setExtensions();
}

void ExtensionSelecter::loadExtensions()
{
	//ファイルあり
	if (_extensionData[U"extension"].isEmpty() != true)
		_allExtensions = _extensionData[U"extension"].getArray<String>();
	//ファイルなし
	else
		_allExtensions = { U"jpg",U"png",U"gif" };
}

void ExtensionSelecter::setExtensions()
{
	_extensions.clear();
	//チェックが入っている拡張子を採用
	for (size_t i = 0; i < _member; i++)
		if (_checkFlags[i] == true)
			_extensions.push_back(_allExtensions[i]);
}

ExtensionSelecter::ExtensionSelecter()
{
	_extensionData.open(U"extension.json");	//拡張子ファイルを開く

	if (_extensionData.isEmpty() == true)	//ファイルがない場合
	{
		//拡張子ファイルの初期化
		JSONWriter extensionData;
		extensionData.startObject();
		{
			extensionData.key(U"extension").writeArray<String>({ U"jpg",U"png",U"gif" });
			extensionData.key(U"default").writeArray<String>({ U"png" });
		}
		extensionData.endObject();
		extensionData.save(U"extension.json");
	}

	loadExtensions();	//拡張子の読み込み

	//チェックボックス要素の初期化
	_member = _allExtensions.size();
	_checkFlags.resize(_member);

	setCheck();

	_reloadFlag = false;

	_extensionData.close();
}

void ExtensionSelecter::update()
{
	for (size_t i = 0; i < _member; i++)
		if (SimpleGUI::CheckBox(_checkFlags[i], _allExtensions[i], Vec2(MERGIN.x + SIZE.x * i, MERGIN.y), SIZE.x-MERGIN.x) == true)
		{
			setExtensions();	//どれかの拡張子の有効が変更されたら拡張子を更新
			_reloadFlag = true;
		}
}

Array<String> ExtensionSelecter::extensions()
{
	_reloadFlag = false;
	return _extensions;
}

bool ExtensionSelecter::reloadFlag()
{
	return _reloadFlag;
}
