n = int(input())
arr = []

for i in range(n):
    arr.append(int(input()))

arr.sort()

m = 1
cnt = 1
ans = arr[0]
for i in range(1, n):
    if arr[i] == arr[i-1]:
        cnt += 1
    else:
        if m < cnt:
            m = cnt
            ans = arr[i-1]
        cnt = 1
if m < cnt:
    m = cnt
    ans = arr[i-1]
print(ans)
