# ゼロ知識証明用語集

ゼロ知識証明における専門用語をまとめました

## Proof Systems

| 用語 | 説明 |
|------|------|
| Interactive Proof (IP) | 証明者と検証者が**複数回通信**して成り立つ証明モデル。 |
| IOP (Interactive Oracle Proof) | 証明者が**oracle（証明）へのアクセスを提供**し、検証者はそれを照会する新しい証明モデル。 |
| PCP (Probabilistically Checkable Proof) | 一部のビットをランダムに読むことで検証可能な証明モデル。IOPの基礎理論。 |
| Non-Interactive Zero-Knowledge (NIZK) | 通信を**一回に圧縮**したゼロ知識証明。Fiat–Shamir変換などが必要。 |

## Arithmetization Schemes

| 用語 | 説明 |
|------|------|
| Arithmetization | 命題やプログラムをZKが扱える数式表現（制約／多項式）に変換する全体工程。 |
| Constraint System | 証明で命題を数式として表現する制約の体系。例：R1CS, PLONK constraint, AIR。 |
| R1CS (Rank-1 Constraint System) | ゼロ知識証明における**算術制約の一般表現形式**。PlonkやGroth16で使われる。 |
| AIR (Algebraic Intermediate Representation) | STARKで使われる**中間演算表現**。R1CSとは別系統。 |

## Setup

| 用語 | 説明 |
|------|------|
| Trusted Setup | 証明システムの初期化において、**秘密情報を生成し破棄する必要がある**ステップ。 |
| Transparent Setup | Trusted Setupを必要としない設定方式。例：STARK, Bulletproofs。 |
| CRS (Common Reference String) | 証明者と検証者が共有する**共通のランダムな設定値**。 |
| Structured Reference String (SRS) | 特定構造を持つCRSの一種で、効率的なプロトコルの前提として使われる。KZGなどで用いられる。 |
| Toxic Waste | Trusted Setupで生成される秘密の破棄すべき値。流出すると証明の偽造が可能になる。 |
| Universal Setup | 任意の回路に使える一度きりのセットアップ方式。MarlinやSonicで使用。 |
| Circuit Specific Setup | 特定の回路専用のセットアップ。Groth16などで使われるが再利用不可 |

## Commitment Scheme

| 用語 | 説明 |
|------|------|
| Polynomial Commitment Scheme(PCS) | 多項式を**固定サイズのコミットメント**として証明に使う。例：KZG, FRI。 |
| KZG Commitment | Kate-Zaverucha-Goldbergの方式。多項式コミットメントの一種で、評価証明が一つのペアリングで検証可能。Groth16やEIP-4844で使われる。 |
| FRI (Fast Reed-Solomon IOP) | STARKに使われる**軽量な多項式検証プロトコル**。 |
| Merkle Tree | データ整合性を**ハッシュ木構造で保証**する仕組み。ZKPでは入力証明に使われる。 |
| Pedersen Commitment | 離散対数の難しさに基づく加法的ホモモルフィックコミットメント。ZKで入力を隠すのに頻繁に使用。 |
| Vector Commitment | 一連の値を1つのコミットにまとめ、任意の位置の証明が可能。Verkle treeやHaloで活用。 |

## Hash function

| 用語 | 説明 |
|------|------|
| zk-Friendly Hash Function | ZK回路での効率を意識した制約数が少ないハッシュ関数の総称。例：Poseidon, Rescue, MiMC。 |
| Poseidon Hash | ゼロ知識証明に特化して設計された低コストなハッシュ関数。特にPlonk系で広く利用される。 |
| MiMC | ZK用途のために設計されたFeistel構造ベースのハッシュ関数。Poseidonより古く、非線形性が強い。 |
| Rescue | ZK向けに設計されたハッシュ関数で、線形と非線形ステップを交互に構成。 |

## Recursive SNARKs

| 用語 | 説明 |
|------|------|
| Recursion | 証明の中で**別の証明を検証する**構造。IVCの基本要素であり、IVCは再帰を構造化・圧縮して実用化した形 |
| Folding | 証明の繰り返し構造を**再帰的にまとめる**技術。IVCの計算圧縮ステップに頻出する。Nova, SuperNovaなどで使用。 |
| Accumulation | 証明を**累積的にまとめて検証**する技術（例：Halo, BCTV）。 |

## 応用技術

| 用語 | 説明 |
|------|------|
| zkRollup | L1の状態を**zk証明でまとめて圧縮**し投稿するLayer2技術。 |
| zkVM | zkで**仮想マシンの実行過程を証明**する仕組み。例：RiscZero、Jolt。 |
| IVC (Incrementally Verifiable Computation) | 長い計算を逐次的に検証可能なZK証明として構築する概念。各ステップで小さな証明を生成し、次に引き継ぐ。NovaやHaloが該当。 |
| NIVC (Non-Interactive IVC) | IVCの非対話型バージョン。一度の提出で全体の計算履歴を証明可能。SuperNovaやOrionなどが該当。 |

## その他の重要な概念

| 用語 | 説明 |
|------|------|
| Witness | 証明の際に使われる**秘密情報**（制約を満たす入力）。 |
| Fiat–Shamir変換 | 対話型証明を非対話型にする**ハッシュベースの置換手法**。 |
| FFT (Fast Fourier Transform) | 有限体上での高速な多項式変換アルゴリズム。証明サイズの削減や構築の高速化に重要。 |
| Lookup Argument | 回路の中で、ある値が特定のテーブルに存在することを効率的に証明する仕組み。Plonkish系で導入。 |
| Permutation Argument | 入力や中間値が一貫した配置にあることを証明する仕組み。Plonkのσ-permutationなどに使われる。 |
| Custom Gate | 頻出する演算（例：加算・比較）を一つのゲートとして定義し、回路の効率を向上させる技術。 |
| Proof Carrying Data (PCD) | 各ノードが自分の出力とその証明を次のノードに引き渡す証明フレームワーク。ZKでの逐次的な整合性保持に用いられる。 |
| QAP (Quadratic Arithmetic Program) | R1CSを多項式として表現する方式。Groth16の基盤。 |
| IPA (Inner Product Argument) | 多項式評価の証明に使用される省スペースな代替手法。Bulletproofsで使われる。 |
