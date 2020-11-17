#pragma once
#include <Siv3d.hpp>
#include <windows.h>

class ImageCell
{
private:
	TextureRegion _texture;	//サムネイル
	String _path;	//画像パス
	String _name;	//画像名前

	Rect _rect;	//一番外枠
	Rect _imageRect;	//画像枠
	Rect _nameRect;	//名前枠
	double _scrollY;	//スクロールしたy数値

	Point WINDOW_MERGIN = Point(16, 64);	//ウィンドウの余白
	Point CELL_MERGIN = Point(8, 8);	//セルの余白
	Point SIZE = Point(128, 128);	//大きさ

public:
	ImageCell();
	ImageCell(Point pos, String path);

	~ImageCell();

	void setScroll(double scroll);	//スクロール値の反映
	void setTexture();	//画像の設定

	void update();
	void draw();	//描画

	double bottomY();	//底辺を取得
};

