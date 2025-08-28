pragma circom 2.1.2;

// 回路の定義
template Multiplier3() {
    signal input a;
    signal input b;
    signal input c;
    signal output d;
    signal e;

    e <== a * b;
    d <== e * c;
}

// インスタンス化
component main = Multiplier3();