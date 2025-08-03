def extended_euclidean(a, b):
    #拡張ユークリッドの互除法：
    #ax + by = gcd(a, b) を満たす (gcd, x, y) を返す
    
    r0, r1 = a, b
    s0, s1 = 1, 0
    t0, t1 = 0, 1

    while r1 != 0:
        q = r0 // r1
        r0, r1 = r1, r0 - q * r1
        s0, s1 = s1, s0 - q * s1
        t0, t1 = t1, t0 - q * t1

    return r0, s0, t0  # gcd, x, y

# 使用例
a = 5
b = 7
gcd, x, y = extended_euclidean(a, b)
print(f"gcd({a}, {b}) = {gcd}")
print(f"x = {x}, y = {y}")
print(f"{a} * {x} + {b} * {y} = {a*x + b*y}")
