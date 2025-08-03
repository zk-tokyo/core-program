# ライブラリリスト

ゼロ知識証明を用いたアプリケーションやライブラリを実装する際の技術選定に役立つリストを作りました。ここでは主要な実装のみを取り上げています。他にも様々な実装がありますが、ひとまずこれらを認知しておけば事足りると思います。

⚠️注意

- PoCやProduction Readyでない実装が多いです。そもそも、ブロックチェーン業界から生まれたゼロ知識証明プロトコルはsecurity proofが存在しない場合や監査がなされていない場合も多く、信頼性に欠けることを留意ください。
- 最終的な技術選定にはパフォーマンスの比較が必要ですが、ここでは取り上げません。末尾の参考資料にベンチマークなどが掲載されているので、そちらをご参照ください。

## 1. フロントエンド

これは、ゼロ知識証明を生成するための回路を記述するために特化して設計された言語を指します。これらの言語は、特定の構文や抽象化を提供し、通常のプログラミング言語では扱いにくい制約システムを直感的に記述できるようにします。多くの場合、コンパイラによってZKPプロトコルが処理できる形式（R1CS、AIRなど）に変換されます。

| | 概要 | Language | Proving systems | Arithmetization Schemes | Field | Solidity Verifier |
|---|---|---|---|---|---|---|
| [Circom](/20e4cf0b61e4800b8f5ef326951ed13f) | R1CSを抽象化して回路を構築するDSL。最も広く採用されている定番のDSL | DSL | - Groth16<br>- Plonk | - R1CS<br>- Plonkish | - Goldilocks<br><br>Scalar field<br>- BN128<br>- BLS12-381<br>- Pallas<br>- Vesta<br>- secq256r1 | [YES](https://docs.circom.io/getting-started/proving-circuits/#verifying-from-a-smart-contract) |
| [Noir](https://github.com/noir-lang/noir/tree/98d19fb4d61fd3b4f6420862af2d5f7af8a30f0f) | Aztec Protocolが開発したDSLで、複数のバックエンドをサポート可能なACIRが特徴。現在はHalo2のみサポートされている。 | DSL | Halo2 | - R1CS<br>- Plonkish | Scalar field<br>- Pasta<br>- BN128 | [YES](https://noir-lang.org/docs/dev/how_to/how-to-solidity-verifier) |
| [Lurk](/20e4cf0b61e4800b8f5ef326951ed13f) | 再帰的な証明(Recurive Proof)を効率的に記述することを主眼としている。 | Lisp-like DSL | Halo2 | Plonkish | Scalar field<br>- Pasta | No |
| [Cairo](GitHub%20GitHub%20-%20starkware-libs/cairo-lang) | StarkWare開発のチューリング完全プログラミング言語で、StarkNetのスマートコントラクト言語としても使用される。 | DSL | zk-STARK | AIR | | [YES (for StarkNet)](https://docs.starknet.io/architecture-and-concepts/solidity-verifier/) |

## 2. バックエンドライブラリ

これらは既存の汎用プログラミング言語で記述され、ゼロ知識証明の生成・検証、またはその基盤となる暗号プリミティブ（有限体演算、楕円曲線演算など）を提供するソフトウェアモジュール群を指します。開発者はこれらのライブラリを通常のコードに組み込んで、ZKP関連の機能を実現します。多くの場合、回路の定義もこのライブラリ内のAPIを使って行われます。

| | 概要 | Language | Proving systems | Arithmetization Schemes | Field | Solidity Verifier |
|---|---|---|---|---|---|---|
| [Arkworks](https://github.com/arkworks-rs) | モジュール化された構成を持つzkライブラリ群で、R1CS・PLONK両方の証明系に対応し、ペアリング・有限体・FFT・多項式コミットメントなどを組み合わせてカスタムZKシステムを構築可能。 | Rust | - Groth16 | R1CS | Scalar field<br>- bn254<br>- bls12-381 | [YES(サードパーティ製)](https://github.com/Tetration-Lab/arkworks-solidity-verifier) |
| [gnark](https://github.com/Consensys/gnark) | R1CSベースのDSLを通じて高水準のZK回路定義が可能な実装で、Groth16とPLONKをバックエンドに持ち、証明生成の並列化や効率的なベンチマークを提供する実用志向のフレームワーク。ICECLEハードウェアアクセラレーションと相性が良い | Go | - Groth16<br>- Plonk | - R1CS<br>- Plonkish | Scalar field<br>- bn254<br>- bls12-381 | [YES](https://github.com/Consensys/gnark-solidity-checker) |
| [bellman](https://github.com/zkcrypto/bellman) | R1CSベースでGroth16専用に設計された軽量な証明システムで、静的な回路構築と信頼性を重視し、ZcashのSaplingプロトコルの中核を担う。 | Rust | - Groth16 | R1CS | Scalar field<br>- bls12-381 | No |
| [Libsnark](https://github.com/scipr-lab/libsnark) | Groth16、Pinocchio等を実装する初期の汎用ライブラリで、理論実装の検証用途として広く用いられたが、保守が停滞している。 | C++ | - Groth16 | R1CS | Scalar field<br>- bn128 | No |
| [snarkjs](https://github.com/iden3/snarkjs) | Circomとの連携を前提としたZKツールチェーンで、証明生成・検証・回路処理の一通りを扱える。 | JS/WASM | - Groth16<br>- Plonk | - R1CS<br>- Plonkish | Scalar field<br>- bn254<br>- bls12-381 | [YES](https://github.com/iden3/snarkjs-generate-solidity) |
| [rapidsnark](https://github.com/iden3/rapidsnark) | snarkjsの証明生成部分を高速化した実行エンジンで、大規模証明を並列処理で効率よく生成可能。 | C++ | - Groth16<br>- Plonk | - R1CS<br>- Plonkish | Scalar field<br>- bn128 | No |
| [EMP-zk](https://github.com/emp-toolkit/emp-zk) | VOLE-based zkに特化したライブラリ群 | C++ | - Wolverine<br>- Quicksilver<br>- Mystiqui | Not Arithmetic circuit, Boolean Circuit | Galois Field | No |
| [starky](https://github.com/0xPolygonZero/plonky2/tree/main/starky) | Plonky2のために実装されたFRI-baseのSTARK実装。高速なSTARK Proof生成が可能。 | Rust | zk-STARK | AIR | Goldilocks | No |

## 3. プリミティブ実装

Plonky2(3)やHalo2, Novaはゼロ知識証明プロトコルの名前です。このリストに記載しているのはそれらのプリミティブ実装になります。

| | 概要 | Language | Proving systems | Field | Solidity Verifier |
|---|---|---|---|---|---|
| [Halo2(Zcash)](https://github.com/zcash/halo2) | PLOOKUPやカスタムゲートを備える汎用的な証明システム。トラステッドセットアップ不要かつ再帰的証明に最適化されたzk-SNARK実装。ただし、必要とする前提知識が多く、学習コストが高いため書きにくい。 | Rust | Halo2 | Pasta scalar | No |
| [Halo2(PSE)](https://github.com/privacy-scaling-explorations/halo2) | PSEがZcash実装をフォークしたもの。IPAをKZGコミットメントに換装している。 | Rust | Halo2 | Pasta scalar | [YES](https://github.com/privacy-scaling-explorations/snark-verifier) |
| [Halo2(Axiom)](https://github.com/axiom-crypto/halo2) | PSEのHalo2をさらにフォークしたもの。インターフェースが洗練されたうえ、[ライブラリ](https://github.com/axiom-crypto/halo2-lib?tab=readme-ov-file)も提供している。 | Rust | Halo2 | Pasta scalar | [YES](https://github.com/axiom-crypto/snark-verifier) |
| [Plonky2](https://github.com/0xPolygonZero/plonky2) | Polygon LabsがzkEVMのために開発した。非常に高速なRecursive SNARKというテクニックが特徴。Halo2に比べてかなり書きやすい。 | Rsut | Plonky2 | Goldilocks | [YES](https://github.com/axiom-crypto/halo2) |
| [Plonky3](https://github.com/Plonky3/Plonky3) | Plonky2の後継として設計され、より小さいFieldで定義されている | Rsut | Plonky3 | Mersenne31 | No but maybe we can do that with [Plonky2.5](https://github.com/QEDProtocol/plonky2.5) |
| [Nova](https://github.com/microsoft/Nova) | Folding schemeと呼ばれるテクニックにより、複数のR1CSを単一のR1CSに"畳こむ"ことができる。 | Rust | Nova+Spartan | - Pasta scalar<br>-BN254<br>- secp256k1 | No |

## 4. Applications & Protocols

CircomやGnark、Arkworks、Plonky2は、ZKPの構成要素や実装ツールを提供するのに対し、zk EmailやSemaphoreは、それらのツールを組み合わせて実現されたZKPの具体的な応用例や利用プロトコルです

| | 概要 | zk コンポーネント |
|---|---|---|
| [ZK email](https://github.com/zkemail) | ユーザーがメールアカウントの認証情報や内容を明かすことなく、メールの内容に関するゼロ知識証明を生成・検証できるプロトコルです。 | circom, snarkjs, Halo2, Noir |
| [Semaphore](https://github.com/semaphore-protocol) | 匿名性のあるシグナリングシステムであり、ユーザーが自身のオンチェーンIDを明かさずにグループメンバーシップを証明し、メッセージを送信できるようにします。 | circom, snarkjs |
| [Mopro](https://github.com/zkmopro) | モバイルデバイスなどで高速かつ効率的にゼロ知識証明を生成・検証するための、クロスプラットフォーム対応のライブラリです。 | Halo2, Circom |
| [MACI](https://github.com/privacy-scaling-explorations/maci) | 共謀耐性のある投票や調整メカニズムを実現し、投票者が一意であることをZKPで保証しつつ、集計結果のみを公開するプロトコルです。 | circom, snarkjs |
| [zk-kit](https://github.com/privacy-scaling-explorations/zk-kit) | ゼロ知識証明の構築に必要な汎用的なツールやユーティリティ、再利用可能な回路部品を集めた開発者向けライブラリの集合体です。 | Circcom, Noir |
| [ZKP2P](https://github.com/zkp2p) | ユーザーが自身の身元や取引相手を明かすことなく、P2P（ピアツーピア）で匿名かつ検証可能な取引を可能にするプロトコルです。 | circom, Halo2 |
| [OpenPassport](https://github.com/zk-passport/openpassport) | ユーザーが自身の身元情報（パスポートなど）の特定の側面についてゼロ知識証明を生成し、プライバシーを保ちながら認証やクレデンシャルを共有できるようにするプロトコルです。 | circom, snarkjs |
| [zkID](https://github.com/privacy-scaling-explorations/zkID) | 個人が自身のID情報を管理し、必要な属性のみを限定的に、かつプライバシーを保護しながら証明できるデジタルIDシステムです。 | |
| [TLSNotary](https://github.com/tlsnotary) | TLS (Transport Layer Security) セッションの内容に関するゼロ知識証明を生成することで、Webサイトから取得した情報が改ざんされていないことを信頼できる第三者を介さずに証明できるプロトコルです。 | |
| [semaphore-noir](https://github.com/hashcloak/semaphore-noir) | SemaphoreのNoir実装 | Noir |

## 5. 参考

https://www.researchgate.net/figure/The-Process-of-Zero-Knowledge-Proofs-ZKP_fig5_362645703

https://zkv.xyz/the-map-of-zk/

https://arxiv.org/html/2408.00243v1

https://arxiv.org/html/2502.07063v1

https://www.computer.org/csdl/journal/tq/2023/06/10002421/1Jv6BEAupcA

https://github.com/ventali/awesome-zk
