pragma circom 2.1.2;

include "node_modules/circomlib/circuits/comparators.circom";

template Multiplier3 () {
   signal input a;
   signal input b;
   signal input c;
   signal output d;
   component mult1 = Multiplier2();
   component mult2 = Multiplier2();

   mult1.in1 <== a;
   mult1.in2 <== b;
   mult2.in1 <== mult1.out;
   mult2.in2 <== c;
   d <== mult2.out;
}

component main = Multiplier3();