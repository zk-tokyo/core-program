pragma circom 2.1.2;

include "node_modules/circomlib/circuits/comparators.circom";
include "node_modules/circomlib/circuits/mux1.circom";

// divisorで割った商と余りを計算するテンプレート
// nBits は、比較する数値のビット数を指定
template DivRem(divisor, nBits) {
    signal input dividend;
    signal output quotient;
    signal output remainder;

    // \ (除算) と % (剰余) 演算は、R1CSに直接変換できない非二次制約です。
    // そのため、まずwitness計算機に商と余りの計算方法を指示します。
    quotient <-- dividend \ divisor;
    remainder <-- dividend % divisor;

    // ここでは、上で計算した商と余りが正しいことを確認するための制約を追加しています。
    // `dividend = divisor * quotient + remainder` という関係が満たされているかをチェックします。
    // この式は二次形式（A * B + C = 0）であるため、R1CS制約として有効です。
    divisor * quotient + remainder === dividend;

    // さらに、余りが除数より小さい(remainder < divisor)ことも制約として追加する必要があります。
    // この制約がないと、`dividend = divisor * quotient + remainder` を満たす商と余りの組み合わせが
    // 一意に定まらないためです。(例: 10 = 3 * 2 + 4 など、不正な組み合わせも許されてしまう)
    component lt = LessThan(nBits);
    lt.in[0] <== remainder;
    lt.in[1] <== divisor;
    lt.out === 1; // lt.outが1であることを強制し、remainder < divisor を保証
}

// FizzBuzzのロジックを実装し、ルールに従って配列の値を変換する回路
template FizzBuzz () {
   signal input array[15]; // 15個の数値の入力配列
   signal output out[15]; // 変換後の出力配列

   var arrayLength = 15;

   // signal を定義
   component divRem3[arrayLength];
   component divRem5[arrayLength];
   component divRem15[arrayLength];

   component isFizzs[arrayLength];
   component isBuzzs[arrayLength];
   component isFizzBuzzs[arrayLength];

   component muxFizzs[arrayLength];
   component muxBuzzs[arrayLength];
   component muxFizzBuzzs[arrayLength];


   for (var i = 0; i < arrayLength; i++) {
      var num = array[i];
      log("=== ", num, " ===");

      // ロジックを実装
      divRem3[i] = DivRem(3, 4);
      divRem3[i].dividend <== num;

      divRem5[i] = DivRem(5, 4);
      divRem5[i].dividend <== num;

      divRem15[i] = DivRem(15, 4);
      divRem15[i].dividend <== num;

      isFizzs[i] = IsZero();
      isBuzzs[i] = IsZero();
      isFizzBuzzs[i] = IsZero();

      isFizzs[i].in <== divRem3[i].remainder;
      isBuzzs[i].in <== divRem5[i].remainder;
      isFizzBuzzs[i].in <== divRem15[i].remainder;

      muxFizzs[i] = Mux1();
      muxBuzzs[i] = Mux1();
      muxFizzBuzzs[i] = Mux1();

      muxFizzs[i].s <== isFizzs[i].out;
      muxFizzs[i].c[0] <== num;
      muxFizzs[i].c[1] <== 3333;

      muxBuzzs[i].s <== isBuzzs[i].out;
      muxBuzzs[i].c[0] <== muxFizzs[i].out;
      muxBuzzs[i].c[1] <== 5555;

      muxFizzBuzzs[i].c[0] <== muxBuzzs[i].out;
      muxFizzBuzzs[i].c[1] <== 1515;
      muxFizzBuzzs[i].s <== isFizzBuzzs[i].out;
      out[i] <== muxFizzBuzzs[i].out;

      // デバッグ用にログを出力
      if (isFizzBuzzs[i].out) {
         log("FizzBuzz");
      } else if (isFizzs[i].out) {
         log("Fizz");
      } else if (isBuzzs[i].out) {
         log("Buzz");
      } else {
         log(num);
      }

      log("out:", out[i]);
   }

   log("============");
}

// FizzBuzzテンプレートをmainコンポーネントとしてインスタンス化
component main = FizzBuzz();