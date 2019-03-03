n, k = [ int(x) for x in input().split() ]
arr = [ int(x) for x in input().split() ]

s = sum(arr[:k])
m = s
for i in range(k, n):
    s += arr[i]
    s -= arr[i-k]
    m = max(m, s)

print(m)
