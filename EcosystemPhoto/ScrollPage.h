#pragma once
#include <Siv3D.hpp>

class ScrollPage
{
private:
	double _scroll;	//スクロールしたy座標
	double _bottomY;	//スクロールの下限

	const double SPEED;	//スクロール速度

public:
	ScrollPage();

	void reset(double bottomY);	//下限の設定
	void update();	//更新

	double scroll();	//スクロール値の取得
};
