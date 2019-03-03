n = int(input())
f = map(int, input().split())
c = int(input())

s = 0
for fi in f:
    s += ((fi+c-1) // c) * c

print(s)
