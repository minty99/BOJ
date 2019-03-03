n = int(input())
a = [ int(x) for x in input().split() ]
m = int(input())
s = [ int(x) for x in input().split() ]

for x in s:
    if x in a: print(1)
    else: print(0)
