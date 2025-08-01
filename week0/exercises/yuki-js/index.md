# Week 0 Exercises - Yuki Aoki

回答者: Yuki Aoki

## 演習1

> 減算と除算の計算方法を調べ、それぞれ逆元に注目して説明してください 

減算の計算方法について: 加法の単位元は $0$ で、加法の逆元を定義できるので、逆元を加算することにより、有限体上の減算を計算できる。
除算の計算方法について: 乗法の単位元は $1$ で、乗法の逆元を定義できるので、逆元を乗算することにより、有限体情の除算を計算できる。


> 拡張ユークリッド法について調べ、実装してください

ユークリッド互除法を拡張し、

$$ax+by=\gcd(a,b)$$

を満たす $(x,y)$ の組を見つけることができるアルゴリズムである。


```python

def euclid(a,b):
  if a < b:
    b, a = a, b
  
  if b == 0:
    return a, 1, 0
  else:
    g, t, s = euclid(b, a % b)
    return g, s, t - (a // b) * s


g, t, s = euclid(27,4)
print(f"gcd(27, 4) = {g}, t = {t}, s = {s}")

assert 27 * t + 4 * s == g

  
```

> 3-2(mod5)を計算せよ

1

> 3÷2(mod5)を計算せよ

$$2^{-1} = 3$$
$$3 * 2^{-1} = 3 * 3 = 9 = 4$$

4

> $(7 * 5)^{-1} \mod 13$を計算せよ

$$(7 * 5)^{-1} = 7^{-1} * 5^{-1} = 2 * 8 = 16 = 3 \mod 13$$

3

## 演習2

> $\mathbb{F}_2$ で10110101 - 00110110を解いてください

$\mathbb{F}_2 = \{x \in \mathbb{R} | x \mod 2\}$ なので

1

> $\mathbb{F}_{2^8}$ で10110101 - 00110110を解いてください

各ビットのxorを取ればよいので

10000011

> $\mathbb{F}_{2^3}$ における $x^3 + x + 1$ 以外の既約多項式を一つ見つけてください

$$x^3 + x^2 + 1$$

## 演習3

> 離散対数問題以外で安全性仮定になっている数学的問題を２つ挙げてください。それぞれ、なぜ安全と言えるのか説明してください

- 素因数分解困難性: 古典コンピュータで巨大な合成数の素因数分解を多項式時間で解く方法が見つかっていないから。
- LWE: 多項式時間でLWE問題を解くアルゴリズムが見つかっていないから。

> 離散対数問題を効率的に解くアルゴリズムを一つ調べ、なぜ効率的か説明してください

Baby-step giant-stepアルゴリズム

探索範囲を分割し、また、事前計算したリストを用意しておくことで、探索範囲が小さくなり、事前計算情報から取得すればよく高速だから

> $5^x \equiv 8 (\mod 23)$を解け


x=6

## 演習4


> ECDLPを効率的に計算するアルゴリズムをひとつ挙げてください

Baby-step giant-stepアルゴリズム

> スカラー倍算を効率的に計算するアルゴリズムをひとつ挙げてください

バイナリ法

> ゼロ知識証明ライブラリ「Circom」で使われているデフォルトの楕円曲線を調べてください

bn128

> BLS12-381上の2点P(3,5),Q(5,3)の加算をシュミレータを使って計算してください

そもそも点Pはない…？