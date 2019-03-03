def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

a, b = [ int(x) for x in input().split() ]

G = gcd(a, b)
L = a*b/G
print(int(L))
