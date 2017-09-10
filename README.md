# ACPC 2017
## これ何？
立命の有志(OB含む)によるプログラミングコンテストの準備プロジェクトです.

## 環境構築
必要なもの

* Git
* Rime (作問ツール)
  * Python2 (Rimeの実行に必要)
* コード実行に使う各言語の処理系 (必要に応じてgcc, g++, javaなど)

### Gitのインストール
aptやyumなどのパッケージマネージャーでインストールできます.
```
$ sudo apt-get install git
```

### Python2のインストール
まずPython2が既にインストールされているか確認します.
```
$ python -V
Python 2.7.13
```
コマンドが存在しないまたはバージョンが2.\*.\*でない場合はpyenvなどを使ってインストールします.
```
$ cd acpc2017
$ pyenv install 2.7.13
$ pyenv rehash
$ pyenv local 2.7.13
```

### Rimeのインストール
pipを用いてインストールします.

```
$ pip install git+https://github.com/icpc-jag/rime
```

インストールに成功したか確認します.
```
$ rime
rime.py <command> [<options>...] [<args>...]

    Rime is a tool for programming contest organizers to automate usual, boring
    and error-prone process of problem set preparation. It supports various
    programming contest styles like ACM-ICPC, TopCoder, etc. by plugins.

    To see a brief description and available options of a command, try:

    rime.py help <command>
(略)
```


テストが走ることを確認します.
```
$ rime test
[ COMPILE  ] A+B/tests: generator.cc
[ COMPILE  ] A+B/tests: validator.cc
[ GENERATE ] A+B/tests: generator.cc
(略)
```

## リンク

- [作問ツールの使い方](https://drive.google.com/file/d/0B8nawKhBgu7IV0hTcnNMUEhqb2c/view?usp=sharing)
- [Rime 1.0 documentation](http://rime.readthedocs.io/ja/latest/)
- [testlib](http://codeforces.com/testlib)
- [競技プログラミングの作問進行法](http://itohjam.hatenablog.com/entry/2014/12/02/214019)
