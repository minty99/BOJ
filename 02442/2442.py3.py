n = int(input())
for i in range(n):
    print(" " * (n-1-i), end="")
    print("*" * (2*(i+1)-1))
