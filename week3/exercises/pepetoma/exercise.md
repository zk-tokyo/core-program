# Weeek 0 演習問題回答

## 演習1
### 1.
Proofには、客観的で絶対的な真実を示し、必ずしも他者の存在に依存しないというニュアンスがある。
一方、Argumentには、相手に対する説得や論証といった、他者とのやり取りを前提とする。

SNARKは知識自体を客観的に開示するわけではなく、証明者が自身の主張に対する検証者からの質問・チャレンジに正しく応答できることを示すことで、確率的に正しさを主張する仕組みです。
応答することで正しさを示すという点から、proofという表現するよりも、argumentといる表現の方が適している。

### 2.
単純なKZGコミットメントは次のとおりであるが、
$$\text{com}_f = g^{f(\tau)}$$

次のようにすることで、秘匿性を持たせることができる。
$$\text{com}_f = g^{f(\tau) + r \cdot \eta}$$

ここで、
$r$ はランダムに選択されるマスキング値
$\eta$ は追加のランダムネス要素

### 3.
|     |$q_L$|$q_R$|$q_M$|$q_O$|$q_C$|
| --- | --- | --- | --- | --- | --- |
|gate#0|0|0|1|-1|0|
|gate#1|1|-1|0|-1|0|
|gate#2|0|0|1|-1|0|
|gate#3|0|0|1|-1|0|
|gate#4|1|1|0|-1|0|


|     |L|R|O|
| --- | --- | --- | --- |
|gate#0|$a$|$b$|$a \times b$|
|gate#1|$a \times b$|$a$|$(a \times b) - a$|
|gate#2|5|$(a \times b) - a$|$5 \times ((a \times b) - a)$|
|gate#3|2|$b$|$2 \times b$|
|gate#4|$5 \times ((a \times b) - a)$|$2 \times b$|$5 \times ((a \times b) - a) + 2 \times b$|

|     |$\sigma_L$|$\sigma_R$|$\sigma_O$|
| --- | --- | --- | --- |
|gate#0|$\omega^1 \cdot k_1$|$\omega^3 \cdot k_1$|$\omega^1 \cdot k_0$|
|gate#1|$\omega^0 \cdot k_2$|$\omega^0 \cdot k_0$|$\omega^2 \cdot k_1$|
|gate#2|$\omega^2 \cdot k_0$|$\omega^1 \cdot k_2$|$\omega^4 \cdot k_0$|
|gate#3|$\omega^3 \cdot k_0$|$\omega^0 \cdot k_1$|$\omega^4 \cdot k_1$|
|gate#4|$\omega^2 \cdot k_2$|$\omega^3 \cdot k_2$|$\omega^4 \cdot k_2$|

上記の表を参考に、各多項式は次のように表せる

- $q_L$ = $(1,0), (\omega,1), (\omega^2,0), (\omega^3,0), (\omega^4,1)$ の五点を通る多項式
- $q_R$ = $(1,0), (\omega,-1), (\omega^2,0), (\omega^3,0), (\omega^4,1)$ の五点を通る多項式
- $q_M$ = $(1,1), (\omega,0), (\omega^2,1), (\omega^3,1), (\omega^4,0)$ の五点を通る多項式
- $q_O$ = $(1,-1), (\omega,-1), (\omega^2,-1), (\omega^3,-1), (\omega^4,-1)$ の五点を通る多項式
- $q_C$ = $(1,0), (\omega,0), (\omega^2,0), (\omega^3,0), (\omega^4,0)$ の五点を通る多項式
<br>
<br>
- $L$ = $(1,a), (\omega,a \times b), (\omega^2,5), (\omega^3,2), (\omega^4,5 \times ((a \times b) - a))$ の五点を通る多項式
- $R$ = $(1,b), (\omega,a), (\omega^2,(a \times b) - a), (\omega^3,b), (\omega^4,2 \times b)$ の五点を通る多項式
- $O$ = $(1,a \times b), (\omega,(a \times b) - a), (\omega^2,5 \times ((a \times b) - a)), (\omega^3,2 \times b), (\omega^4,5 \times ((a \times b) - a) + 2 \times b)$ の五点を通る多項式
<br>
<br>
- $\sigma_L$ = $(1, \omega^1 \cdot k_1), (\omega, \omega^0 \cdot k_2), (\omega^2, \omega^2 \cdot k_0), (\omega^3, \omega^3 \cdot k_0), (\omega^4, \omega^2 \cdot k_2)$ の五点を通る多項式
- $\sigma_R$ = $(1, \omega^3 \cdot k_1), (\omega, \omega^0 \cdot k_0), (\omega^2, \omega^1 \cdot k_2), (\omega^3, \omega^0 \cdot k_1), (\omega^4, \omega^3 \cdot k_2)$ の五点を通る多項式
- $\sigma_O$ = $(1, \omega^1 \cdot k_0), (\omega, \omega^2 \cdot k_1), (\omega^2, \omega^4 \cdot k_0), (\omega^3, \omega^4 \cdot k_1), (\omega^4, \omega^4 \cdot k_2)$ の五点を通る多項式


### 4.
パブリックな値の集合を$\{v_i\}_{i \in S}$とし、対応するインデックス集合を$S$とし、以下のようなパブリックインプット多項式$PI(X)$を構築します。
$$PI(X) = \sum_{i \in S} v_i \cdot L_i(X)$$

ここで<br>
$v_i$：パブリックな入力・出力値<br>
$L_i(X)$：$i$番目のラグランジュ基底多項式<br>
$S$：パブリックインデックス集合

ウィットネス多項式 $W(X)$ と パブリックインプット多項式 $PI(X)$ の差分として制約多項式を次のように定めます。
$$h(X) = W(X) - PI(X)$$

消滅多項式（vanishing polynomial）を用いて
$$Z_S(X) = \prod_{i \in S} (X - \omega^i)$$

次のように表し、
$$h(X) = q(X) \cdot Z_S(X)$$

商多項式である$q(X)$に対して、KZGコミットメントを行うことで、1つのKZG評価証明で証明を行うことが可能。