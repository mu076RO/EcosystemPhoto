#include "FolderSelecter.h"

void FolderSelecter::loadPath()
{
	//�p�X�t�@�C���̓ǂݍ���
	JSONReader pathData(U"path.json");
	//�p�X�t�@�C��������ꍇ
	if (pathData.isEmpty() != true)
	{
		_basePath = pathData[U"base"].getString();
		_path = pathData[U"current"].getString();
	}
	//�p�X�t�@�C�����Ȃ��ꍇ
	else
	{
		//���݃p�X�A���p�X�Ƃ��Ɏ��s�t�@�C���̈ʒu���w��
		FilePath currentPath = FileSystem::CurrentDirectory();
		_basePath = currentPath;
		_path = currentPath;

		//json�t�@�C�����쐬
		JSONWriter pathData;
		pathData.startObject();
		{
			pathData.key(U"base").writeString(_basePath);
			pathData.key(U"current").writeString(_path);
		}
		pathData.endObject();
		pathData.save(U"path.json");
	}
}

FolderSelecter::FolderSelecter()
{
	loadPath();

	_reloadFlag = false;
}

void FolderSelecter::update()
{
	if (SimpleGUI::Button(U"brows", MERGIN, SIZE.x) == true)
	{
		Optional<String> newPath = Dialog::SelectFolder(_path, U"�t�H���_��I��");

		if (newPath.has_value() == true)	//���t�H���_�ȉ��ł���
		{
			if (newPath.value().includes(_basePath) == true)
			{
				_path = newPath.value();
				_reloadFlag = true;

				//json�t�@�C���̍X�V
				JSONWriter pathData;
				pathData.startObject();
				{
					pathData.key(U"base").writeString(_basePath);
					pathData.key(U"current").writeString(_path);
				}
				pathData.endObject();
				pathData.save(U"path.json");

				_reloadFlag = true;
			}
			else
				System::ShowMessageBox(U"���s�t�@�C������ʂ̃f�B���N�g���͎w��ł��܂���");
		}
	}
}

bool FolderSelecter::reloadFlag()
{
	return _reloadFlag;
}

FilePath FolderSelecter::path()
{
	_reloadFlag = false;
	return _path;
}
