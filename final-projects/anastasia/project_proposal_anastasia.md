# Project Proposal: <!-- プロジェクト名を記載 -->

Anastasia: Cinderella's Stepsister Turning X.509 ECDSA Certificates into Anonymous Mobile Device Attestation

## 1. Overview <!-- プロジェクトの概要を数行で記載 -->

X.509証明書チェーンの正しさを、必要最低限の情報開示だけで証明可能とするシステム。
先行研究Cinderella(IEEE S&P 2016)のアプローチをベースに改良を加え、
Androidデバイスの鍵構成証明(Key Attestation)におけるユーザのプライバシ強化を実現する。

## 2. Objectives <!-- プロジェクトの背景・目的・スコープ等を記載 -->

PKIの主要な構成要素であるX.509証明書は、公開鍵とその持ち主の関係を示した署名付きデータであり、信頼された認証局(CA; Certification Authority)によって発行される。
X.509証明書の多くはサーバー証明書として使われる。クライアント証明書として使うことも可能だが、証明書に含まれるシリアル番号や公開鍵、署名値などの情報がユーザの行動追跡を容易にするため、プライバシの懸念から利用は限定的である。

国際学会IEEE S&P 2016でMicrosoft Researchの研究者らが発表したCinderellaは、
RSAベースのX.509証明書をzk-SNARKによって匿名クレデンシャル化し、
プライバシー保護や検証精度を向上させる画期的な研究であった。
zk-SNARKにはLinear PCP型のPinocchioが採用され、
検証時間は非常に短く(数ミリ秒)、証明サイズも極めて小さくなり(288バイト)、
検証者にとっては性能上のオーバーヘッドが小さく受容しやすい提案であると言える。
しかしながら、Linear PCPベースの方式であるがために、
回路ごとのTrusted Setupが必要であり、
さらには複雑な回路を処理する都合上、
長い証明時間(数十〜数百秒)と巨大なパラメータサイズ(最大1GB)が必要とされた。
結果、リソースの限られた証明者による証明生成は実用的ではなく、
例えばAndroidデバイスの鍵構成証明(デバイスの公開鍵が、デバイス内のSecure Elementで生成された鍵であることの証明)
におけるユーザのプライバシ強化に適用することはできなかった。

本プロジェクトではCinderellaのアプローチをなぞりつつ、実装面と応用面で貢献を加える。
具体的には、Androidスマートフォン上での証明生成を可能にするため、
Pinocchioの代わりにPlonkベースのUltraHonkを用いることで回路サイズや計算効率の向上を図る。
また、回路の設計にはDSLであるNoirを利用することで、メンテナンスや拡張の容易性を高める。
さらに、RSA署名の代わりにECDSA署名の検証回路を組み込むことで、
Androidの鍵構成証明で利用されるECDSAベースのX.509証明書を扱えるようにする。
また、メモリの小さいモバイルデバイスでの実行を可能にするため、
証明書チェーンの正しさを一度に証明するのではなく、
個々の証明書ごとに分割証明するアプローチを採用する。
結果、鍵構成証明に現れるX.509証明書チェーンの真正性をゼロ知識証明可能とし、
証明書の利用者の特定に繋がる情報を開示することなく、
利用者の鍵が確かにデバイスのSecure Elementで生成されたものであることを検証者に証明可能とする。

## 3. Deliverables <!-- プロジェクトにおける成果物の想定を記載 -->

- ZK回路 (Noir)
- ライブラリ (Rust)
- Android用SDK (Kotlin)
- Android用サンプルアプリケーション (Kotlin)
- Verifier用SDK (TypeScript)
- Verifier用サンプルアプリケーション (TypeScript)
- 説明文書

## 4. Team <!-- プロジェクトメンバーとそれぞれの役割(e.g.,どの部分を担当するか)を記載 -->

| Member | Role |
|-------:|:-----|
| yamdan | 全体  |

## 5. Design & Architecture <!-- 全体設計や細部のアーキテクチャーを具体的に記載(成果物が実装の場合のみ) -->

### ZK回路 (Noir)

- 以下のような回路をNoir言語で実装
    - private input: チェーンに含まれる複数のX.509証明書の列 (かそれらを最低限パースしたもの)
    - public input: 検証者にとっての信頼の起点となるCA証明書 (Googleのルート証明書か第2CA証明書)
    - 計算内容: 各証明書に付与されているECDSA署名の検証と、証明書内の各種情報の有効性確認(有効期間の確認、失効有無の確認、ポリシー準拠の確認など。全部はきっと間に合わないのでまずは最低ラインだけ...)
- SHA256, SHA384, ECDSAの計算は既存のブラックボックス実装を活用(本プロジェクトでは実装しない)
- X.509証明書で使われるASN.1データ構造のパース(in ZK回路)がおそらく最大の課題。Cindelleraやzk-Regexなどを参考に検討予定

### ライブラリ (Rust)

- X.509証明書を受け取り、上のNoir回路への入力に適した形に変換したり、Noirの出力を処理したりするライブラリ
- 証明書チェーンの一括証明が計算リソース上不可能だった場合は、分割証明するためのコミットメント計算などもここで行う
- [Mopro](https://github.com/zkmopro)を用いてUniFFIを生成し、Kotlinから呼び出し可能にする

### Android用SDK (Kotlin)

- Prover用SDK
- Androidアプリから受け取ったX.509証明書チェーンを受け取り、Rustライブラリを呼び出して証明を生成する
- [Mopro](https://github.com/zkmopro)を用いて雛形を作成

### Android用サンプルアプリケーション (Kotlin)

- Prover用のサンプルアプリ
- インストール時にSecure Elementで鍵ペアやAttestation用証明書チェーンを生成
- 「証明」ボタンを押すと、証明書チェーンの真正性と有効性をゼロ知識証明した結果を出力 (Base64文字列などで)

### Verifier用SDK (TypeScript)

- Proverが生成した証明を検証し、証明書チェーンの真正性と有効性を確認するTypeScript用ライブラリ
- Webアプリでの利用を想定
- [@aztec/bb.js](https://www.npmjs.com/package/@aztec/bb.js) の検証機能を使ってUltraHonkの証明を検証

### Verifier用サンプルアプリケーション (TypeScript)

- Verifier用のサンプルアプリ
- WebフォームにペーストされたBase64文字列をデコードすることで証明を受け取り、Verifier用SDKを使って検証を実施
- React(フロントエンド)+Express(バックエンド)などで実装

## 6. Reference Materials <!-- 参考にした資料・リンク等を記載 -->

- [Cinderella: Turning Shabby X.509 Certificates into Elegant Anonymous Credentials with the Magic of Verifiable Computation](https://ieeexplore.ieee.org/document/7546505)
- [Cinderella (Slides)](https://www.ieee-security.org/TC/SP2016/slides/23-3/delignat.pdf)
- [鍵構成証明と ID 構成証明 | Android Open Source Project](https://source.android.com/docs/security/features/keystore/attestation?hl=ja)
- [Noir Documentation](https://noir-lang.org/)
- [Mopro](https://github.com/zkmopro)
- [zkmopro/noir-rs](https://github.com/zkmopro/noir-rs)
- [noir-lang/sha256](https://github.com/noir-lang/sha256)
- [noir-lang/sha512](https://github.com/noir-lang/sha512)
- [ECDSA Signature Verification | Noir Documentation](https://noir-lang.org/docs/noir/standard_library/cryptographic_primitives/ecdsa_sig_verification)
- [zkemail/zk-regex](https://github.com/zkemail/zk-regex)
- [デバイスとアプリの完全性保証からサービスリクエストの保護まで：LINEのデバイス証明サービス 第1弾](https://techblog.lycorp.co.jp/ja/20240806a)
- [Android Protected Confirmation - Try it](https://apc.ti.bfh.ch/stats/cert_hierarchy.html)
- [Anonymous credentials from ECDSA](https://eprint.iacr.org/2024/2010)
