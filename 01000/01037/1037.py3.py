n = int(input())
s = [ int(x) for x in input().split()]
s.sort()
print(s[0] * s[-1])
