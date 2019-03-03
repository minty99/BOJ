v = int(input()) * int(input()) * int(input())
l = list(str(v))
s = [ 0 ] * 10
for i in range(0, len(l)): s[int(l[i])] += 1

for x in s: print(x)