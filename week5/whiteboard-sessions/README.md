# Tornado Cash 実装演習

## 概要

このプロジェクトは、プライバシー保護型ミキサープロトコルである Tornado Cash の学習用実装です。ZK-SNARKs（ゼロ知識証明）を用いて、暗号通貨のデポジットと引き出しのリンクを切り、取引のプライバシーを保護します。

## 技術スタック

* **Circom**：ゼロ知識証明サーキットの記述
* **SnarkJS**：ZK-SNARKs の証明生成・検証
* **Solidity**：スマートコントラクト
* **Foundry**：スマートコントラクトのテストフレームワーク

## 演習課題

### 1. サーキット実装

`circuits/` ディレクトリ内の `.circom` ファイルの TODO 箇所を実装してください。

#### circuits/merkleTree.circom

* `DualMux` テンプレートの実装を完成させる

  * 選択信号 `s` に基づいて入力を切り替える機能を実装

#### circuits/withdraw.circom

* `Withdraw` テンプレートで以下を実装する：

  * 公開入力の定義（`root`, `nullifierHash`, `recipient`, `relayer`, `fee`）
  * 秘密入力の定義（`nullifier`, `secret`, `pathElements`, `pathIndices`）
  * `CommitmentHasher` を用いた `nullifierHash` の計算と検証
  * `MerkleTreeChecker` による Merkle 木の検証

### 2. ビルドとテスト

以下のコマンドが正しく動作することを確認してください。

```bash
# 依存関係のインストール
npm i -g snarkjs
make init

# フェーズ1: Powers of Tau セレモニーの実行
make phase1

# フェーズ2: サーキットのコンパイルと proving key の生成
make phase2

# テストの実行
make test
```

### 3. 追加機能の実装

任意で追加機能を1つ設計・実装してください。例：

#### 実装例

* **時間ロック付き引き出し**：一定期間が経過するまで引き出しを制限
* **動的手数料調整**：ネットワーク状況に応じて手数料を調整
* **マルチカレンシー対応**：複数のトークン種別をサポート
* **部分引き出し**：全額ではなく一部のみを引き出せるようにする
* **緊急停止機能**：セキュリティ事故時にプロトコルを一時停止

## プロジェクト構成

```
.
├── circuits/              # Circom サーキットファイル
│   ├── merkleTree.circom  # Merkle 木の検証サーキット
│   └── withdraw.circom    # 引き出し用の証明サーキット
├── contracts/             # Solidity スマートコントラクト
│   ├── src/
│   │   ├── TornadoCats.sol  # メインコントラクト
│   │   └── Verifier.sol     # 生成される検証コントラクト
│   └── test/               # コントラクトのテスト
├── build/                 # ビルド生成物
├── Makefile               # ビルドコマンド
└── README.md              # 本書類
```

## 仕組み

1. **デポジット（入金）**:

   * ユーザーが `nullifier` と `secret` を生成
   * `commitment = Pedersen(nullifier, secret)` を計算
   * コミットメントを Merkle 木に追加し、固定額をデポジット

2. **引き出し**:

   * ユーザーは次を証明するゼロ知識証明を生成：

     * 有効なコミットメントが Merkle 木に存在すること
     * そのコミットメントに対応する `nullifier` と `secret` を知っていること
   * 二重使用防止のため `nullifierHash` を公開
   * 証明が有効なら、指定アドレスへ資金を送金

## セキュリティ上の注意

* **nullifier の秘匿**：引き出しまで `nullifier` は秘密に保つ
* **secret の管理**：`secret` は決して漏えいしないようにする
* **信頼できるセットアップ**：Powers of Tau セレモニーを正しく実行することが重要
* **フロントラン保護**：リレイヤー機能で引き出しトランザクションの送信者を秘匿

## 開発のヒント

1. **サーキットのデバッグ**：`circom --inspect` オプションで中間値を確認
2. **ガス最適化**：Solidity での Merkle 木操作を最適化
3. **テスト**：エッジケースを含む包括的なテストケースを作成

## 参考資料

* [Circom ドキュメント](https://docs.circom.io/)
* [SnarkJS ドキュメント](https://github.com/iden3/snarkjs)
* [Tornado Cash ホワイトペーパー](https://tornado.cash/Tornado.cash_whitepaper_v1.4.pdf)
* [ZK-SNARKs の基礎](https://z.cash/technology/zksnarks/)

## ライセンス

本プロジェクトは教育目的のみです。
