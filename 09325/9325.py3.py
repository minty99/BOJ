t = int(input())
while t > 0:
    t -= 1
    s = int(input())
    n = int(input())
    for i in range(n):
        q, p = [ int(x) for x in input().split() ]
        s += q * p
    print(s)