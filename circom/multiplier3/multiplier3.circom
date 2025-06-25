pragma circom 2.1.2;

// 回路の定義
template Multiplier3 () {  

   // シグナルの宣言
   signal input a;
   signal input b;
   signal input c;
   signal output d;

   // 制約
   tmp <== a * b;
   d <== tmp * c;
}

// インスタンス化
component main = Multiplier3();