pragma circom 2.1.6;

// TODO: circomlibから comparators.circom をインクルードして `IsZero` コンポーネントにアクセスしてください

template Over20() {

    signal input age;
    signal output oldEnough;
    
    // 年齢を格納するには8ビットで十分なため、8ビットの比較器を使用
    component gt = GreaterThan(8);
    gt.in[0] <== age;
    gt.in[1] <== 20;
	0 === gt.out;
    
    oldEnough <== gt.out;
}

component main = Over20();