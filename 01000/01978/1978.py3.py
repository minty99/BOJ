from math import sqrt

primes = [ False for _ in range(1001)]
for i in range(2, 1001):
    for j in range(2, int(sqrt(i)+1)):
        if i%j == 0: break
    else: primes[i] = True
n = int(input())
count = 0
s = [ int(x) for x in input().split() ]
for i in s:
    if primes[i] == True: count += 1

print(count)
