import math

x = int(input())
n = 0.5 * (-1 + math.sqrt(1 + 8*x)) # n^2 + n - 2x = 0
if n == int(n): n -= 1
n = int(n)

hap = n + 2
if n % 2 == 0: print("%d/%d" % ( hap - (x - (n*(n+1)/2)), x - (n*(n+1)/2) ))
else: print("%d/%d" % ( x - (n*(n+1)/2), hap - (x - (n*(n+1)/2)) ))