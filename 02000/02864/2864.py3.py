a, b = input().split()

for k in range(len(a)):
    if a[k] == '5' or a[k] == '6': a = a[:k] + '5' + a[k+1:]

for k in range(len(b)):
    if b[k] == '5' or b[k] == '6': b = b[:k] + '5' + b[k+1:]

print(int(a) + int(b), end=" ")

for k in range(len(a)):
    if a[k] == '5' or a[k] == '6': a = a[:k] + '6' + a[k+1:]

for k in range(len(b)):
    if b[k] == '5' or b[k] == '6': b = b[:k] + '6' + b[k+1:]

print(int(a) + int(b))
