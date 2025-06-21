# circom の基礎

このセクションでは、 [Tornado Cats の circom についての章](https://minaminao.github.io/tornado-cats/circuit/)を読み進めながら、いくつかの資料や演習を追加で確認していきます。

## circom の概要

Tornado Cats の[ゼロ知識証明の回路の基礎](https://minaminao.github.io/tornado-cats/circuit/)と [Circom とは](https://minaminao.github.io/tornado-cats/circuit/circom/)を読んでください。

## 環境構築

circom を利用するためには、主に circom コンパイラ本体と、証明生成・検証のための snarkjs 等のライブラリをセットアップする必要があります。

### circom と snarkjs のインストール

Circom 2 Documantation の [Installation](https://docs.circom.io/getting-started/installation/) を参考に circom をインストールしてください。

circom には rust が必要なことに注意してください。

### snarkjs のインストール

[snarkjs の GitHub の README](https://github.com/iden3/snarkjs) を参考に snarkjs をインストールしてください。

snarkjs には node.js の v18 以上が必要なことに注意してください。

## circom によるゼロ知識証明の流れ

この GitHub のリポジトリをローカルに `git clone` してください。もし、まだ環境構築が完了していない場合には、 GitHub Codespaces というクラウド環境で動かしてください。

GitHub Codespaces を使用する場合は、「<> Code 」ボタンを押した後 Codespaces タブに移動して、「 Create codespace on main 」ボタンを押してください。

環境が整ったら、Tornado Cats の 以下のページを読みながら、ご自身のローカル環境または Codespaces 上で一つずつ実際に手を動かしてみてください。
また、その際の作業ディレクトリは、 `/tornado-cats` になります。
事前に `cd` コマンドで移動してください。

### 回路の例:因数分解

[回路の例:因数分解（Tornado Cats）](https://minaminao.github.io/tornado-cats/circuit/factorization/)

### 回路のコンパイル

[回路のコンパイル（Tornado Cats）](https://minaminao.github.io/tornado-cats/circuit/compile/)

circom コマンドによるコンパイルのより詳しい各オプションの説明は、Circom 2 Documentation の [Compiling our circuit](https://docs.circom.io/getting-started/compiling-circuits/) を参照してください。

### Rank 1 Constraint System

[Rank 1 Constraint System（Tornado Cats）](https://minaminao.github.io/tornado-cats/circuit/r1cs/)

### ウィットネスの計算
[ウィットネスの計算（Tornado Cats）](https://minaminao.github.io/tornado-cats/circuit/witness-computation/)

### ゼロ知識証明のセットアップ

[ゼロ知識証明のセットアップ（Tornado Cats）](https://minaminao.github.io/tornado-cats/circuit/setup-zkp/)

snarkjs によるセットアップのより詳しい説明は、snarkjs の GitHub の README の [Guide](https://github.com/iden3/snarkjs/blob/master/README.md#guide) を参照してください。

### ゼロ知識証明の生成と検証

[ゼロ知識証明の生成と検証（Tornado Cats）](https://minaminao.github.io/tornado-cats/circuit/generation-and-verification/)

### コンパイルから検証までの流れを俯瞰する

![circom と snarkjs の流れ](circom_and_snarkjs.png)

*画像引用元: [Circom 2 Documentation - Visual summary](https://docs.circom.io/#visual-summary)*



## circom 言語の基本

### インポート

`include` : 外部のテンプレートをインポートする。

### 変数の宣言

`signal` : `signal input` の値によって変化する変数を定義する。
- 一度値が割り当てられると変更不可（immutable）
- コンパイル時には常に未知の値として扱われる
- 算術回路の一部となる

`var` : `signal input` の値によって変化しない変数を定義する。
- 制約生成時の計算に使用される
- 再代入可能（mutable）

### 代入演算子

**`<--`** : シグナルに値を代入する（制約は生成されない点に注意）

**`<==`** : シグナルに代入しつつ、両辺が等しいという制約を R1CS に追加する
- **推奨**: 代入と制約生成を同時に行うため安全。可能な限りこちらを使用すべき。



## コーディングにおける circom 特有の制限

circom のコードは算術回路などに変換された後、証明者と検証者に渡されるため、証明者から入力される `signal input` によって算術回路の構造を後から動的に変化させることはできません。
そのため、 `signal` は未知の値として定義されていて、 circom のコード内の算術回路の構造に影響を与えるような部分では、 `signal` の値を直接利用することができません。

### signal と 配列

配列のインデックスに signal を使用することはできません。
`array[signal_value]` のように、signal の値を用いて配列の要素を指定することは、動的な変更となってしまうためです。

### 分岐とループ

分岐やループの条件部分などで、例えば if 文で `signal` の値により分岐させたい場合には、どちらの分岐も計算され両方の和が計算されるものの、条件により分岐の片方の計算結果は 0 になるようにコードを書く必要があります。

### その他の制限

他の制限事項についても確認してみたい方は、[Circom 2 Documentation](https://docs.circom.io/) の The circom language を参照してください。

## circomlib の活用

circomlib は、よく使われる回路パターンをテンプレートとして提供するライブラリです。分岐やループを含む複雑な処理を、より簡単に記述できます。

### circomlib のインストール

circomlib は Node.js のパッケージとして提供されており、circom内 の `include` 文はプロジェクトの `node_modules` ディレクトリからライブラリを探すため、ローカルインストールが必要です。

`circomlib-test` ディレクトリに移動し、今回は npm コマンドを使用して、 circomlib をディレクトリ内にローカルインストールしてください。

これで circomlib のテンプレートを使用する準備が整いました。

### circomlib を使用したコンパイル時の注意

circomlib をインストールした後、circom でコンパイルする際には以下のようなエラーが発生することがあります：

```
error[P1000]: Include not found: circomlib/circuits/*.circom
```

このエラーは、circom コンパイラがデフォルトで `node_modules` ディレクトリを検索パスに含めていないために発生します。

circomlib を使用する際は、 `-l node_modules` (library) オプションを使用して `node_modules` ディレクトリを検索パスに追加してください。

### 主要なテンプレート

**比較器（Comparators）**
- `IsZero()`: 入力が 0 かどうかをチェック
- `IsEqual()`: 2つの入力が等しいかをチェック
- `LessThan(n)`: 2つの入力を比較して in[0] < in[1] かをチェック（n ビット以内の数値）
- `LessEqThan(n)`: 2つの入力を比較して in[0] <= in[1] かをチェック
- `GreaterThan(n)`: 2つの入力を比較して in[0] > in[1] かをチェック
- `GreaterEqThan(n)`: 2つの入力を比較して in[0] >= in[1] かをチェック

**ビット変換（Bit Operations）**
- `Num2Bits(n)`: 数値を n ビットの配列に変換
- `Bits2Num(n)`: n ビットの配列を数値に変換

**マルチプレクサ（Mux1 & Mux2）**
- `Mux1()`: 2つの入力から1つを選択
- `Mux2()`: 4つの入力から1つを選択

### 使用例

```circom
pragma circom 2.0.0;
include "circomlib/circuits/comparators.circom";
include "circomlib/circuits/mux1.circom";

template ConditionalAssignment() {
    signal input value;
    signal input threshold;
    signal output out;

    // value < threshold かをチェック（8ビット以内の数値）
    component lt = LessThan(8);
    lt.in[0] <== value;
    lt.in[1] <== threshold;

    // 条件に応じて異なる値を出力
    component mux = Mux1();
    mux.s <== lt.out;
    mux.c[0] <== 100; // value >= threshold の場合
    mux.c[1] <== 200; // value < threshold の場合

    out <== mux.out;
}
```

### circomlibjs

`circomlibjs` は、 `circomlib` の回路の witness を計算するための JavaScript ライブラリです。主に `circomlib` の回路をテストする際に使用されます。詳細については、[circomlibjs の GitHub リポジトリ](https://github.com/iden3/circomlibjs) を参照してください。

### TIPS
## デバッグ手法

circom では、回路開発時のデバッグを支援するいくつかの機能が提供されています。

### log 操作

`log` 操作を使用して、式の評価結果を標準エラー出力に表示できます。

```circom
log(135);
log(c.b);
log(x==y);
log("The expected result is ", 135, " but the value of a is", a);
```

詳細については、Circom2 Documantaion の 「[Debugging Operations](https://docs.circom.io/circom-language/code-quality/debugging-operations/)」 を参照してください。

### assert 文

`assert` 文を使用して、条件をチェックできます。コンパイル時に評価可能な場合はコンパイル時にチェックされ、そうでない場合は witness 生成時にチェックされます。

```circom
template A(n) {
  signal input in;
  assert(n>0);  // コンパイル時にチェック
  assert(in<=254);  // witness 生成時にチェック
}
```

詳細については、Circom2 Documantaion の 「[Code Assertion](https://docs.circom.io/circom-language/code-quality/code-assertion/)」 を参照してください。

### --inspect オプション

コンパイル時に `--inspect` オプションを使用すると、制約不足の可能性があるシグナルを検出できます。使用されていないシグナルがある場合は、`_` を使用して意図的であることを示すことができます。

```circom
template check_bits(n) {
  signal input in;
  component check = Num2Bits(n);
  check.in <== in;
  _ <== check.out;  // 出力を意図的に使用しないことを明示
}
```

詳細については、Circom2 Documantaion の 「[Improving security of circuits by using --inspect option](https://docs.circom.io/circom-language/code-quality/inspect/)」 を参照してください。

## 練習問題

### 1. 基本的な算術回路

二次方程式 `x^2 + bx + c = 0` の解を検証する回路を作成してください。

```circom
pragma circom 2.0.0;

template QuadraticEquation() {
    signal input x;      // 解の候補
    signal input b;      // 係数
    signal input c;      // 定数項
    
    // TODO: x が方程式の解であることを検証する制約を追加
}

component main = QuadraticEquation();
```

### 2. circomlib を使った条件分岐

入力が 0 以上 100 以下の範囲にあるかをチェックする回路を作成してください。

```circom
pragma circom 2.0.0;
include "circomlib/circuits/comparators.circom";

template RangeCheck() {
    signal input in;
    signal output valid;
    
    // TODO: circomlib のテンプレートを使用して範囲チェックを実装
    // ヒント: GreaterEqThan と LessEqThan を組み合わせて使用
}

component main = RangeCheck();
```

### 3. 配列操作の基本

3つの入力の最大値を出力する回路を作成してください。

```circom
pragma circom 2.0.0;

template Max3() {
    signal input in[3];
    signal output out;
    
    // TODO: 3つの入力の最大値を計算
    // ヒント: 条件分岐は使えないので、算術的な方法を考える
}

component main = Max3();
```

### 4. （オプション）ZKU Week2 の課題

もし余裕がある方は、ZKU Week 2 Assignment の「 Part 1 Hashes and Merkle Tree 」の 課題 2 と 3 を解いてみてください。（ Part 2 の Tornado Cash は別途解説があるため、スキップしてください。）

ページに遷移したら、Log in ではなく、 Access as a guest ボタンを押してください。

[ZKU Week 2 Assignment](https://zku.gnomio.com/mod/assign/view.php?id=119)


## 参考資料

### 基礎学習向け
-   [Tornado Cats](https://minaminao.github.io/tornado-cats/)
-   [circom101](https://circom.erhant.me/)

### 公式ドキュメント
-   [Circom 2 Documentation](https://docs.circom.io/)

### 実践的な内容
-   [core-program](https://github.com/ethereum/zket-core-program)
-   [learn.0xparc.org](https://learn.0xparc.org/)
-   [zkhack](https://zkhack.dev/)
-   [ZKU](https://zku.gnomio.com/course/view.php?id=8)

### ライブラリ・ツール
-   [circomlib](https://github.com/iden3/circomlib)
-   [circomlibjs](https://github.com/iden3/circomlibjs)
-   [snarkjs](https://github.com/iden3/snarkjs)
-   [zkrepl.dev](https://zkrepl.dev/)  （オンラインで circom を気軽に試せるプレイグラウンド）