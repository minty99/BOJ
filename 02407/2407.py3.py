n, k = [ int(x) for x in input().split() ]
C = [ [ 0 for _ in range(1200) ] for __ in range(1200) ]

C[1][0] = 1
C[1][1] = 1
for i in range(2, n+1):
    for j in range(0, i+1):
        C[i][j] = C[i-1][j-1] + C[i-1][j]
print(C[n][k])