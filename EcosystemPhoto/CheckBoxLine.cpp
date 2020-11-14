#include "CheckBoxLine.h"

CheckBoxLine::CheckBoxLine()
{
	JSONReader extensionData(U"extension.json");

	if (extensionData.isEmpty() != true)
	{
		_extensions = extensionData[U"extension"].getArray<String>();
		_member = _extensions.size();
		_checkFlags.resize(_member);
	}
	else
	{
		JSONWriter extensionData;
		extensionData.startObject();
		{
			extensionData.key(U"extension").writeArray<String>({ U"jpg",U"png",U"gif" });
		}
		extensionData.endObject();
		extensionData.save(U"extension.json");

		_extensions = { U"jpg",U"png",U"gif" };
		_member = _extensions.size();
		_checkFlags.resize(_member);
	}

	for (auto& checkFlag : _checkFlags)
		checkFlag = false;
}

void CheckBoxLine::setValidExtensions(Array<String>* extensions)
{
	_validExtensions.clear();
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
			setValidExtensions(extensions);
			reloadFlag = true;
		}

	return reloadFlag;
}

Array<String> CheckBoxLine::extensions()
{
	return _validExtensions;
}
