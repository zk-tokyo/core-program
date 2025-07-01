pragma circom 2.1.2;

include "node_modules/circomlib/circuits/comparators.circom";
include "node_modules/circomlib/circuits/mux1.circom";

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

      divRem3[i] = DivRem(3, 4);
      divRem3[i].dividend <== num;

      divRem5[i] = DivRem(5, 4);
      divRem5[i].dividend <== num;

      divRem15[i] = DivRem(15, 5);
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

component main = FizzBuzz();