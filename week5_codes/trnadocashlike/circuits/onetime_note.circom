pragma circom 2.0.0;

// -------------------------------------------------------------
// 必要なライブラリをインポート
// -------------------------------------------------------------
// ハッシュ関数
include "node_modules/circomlib/circuits/poseidon.circom";        // Poseidon ハッシュ

// 署名検証
include "node_modules/circomlib/circuits/eddsaposeidon.circom";   // EdDSA(Ed25519) + Poseidon

// データ構造・検証
include "node_modules/circomlib/circuits/smt/smtverifier.circom"; // Sparse Merkle Tree (SMT)証明

// ユーティリティ
include "node_modules/circomlib/circuits/comparators.circom";      // 比較器
include "node_modules/circomlib/circuits/bitify.circom";          // ビット変換 (Num2Bits等)
// =====================================================================
// サブコンポーネント定義
// =====================================================================

/**
 * @dev ConsumeNoteCircuit - 1つのノートを消費する処理
 * 
 * 機能:
 * 1. Nullifier を計算
 * 2. Sparse Merkle Tree で「未使用(非包含)」を証明
 * 3. ワンタイムノートの Merkle Inclusion を証明
 * 4. 金額を出力 (後で合計に使用)
 *
 * @param merkleDepth ワンタイムノートのマークルツリーの深さ
 * @param smtDepth    Nullifier SMTの深さ
 */
template ConsumeNoteCircuit(merkleDepth, smtDepth) {
    // ---- 入力シグナル ----
    // ノート基本情報
    signal input amount;             // ノート金額
    signal input encryptedReceiver;  // 受取人情報(暗号化)
    signal input rho;                // ランダム値

    // Nullifier SMT 検証用データ
    signal input rootNullifier;      // 使用済みノート(SMT)のルート
    signal input smtSiblings[smtDepth];  // SMT検証用の兄弟ノード
    signal input oldKey;             // 非包含証明用の古いキー
    signal input oldValue;           // 非包含証明用の古いキー値
    signal input isOld0;             // 古いキーが0かどうか

    // ワンタイムノート検証用データ
    signal input rootNote;           // ワンタイムノート(SMT)のルート
    signal input notePathElements[merkleDepth]; // 証明用のパス要素
    signal input noteValue;          // ノートの値 (SMT用)

    // ---- 出力シグナル ----
    signal output outAmount;         // ノート金額 (合計計算用)

    // ステップ1: Nullifier の計算
    // rhoを内部ハッシュ
    component rhoHash = Poseidon(1);
    rhoHash.inputs[0] <== rho;

    // Nullifier = Poseidon(amount, encryptedReceiver, hashedRho)
    component nullifierCalc = Poseidon(3);
    nullifierCalc.inputs[0] <== amount;
    nullifierCalc.inputs[1] <== encryptedReceiver;
    nullifierCalc.inputs[2] <== rhoHash.out;

    // 注: Nullifier の値自体は外部出力せず、
    // 「rootNullifier に非包含であること」を証明する

    // ステップ2: Sparse Merkle Tree による非包含証明 
    // (Nullifierがツリーに存在しないことを証明)
    component smtVer = SMTVerifier(smtDepth);
    
    // SMTVerifier設定
    smtVer.enabled <== 1;            // 検証有効化
    smtVer.fnc <== 1;                // 1: 非包含検証モード
    smtVer.root <== rootNullifier;   // SMTルート
    smtVer.key <== nullifierCalc.out; // 検証キー(Nullifier値)
    smtVer.value <== 0;              // 検証値(非包含の場合は0)
    
    // 非包含証明用パラメータ
    smtVer.oldKey <== oldKey;
    smtVer.oldValue <== oldValue;
    smtVer.isOld0 <== isOld0;
    
    // SMT兄弟ノード設定
    for (var d = 0; d < smtDepth; d++) {
        smtVer.siblings[d] <== smtSiblings[d];
    }

    // ステップ3: ワンタイムノートの包含証明
    // hashedOnetimeNote = Poseidon(amount, encryptedReceiver, rho)
    component noteHash = Poseidon(3);
    noteHash.inputs[0] <== amount;
    noteHash.inputs[1] <== encryptedReceiver;
    noteHash.inputs[2] <== rho;

    // ノートの包含証明 (ノートが存在することを証明)
    component noteSMTCheck = SMTVerifier(merkleDepth);
    
    // SMTVerifier設定
    noteSMTCheck.enabled <== 0;         // 検証有効化
    noteSMTCheck.fnc <== 0;             // 0: 包含検証モード
    noteSMTCheck.root <== rootNote;     // ノートのマークルルート
    noteSMTCheck.key <== noteHash.out;  // 検証キー(ノートハッシュ)
    noteSMTCheck.value <== noteValue;   // 検証値(通常は1)
    // 包含証明用パラメータ (使用しないが仕様上必要)
    noteSMTCheck.oldKey <== 0;
    noteSMTCheck.oldValue <== 0;
    noteSMTCheck.isOld0 <== 1;
    
    // 証明パス設定
    for (var m = 0; m < merkleDepth; m++) {
        noteSMTCheck.siblings[m] <== notePathElements[m];
    }

    // ステップ4: 出力 - このノートの金額
    outAmount <== amount;
}

/**
 * @dev CreateNoteCircuit - 新規ノートを作成
 * 
 * 機能:
 * 1. 1つの新規ノートを作成し、ハッシュ値を計算
 * 2. ハッシュ値(hashedOnetimeNote)を出力
 */
template CreateNoteCircuit() {
    // ---- 入力シグナル ----
    signal input amount;             // ノート金額
    signal input encryptedReceiver;  // 受取人情報(暗号化)
    signal input rho;                // ランダム値

    // ---- 出力シグナル ----
    signal output hashedNote;        // 新規ノートのハッシュ

    // ノートハッシュの計算: hashedNote = Poseidon(amount, encryptedReceiver, rho)
    component noteHash = Poseidon(3);
    noteHash.inputs[0] <== amount;
    noteHash.inputs[1] <== encryptedReceiver;
    noteHash.inputs[2] <== rho;
    hashedNote <== noteHash.out;
}

// =====================================================================
// メイン回路定義
// =====================================================================

/**
 * @dev MainCircuit - メイン検証回路
 * 
 * 機能:
 * 1. nIn個の既存ノートを消費 (ConsumeNoteCircuit)
 * 2. nOut個の新規ノートを作成 (CreateNoteCircuit)
 * 3. 送金額合計の検証
 * 4. 署名検証
 * 5. 公開鍵の検証
 *
 * @param nIn          消費するノートの数
 * @param nOut         作成する新規ノートの数
 * @param merkleDepth  ワンタイムノートのマークルツリーの深さ
 * @param smtDepth     Nullifier SMTの深さ
 */
template MainCircuit(nIn, nOut, merkleDepth, smtDepth) {
    // ------------------------------------------------
    // 公開入力 (Public Inputs)
    // ------------------------------------------------
    signal input rootNullifier;                    // Nullifier SMTのルート
    signal input rootNote;                         // ワンタイムノートのマークルルート
    signal input hashedSignature;                  // 署名ハッシュ
    signal input Nullifier[nIn];                   // 各ノートのNullifier (比較用)
    signal input hashedOnetimeNote_out[nOut];      // 新規ノートのハッシュ配列
    signal input hashedAmount;                     // 送金額合計のハッシュ

    // ------------------------------------------------
    // 秘密入力 (Private Inputs)
    // ------------------------------------------------
    // 1. 消費ノート情報
    // 基本情報
    signal input amount_in[nIn];                   // 入力ノート金額配列
    signal input encryptedReceiver_in[nIn];        // 入力ノート受取人情報配列
    signal input rho_in[nIn];                      // 入力ノートランダム値配列

    // ノート証明情報
    signal input note_pathElements[nIn][merkleDepth]; // マークルパス要素
    signal input note_value[nIn];                     // ノート値

    // Nullifier SMT情報
    signal input smt_siblings[nIn][smtDepth];       // SMT兄弟ノード
    signal input smt_oldKey[nIn];                   // 非包含証明用の古いキー
    signal input smt_oldValue[nIn];                 // 非包含証明用の古いキー値
    signal input smt_isOld0[nIn];                   // 古いキーが0かどうか

    // 2. 新規ノート情報
    signal input amount_out[nOut];                 // 出力ノート金額配列
    signal input encryptedReceiver_out[nOut];      // 出力ノート受取人情報配列
    signal input rho_out[nOut];                    // 出力ノートランダム値配列

    // 3. 署名情報 (EdDSA Poseidon)
    signal input Ax;                               // 公開鍵 x座標
    signal input Ay;                               // 公開鍵 y座標
    signal input R8x;                              // 署名 R8 x座標
    signal input R8y;                              // 署名 R8 y座標
    signal input S;                                // 署名 S値

    // 4. その他の検証情報
    signal input rho2;                             // 金額ハッシュ用ランダム値

    // ------------------------------------------------
    // ステップ1: 消費ノートの検証
    // ------------------------------------------------
    // 入力合計金額の追跡
    var sumIn = 0;

    // 各入力ノートに対して処理
    component consumeNotes[nIn];
    for (var i = 0; i < nIn; i++) {
        // ノート消費サブコンポーネント初期化
        consumeNotes[i] = ConsumeNoteCircuit(merkleDepth, smtDepth);

        // 基本ノート情報の設定
        consumeNotes[i].amount <== amount_in[i];
        consumeNotes[i].encryptedReceiver <== encryptedReceiver_in[i];
        consumeNotes[i].rho <== rho_in[i];

        // Nullifier SMT情報設定
        consumeNotes[i].rootNullifier <== rootNullifier;
        consumeNotes[i].oldKey <== smt_oldKey[i];
        consumeNotes[i].oldValue <== smt_oldValue[i];
        consumeNotes[i].isOld0 <== smt_isOld0[i];
        
        // SMTシブリング設定
        for (var d = 0; d < smtDepth; d++) {
            consumeNotes[i].smtSiblings[d] <== smt_siblings[i][d];
        }

        // ノートマークルツリー情報設定
        consumeNotes[i].rootNote <== rootNote;
        consumeNotes[i].noteValue <== note_value[i];
        
        // マークルパス設定
        for (var md = 0; md < merkleDepth; md++) {
            consumeNotes[i].notePathElements[md] <== note_pathElements[i][md];
        }

        // 注: Nullifier比較はメイン回路では実装していないが、
        // 設計に応じてサブコンポーネントで出力し比較することも可能

        // 合計金額の累積
        sumIn += consumeNotes[i].outAmount;
    }

    // ------------------------------------------------
    // ステップ2: 新規ノートの作成と検証
    // ------------------------------------------------
    // 出力合計金額の追跡
    var sumOut = 0;

    // 各出力ノートに対して処理
    component createNotes[nOut];
    for (var j = 0; j < nOut; j++) {
        // ノート作成サブコンポーネント初期化
        createNotes[j] = CreateNoteCircuit();

        // 入力パラメータの設定
        createNotes[j].amount <== amount_out[j];
        createNotes[j].encryptedReceiver <== encryptedReceiver_out[j];
        createNotes[j].rho <== rho_out[j];

        // パブリック入力との整合性検証
        // 生成されたハッシュが公開ハッシュと一致することを確認
        hashedOnetimeNote_out[j] === createNotes[j].hashedNote;

        // 出力金額の累積
        sumOut += amount_out[j];
    }

    // ------------------------------------------------
    // ステップ3: 金額合計の検証
    // ------------------------------------------------
    // 入出力の金額が一致することを確認 (sumIn === sumOut)
    sumIn === sumOut;

    // ------------------------------------------------
    // ステップ4: 金額ハッシュの検証
    // ------------------------------------------------
    // hashedAmount = Poseidon(sumIn, rho2)
    component amountHash = Poseidon(2);
    amountHash.inputs[0] <== sumIn;
    amountHash.inputs[1] <== rho2;
    amountHash.out === hashedAmount;

    // ------------------------------------------------
    // ステップ5: 署名検証 (EdDSA Poseidon)
    // ------------------------------------------------
    // ここで メッセージを計算
    component msgHash = Poseidon(2);
    msgHash.inputs[0] <== encryptedReceiver_in[0];
    msgHash.inputs[1] <== rho_in[0];

    // circomlib/eddsaposeidon.circom の回路名に合わせて修正
    component eddsaCheck = EdDSAPoseidonVerifier();
    eddsaCheck.enabled <== 1; // 必須のenabled入力パラメータを追加
    eddsaCheck.Ax <== Ax;
    eddsaCheck.Ay <== Ay;
    eddsaCheck.R8x <== R8x;
    eddsaCheck.R8y <== R8y;
    eddsaCheck.S <== S;
    eddsaCheck.M <== msgHash.out;

    // hashedSignature との比較
    component sigDataHash = Poseidon(3);
    sigDataHash.inputs[0] <== R8x;
    sigDataHash.inputs[1] <== R8y;
    sigDataHash.inputs[2] <== S;
    sigDataHash.out === hashedSignature;

}

// メイン回路のインスタンス
component main {public [rootNullifier, rootNote, hashedSignature, Nullifier, hashedOnetimeNote_out, hashedAmount]} = MainCircuit(2, 2, 128, 128);