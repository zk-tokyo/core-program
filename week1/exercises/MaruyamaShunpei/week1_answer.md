## 1. zkSNARKの具体的なユースケースを自分で一つ考えて、p.22にある方式のうちどれを使うべきか理由とともに説明してください

#### 具体的なユースケース

「特許の更新を、旧・新レコードを秘匿したままできるサービス」

#### p.22にある方式のうちどれを使うべきか

特許は数十年以上の保全が要求されるデータベースを持ち、将来のことを考えると、量子耐性を持つFRI-STARKを使うべきだと考えた。一方で、長期的に考えると、証明サイズ・検証時間の点で効率的ではない。しかし、特許の申請や更新は高頻度で行われていない？ことを考えると、多少は許容できるのではないかと考えた。

https://www.wipo.int/web-publications/world-intellectual-property-indicators-2024-highlights/en/patents-highlights.html?utm_source=chatgpt.com


---

## 2. 実用化されているZKアプリケーションを一つ見つけて、以下の3つのドメインに何が採用されているのかURLとともに答えてください

#### ZKアプリケーション

Nodle (https://www.nodle.com、https://docs.nodle.com/nodle-on-zksync-era)

#### 技術スタック

- ドメイン固有言語: Solidity (https://medium.com/%40scalingx/zk-programming-languages-a-comprehensive-overview-a3046ea5e859)
- SNARKフレンドリな形式: Plonkスタイルの算術方式 (https://zksync.mirror.xyz/HJ2Pj45EJkRdt5Pau-ZXwkV2ctPx8qFL19STM5jdYhc)
- バックエンド証明器: Boojumを利用している。これは、最終段階で、STARK証明をSNARK証明にラップする。 (https://zksync.mirror.xyz/HJ2Pj45EJkRdt5Pau-ZXwkV2ctPx8qFL19STM5jdYhc)

---

## 3. (+α問題) 2で採用されている方法にはどんな特徴があるか説明してください

余力ある人だけでOK。文章でメリット・デメリットを説明してください。

---