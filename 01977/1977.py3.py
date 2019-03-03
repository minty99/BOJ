a = int(input())
b = int(input())

s = 0
m = 999999
for i in range(1, 101):
    if i**2 >= a and i**2 <= b:
        s += i**2
        if m > i**2: m = i**2

if s > 0:
    print(s)
    print(m)
else:
    print(-1)
