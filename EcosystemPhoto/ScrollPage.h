#pragma once
#include <Siv3D.hpp>

class ScrollPage
{
private:
	int _scroll;	//スクロールしたy座標
	int _bottomY;	//スクロールの下限

	const int SPEED;	//スクロール速度
	const int SCROLL_MERGIN;

public:
	ScrollPage();

	void reset(int bottomY);	//下限の設定
	void update();	//更新

	int scroll();	//スクロール値の取得
};
