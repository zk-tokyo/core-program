pragma circom 2.1.2;

include "../node_modules/circomlib/circuits/bitify.circom";
include "../node_modules/circomlib/circuits/pedersen.circom";
include "merkleTree.circom";

// Pedersen(nullifier + secret) を計算する
template CommitmentHasher() {
    signal input nullifier;
    signal input secret;
    signal output commitment;
    signal output nullifierHash;

    component commitmentHasher = Pedersen(496);
    component nullifierHasher = Pedersen(248);
    component nullifierBits = Num2Bits(248);
    component secretBits = Num2Bits(248);
    nullifierBits.in <== nullifier;
    secretBits.in <== secret;
    for (var i = 0; i < 248; i++) {
        nullifierHasher.in[i] <== nullifierBits.out[i];
        commitmentHasher.in[i] <== nullifierBits.out[i];
        commitmentHasher.in[i + 248] <== secretBits.out[i];
    }

    commitment <== commitmentHasher.out[0];
    nullifierHash <== nullifierHasher.out[0];
}

// 与えたシークレットとヌリファイアに対応するコミットメントがMerkleツリーに含まれているという条件のもとで証明を生成できる
template Withdraw(levels) {
    // TODO: public inputs: root, nullifierHash, recipient, relayer, fee


    // TODO: private inputs: nullifier, secret, pathElements[levels], pathIndices[levels]


    // TODO: CommitmentHasherを定義し、nullifierHashを計算する


    // TODO: MerkleTreeCheckerを定義し、コミットメントとルートをもとにマークルツリーの検証を行う


    // 最終的な出力の定義
    signal recipientSquare;
    signal feeSquare;
    signal relayerSquare;
    recipientSquare <== recipient * recipient;
    feeSquare <== fee * fee;
    relayerSquare <== relayer * relayer;
}

component main {public [root, nullifierHash, recipient, relayer, fee]} = Withdraw(20);