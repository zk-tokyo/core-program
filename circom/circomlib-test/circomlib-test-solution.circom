pragma circom 2.1.2;

include "node_modules/circomlib/circuits/comparators.circom";

template Multiplier2Alt () {
  signal input a;
  signal input b;
  signal output c;

  // a または b のいずれかが1の場合、in は0になります
  // in が0でないことを確認します
  component isZeroCheck = IsZero();
  isZeroCheck.in <== (a - 1) * (b - 1);
  isZeroCheck.out === 0;

  c <== a * b;
}

component main = Multiplier2Alt();