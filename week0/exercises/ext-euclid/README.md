# ext-euclid

拡張ユークリッド互除法 (Extended Euclidean Algorithm) を計算する単純な Rust クレートです。

## 使い方

コマンドライン引数で2つの整数 a, b を与えて実行します。

```
cargo run -- <a> <b>
```

例:

```
$ cargo run -- 30 12
Result { d: 1, x: 1, y: 0, a: 1, b: 0 } [1 * 1 + 0 * 0 = 1]
Result { d: 1, x: 0, y: 1, a: 2, b: 1 } [2 * 0 + 1 * 1 = 1]
Result { d: 1, x: 1, y: -1, a: 3, b: 2 } [3 * 1 + 2 * -1 = 1]
Result { d: 1, x: -1, y: 7, a: 20, b: 3 } [20 * -1 + 3 * 7 = 1]
Result { d: 1, x: 7, y: -8, a: 23, b: 20 } [23 * 7 + 20 * -8 = 1]
Result { d: 1, x: -8, y: 7, a: 20, b: 23 } [20 * -8 + 23 * 7 = 1]
20 * -8 + 23 * 7 = 1
```
