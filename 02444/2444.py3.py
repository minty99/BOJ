n = int(input())
for i in range(n):
    print(" " * (n-1-i), end="")
    print("*" * (2*(i+1)-1))

for i in range(1, n):
    print(" " * i, end="")
    print("*" * (2*(n-i)-1))
