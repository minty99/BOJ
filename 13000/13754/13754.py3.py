n = int(input())

arr = []
s = 0
for i in range(n):
    arr += [int(input())]
    s += arr[i]

arr.sort()
arr = arr[::-1]
s -= arr[0]

if arr[0] >= s: print(s)
else:
    print((arr[0] + s)//2)
