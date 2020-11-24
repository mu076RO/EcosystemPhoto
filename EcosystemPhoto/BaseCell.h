#pragma once
#include <Siv3d.hpp>
#include <windows.h>
#include "DEFINE.h"

class BaseCell
{
protected:
	TextureRegion _texture;	//サムネイル
	FilePath _path;	//画像パス
	String _name;	//画像名前

	Rect _rect;	//一番外枠
	Rect _imageRect;	//画像枠
	Rect _nameRect;	//名前枠
	double _scrollY;	//スクロールしたy数値

	Point WINDOW_MERGIN = Point(16, 64);	//ウィンドウの余白
	Point IMAGE_MERGIN = Point(8, 8);	//セルの余白
	Point SIZE = Point(128, 128);	//大きさ

public:
	BaseCell();
	BaseCell(Point pos, String path);

	virtual ~BaseCell();

	void setScroll(double scroll);	//スクロール値の反映
	virtual void setTexture() {};
	void reshapeTexture();	//画像の設定

	virtual void update();
	void draw();	//描画

	double bottomY();	//底辺を取得
	FilePath path();
	virtual bool reloadFlag();
};

