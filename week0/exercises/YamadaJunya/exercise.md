# 演習1

## 1. 減算と除算の計算方法を調べ、それぞれ逆元に注目して説明してください

- 減算：加法逆元を使った加算、つまり  
  $$a - b \equiv a + (p - b) \bmod p$$

- 除算：乗法逆元を使った乗算、つまり  
  $$a \div b \equiv a \cdot b^{-1} \bmod p$$


---

## 2. 拡張ユークリッド法について調べ、実装してください
    
拡張ユークリッド法は、ユークリッドの互除法を発展させて、次の形の整数解 \( x, y \) を求めるアルゴリズムである
$$\gcd(a, b) = ax + by$$

Python 実装
```python
def extended_gcd(a, b):
    if b == 0:
        return (a, 1, 0)
    else:
        gcd, x1, y1 = extended_gcd(b, a % b)
        x = y1
        y = x1 - (a // b) * y1
        return (gcd, x, y)

# 使用例
a = 56
b = 15
gcd, x, y = extended_gcd(a, b)
print(f"gcd({a}, {b}) = {gcd}")
print(f"{a}*({x}) + {b}*({y}) = {gcd}")
```

---

## 3. $3-2\mod{5}$ を計算してください

$3 - 2 \equiv 3 + (-2) \equiv 3 + 3  = 6 \equiv 1 \mod{5}$

---

## 4. $3÷2\mod{5}$ を計算してください

まず、2 の逆元を mod 5 で求める：  
$2x \equiv 1 \mod{5} \Rightarrow x = 3$  
（なぜなら $2 \times 3 = 6 \equiv 1 \mod{5}$）  
したがって：  
$3 \div 2 \equiv 3 \times 3 = 9 \equiv 4 \mod{5}$  
$\therefore\ 3 \div 2 \equiv 4 \mod{5}$

---

## 5. $(7 \times 5)^{-1} \mod{13}$ を計算してください

$(7 \times 5)^{-1} \mod{13} = (35)^{-1} \mod{13}$

$35 \equiv 9 \mod{13}$ よって、

$9^{-1} \mod{13}$ を求める。

$9x \equiv 1 \mod{13}$ を満たす $x$ を探すと、

$9 \times 3 = 27 \equiv 1 \mod{13}$

したがって、

${(7 \times 5)^{-1} \mod{13} = 3}$


---
# 演習2

## 1. $\mathbb{F}_2$ で10110101-0110110を解いてください
10000011

---

## 2. $\mathbb{F}_{2^8}$ で10110101-0110110を解いてください
10000011

---

## 3. $\mathbb{F}_{2^3}$ における $x^3+x+1$ 以外の既約多項式を一つ見つけてください

$x^3+x^2+1$

---

# 演習3

## 1. 離散対数問題以外で安全性仮定になっている数学的問題を２つ挙げてください。それぞれ、なぜ安全と言えるのか説明してください

1. RSA問題
概要：大きな合成数 $N = p \cdot q$ を素因数分解して $p, q$ を求める問題。  
安全性の理由：現在、数百桁の合成数を効率的に素因数分解する方法は知られていない。既知のアルゴリズム（例：数体篩）では膨大な計算時間が必要なため、安全性が保たれている。

2. LWE問題  
概要： $b = A \cdot s + e$ の形の式から、誤差 $e$ がある中で秘密ベクトル $s$ を推測する問題。  
安全性の理由：この問題は「格子問題」に帰着可能で、古典的にも量子的にも解くのが難しいことが証明されている。

---

## 2. 離散対数問題を効率的に解くアルゴリズムを一つ調べ、なぜ効率的か説明してください

Pollardのロー法は、離散対数問題に対して平均計算量 $O(\sqrt{n})$ を達成する確率的アルゴリズムである。擬似ランダム写像により生成される数列内の衝突（巡回）を利用し、少ない計算と定数メモリで解を導出できる。

---

## 3. $5^x \equiv 8 \pmod{23}$ の離散対数 $x$ を求めてください

総当たりで計算する。

| $x$ | $5^x \mod 23$                    |
| --- | -------------------------------- |
| 1   | $5$                              |
| 2   | $25 \equiv 2 \mod 23$            |
| 3   | $5^3 = 125 \equiv 10 \mod 23$    |
| 4   | $5^4 = 625 \equiv 4 \mod 23$     |
| 5   | $5^5 = 3125 \equiv 20 \mod 23$   |
| 6   | $5^6 = 15625 \equiv 8 \mod 23$   |

答え $x = 6$

---

# 演習4

## 1. ECDLPを効率的に計算するアルゴリズムをひとつ挙げてください
Pollard’s Rhoアルゴリズム

---

## 2. スカラー倍算を効率的に計算するアルゴリズムをひとつ挙げてください
Double-and-Add法

---

## 3. ゼロ知識証明ライブラリ「Circom」で使われているデフォルトの楕円曲線を調べてください
BN254

---

## 4. BLS12-381上の2点P(3,5),Q(5,3)の加算をシュミレータを使って計算してください
skip
