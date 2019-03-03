# n <= 10, l <= 10^1000, k <= 1000, m <= 1000
# n: count of a_i, range: l~l+k-1, print: last m digits
n, l, k, m = map(int, input().split())
a = list()
div = 10**m
for i in range(n+1): a.append(int(input())%div)

for i in range(l, l+k): # i : value of x
    sum = a[n]          # constant (a_n)
    for j in range(n):
        sum += a[j] * (i**(n-j))
        sum %= div
    answer = 0
    for i in range(m):
        answer += (sum%10)**2
        sum = sum//10
        if sum == 0: break
    print(answer)
