# 演習問題

## zkSNARKの具体的なユースケースを自分で一つ考えて、p.23にある方式のうちどれを使うべきか理由とともに説明してください

結婚の意志を証明し公告する「ビット婚姻」というアプリケーションを考えてみる。結婚の意志を証明するためには、結婚の条件を満たしていることや婚姻届のformat validationを行う必要がある。しかしながら、個人情報の保護のため、婚姻届の内容を公開することは避けたい。そこで、zkSNARKを利用して、婚姻届の内容が正しいことを証明しつつ、その内容自体は公開しない、というユースケースを考えてみる。
公告するとはいっても、ブロックチェーンにアップロードするとは言っていない。HTTPでもよいことになる。必要に応じて検証をする形をとる。

証明サイズも検証時間も気にしなくていいので、BulletproofsまたはFRI-STARKを使うべきである。
Trusted Setupが必要ないので、結婚前に浮かれているカップルでも安心してデータをアップロードできる。
証明サイズや検証時間が多少大きいが、本仮定ではそれほど気にならない。

## 実用化されているZKアプリケーションを一つ見つけて、以下の3つのドメインに何が採用されているのかURLとともに答えてください

Self

DSL: Circom (https://github.com/selfxyz/self/blob/cb2ef9137e64d07e98e9200490ac5052270d7fae/circuits/circuits/register/register.circom) (一部Noirコードがあったが、何をやっているのかよくわからなかった。)
Snarkフレンドリ形式: R1CS (https://github.com/selfxyz/self/blob/cb2ef9137e64d07e98e9200490ac5052270d7fae/circuits/scripts/build/common.sh#L78)
バックエンド証明: Groth16(https://github.com/selfxyz/self/blob/cb2ef9137e64d07e98e9200490ac5052270d7fae/circuits/scripts/build/common.sh#L82)

## 2で採用されている方法にはどんな特徴があるか説明してください

Circom: 定番のDSLである。回路を簡潔に記述できる。実績も豊富で、コミュニティも活発である。
R1CS: Circomなどで書かれた回路を線形結合の形に表現したもの。先発で、色々他の仕組みと相性がいいらしい。
Groth16: 証明方式の一つ。Trusted Setupが必要だが、証明サイズが小さい。先発で、実績も豊富である。