n = int(input())
arr = [ 0 for x in range(n+1) ]
dp = [ [0 for x in range(3)] for x in range(n+1)  ]
for i in range(1, n+1): arr[i] = int(input())

for i in range(1, n+1):
    dp[i][1] = dp[i-1][2] + arr[i]
    dp[i][2] = max(dp[i-2][1], dp[i-2][2]) + arr[i]

print(max(dp[n][1], dp[n][2]))
