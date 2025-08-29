pragma circom 2.1.2;


template Multiplier2 () {
   signal input in1;
   signal input in2;
   signal output out;

   out <== in1 * in2;
}

template Multiplier3 () {
    signal input in1;
    signal input in2;
    signal input in3;
    signal output out;
    signal intermediate;

    component mult2_1 = Multiplier2();
    mult2_1.in1 <== in1;
    mult2_1.in2 <== in2;
    intermediate <== mult2_1.out;

    component mult2_2 = Multiplier2();
    mult2_2.in1 <== intermediate;
    mult2_2.in2 <== in3;
    out <== mult2_2.out;
}

component main = Multiplier3();
