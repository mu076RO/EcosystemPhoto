#include "FolderChoiceButton.h"

FolderChoiceButton::FolderChoiceButton()
{
}

bool FolderChoiceButton::update(String* path, String base)
{
	bool reloadFlag = false;

	if (SimpleGUI::Button(U"brows", MERGIN, SIZE.x) == true)
	{
		Optional<String> newPath = Dialog::SelectFolder(*path, U"フォルダを選択");

		if (newPath.has_value() == true && newPath.value().includes(base) == true)	//基底フォルダ以下である
		{
			*path = newPath.value();
			reloadFlag = true;

			//jsonファイルの更新
			JSONWriter pathData;
			pathData.startObject();
			{
				pathData.key(U"base").writeString(base);
				pathData.key(U"current").writeString(*path);
			}
			pathData.endObject();
			pathData.save(U"path.json");
		}	
	}

	return reloadFlag;
}
