ans = 0
n = int(input())
for i in range(n):
    a, b = [ int(x) for x in input().split() ]
    ans += b % a
print(ans)