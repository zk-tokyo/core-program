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
   component divRem3[15];
   component divRem5[15];
   component isMultipleOf3[15];
   component isMultipleOf5[15];

   signal fizz[15];
   signal buzz[15];
   signal fizzbuzz[15];
   signal none[15];

   for (var i = 0; i < arrayLength; i++) {
      var num = array[i];
      log("=== ", num, " ===");

      // ロジックを実装
      divRem3[i] = DivRem(3, 4);
      isMultipleOf3[i] = IsZero();
      divRem3[i].dividend <== num;
      isMultipleOf3[i].in <== divRem3[i].remainder;

      divRem5[i] = DivRem(5, 4);
      isMultipleOf5[i] = IsZero();
      divRem5[i].dividend <== num;
      isMultipleOf5[i].in <== divRem5[i].remainder;

      fizzbuzz[i] <== isMultipleOf3[i].out * isMultipleOf5[i].out;
      fizz[i] <== isMultipleOf3[i].out * (1 - isMultipleOf5[i].out);
      buzz[i] <== (1 - isMultipleOf3[i].out) * isMultipleOf5[i].out;
      none[i] <== (1 - isMultipleOf3[i].out) * (1 - isMultipleOf5[i].out);

      if(fizzbuzz[i] == 1) {
         log("FizzBuzz");
      } else if(fizz[i] == 1) {
         log("Fizz");
      } else if(buzz[i] == 1) {
         log("Buzz");
      }
      out[i] <== 1515 * fizzbuzz[i]
               + 3333 * fizz[i]
               + 5555 * buzz[i]
               + num * none[i];
   }

   log("============");
}

// FizzBuzzテンプレートをmainコンポーネントとしてインスタンス化
component main = FizzBuzz();