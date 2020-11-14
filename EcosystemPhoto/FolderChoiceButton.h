#pragma once
#include <Siv3D.hpp>

class FolderChoiceButton
{
private:
	const Point MERGIN = Point(800-96-16, 16);
	const Point SIZE = Point(96, 32);

public:
	FolderChoiceButton();

	bool update(String* path);
};

