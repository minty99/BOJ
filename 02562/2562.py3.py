M = 0
ans = 0
for i in range(1, 10):
    n = int(input())
    if M < n:
        M = n
        ans = i
print(M)
print(ans)