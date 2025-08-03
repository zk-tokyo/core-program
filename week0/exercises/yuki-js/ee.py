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

  