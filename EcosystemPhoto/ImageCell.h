#pragma once
#include <Siv3d.hpp>

class ImageCell
{
private:
	TextureRegion _texture;	//サムネイル
	String _path;	//画像パス
	String _name;	//画像名前

	Rect _rect;	//一番外枠
	Rect _imageRect;	//画像枠
	Rect _nameRect;	//名前枠

	Point WINDOW_MERGIN = Point(16, 64);	//ウィンドウの余白
	Point CELL_MERGIN = Point(8, 8);	//セルの余白
	Point SIZE = Point(128, 128);	//大きさ

public:
	ImageCell();
	ImageCell(Point pos, String path);

	~ImageCell();

	void setTexture();	//画像の設定

	void draw();	//描画
};

