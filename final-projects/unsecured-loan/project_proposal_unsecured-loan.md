# DeFi個人向け無担保ローン・プロトコル

## 1. Overview <!-- プロジェクトの概要を数行で記載 -->

ZKSNARKと信用情報機関を活用し、プライバシーを保護しながら信用確認を可能にするDeFi個人向け無担保ローンプロトコル。アドレス変更によるデフォルト履歴の回避を防止し、持続可能な信用市場の構築を目指します。

## 2. Objectives <!-- プロジェクトの背景・目的・スコープ等を記載 -->

### 背景
- 世界中に金融排除の問題が普遍的に存在しており、DeFiは全ての人がアクセスできる潜在的な解決策として期待されている
- しかし、DeFiには実用的な個人向け無担保ローン・プロトコルがまだ存在していない

### 課題
- DeFiでは借り手が新しいアドレスを作るだけで不利な履歴を切り離せるため、借り手の返済インセンティブが弱く、貸し手もデフォルトした借り手をフィルターできない
- 従来の信用審査では、借り手の金融データが全て露出してしまう

### 解決アプローチ
- 伝統的金融は信用情報機関を介してデフォルト履歴を共有し、金融機関を跨いでも逃避できない構造を構築している
- すでに168か国で信用情報機関が整備されており、この実社会インフラをプライバシーを守ったままDeFiに持ち込むことで、個人向け無担保ローンの成立可能性を高める

### プロジェクト目標
- 信用情報機関とCreditVCによるDeFi無担保ローン市場の構築
- zkSNARKによる与信とプライバシー保護の両立
- 完済・デフォルト履歴を中心とする信用市場を構築し、薄い信用履歴でも段階的に信用を蓄積することで金融包摂を実現

## 3. Deliverables <!-- プロジェクトにおける成果物の想定を記載 -->

### 主要コンポーネント

### システム要件実装
- 以下の要件が満たせるシステムを設計し、その中にどのように経済機能要件が満たせるかを示すDEMOを実装する予定

#### 経済機能要件
- **既存デフォルト遮断**: オンチェーン・オフチェインでデフォルトした利用者のローン受付拒否
- **デフォルト共有**: クロススマートコントラクト・アドレス変更によるデフォルト履歴回避の防止
- **無限申請防止**: 信用力を超えた多重ローン申請の防止
- **良好履歴の累計**: 完済等の良好記録の累積機能

#### プライバシー保護要件
- **最小限開示**: 与信判断に必要な真偽値のみ提示、属性の生値は非公開

#### 安全性要件
- **CreditVC失効対策**: 失効したCreditVCの使用禁止
- **CreditVC発行者資格**: 認定信用情報機関発行のCreditVCのみ使用可能
- **Proof盗難耐性**: バインディングされたアドレスのみProof使用可能

## 4. Team <!-- プロジェクトメンバーとそれぞれの役割(e.g.,どの部分を担当するか)を記載 -->

| メンバー | 役割 |
|-------:|:-----|
| WU Yihsuan | システム要件定義、データセット用意、ZK回路設計 |
| Masanari Gotoh | ZK回路設計、DEMO実装 |
## 5. Design & Architecture <!-- 全体設計や細部のアーキテクチャーを具体的に記載(成果物が実装の場合のみ) -->

### システムアーキテクチャ

#### 主要構成要素

1. **信用情報機関**
   - 信用情報を含むCreditVCの発行
   - オラクル経由での失効リスト管理
   

2. **利用者**
   - CreditVCの保持
   - ローン申請用proofの生成
   - ローン返済の管理

3. **スマートコントラクト**
   - Proofの検証
   - ローン状態（返済済み/未返済）の追跡
   - デフォルトリストの維持
   - 認定発行者（信用情報機関）public keyリストの管理
   - 信用ランクに基づくローンルールの実行
   
#### ZK回路設計
```
パブリック入力:
- 失効リスト (Revocation List)
- デフォルトリスト (Default List)
- 信用情報機関署名リスト (信情 Sign List)

プライベート入力:
- CreditVC（信用スコア、過去CreditVC IDリスト、発行者sign含む）

出力:
- 失効状態: True/False
- 信用情報機関署名: True/False
- デフォルト状態: True/False
- 信用ランク: A/B/C等
- CreditVC ID: XXXXX
```

### 技術仕様

#### 使用技術
- **ZK証明**: Circom + snarkjs?
- **ブロックチェーン**: Ethereum testnet?
- **スマートコントラクト**: Solidity
- **フロントエンド**: React/Next.js + ethers.js?
- **検証可能クレデンシャル**: W3C VC標準準拠



## 6. Reference Materials <!-- 参考にした資料・リンク等を記載 -->

- [World Bank - Making access to new credit easier](https://blogs.worldbank.org/en/developmenttalk/making-access-new-credit-easier)
- [COINTELEGRAPH - DeFiレンディング向けにID保護のクレジットスコア導入](https://jp.cointelegraph.com/news/transunion-to-begin-providing-identity-protected-credit-scoring-for-defi-lending)
- Kravitz, David W., and Mollie Zechlin Halverson. "Course-Correct to DeFi Lacking Default Deficiency." 2023 20th Annual International Conference on Privacy, Security and Trust (PST). IEEE, 2023.


