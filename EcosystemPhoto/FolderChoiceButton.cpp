#include "FolderChoiceButton.h"

FolderChoiceButton::FolderChoiceButton()
{
}

bool FolderChoiceButton::update(String* path)
{
	bool reloadFlag = false;

	if (SimpleGUI::Button(U"brows", MERGIN, SIZE.x) == true)
	{
		Optional<String> newPath = Dialog::SelectFolder(*path, U"フォルダを選択");

		if (newPath.has_value() == true && newPath.value().includes(U"C:/Users/okamu/Desktop") == true)
		{
			*path = newPath.value();
			reloadFlag = true;
		}	
	}

	return false;
}
