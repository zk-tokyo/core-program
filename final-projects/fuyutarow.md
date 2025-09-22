# Project Proposal: XML Signature Verification in Noir

## 1. Overview
NoirでXMLデジタル署名（XMLDSig）の検証を行う最小限の実装。署名済みXMLドキュメントの署名値が正しいことをゼロ知識証明で検証する。

## 2. Objectives
### 背景
- 企業間のXML文書交換では署名検証が必要
- 文書内容を明かさずに署名の有効性を証明したい

### 目的
- XML文書をprivate inputとして署名検証を実行
- 署名が有効であることをゼロ知識で証明

### スコープ
- XMLDSigの基本構造（SignedInfo, SignatureValue）のみ対応
- SHA-256ハッシュベースの検証
- 公開鍵暗号（RSA/ECDSA）は将来課題、今回はハッシュ検証のみ

## 3. Deliverables
1. 簡易XMLパーサー（署名関連要素のみ）
2. SHA-256ハッシュ検証回路
3. 動作確認用テストケース

## 4. Team
| Member | Role |
|-------:|:-----|
| fuyutarow | 全実装 |

## 5. Design & Architecture
### 基本設計
```
Input:
  - 署名付きXML文書（private witness）
  - 期待される署名者ID（public input）

Circuit:
  1. XMLから<SignatureValue>と<SignedInfo>要素を抽出
  2. SignedInfoのCanonicalXMLを生成
  3. SHA-256でハッシュ計算
  4. 署名値のハッシュと一致することを検証

Output:
  - 検証結果（bool）
  - 署名者IDの一致（bool）
```

### 実装計画
1. XMLの基本要素（SignatureValue, SignedInfo）を抽出する簡易パーサー
2. Canonical XML形式に正規化（最小限の実装）
3. SHA-256ハッシュ計算と検証

## 6. Reference Materials
- [XMLDSig仕様](https://www.w3.org/TR/xmldsig-core/)
- [Noir公式ドキュメント](https://noir-lang.org/)
- [noir-json-parser](https://github.com/noir-lang/noir_json_parser) (参考実装)