import sys
#sys.stdin = open("in.txt", "r")

n, k = map(int, input().split())

if k == 1:
    n = -n
    k = 0

if k % 2 == 1:
    print("ERROR")
    sys.exit(0)

if n > 0 and k == 0:
    print("INFINITE")
    sys.exit(0)

n -= k//2
ans = 0
while n > 0:
    n -= k//2
    ans += 1
print(ans)
