n, m = [ int(x) for x in input().split() ]
print(min((m-1) + m * (n-1), (n-1) + n * (m-1)))
