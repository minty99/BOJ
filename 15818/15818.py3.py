n, m = [ int(x) for x in input().split() ]
a = [ int(x) for x in input().split() ]

s = 1
for x in a:
    s *= x
    s %= m
print(s)