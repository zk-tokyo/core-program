pragma circom 2.1.2;

// TODO: circomlibから comparators.circom をインクルードしてください

template Over20() {

    signal input age;
    signal output oldEnough;
    
    // 年齢を格納するには8ビットで十分なため、8ビットの比較器を使用
    component get = GreaterEqThan(8);
    get.in[0] <== age;
    get.in[1] <== 20;
	1 === get.out;
    
    oldEnough <== get.out;
}

component main = Over20();