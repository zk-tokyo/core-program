pragma circom 2.1.5;

template Multiplier3() {
    signal input a;
    signal input b;
    signal input c;
    signal output d;

    signal e;

    e <== a * b;
    d <== e * c;
}

component main = Multiplier3();
