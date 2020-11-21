#include "FolderSelecter.h"

void FolderSelecter::loadPath()
{
	//パスファイルの読み込み
	JSONReader pathData(DEFINE::DATAFOLDERPATH + U"/path.json");
	//パスファイルがある場合
	if (pathData.isEmpty() != true)
	{
		_basePath = pathData[U"base"].getString();
		_path = pathData[U"current"].getString();
	}
	//パスファイルがない場合
	else
	{
		//現在パス、基底パスともに実行ファイルの位置を指定
		FilePath currentPath = FileSystem::CurrentDirectory();
		_basePath = currentPath;
		_path = currentPath;

		//jsonファイルを作成
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
		Optional<String> newPath = Dialog::SelectFolder(_path, U"フォルダを選択");

		if (newPath.has_value() == true)
		{
			MessageBoxSelection select = MessageBoxSelection::No;
			if (newPath.value().includes(_basePath) != true)	//基底フォルダ以下でない
				select = System::ShowMessageBox(U"実行ファイルより上位のフォルダを指定しています。\n開いてもよろしいですか？", MessageBoxButtons::YesNo);
			
			if (newPath.value().includes(_basePath) == true || select == MessageBoxSelection::Yes)
			{
				_path = newPath.value();
				_reloadFlag = true;

				//jsonファイルの更新
				JSONWriter pathData;
				pathData.startObject();
				{
					pathData.key(U"base").writeString(_basePath);
					pathData.key(U"current").writeString(_path);
				}
				pathData.endObject();
				pathData.save(DEFINE::DATAFOLDERPATH + U"/path.json");

				_reloadFlag = true;
			}
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
