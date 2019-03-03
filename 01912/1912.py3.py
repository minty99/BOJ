n = int(input())
arr = [ int(x) for x in input().split() ]
dp = [ arr[0] ]

for i in range(1, n):
    dp.append(max(dp[i-1] + arr[i], arr[i]))

answer = dp[0]
for k in dp:
    if k > answer: answer = k

print(answer)
