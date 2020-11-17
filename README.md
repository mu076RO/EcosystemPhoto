# EcosystemPhoto

## 概要
生物の画像を分類分けする画像ビューア

## リンクとか
[ダウンロード（EcosystemPhoto.v1）](Release/EcosystemPhoto.v1)<br>
[仕様書ダウンロード（readme.txt）](Release/readme.txt)

## 仕様説明

### 操作説明

- 拡張子選択欄<br>
  - チェックを付けた拡張子の画像が表示されます。（バージョンアップによって拡張子追加ができる機能を実装する予定です。）
- 「brows」ボタン<br>
  - クリックすることでフォルダ選択画面が開きます。選択したフォルダ下にある画像を表示します。
- 画像サムネイル<br>
  - クリックすることで、デフォルトに設定されているビューアーで画像を開きます。
### 注意事項
- 「brows」が反応しない<br>
  - 安全のため、初期フォルダより上の階層のフォルダは開けないようになっています。列挙したい画像があるフォルダより上の階層でもう一度アプリケーションを実行してください。
- jsonファイルについて<br>
  - jsonファイルは、各種設定を記述したファイルです。消去した場合設定が初期化されます。また、書き換えた場合の動作は保証しかねます。
  ### 権利等
- 制作:		ムゥビィ<br>
- 使用エンジン:	Siv3D(https://siv3d.github.io/ja-jp/)<br>

- 当アプリケーションによって生じた障害等について、保証はしかねます。<br>
- 動作不良・バグなどに関しては、制作者Twitter([@]movie_murby)までご報告ください。<br>

## リリースノート
- 20201117:バージョン1リリース
- 20201112:プロジェクト開始
