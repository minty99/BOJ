a, b = [ int(x) for x in input().split() ]
c = int(input())

b += c
while b >= 60:
    b -= 60
    a += 1

while a >= 24:
    a -= 24

print("%d %d" % (a, b))
