#include <Siv3D.hpp> // OpenSiv3D v0.4.3

void Main()
{
	Scene::SetBackground(Color(255, 255, 255));

	const Font font(16);	//フォントを用意

	FilePath path = U"C:/Users/okamu/Desktop";	//捜査パスの初期位置
	Array<String> photoPaths;	//結果を格納

	JSONReader extensionData(U"extension.json");
	Array<String> extensions;

	if (extensionData.isEmpty() != true)
	{
		extensions = extensionData[U"extension"].getArray<String>();
	}

	//再帰的にpath以下の全ファイルを捜査
	for (auto& child : FileSystem::DirectoryContents(path, /*true*/false))
	{
		child = FileSystem::FileName(child);	//.pngファイルを格納
		if (extensions.includes(FileSystem::Extension(child)) == true)
			photoPaths.push_back(child);
	}

	while (System::Update())
	{
		for (size_t row = 0; row < photoPaths.size(); row++)	//列挙
			font(photoPaths[row]).draw(Point(0, 16 * row), Palette::Black);
	}
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
