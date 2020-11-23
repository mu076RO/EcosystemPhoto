#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "DEFINE.h"
#include "ExtensionSelecter.h"
#include "ImageCell.h"
#include "FolderSelecter.h"
#include "ScrollPage.h"

//設定ファイルをフォルダに入れる

//画像セルの行数と列数
const size_t LINENUM = 6;
const size_t ROWNUM = 5;

const size_t MAXROWNUM = 10;

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
	ini();	//その他初期化処理

	ExtensionSelecter extensionSelecter;	//チェックボックス列
	extensions = extensionSelecter.extensions();	//有効な拡張子の初期化

	FolderSelecter folderChoice;	//ブラウズボタン
	path = folderChoice.path();	//カレントパスの初期化

	loadCell();

	while (System::Update())
	{
		//更新処理
		if (extensionSelecter.reloadFlag() == true)	//拡張子設定が変更されたら
		{
			extensions = extensionSelecter.extensions();
			loadCell();
		}

		if (folderChoice.reloadFlag())	//パスが変更されたら
		{
			path = folderChoice.path();
			loadCell();
		}

		scroll.update();

		for (auto& cell : cells)
		{
			if (DEFINE::taskBar.mouseOver() != true)	//タスクバー上にマウスがない
				cell.update();	//画像ビューの呼び出し

			cell.setScroll(scroll.scroll());
		}

		//画像の順次ロード
		if (cellIndex < cells.size())
		{
			loadImage(cellIndex);
			cellIndex++;
		}

		//描画
		for (auto& cell : cells)
			cell.draw();
		DEFINE::taskBar.draw(DEFINE::backGloundColor);

		//UI描画
		extensionSelecter.update();
		folderChoice.update();
	}
}

void ini()
{
	Scene::SetBackground(DEFINE::backGloundColor);
	Window::SetTitle(U"EcosystemPhoto");

	FontAsset::Register(U"16", DEFINE::fontSize);	//フォントを用意

	if (FileSystem::Exists(DEFINE::DATAFOLDERPATH) != true || FileSystem::IsDirectory(DEFINE::DATAFOLDERPATH) != true)
	{
		System::ShowMessageBox(U"以下のディレクトリに設定フォルダを作成します。\n" + FileSystem::CurrentDirectory());
		FileSystem::CreateDirectories(DEFINE::DATAFOLDERPATH);
	}
}

void loadCell()
{
	photoPaths.clear();
	size_t cellNum = 0;
	//再帰的にpath以下の全ファイルを捜査
	for (auto& child : FileSystem::DirectoryContents(path, true))
	{
		//拡張子が一致したら同じ
		if (extensions.includes(FileSystem::Extension(child)) == true || FileSystem::IsDirectory(child) == true)
		{
			photoPaths.push_back(child);
			cellNum++;
		}

		if (cellNum == MAXROWNUM * LINENUM)
		{
			MessageBoxSelection select = System::ShowMessageBox(U"読み込んだ方向が制限値を超えました。\n" + Format(MAXROWNUM * LINENUM) + U"項目目以降もロードしますか？",MessageBoxButtons::YesNo);
			if (select == MessageBoxSelection::No)
				break;
		}
	}

	//パスを基にセルを作成
	cells.clear();
	cellIndex = 0;
	for (size_t row = 0; row < photoPaths.size(); row++)
		if (extensions.includes(FileSystem::Extension(photoPaths[row])) == true)
			cells.push_back(ImageCell(Point(row % LINENUM, row / LINENUM), photoPaths[row], false));
		else
			cells.push_back(ImageCell(Point(row % LINENUM, row / LINENUM), photoPaths[row], true));

	//スクロール下限値の設定
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
