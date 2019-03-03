import sys
for line in sys.stdin:
    a, b, c, d = [ int(x) for x in line.split() ]
    t = a + b + c + d
    if t == 3: print("A")
    if t == 2: print("B")
    if t == 1: print("C")
    if t == 0: print("D")
    if t == 4: print("E")
