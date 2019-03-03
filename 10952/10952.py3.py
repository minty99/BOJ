x = -1
y = -1

while True:
    x, y = [int(t) for t in input().split()]
    if x == 0 and y == 0: break
    print(x+y)
