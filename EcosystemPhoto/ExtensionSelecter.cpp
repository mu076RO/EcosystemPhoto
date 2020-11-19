#include "ExtensionSelecter.h"

void ExtensionSelecter::setCheck()
{
	Array<String> defaultExtensions = _extensionData[U"default"].getArray<String>();

	for (size_t i = 0; i < _member; i++)
		if (defaultExtensions.includes(_allExtensions[i]) == true)
			_checkFlags[i] = true;
		else
			_checkFlags[i] = false;

	setExtensions();
}

void ExtensionSelecter::loadExtensions()
{
	//�t�@�C������
	if (_extensionData.isEmpty() != true)
	{
		_allExtensions = _extensionData[U"extension"].getArray<String>();
	}
	//�t�@�C���Ȃ�
	else
	{
		//�g���q�t�@�C���̏�����
		JSONWriter extensionData;
		extensionData.startObject();
		{
			extensionData.key(U"extension").writeArray<String>({ U"jpg",U"png",U"gif" });
		}
		extensionData.endObject();
		extensionData.save(U"extension.json");

		_allExtensions = { U"jpg",U"png",U"gif" };
	}
}

void ExtensionSelecter::setExtensions()
{
	_extensions.clear();
	//�`�F�b�N�������Ă���g���q���̗p
	for (size_t i = 0; i < _member; i++)
		if (_checkFlags[i] == true)
			_extensions.push_back(_allExtensions[i]);
}

ExtensionSelecter::ExtensionSelecter()
{
	//�g���q�t�@�C���̐ݒ�
	_extensionData.open(U"extension.json");

	loadExtensions();

	//�`�F�b�N�{�b�N�X�v�f�̏�����
	_member = _allExtensions.size();
	_checkFlags.resize(_member);

	setCheck();

	_reloadFlag = true;

	_extensionData.close();
}

void ExtensionSelecter::update()
{
	for (size_t i = 0; i < _member; i++)
		if (SimpleGUI::CheckBox(_checkFlags[i], _allExtensions[i], Vec2(MERGIN.x + SIZE.x * i, MERGIN.y), SIZE.x-MERGIN.x) == true)
		{
			setExtensions();	//�ǂꂩ�̊g���q�̗L�����ύX���ꂽ��g���q���X�V
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