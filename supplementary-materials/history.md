# ゼロ知識証明の歴史

ここではゼロ知識証明がどのように理論的発展を遂げたのか解説します。

## 1. ゼロ知識証明の年表

| 年 | 主要な出来事/論文発表/プロトコル登場/応用 |
|---|---|
| 1985 | ゼロ知識証明の概念がGoldwasser, Micali, Rackoffの論文「[The Knowledge Complexity of Interactive Proof Systems](https://dl.acm.org/doi/pdf/10.1145/22145.22178)」で初めて提唱される。対話型証明システムが確立される。 |
| 1986 | [Fiat-Shamir huristic](https://link.springer.com/chapter/10.1007/3-540-47721-7_12)が発表され、対話型証明を非対話型に変換する手法が提示される。 |
| 1988 | Blum, Feldman, Micaliが[共通参照文字列（CRS）を用いた非対話型ゼロ知識証明の構成](https://dl.acm.org/doi/10.1145/62212.62222)を示す |
| 1992 | Probabilistically Checkable Proofs (PCPs) が導入され、後のSNARKsの基盤となる。[Sumcheck](https://dl.acm.org/doi/pdf/10.1145/146585.146605)プロトコルが提案される。 |
| 2003 | Shafi GoldwasserとYael Tauman Kalaiが、特定の識別スキームにおいて、任意のハッシュ関数が安全でないデジタル署名スキームを生成することを示す[論文](https://eprint.iacr.org/2003/034.pdf)を発表。 |
| 2007 | [GKR](https://dl.acm.org/doi/10.1145/2699436)プロトコルが導入され、効率的な証明システムへの一歩となる。 |
| 2010 | [Succinct Non-interactive ARguments (SNARGs)](https://eprint.iacr.org/2010/610.pdf)がMicaliによって開発される。[KZGコミットメントスキーム](https://www.iacr.org/archive/asiacrypt2010/6477178/6477178.pdf)が導入される。 |
| 2012 | zk-SNARKsの[最初の実用的な構成](https://eprint.iacr.org/2012/215)がGennaro, Gentry, Parno, Raykovaによって発表される |
| 2013 | 最初の実用的なzk-SNARKである[Pinocchio](https://ieeexplore.ieee.org/document/6547113)が誕生。[Zerocoin](https://ieeexplore.ieee.org/document/6547123/)論文が発表される。 |
| 2014 | [Zerocash](http://zerocash-project.org/paper)論文が発表される。 |
| 2015 | [Zcash](https://zips.z.cash/protocol/protocol.pdf)（旧Zerocash）がzk-SNARKsを実装し、初の本格的な実世界応用となる。 |
| 2016 | [Groth16](https://eprint.iacr.org/2016/263)発表され、最小の証明サイズと高速な検証を特徴とする。 |
| 2017 | [Bulletproof](https://ieeexplore.ieee.org/document/8418611)が公開され、信頼されたセットアップ不要の範囲証明として注目される。FRIプロトコル論文が発表される。[Ligero](https://dl.acm.org/doi/10.1145/3133956.3134104)が導入される。 |
| 2018 | [zk-STARKs](https://link.springer.com/chapter/10.1007/978-3-030-26954-8_23)がEli Ben-Sassonらによって導入され、透過性と量子耐性を提供する。 |
| 2019 | [PLONK](https://eprint.iacr.org/2019/953), [Sonic](https://dl.acm.org/doi/10.1145/3319535.3339817), [Halo](https://eprint.iacr.org/2019/1021)が発表され、普遍的セットアップや信頼されたセットアップ不要のSNARKsが登場。 |
| 2020 | [Marlin](https://link.springer.com/chapter/10.1007/978-3-030-45721-1_26)、Halo2、[Plookup](https://eprint.iacr.org/2020/315.pdf)が発表され、効率性と柔軟性が向上。[SuperSonic](https://eprint.iacr.org/2019/1229)、[Virgo](https://people.eecs.berkeley.edu/~kubitron/courses/cs262a-F19/projects/reports/project5_report_ver2.pdf)といった新しいzk-SNARKsが登場。 |
| 2021 | [Nova](https://eprint.iacr.org/2021/370.pdf) 論文でIncrementally Verifiable Computation (IVC) / Folding技術が導入される。 |
| 2022 | [Plonky2](https://github.com/0xPolygonZero/plonky2/blob/main/plonky2/plonky2.pdf)が発表され、再帰的SNARKsの性能を大幅に向上。[Supernova](https://eprint.iacr.org/2022/1758)がNovaを拡張し、異なる計算タイプに対応。 |
| 2023 | [Binius](https://eprint.iacr.org/2023/1784)、[Hypernova](https://eprint.iacr.org/2023/573)、[Jolt](https://eprint.iacr.org/2023/1217)、[Lasso](https://eprint.iacr.org/2023/1216)などが発表され、効率性とスケーラビリティがさらに向上 |

## 2. ゼロ知識証明の黎明期

ゼロ知識証明の理論的基盤は1980年代に確立されました。この時期はZKPが学術的な好奇心の対象であり、その後の実用化に向けた重要な概念が提示された時代といえます。

| 年 | 主要な出来事/論文発表/プロトコル登場/応用 |
|---|---|
| 1985 | ゼロ知識証明の概念がGoldwasser, Micali, Rackoffの論文「[The Knowledge Complexity of Interactive Proof Systems](https://dl.acm.org/doi/pdf/10.1145/22145.22178)」で初めて提唱される。対話型証明システムが確立される。 |
| 1986 | [Fiat-Shamir huristic](https://link.springer.com/chapter/10.1007/3-540-47721-7_12)が発表され、対話型証明を非対話型に変換する手法が提示される。 |
| 1988 | Blum, Feldman, Micaliが[共通参照文字列（CRS）を用いた非対話型ゼロ知識証明の構成](https://dl.acm.org/doi/10.1145/62212.62222)を示す |
| 1992 | Probabilistically Checkable Proofs (PCPs) が導入され、後のSNARKsの基盤となる。[Sumcheck](https://dl.acm.org/doi/pdf/10.1145/146585.146605)プロトコルが提案される。 |

- Goldwasser, Micali, Rackoffによる提唱（1985年）
- 対話型証明システムの確立
- 非対話型ゼロ知識証明への進化：Fiat-Shamirヒューリスティックと初期の構成

## 3. 実用化への飛躍

2010年代に入るとゼロ知識証明は理論的な概念から実用的な応用へと大きく飛躍しました。この時期には、PCP（Probabilistically Checkable Proofs）やSNARG（Succinct Non-interactive ARguments）といった先行研究が後にzk-SNARKsとして結実する基盤を築きました。

| 年 | 主要な出来事/論文発表/プロトコル登場/応用 |
|---|---|
| 2003 | Shafi GoldwasserとYael Tauman Kalaiが、特定の識別スキームにおいて、任意のハッシュ関数が安全でないデジタル署名スキームを生成することを示す[論文](https://eprint.iacr.org/2003/034.pdf)を発表。 |
| 2007 | [GKR](https://dl.acm.org/doi/10.1145/2699436)プロトコルが導入され、効率的な証明システムへの一歩となる。 |
| 2010 | [Succinct Non-interactive ARguments (SNARGs)](https://eprint.iacr.org/2010/610.pdf)がMicaliによって開発される。[KZGコミットメントスキーム](https://www.iacr.org/archive/asiacrypt2010/6477178/6477178.pdf)が導入される。 |
| 2012 | zk-SNARKsの[最初の実用的な構成](https://eprint.iacr.org/2012/215)がGennaro, Gentry, Parno, Raykovaによって発表される |
| 2013 | 最初の実用的なzk-SNARKである[Pinocchio](https://ieeexplore.ieee.org/document/6547113)が誕生。[Zerocoin](https://ieeexplore.ieee.org/document/6547123/)論文が発表される。 |
| 2014 | [Zerocash](http://zerocash-project.org/paper)論文が発表される。 |
| 2015 | [Zcash](https://zips.z.cash/protocol/protocol.pdf)（旧Zerocash）がzk-SNARKsを実装し、初の本格的な実世界応用となる。 |
| 2016 | [Groth16](https://eprint.iacr.org/2016/263)発表され、最小の証明サイズと高速な検証を特徴とする。 |
| 2017 | [Bulletproof](https://ieeexplore.ieee.org/document/8418611)が公開され、信頼されたセットアップ不要の範囲証明として注目される。FRIプロトコル論文が発表される。[Ligero](https://dl.acm.org/doi/10.1145/3133956.3134104)が導入される。 |
| 2018 | [zk-STARKs](https://link.springer.com/chapter/10.1007/978-3-030-26954-8_23)がEli Ben-Sassonらによって導入され、透過性と量子耐性を提供する。 |
| 2019 | [PLONK](https://eprint.iacr.org/2019/953), [Sonic](https://dl.acm.org/doi/10.1145/3319535.3339817), [Halo](https://eprint.iacr.org/2019/1021)が発表され、普遍的セットアップや信頼されたセットアップ不要のSNARKsが登場。 |

ブロックチェーンにおけるスケーリングとプライバシーという二つの課題がZKPを理論的な領域から実用的な領域へと押し上げた重要な要因と言えるでしょう。特にZcashにおけるZKPの採用とEthereumにおけるzk-Rollupの発明は、ZKP研究と資金提供の爆発的な増加を引き起こしました。

## 4. 現代のゼロ知識証明

2020年代に入り効率性を大幅に向上させる革新的な技術が次々と開発されています。

| 年 | 主要な出来事/論文発表/プロトコル登場/応用 |
|---|---|
| 2020 | [Marlin](https://link.springer.com/chapter/10.1007/978-3-030-45721-1_26)、Halo2、[Plookup](https://eprint.iacr.org/2020/315.pdf)が発表され、効率性と柔軟性が向上。[SuperSonic](https://eprint.iacr.org/2019/1229)、[Virgo](https://people.eecs.berkeley.edu/~kubitron/courses/cs262a-F19/projects/reports/project5_report_ver2.pdf)といった新しいzk-SNARKsが登場。 |
| 2021 | [Nova](https://eprint.iacr.org/2021/370.pdf) 論文でIncrementally Verifiable Computation (IVC) / Folding技術が導入される。 |
| 2022 | [Plonky2](https://github.com/0xPolygonZero/plonky2/blob/main/plonky2/plonky2.pdf)が発表され、再帰的SNARKsの性能を大幅に向上。[Supernova](https://eprint.iacr.org/2022/1758)がNovaを拡張し、異なる計算タイプに対応。 |
| 2023 | [Binius](https://eprint.iacr.org/2023/1784)、[Hypernova](https://eprint.iacr.org/2023/573)、[Jolt](https://eprint.iacr.org/2023/1217)、[Lasso](https://eprint.iacr.org/2023/1216)などが発表され、効率性とスケーラビリティがさらに向上 |

Recursive Proofs (Halo2, Plonky2)、Folding Schemes (Nova, Supernova)、Lookup Argument (plookup) といった最新技術の登場は、ZKPが抱えていた計算オーバーヘッドの課題を克服し、その実用的な応用範囲を大きく広げる取り組みの成果です。

これらの技術はZKPを単なる学術的な存在から、現代の計算環境の要求に合致する高性能なツールへと変貌させています。これにより、ブロックチェーンのスケーリングだけでなく、他のデータ集約型分野へのZKPの応用が加速しています。

- Recursive ProofsとFolding Schemesは、ある証明の検証自体を別の証明の中で行うことで、多数の計算を単一のコンパクトな証明に集約し、スケーラビリティを飛躍的に向上させます。
- Lookup Argumentはビット単位の操作やハッシュ関数といった複雑な計算を事前計算されたルックアップテーブルとして扱うことで、ZKPの効率を大幅に向上させました。Barry Whitehatはゼロ知識証明を全てLookupで行うLookup *Singularity*という考え方を提唱しました。
- zkVM（Zero-Knowledge Virtual Machine）は、プログラムの実行トレースに対してZKPを生成する技術です。これにより、Rustのような既存の高級言語で書かれた任意のプログラムにZKPを適用できるため、開発者はZKPの基礎となる複雑な数学やプロトコルの詳細を深く理解することなくZKPを構築でき、採用障壁を大幅に引き下げています。zkVMのバックエンドにはRecursive ProofsとFolding Schemes、Lookup Argumentが採用されており、まさにゼロ知識証明の集大成と言える技術です。
- その他にも、STARKsで用いられるFRIプロトコルを改善し、証明サイズと検証時間を削減したSTIRや**、**バイナリフィールド上での計算を用いることでメモリ使用量の削減と効率向上を実現したBiniusといった進展が見られます。

すでにゼロ知識証明は技術的成熟度と効率性の向上により、当初の暗号通貨のプライバシー保護という枠を超え、多岐にわたる分野での応用が進んでいます。

特にzkVMの登場によって、高級言語で書かれた任意のプログラムの実行をZKPで証明できるようになりました。これは、ZKP技術の根本的な転換点であり、高度に専門化された暗号ツールから、より柔軟で開発者フレンドリーなパラダイムへの移行を意味します。

この汎用化は、ZKPの普及にとって極めて重要で、開発プロセスを簡素化し、ブロックチェーンのニッチな応用を超えて、クラウドコンピューティング、AI、セキュアなデータ処理など、より広範なソフトウェア開発分野への進出を可能にしています。これは、「暗号学者がZKPを構築する」時代から「開発者がZKPを活用して構築する」時代への移行を示唆しています。

もはやデジタル世界は全て数学的に検証可能と言えるでしょう。

## 5. 今後の展望

ここ10年間の間に爆発的な進化を遂げたゼロ知識証明ですが、以前として課題は残されています。

最も顕著な課題は証明計算コストの高さです。ZKPの生成には依然として高い計算能力が求められ、モバイルデバイスなどリソースが限られた環境での利用を制限しています。複雑なユースケースにおいてはProof生成の外部委託やハードウェアアクセラレーションが必要となっています。

さらに、ZKPの設計と実装には一定の専門的な暗号学的知識が不可欠であり、一般的な開発者にとっては実装の複雑さが大きな障壁となっています。国際的な標準化の欠如は、相互運用性と広範な採用を妨げています。

しかしながら、ZKPの応用は暗号通貨やブロックチェーンに留まらず、デジタルID認証、機械学習 (zkML)、サプライチェーン管理、さらには編集された画像の真正性検証といった多岐にわたる分野へと拡大しています。これは、ZKPの核となる「知識を明かさずに証明する」能力が、機密データや検証可能な計算を扱うあらゆる領域で普遍的に価値があることが認識され始めている結果です。

GDPRのようなデータプライバシー規制の強化、セキュアな外部委託の必要性、AIの台頭といった要因がこの傾向を加速させており、金融分野だけでなく幅広いデジタルシステムに統合される可能性を秘めていることを示唆しています。

このように、応用が進む中で知っておいていただきたいのが高機能暗号やProgramable Cryptographyといった概念です。

ゼロ知識証明やMPC, FHEはこれまでの暗号技術と違い、circuitという形でプログラム可能であり、開発者が自由にアプリケーションを生み出すことができます。例えばゼロ知識証明とMPC, FHEを組み合わせることすら可能です。

![Programmable Cryptography概念図](https://prod-files-secure.s3.us-west-2.amazonaws.com/8beade4f-e5e9-455c-9c1d-809f8a8db8be/22c84759-8a27-4668-8476-bffc0e4275c2/image.png)

Core ProgramではFHEなどを学ぶ機会を提供できませんでしたが、ゼロ知識証明だけでなく、これらの技術についても統合的に理解を深めることで、新たな応用分野を見つけることができるでしょう。

## 6. 引用文献

1. https://arxiv.org/html/2408.00243v1
2. https://www.criipto.com/blog/zero-knowledge-proofs
3. https://www.numberanalytics.com/blog/ultimate-guide-zero-knowledge-proofs-history-mathematics
4. https://cointelegraph.com/explained/zero-knowledge-proofs-explained
5. https://www.jri.co.jp/file/advanced/advanced-technology/pdf/15179.pdf
6. https://www.nttdata.com/jp/ja/trends/data-insight/2023/0724/
7. https://www.netattest.com/zero-knowledge-proof-2024_mkt_tst
8. https://www.chaincatcher.com/ja/article/2102285
9. https://www.debutinfotech.com/blog/zero-knowledge-proof-uses
10. https://www.chainalysis.com/blog/introduction-to-zero-knowledge-proofs-zkps/
11. https://arxiv.org/html/2502.07063v1
12. https://www2.eecs.berkeley.edu/Pubs/TechRpts/2025/EECS-2025-20.pdf
13. https://en.wikipedia.org/wiki/Zero-knowledge_proof
14. https://eprint.iacr.org/2024/050.pdf
15. https://ops-today.com/topics-1777/
16. https://www.gate.com/learn/articles/a-beginners-guide-to-zero-knowledge-proofs/1276
17. https://www.auditone.io/blog-posts/exploring-zero-knowledge-proofs-a-comparative-dive-into-zk-snarks-zk-starks-and-bulletproofs
18. https://zenn.dev/mameta29/scraps/7a41cdca76bced
19. https://www.wisdom.weizmann.ac.il/~oded/PSX/zk-tut02v3.pdf
20. https://people.csail.mit.edu/silvio/Selected%20Scientific%20Papers/Proof%20Systems/The_Knowledge_Complexity_Of_Interactive_Proof_Systems.pdf
21. https://www.circularise.com/blogs/zero-knowledge-proofs-explained-in-3-examples
22. https://updraft.cyfrin.io/courses/fundamentals-of-zero-knowledge-proofs/fundamentals/interactive-vs-non-interactive
23. https://www.scirp.org/reference/referencespapers?referenceid=2077830
24. https://www.researchgate.net/publication/377827237_Systematic_Review_Comparing_zk-SNARK_zk-STARK_and_Bulletproof_Protocols_for_Privacy-Preserving_Authentication
25. https://zenn.dev/mameta29/articles/3941b48b2971ea
26. https://www.reddit.com/r/CryptoTechnology/comments/1ka4txu/zeroknowledge_proofs_explained/
27. https://acompany.tech/privacytechlab/non-interactive-zkp
28. https://en.wikipedia.org/wiki/Non-interactive_zero-knowledge_proof
29. https://en.wikipedia.org/wiki/Fiat%E2%80%93Shamir_heuristic
30. https://www.researchgate.net/publication/2604232_Robust_Non-Interactive_Zero_Knowledge
31. https://www.cs.cornell.edu/~rafael/papers/nizk-preprocess.pdf
32. https://tomorrowdesk.com/info/zk-snark
33. https://www.numberanalytics.com/blog/future-cryptography-zero-knowledge-proofs
34. https://technode.global/2025/04/21/zero-knowledge-proofs-the-key-to-privacy-and-safety-in-crypto/
35. https://z.cash/learn/what-are-zero-knowledge-proofs/
36. https://arxiv.org/html/2503.22709v1
37. https://academy.bit2me.com/en/what-are-zk-stark/
38. https://icbc2025.ieee-icbc.org/workshop/zkdapps
39. https://www.binance.com/en/square/post/01-12-2025-experts-predict-continued-growth-and-adoption-of-zero-knowledge-proof-technology-by-2025-18818875911921
40. https://news.bitcoin.com/zk-proofs-2025-predictions-another-breakthrough-year-projected-expert-sees-100x-improvement/
41. https://law.stanford.edu/codex-the-stanford-center-for-legal-informatics/projects/zero-knowledge-cryptography/
42. https://sussblockchain.com/zero-knowledge-proof-workshop/
