#pragma once
#include <Siv3D.hpp>

namespace DEFINE
{
	const Color backGloundColor(128, 128, 128);
	const size_t fontSize = 16;

	const Rect taskBar = Rect(Point(0, -64), Point(800, 128));	//タスクバー（被った画像セルを隠す）

	const FilePath DATAFOLDERPATH = U".ecosystem.data/";
}