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
   signal output out[15]; // 変換後の出力配列、component muxMultipleOf15[arrayLength]を消して、ここをcomponet out[15]と宣言しても通る。

   var arrayLength = 15;

   // signal を定義
   component divRem3[arrayLength];
   component divRem5[arrayLength];
   component divRem15[arrayLength];
   
   component isMultipleOf3[arrayLength];
   component isMultipleOf5[arrayLength];
   component isMultipleOf15[arrayLength];

   component muxMultipleOf3[arrayLength];
   component muxMultipleOf5[arrayLength];
   component muxMultipleOf15[arrayLength];

   // signal multipleOf3_convertResult[arrayLength]; // Mux1使わない場合
   // signal multipleOf5_convertResult[arrayLength]; // Mux１使わない場合

   for (var i = 0; i < arrayLength; i++) {
      var num = array[i];
      log("=== ", num, " ===");

      // ロジックを実装
      divRem3[i] = DivRem(3, 8); // 3で割る回路
      divRem5[i] = DivRem(5, 8); // 5で割る回路
      divRem15[i] = DivRem(15, 8); // 15で割る回路

      // 被除数に配列の値を接続
      divRem3[i].dividend <== num;
      divRem5[i].dividend <== num;
      divRem15[i].dividend <== num;

      // log("quotient:", divRem3[i].quotient, "remainder:", divRem3[i].remainder);
      // log("quotient:", divRem5[i].quotient, "remainder:", divRem5[i].remainder);
      // log("quotient:", divRem15[i].quotient, "remainder:", divRem15[i].remainder);

      isMultipleOf3[i] = IsZero(); // 3で割った余りが0かどうかを判定する回路
      isMultipleOf3[i].in <== divRem3[i].remainder;

      isMultipleOf5[i] = IsZero(); // 5で割った余りが0かどうかを判定する回路
      isMultipleOf5[i].in <== divRem5[i].remainder;

      isMultipleOf15[i] = IsZero(); // 15で割った余りが0かどうかを判定する回路
      isMultipleOf15[i].in <== divRem15[i].remainder;

      // fizzbuzzのルールに従って、ログを出力
      if(isMultipleOf15[i].out) { // if(isMultipleOf15[i].out === 1)だと通らない。また、条件が未知で、ブロック内で制約生成に影響する処理があると通らない。
         log("FizzBuzz");
      } else if(isMultipleOf5[i].out) { // if(isMultipleOf5[i].out === 1)だと通らない。また、条件が未知で、ブロック内で制約生成に影響する処理があると通らない。
         log("Buzz");
      }else if(isMultipleOf3[i].out) { // if(isMultipleOf3[i].out === 1)だと通らない。また、条件が未知で、ブロック内で制約生成に影響する処理があると通らない。
         log("Fizz");
      }

      // fizzbuzzのルールに従って、配列の値を変換
      // 3で割り切れる場合は3333に変換
      muxMultipleOf3[i] = Mux1();
      muxMultipleOf3[i].c[0] <== num;
      muxMultipleOf3[i].c[1] <== 3333;
      muxMultipleOf3[i].s <== isMultipleOf3[i].out;

      // 5で割り切れる場合は5555に変換
      muxMultipleOf5[i] = Mux1();
      muxMultipleOf5[i].c[0] <== muxMultipleOf3[i].out;
      muxMultipleOf5[i].c[1] <== 5555;
      muxMultipleOf5[i].s <== isMultipleOf5[i].out;

      // 15で割り切れる場合は1515に変換
      muxMultipleOf15[i] = Mux1();
      muxMultipleOf15[i].c[0] <== muxMultipleOf5[i].out;
      muxMultipleOf15[i].c[1] <== 1515;
      muxMultipleOf15[i].s <== isMultipleOf15[i].out;

      out[i] <== muxMultipleOf15[i].out;

      // Mux1を使わない場合
      // out[i] <== isMultipleOf15[i]*1515 + (1 - isMultipleOf15[i])*(isMultipleOf5[i]*5555 + (1 - isMultipleOf5[i])*(isMultipleOf3[i]*3333 + (1 - isMultipleOf3[i])*num));
      // multipleOf3_convertResult[i] <== isMultipleOf3[i].out * 3333 + (1 - isMultipleOf3[i].out) * num; // 3で割り切れる場合は3333に変換
      // multipleOf5_convertResult[i] <== isMultipleOf5[i].out * 5555 + (1 - isMultipleOf5[i].out) * multipleOf3_convertResult[i]; // 5で割り切れる場合は5555に変換
      // out[i] <== isMultipleOf15[i].out * 1515 + (1 - isMultipleOf15[i].out) * multipleOf5_convertResult[i]; // 15で割り切れる場合は1515に変換
      
      // log("out[", i, "] :", out[i]);
   }

   log("============");

   // for (var i = 0; i < arrayLength; i++) {
   //    log("out[", i, "] :", "previous value:",array[i],"converted value:", out[i]);
   // }
}

// FizzBuzzテンプレートをmainコンポーネントとしてインスタンス化
component main = FizzBuzz();

/*
メモ：コマンド
circom fizzbuzz.circom --r1cs --wasm --sym --c
node fizzbuzz_js/generate_witness.js fizzbuzz_js/fizzbuzz.wasm input.json witness.wtns
*/