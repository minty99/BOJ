t = int(input())

for s in range(1, t+1):
    a, b = [int(x) for x in input().split() ]
    print("Case #%d: %d + %d = %d" % (s, a, b, a+b))
