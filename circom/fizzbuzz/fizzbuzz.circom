pragma circom 2.1.2;

include "node_modules/circomlib/circuits/comparators.circom";

template DivRem(divisor, nBits) {
    signal input dividend;
    signal output quotient;
    signal output remainder;

    quotient <-- dividend \ divisor;
    remainder <-- dividend % divisor;

    divisor * quotient + remainder === dividend;

    component lt = LessThan(nBits);
    lt.in[0] <== remainder;
    lt.in[1] <== divisor;
    lt.out === 1;
}

template FizzBuzz () {
   signal input array[15];
   signal output out[15];

   var arrayLength = 15;

   // signal を定義

   for (var i = 0; i < arrayLength; i++) {
      var num = array[i];
      log("=== ", num, " ===");

      // ロジックを実装


   }

   log("============");
}

component main = FizzBuzz();