n = int(input())
s = []
for i in range(n):
    s.append(input())

s.sort()
t = []
i = 0
count = 0
now = s[0].split()[0]

while i < n:
    a, b = s[i].split()

    if now == a:
        if b == "enter": count += 1
        elif b == "leave": count -= 1
        i += 1
    else:
        if count > 0: t.append(now)
        now = a
        count = 0

if count > 0: t.append(now)

t.sort()
t = t[::-1]
for k in t:
    print(k)
