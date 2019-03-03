n = int(input())
s = []
for i in range(n): s += [ input() ]

out = s[0]
for i in range(len(s[0])):
    for j in range(1, n):
        if s[0][i] != s[j][i]:
            out = out[:i] + "?" + out[i+1:]
            break

print(out)
