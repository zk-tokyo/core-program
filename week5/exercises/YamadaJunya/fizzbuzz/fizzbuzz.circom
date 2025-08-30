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

   component divRem3[15];
   component divRem5[15];
   component isZero3[15];
   component isZero5[15];
   
   signal isFizz[15];
   signal isBuzz[15];
   signal isFizzBuzz[15];
   signal notFizz[15];
   signal notBuzz[15];
   signal fizzOnly[15];
   signal buzzOnly[15];

   for (var i = 0; i < 15; i++) {
      log("=== ", array[i], " ===");

      divRem3[i] = DivRem(3, 8);
      divRem3[i].dividend <== array[i];

      divRem5[i] = DivRem(5, 8);
      divRem5[i].dividend <== array[i];

      isZero3[i] = IsZero();
      isZero3[i].in <== divRem3[i].remainder;

      isZero5[i] = IsZero();
      isZero5[i].in <== divRem5[i].remainder;
      
      isFizz[i] <== isZero3[i].out;
      isBuzz[i] <== isZero5[i].out;
      isFizzBuzz[i] <== isFizz[i] * isBuzz[i];
      
      notFizz[i] <== 1 - isFizz[i];
      notBuzz[i] <== 1 - isBuzz[i];
      
      fizzOnly[i] <== isFizz[i] * notBuzz[i];
      buzzOnly[i] <== isBuzz[i] * notFizz[i];
      
      out[i] <== isFizzBuzz[i] * 3 + fizzOnly[i] * 1 + buzzOnly[i] * 2;
      
      var num = array[i];
      if (num % 15 == 0) {
          log("FizzBuzz");
      } else if (num % 3 == 0) {
          log("Fizz");
      } else if (num % 5 == 0) {
          log("Buzz");
      } else {
          log(num);
      }
   }

   log("============");
}

component main = FizzBuzz();