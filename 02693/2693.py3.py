t = int(input())
for i in range(t):
    a = [ int(x) for x in input().split() ]
    a.sort()
    print(a[7])