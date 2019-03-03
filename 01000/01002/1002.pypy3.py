def dist(x, y, a, b):
    return ((x-a)**2 + (y-b)**2)

t = int(input())

for _ in range(t):
    x1, y1, r1, x2, y2, r2 = [ int(x) for x in input().split() ]
    if x1 == x2 and y1 == y2 and r1 == r2:
        print("-1")
        continue
    centerdist2 = dist(x1, y1, x2, y2)
    if centerdist2 > (r1-r2)**2 and centerdist2 < (r1+r2)**2:
        print("2")
    elif centerdist2 == (r1+r2)**2 or centerdist2 == (r1-r2)**2:
        print("1")
    else:
        print("0")
