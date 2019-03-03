def GCD(a, b):
    if b == 0: return a
    return GCD(b, a%b)

t = int(input())
for i in range(t):
    a, b = (int(x) for x in input().split())
    print(int(a*b/GCD(a, b)))
