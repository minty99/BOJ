a, b = [int(x) for x in input().split()]

print(a // b, end="")
if a % b != 0: print(".", end="")
else: exit()
a %= b
for i in range(2000):
    a *= 10
    print(a // b, end="")
    a %= b
