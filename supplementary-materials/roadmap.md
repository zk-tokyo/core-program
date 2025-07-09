# ゼロ知識証明学習ロードマップ

このロードマップの読み方
このロードマップは、ゼロ知識証明技術の3つの世代を順序立てて学習するための体系的なガイドです。
学習の原則:

段階的な依存関係: 各技術は前段階の理解を前提として構築されています
必須前提の明記: 各段階で必要な前提知識を明確に示しています
技術的系譜の重視: 例えばPlonky2はPlonkとSTARK（FRI）の理解が必須です

ロードマップの構造:

基礎知識: 全ての学習に必要な数学的・暗号学的基盤
第一世代: Trusted Setupの課題解決（Groth16 → Plonk → STARK）
第二世代: Recursion ProofとFolding Scheme（Plonky2, Halo2, Nova）
第三世代: zkVMのためのField Size最適化（Binius, Circle STARK）

学習順序: 基礎知識を習得後、段階1から順番に進むことを強く推奨します。各段階内でも示された順序（例：Groth16 → Plonk → STARK）に従うことで、技術的な理解の積み重ねが効率的に行えます。

## 基礎知識（必須前提）

### 数学的基礎
- **楕円曲線暗号学**
  - 有限体上の楕円曲線
  - Pairing（双線形写像）の理論
  - BLS12-381, BN254などの具体的な曲線
- **多項式理論**
  - 有限体上の多項式演算
  - 多項式補間（Lagrange補間）
  - 多項式コミット（KZG commitment）
- **線形代数**
  - ベクトル空間、部分空間
  - 行列演算、階数
  - 線形写像

### 暗号学的基礎
- **ゼロ知識証明の定義**
  - Completeness（完全性）
  - Soundness（健全性）
  - Zero-knowledge（ゼロ知識性）
- **Interactive Proofs**
  - Fiat-Shamir変換
  - Random Oracle Model
- **Commitment Schemes**
  - Vector Commitments
    - Pedersen Commitment
    - Merkle Tree
  - Polynomial Commitment
    - KZG Commitment
    - FRI-based Commitment
    - IPA

---

## 第一世代：Trusted Setupの課題解決

### 段階1：Groth16の理解
**前提知識**: 楕円曲線暗号学、Pairing理論、多項式理論

**学習内容**:
- **QAP（Quadratic Arithmetic Program）**
  - 計算回路からQAPへの変換
  - R1CS（Rank-1 Constraint System）
  - QAPの多項式表現
- **Groth16プロトコル**
  - Setup phase（CRS生成）
  - Proving algorithm
  - Verification algorithm
- **Trusted Setupの問題**
  - Toxic wasteとは何か
  - Universal vs Circuit-specific setup



### 段階2：Plonkの理解
**前提知識**: Groth16、KZG多項式コミット

**学習内容**:
- **Plonkishアリスメティック**
  - Copy constraintの仕組み
  - Custom gatesの設計
  - Permutation argumentの理論
- **Plonkプロトコル**
  - Universal setup（Powers of Tau）
  - Quotient polynomialの構築
  - Opening proofの生成
- **Plonk vs Groth16の比較**
  - Universal setupの利点
  - 証明サイズと検証時間の比較



### 段階3：STARKの理解
**前提知識**: Merkle Tree、ハッシュ関数、有限体理論

**学習内容**:
- **FRI（Fast Reed-Solomon Interactive Oracle Proof）**
  - Reed-Solomon符号の基礎
  - FRIプロトコルの詳細
  - Query phaseの最適化
- **STARK構造**
  - Algebraic Intermediate Representation（AIR）
  - Constraint polynomialの構築
  - Trace polynomialの生成
- **STARKの利点**
  - Quantum resistance
  - Transparent setup（trusted setupなし）
  - Scalabilityの理論



---

## 第二世代：Recursion ProofとFolding Scheme

### 段階4：Plonky2の理解
**前提知識**: Plonk、STARK（FRI）、Goldilocks体

**学習内容**:
- **Plonky2のアーキテクチャ**
  - PlonkとSTARKの融合
  - Goldilocks体（p = 2^64 - 2^32 + 1）の選択理由
  - Poseidon hash functionの使用
- **Recursion技術**
  - 証明の証明（Proof of Proof）
  - Circuit-friendly hash functions
  - Verifier circuitの効率化
- **実装最適化**
  - Parallelization技術
  - Memory効率化
  - Lookup argumentsの活用



### 段階5：Halo2の理解
**前提知識**: Plonk、KZG、Inner Product Arguments

**学習内容**:
- **Halo2の設計思想**
  - Accumulation schemeの概念
  - Nested recursionの実現
  - Amortized polynomial commitments
- **Pasta curves**
  - Pallas/Vesta曲線ペアの特性
  - Cycle of elliptic curvesの理論
- **Lookup arguments**
  - Plookupの理論
  - Table lookupの効率化
  - Custom lookupの実装



### 段階6：Novaの理解
**前提知識**: Halo2、Relaxed R1CS

**学習内容**:
- **Incrementally Verifiable Computation（IVC）**
  - IVCの定義と応用
  - Folding schemeの概念
  - Step circuitの設計
- **Novaプロトコル**
  - Relaxed R1CSの導入
  - Folding witnessの生成
  - Accumulation verifierの実装
- **Supernova拡張**
  - Multiple instruction setsの対応
  - Uniform vs Non-uniform computation



---

## 第三世代：zkVMのためのField Size最適化

### 段階7：Biniusの理解
**前提知識**: Binary field theory、Multilinear polynomial

**学習内容**:
- **Binary fieldの利点**
  - CPU-nativeな演算
  - 32/64-bit操作の効率化
  - Memory accessの最適化
- **Multilinear polynomialの活用**
  - Bivariate polynomialの扱い
  - Sumcheck protocolの応用
  - Tensor productの理論
- **Biniusプロトコル**
  - Binary fieldでの証明生成
  - Commitment schemeの設計
  - Verificationの効率化



### 段階8：Circle STARKの理解
**前提知識**: STARK、Circle group theory

**学習内容**:
- **Circle groupの数学**
  - Circle上の群演算
  - FFT on circleの理論
  - Mersenne31 fieldの特性
- **Circle STARKプロトコル**
  - Circle-based polynomialの構築
  - Constraint systemの拡張
  - Proximity testingの改良
- **zkVMでの応用**
  - RISC-V instructionの効率的表現
  - Memory consistencyの証明
  - Program counterの処理
