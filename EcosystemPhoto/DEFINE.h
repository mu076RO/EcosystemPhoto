#pragma once
#include <Siv3D.hpp>

Color backGloundColor(128, 128, 128);
size_t fontSize = 16;

Rect taskBar = Rect(Point(0, -64), Point(800, 128));	//タスクバー（被った画像セルを隠す）