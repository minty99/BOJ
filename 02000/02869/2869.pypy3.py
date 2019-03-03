a, b, v = [ int(x) for x in input().split() ]

day = (v - a) // (a - b)
h = (a - b) * day

while True:
    day += 1
    h += a
    if h >= v:
        print(day)
        break
    h -= b
