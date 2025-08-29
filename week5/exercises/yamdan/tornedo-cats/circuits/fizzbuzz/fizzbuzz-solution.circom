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

   // ループ内で使用するコンポーネントを配列として宣言
   // circomではループ内でコンポーネントを宣言できないため、先に配列で用意しておく
   component divRem3[arrayLength];
   component divRem5[arrayLength];
   component divRem15[arrayLength];

   component isFizzs[arrayLength];
   component isBuzzs[arrayLength];
   component isFizzBuzzs[arrayLength];

   component muxFizzs[arrayLength];
   component muxBuzzs[arrayLength];
   component muxFizzBuzzs[arrayLength];

   // 配列の各要素をループで処理
   for (var i = 0; i < arrayLength; i++) {
      var num = array[i];
      log("=== ", num, " ===");

      // 3, 5, 15 で割った余りを計算
      divRem3[i] = DivRem(3, 4);
      divRem3[i].dividend <== num;

      divRem5[i] = DivRem(5, 4);
      divRem5[i].dividend <== num;

      divRem15[i] = DivRem(15, 5);
      divRem15[i].dividend <== num;

      // 余りが0かどうかを判定 (0なら is***s[i].out は 1, それ以外は 0)
      isFizzs[i] = IsZero();
      isBuzzs[i] = IsZero();
      isFizzBuzzs[i] = IsZero();

      isFizzs[i].in <== divRem3[i].remainder; // 3で割り切れるか
      isBuzzs[i].in <== divRem5[i].remainder; // 5で割り切れるか
      isFizzBuzzs[i].in <== divRem15[i].remainder; // 15で割り切れるか

      // Mux1コンポーネントを使い、条件に応じて出力値を決定する
      // Mux1(s, c[0], c[1]) は s が 1 なら c[1] を、0 なら c[0] を出力する
      // isFizzBuzzs -> isBuzzs -> isFizzs の優先順位でチェックし、値を置き換える

      // 3で割り切れる場合 (isFizzs.out == 1)、num を 3333 に置き換える
      muxFizzs[i] = Mux1();
      muxBuzzs[i] = Mux1();
      muxFizzBuzzs[i] = Mux1();

      muxFizzs[i].s <== isFizzs[i].out;
      muxFizzs[i].c[0] <== num;
      muxFizzs[i].c[1] <== 3333;

      // 5で割り切れる場合 (isBuzzs.out == 1)、muxFizzsの出力を 5555 に置き換える
      muxBuzzs[i].s <== isBuzzs[i].out;
      muxBuzzs[i].c[0] <== muxFizzs[i].out;
      muxBuzzs[i].c[1] <== 5555;

      // 15で割り切れる場合 (isFizzBuzzs.out == 1)、muxBuzzsの出力を 1515 に置き換える
      muxFizzBuzzs[i].c[0] <== muxBuzzs[i].out;
      muxFizzBuzzs[i].c[1] <== 1515;
      muxFizzBuzzs[i].s <== isFizzBuzzs[i].out;
      out[i] <== muxFizzBuzzs[i].out; // 最終的な結果を出力に代入

      // 以下のif文はログ出力で、回路の制約には影響しない
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