#pragma once
#include <Siv3D.hpp>

class CheckBoxLine
{
private:
	Array<String> _extensions;
	Array<bool> _checkFlags;
	int _member;

	Array<String> _validExtensions;

	const Point MERGIN = Point(16, 16);
	const Point SIZE = Point(96, 32);

public:
	CheckBoxLine();

	void setValidExtensions(Array<String>* extensions);

	bool update(Array<String>* extensions);	//reload‚·‚é‚Æ‚«true

	Array<String> extensions();


};
