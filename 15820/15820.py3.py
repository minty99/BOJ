import sys
a, b = [int(x) for x in input().split()]

for i in range(a):
    x, y = [int(z) for z in input().split()]
    if x != y:
        print("Wrong Answer")
        sys.exit()

for i in range(b):
    x, y = [int(z) for z in input().split()]
    if x != y:
        print("Why Wrong!!!")
        sys.exit()

print("Accepted")
