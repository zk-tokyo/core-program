# 1. zkSNARKの具体的なユースケースを自分で一つ考えて、p.22にある方式のうちどれを使うべきか理由とともに説明してください

### ユースケース
匿名による告発プラットフォーム

### 方式
Groth'16：証明サイズが小さく検証時間が高速であること

---

# 2. 実用化されているZKアプリケーションを一つ見つけて、以下の3つのドメインに何が採用されているのかURLとともに答えてください

zcash

a. ドメイン固有言語  
Bellman DSL  
https://github.com/zkcrypto/bellman  

b. SNARKフレンドリな形式  
R1CS  
https://crates.io/crates/r1cs    

c. バックエンド証明器  
Groth16  
https://github.com/zkcrypto/bellman/tree/main/groth16  

---

# 3. (+α問題) 2で採用されている方法にはどんな特徴があるか説明してください

### a. Bellman DSL
- Rust ベースの zk-SNARK 回路記述用ライブラリ  
- 型安全で低レベルな制約定義が可能  

### b. R1CS
- 足し算・掛け算を制約として表す算術形式  
- 汎用性が高く、多くのSNARK系証明器に対応  
- 構造が明快で証明の最適化がしやすい  

### c. Groth16
- 定数サイズ・高速検証を特徴とする zk‑SNARK  
- Zcash や他多数プロジェクトで採用  
- トラステッドセットアップが必要
