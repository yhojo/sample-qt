# CMakeによるQtサンプルアプリ

Qtのアプリケーション開発用のひな形コード。

Google Testによるユニット・テスト付き

buildディレクトリを作成後、下記の様にMakefileを生成してビルド出来ます。Qtのインストールパスは環境に合わせて読み替えて下さい。

```
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_PREFIX_PATH=/usr/local/opt/qt5
```

CLionにインポートする場合にはメニューからPreferences->Build,Execution,Deployment->CMakeにあるEnvironmentに下記の設定を追加して下さい。Qtのインストールパスは環境に合わせて読み替えて下さい。

```
CMAKE_PREFIX_PATH=/usr/local/opt/qt5
```
