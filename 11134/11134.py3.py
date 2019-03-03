t = int(input())

for z in range(t):
    a, b = [ int(x) for x in input().split() ]
    if a % b == 0: print(a//b)
    else: print(a // b + 1)
