n = int(input())

print(" " * (n-1) + "*")
space = 1
for i in range(n-1, 1, -1):
    print(" " * (i-1) + "*" + " " * space + "*")
    space += 2
if n > 1:
    print("*" * (2*n-1))
