t = int(input())

for z in range(t):
    n = input()
    rn = n[::-1]
    s = int(n) + int(rn)
    if str(s) == str(s)[::-1]: print("YES")
    else: print("NO")