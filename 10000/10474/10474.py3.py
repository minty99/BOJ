while True:
    a, b = [ int(x) for x in input().split() ]
    if a == 0 and b == 0: break
    print("%d %d / %d" % (a // b, a % b, b))