## 1. zkSNARKの具体的なユースケースを自分で一つ考えて、p.22にある方式のうちどれを使うべきか理由とともに説明してください

#### 具体的なユースケース

モバイル端末に保存した資格証明書(運転免許証や検定合格書など)の持ち主が、Webサイトでアカウントを作成する際に以下のことをサイトに対して証明するPoCサービス:

1. 資格証明書には、Webサイトが信頼する発行者(地方自治体や検定機関など)のデジタル署名が付けられていること

2. Webサイトでアカウントを作成しようとしているユーザが、資格証明書の発行先と同一人物であること

3. 資格証明書に含まれる情報のうち、アカウント作成に必要な最低限の情報だけがWebサイトに渡ること (ユーザの行動が追跡されるのを防ぐために、発行者によるデジタル署名もWebサイトには渡さない)

4. 証明書の種類や構造は将来的に随時追加される

#### p.22にある方式のうちどれを使うべきか

実験的なPoCサービス利用を想定しているため、量子耐性は求めない。そこでFRI-STARK以外に絞りこむ。
証明書の種類や構造が追加された場合には回路の再設計や追加が必要となる可能性がある。回路を追加する都度、関係者(ユーザとWebサイト)が信頼可能なTrusted Setupを繰り返すのは運用コストが極めて大きく受容しにくいと思われる。したがってTrusted Setupが必要なGroth16は候補から除外し、Plonk/MarlinまたはBulletproofに絞る。
回路の拡張に伴って証明サイズと検証時間が増加するのはアカウント作成の遅延を招き、ユーザの離脱を伴いかねない。したがって証明サイズと検証時間がconstantオーダーに収まるPlonk/Marlinを選択する。

---

## 2. 実用化されているZKアプリケーションを一つ見つけて、以下の3つのドメインに何が採用されているのかURLとともに答えてください

#### ZKアプリケーション

[ZKPassport](https://zkpassport.id/): パスポートから抽出した署名付きの個人属性データを、不要な属性や署名値を隠したまま、ゼロ知識証明を使うことで検証可能にするもの

#### 技術スタック

- ドメイン固有言語: [Noir](https://noir-lang.org/)
- SNARKフレンドリな形式: [ACIR (Abstract Circuit Intermediate Representation)](https://noir-lang.github.io/noir/docs/acir/circuit/index.html)
- バックエンド証明器: [Barretenberg](https://github.com/AztecProtocol/aztec-packages/tree/next/barretenberg)

---

## 3. (+α問題) 2で採用されている方法にはどんな特徴があるか説明してください

Noirはゼロ知識証明のためのドメイン固有言語の一つ。[Aztec Labs](https://aztec-labs.com)が、EthereumのL2ネットワークであるAztec Network向けに開発したZK DSL。オープンソース化されており、Aztec Network以外でも利用可能。

[Aztec Labs | Building the Endgame for Blockchain Privacy](https://aztec-labs.com/)
> Aztec Labs was founded in 2017, and has a team of +50 leading zero-knowledge cryptographers, engineers, and business experts. We have raised $125M, including a $100m Series B led by a16z crypto in 2022.

NoirはCircomよりも抽象度が高く、Rustの文法をベースにしていることもあってRustのコーディングに近い感覚でゼロ知識証明の回路を記述できる。

Noirプログラムをコンパイルすると ACIR (Abstract Circuit Intermediate Representation) というバイトコードが得られる。
ACIRは特定の証明系/バックエンドに依存しない中間形式で、
ACVM (Abstract Circuit Virtual Machine) によって各種バックエンドに適した形式へ変換される。
こうした分担により、Noirは特定の証明系に縛られない柔軟性を持っているとされる。

バックエンドはUltraHonk, coSNARKs, Supernova, Plonky2, Recursive Groth16, Nova, HyperNovaなどが存在する ([参考](https://github.com/noir-lang/awesome-noir#proving-backends))。
ZKPassportではAztec LabsのBarretenbergという実装が採用され、これはUltraHonkという証明系をサポートしている。

Honkは"Highly optimized Plonk"の略称とのことで、
UltraHonkはその後継版とのこと。
Sumcheckプロトコル、多重線形PCS、Lookupテーブルなどを用いてPlonkを効率化したもの(詳細は確認できず)。

[Client-side Proof Generation | Aztec Blog](https://aztec.network/blog/client-side-proof-generation)
> To further decrease memory and computation requirements for the prover, we use a specific proving system, Honk, which is a highly optimized Plonk developed by Aztec Labs. Honk is a combination of Plonk-ish arithmetization, the sum-check protocol (which has some nice memory tricks), and a multilinear polynomial commitment scheme.

参考: [HonkやUltraHonkを含むAztecのロードマップ](https://aztec.network/aztec-roadmap)


---