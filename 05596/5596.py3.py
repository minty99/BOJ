a, b, c, d = [ int(x) for x in input().split() ]
e, f, g, h = [ int(x) for x in input().split() ]

s = a+b+c+d
t = e+f+g+h

print(max(s, t))
