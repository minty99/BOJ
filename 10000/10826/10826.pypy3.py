n = int(input())
a1 = 0
a2 = 1
a3 = 1
if n == 0: print(0)
elif n == 1: print(1)
else:
    i = 2
    while i <= n:
        a3 = a1 + a2
        a1 = a2
        a2 = a3
        i += 1
    print(a3)
