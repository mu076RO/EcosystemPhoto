#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "CheckBoxLine.h"
#include "ImageCell.h"
#include "FolderChoiceButton.h"

const int LINENUM = 6;

void reload();

FilePath path = U"C:/Users/okamu/Desktop";	//捜査パスの初期位置
Array<String> extensions;
Array<String> photoPaths;	//結果を格納

Array<ImageCell> cells;

void Main()
{
	Scene::SetBackground(Color(0, 255, 255));

	FontAsset::Register(U"16", 16);	//フォントを用意

	CheckBoxLine checkBoxes;
	FolderChoiceButton folderChoice;

	reload();

	while (System::Update())
	{
		if (checkBoxes.update(&extensions) == true)
			reload();
		if (folderChoice.update(&path) == true)
			reload();

		for (auto& cell : cells)
			cell.draw();
	}
}

void reload()
{
	photoPaths.clear();
	//再帰的にpath以下の全ファイルを捜査
	for (auto& child : FileSystem::DirectoryContents(path, /*true*/false))
	{
		if (extensions.includes(FileSystem::Extension(child)) == true)
			photoPaths.push_back(child);
	}

	cells.clear();
	for (size_t row = 0; row < photoPaths.size(); row++)
		cells.push_back(ImageCell(Point(row % LINENUM, row / LINENUM), photoPaths[row]));
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
