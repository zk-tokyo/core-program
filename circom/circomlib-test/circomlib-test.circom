pragma circom 2.1.2;

// TODO: circomlibから comparators.circom をインクルードして `IsZero` コンポーネントにアクセスしてください

template Multiplier2Alt () {
  signal input a;
  signal input b;
  signal output c;

  // TODO: `IsZero` コンポーネントを宣言してください
  // TODO: a または b のいずれかが1の場合、その `in` への入力は0になるようにしてください
  // TODO: 出力 `out` が0（false）であることを確認してください

  c <== a * b;
}

component main = Multiplier2Alt();