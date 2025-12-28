pragma circom 2.1.2;

// 回路の定義
template Multiplier2 () {

   // TODO: シグナルを宣言する
   signal input a;
   signal input b;
   signal output c;

   // TODO: 制約をつける
   c <== a * b;
}

// TODO: インスタンス化する
component main = Multiplier2();