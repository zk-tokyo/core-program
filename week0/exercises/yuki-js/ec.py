
import json
import os

CURVE_JSON = os.path.join(os.path.dirname(__file__), "curve.json")

with open(CURVE_JSON) as f:
    curve = json.load(f)

p = int(curve["field"]["p"], 16)
A = int(curve["params"]["a"]["raw"], 16)
B = int(curve["params"]["b"]["raw"], 16)
G1_x = int(curve["generator"]["x"]["raw"], 16)
G1_y = int(curve["generator"]["y"]["raw"], 16)
ORDER = int(curve["order"], 16)

def euclid(a, b):
    if a < b:
        b, a = a, b
    if b == 0:
        return a, 1, 0
    else:
        g, t, s = euclid(b, a % b)
        return g, s, t - (a // b) * s

class Fp:
    def __init__(self, value):
        self.value = value % p
    def __add__(self, other):
        return Fp(self.value + other.value)
    def __sub__(self, other):
        return Fp(self.value - other.value)
    def __mul__(self, other):
        return Fp(self.value * other.value)
    def __neg__(self):
        return Fp(-self.value)
    def __eq__(self, other):
        return self.value == other.value
    def __pow__(self, n):
        return Fp(pow(self.value, n, p))
    def inv(self):
        g, x, y = euclid(self.value, p)
        assert g == 1
        return Fp(x)
    def __truediv__(self, other):
        return self * other.inv()
    def __repr__(self):
        return f"Fp(0x{self.value:x})"

class G1:
    def __init__(self, x, y, inf=False):
        self.x = x
        self.y = y
        self.inf = inf
    def __add__(self, other):
        if self.inf:
            return other
        if other.inf:
            return self
        if self.x == other.x:
            if (self.y + other.y) == Fp(0):
                return G1(None, None, True)
            l = (Fp(3) * self.x * self.x + Fp(A)) / (Fp(2) * self.y)
        else:
            l = (other.y - self.y) / (other.x - self.x)
        x3 = l * l - self.x - other.x
        y3 = l * (self.x - x3) - self.y
        return G1(x3, y3)
    def __rmul__(self, k):
        n = self
        r = G1(None, None, True)
        for bit in bin(k)[2:]:
            r = r + r
            if bit == '1':
                r = r + n
        return r
    def __repr__(self):
        if self.inf:
            return "G1(infinity)"
        return f"G1(x=0x{self.x.value:x}, y=0x{self.y.value:x})"


if __name__ == "__main__":
    P = G1(Fp(3), Fp(5))
    Q = G1(Fp(5), Fp(3))
    R = P + Q
    print(f"P + Q = {R}")
