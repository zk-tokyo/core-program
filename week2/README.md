# Week 2 - Groth16

Groth16 の構成要素（QAP・Linear PCP・ペアリング）を通して、「なぜ 200 B で定数時間検証が可能なのか」が理解できます。

### 🌄コンテンツ

- Groth16の全体像
- QAP
- Linear PCP
- R1CS
- Groth16

### 🔗講義資料
- [pdf](./groth16.pdf)
- [slide](https://docs.google.com/presentation/d/14fKU6ypnEn2u--uySrmMuSF-Rs_hr-PZCQfNOSF3AGM/edit?usp=sharing)

### 🎥講義動画

https://youtu.be/uYqWn0nk7IE

### 演習問題

1. QAPのトレースがなぜ加算ゲートの出力を記録しなくてもいいのか、理由を説明してください。（ヒント: Linear PCP）
2. 講義で紹介された算術回路とセレクター多項式をもとにマスター多項式p(x)と商多項式q(x)を一つ考えてください。
3. Linear PCPベースのSNARKとGroth16がどのような安全性仮定に基づいているか説明してください。(ヒント: Generic Group Model, KoE Assumption)

提出方法:

[EXERCISE_FORMAT.md](./EXERCISE_FORMAT.md)のフォーマットに従って./exercises/<name>.mdを作成したPull Requestを提出してください。

### 📕参考資料
- https://rdi.berkeley.edu/zk-learning/assets/lecture9.pdf
