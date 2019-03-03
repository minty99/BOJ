a1 = 0
a2 = 0
for i in range(1, 6):
    a = [ int(x) for x in input().split() ]
    if a2 < sum(a):
        a1 = i
        a2 = sum(a)
print("%d %d" % (a1, a2))
