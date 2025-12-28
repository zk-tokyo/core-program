## 演習1

1. 減算は加法逆元を足す，除算は乗法逆元をかける．
2. 
```python
def egcd(a: int, b: int):
    old_r, r = a, b
    old_x, x = 1, 0
    old_y, y = 0, 1
    while r != 0:
        q = old_r // r
        old_r, r = r, old_r - q * r
        old_x, x = x, old_x - q * x
        old_y, y = y, old_y - q * y
    return old_r, old_x, old_y

if __name__ == "__main__":
    a = 56
    b = 15
    gcd_val, x, y = egcd(a, b)
    print(f"gcd({a}, {b}) = {gcd_val}")
    print(f"{a}*({x}) + {b}*({y}) = {a*x + b*y}")
```

3. $3 - 2 \mod 5 = \boxed{1}$
4. $3 \div 2 \mod 5 = \boxed{4}$
5. $(7 \times 5)^{-1} \mod 13 = \boxed{3}$

## 演習2

1. $\mathbb{F}_2$ での引き算 | `11011011`
2. $\mathbb{F}_{2^8}$ での引き算 | `11011011`
3. 既約多項式の例 | $x^3 + x^2 + 1$

## 演習3

1. * **問題名**：素因数分解問題

     **安全とされる理由**：

     * 現在知られているアルゴリズムは指数時間がかかる
     * 鍵長が十分に大きければ、現実的な時間で解くのは不可能
   * **問題名**：楕円曲線離散対数問題

     **安全とされる理由**：

     * 楕円曲線上では通常の離散対数問題よりも効率的な攻撃が存在しない
     * 小さい鍵サイズでも高い安全性を提供

2. * **名前**：Baby-step Giant-step アルゴリズム
     **手順概要**：

     1. $m = \lceil \sqrt{p-1} \rceil$ を計算
     2. Baby-step： $g^j \mod p$ を $j = 0$ から $m-1$ まで計算し、辞書に保存
     3. Giant-step： $h \cdot g^{-im} \mod p$ を $i = 0$ から $m-1$ まで計算し、上の辞書と一致するか確認

    　**なぜ効率的か**：

      * 総当たり（brute-force）は $O(n)$ 時間必要だが、この手法で $O(\sqrt{n})$ に短縮

3. $6$

## 演習4

1. **Baby-Step Giant-Step アルゴリズム**
   時間計算量が $O(\sqrt{n})$ で済む．

2. **Double-and-Add アルゴリズム**
   2進数表現を用いて演算回数を削減する．

3. BN254