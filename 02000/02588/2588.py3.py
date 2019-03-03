a = int(input())
b = int(input())

f = a*b
c = a * (b//100)
b %= 100
d = a * (b//10)
b %= 10
e = a * b

print(e)
print(d)
print(c)
print(f)
