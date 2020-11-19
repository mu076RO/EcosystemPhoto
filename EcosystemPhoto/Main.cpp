#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include <future>
#include <chrono>
#include "ExtensionSelecter.h"
#include "ImageCell.h"
#include "FolderSelecter.h"
#include "ScrollPage.h"

//セル周りの描画の軽量化

//画像セルの行数と列数
const int LINENUM = 6;
const int ROWNUM = 5;

void ini();	//初期化
void loadCell();	//セルのロード
void loadImage(size_t index);

FilePath path;	//現在パス
Array<String> extensions;	//有効な拡張子
Array<String> photoPaths;	//結果を格納

Array<ImageCell> cells;	//画像セル
size_t cellIndex;

ScrollPage scroll;

void Main()
{
	ExtensionSelecter extensionSelecter;	//チェックボックス列
	FolderSelecter folderChoice;	//ブラウズボタン

	extensions = extensionSelecter.extensions();
	path = folderChoice.path();

	ini();

	while (System::Update())
	{
		//更新処理
		if (extensionSelecter.reloadFlag() == true)
		{
			extensions = extensionSelecter.extensions();
			loadCell();
		}

		if (folderChoice.reloadFlag())
		{
			path = folderChoice.path();
			loadCell();
		}

		scroll.update();

		for (auto& cell : cells)
			cell.update();

		for (auto& cell : cells)
			cell.setScroll(scroll.scroll());

		//画像の順次ロード
		if (cellIndex < cells.size())
		{
			loadImage(cellIndex);
			cellIndex++;
		}

		//描画
		for (auto& cell : cells)
			cell.draw();
		Rect(Point(0, 0), Point(800, 64)).draw(Color(128, 128, 128));

		//UI描画
		extensionSelecter.update();
		folderChoice.update();
	}
}

void ini()
{
	Scene::SetBackground(Color(128, 128, 128));

	FontAsset::Register(U"16", 16);	//フォントを用意

	loadCell();
}

void loadCell()
{
	photoPaths.clear();
	//再帰的にpath以下の全ファイルを捜査
	for (auto& child : FileSystem::DirectoryContents(path, true))
	{
		//拡張子が一致したら同じ
		if (extensions.includes(FileSystem::Extension(child)) == true)
		{
			photoPaths.push_back(child);
		}
	}

	//パスを基にセルを作成
	cells.clear();
	cellIndex = 0;
	for (size_t row = 0; row < photoPaths.size(); row++)
		cells.push_back(ImageCell(Point(row % LINENUM, row / LINENUM), photoPaths[row]));

	if(cells.size() != 0)
		scroll.reset(cells[cells.size() - 1].bottomY());
}

void loadImage(size_t index)
{
	cells[index].setTexture();
}

//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
// = お役立ちリンク =
//
// OpenSiv3D リファレンス
// https://siv3d.github.io/ja-jp/
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/basic/
//
// よくある間違い
// https://siv3d.github.io/ja-jp/articles/mistakes/
//
// サポートについて
// https://siv3d.github.io/ja-jp/support/support/
//
// Siv3D ユーザコミュニティ Slack への参加
// https://siv3d.github.io/ja-jp/community/community/
//
// 新機能の提案やバグの報告
// https://github.com/Siv3D/OpenSiv3D/issues
//
