arr = [ int(x) for x in input().split() ]

ans = 0
while True:
    arr.sort()
    if arr[0] + 1 == arr[1] and arr[1] + 1 == arr[2]: break
    ans += 1
    if arr[1] - arr[0] > arr[2] - arr[1]:
        arr[2] = arr[0] + 1
    else:
        arr[0] = arr[1] + 1

print(ans)
