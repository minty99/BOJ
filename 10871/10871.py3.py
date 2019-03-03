s = input().split()
n = int(s[0])
x = int(s[1])
t = input().split()

for i in range(0, n):
    if int(t[i]) < x: print(t[i], end=' ')