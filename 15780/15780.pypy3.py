n, k = [ int(x) for x in input().split() ]
arr = [ (int(x)+1)//2 for x in input().split() ]

if sum(arr) >= n: print("YES")
else: print("NO")
