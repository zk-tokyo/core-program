pragma circom 2.1.2;

template Multiplier3 () {

   signal input a;
   signal input b;
   signal input c;
   signal output d;

   signal tmp;  // 3つ以上の掛け算には一時的な変数が必要
   tmp <== a * b;
   d <== tmp * c;
}

component main = Multiplier3();