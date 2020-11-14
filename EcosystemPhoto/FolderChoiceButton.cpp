#include "FolderChoiceButton.h"

FolderChoiceButton::FolderChoiceButton()
{
}

bool FolderChoiceButton::update(String* path, String base)
{
	bool reloadFlag = false;

	if (SimpleGUI::Button(U"brows", MERGIN, SIZE.x) == true)
	{
		Optional<String> newPath = Dialog::SelectFolder(*path, U"�t�H���_��I��");

		if (newPath.has_value() == true && newPath.value().includes(base) == true)
		{
			*path = newPath.value();
			reloadFlag = true;

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
