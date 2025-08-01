## 1. zkSNARKの具体的なユースケースを自分で一つ考えて、p.22にある方式のうちどれを使うべきか理由とともに説明してください

#### 具体的なユースケース

「信用スコアの正当性を個人情報を開示せずに証明できるサービス」

DeFiレンディングプロトコルにおいて、借り手が貸し手に対して自身の信用力を証明する際、詳細な個人情報や信用レポートを開示することなく、事前に合意された計算式に基づいて正しく算出された信用スコアであることを証明するシステム。

**仕組み：**
1. 貸し手が信用スコアの計算式を事前に公開
2. 借り手が信用情報機関から信用レポートを取得
3. zkSNARKを用いて、個人情報を秘匿したまま計算の正当性を証明
4. 貸し手は証明を検証し、融資判断を実施

#### p.22にある方式のうちどれを使うべきか

**Groth16** を選択すべきである

**理由：**
Groth16は現在最も効率的なzkSNARKプロトコルの一つであるため(ZKcore program-week1資料参照)

1. **証明サイズが最小（200B）**
   - Ethereumでのガス代を最小限に抑制
   - 1ブロックにより多くの証明が格納可能（理論上約90個-Claude AI算出）

2. **検証時間が最速（1.5ms）**  
   - ブロック生成時間への影響を最小化
   - ユーザー体験の向上

3. **Trusted Setupの許容性**
   - 本ユースケースでは信用情報機関という信頼できる第三者が既に存在
   - 信用情報機関が主導してセットアップセレモニーを実施することも可能
   - 既に信頼関係が存在する環境では、Trusted Setupのデメリットが相対的に小さい

---

## 2. 実用化されているZKアプリケーションを一つ見つけて、以下の3つのドメインに何が採用されているのかURLとともに答えてください

#### ZKアプリケーション

**Monero** - https://www.getmonero.org/

#### 技術スタック

- ドメイン固有言語 : 
  - zkSNARK専用のドメイン固有言語は使用せず、C++で直接実装
  - GitHubリポジトリ: https://github.com/monero-project/monero

- SNARKフレンドリな形式: Range Proof用のカスタム制約システム
  -GitHubリポジトリ: https://github.com/monero-project/monero/blob/master/src/ringct/bulletproofs.cc
  
- バックエンド証明器: Bulletproofs実装
  - GitHubリポジトリ: https://github.com/monero-project/monero/blob/master/src/ringct/bulletproofs.cc
  - 2018年10月導入: https://www.getmonero.org/2018/10/11/monero-0.13.0-released.html
  
---
