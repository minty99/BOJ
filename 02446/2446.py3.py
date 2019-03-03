n = int(input())

arr = [ (2*x+1) for x in range(n) ]
rev = arr[::-1]
m = max(arr)

for i in rev:
    print(" " * ((m - i) // 2) + "*" * i)

for i in arr[1:]:
    print(" " * ((m - i) // 2) + "*" * i)
