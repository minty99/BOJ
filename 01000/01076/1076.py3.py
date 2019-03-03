s = []
d = []
for i in range(3):
    s.append(input())
    if s[i] == "black": d.append(0)
    if s[i] == "brown": d.append(1)
    if s[i] == "red": d.append(2)
    if s[i] == "orange": d.append(3)
    if s[i] == "yellow": d.append(4)
    if s[i] == "green": d.append(5)
    if s[i] == "blue": d.append(6)
    if s[i] == "violet": d.append(7)
    if s[i] == "grey": d.append(8)
    if s[i] == "white": d.append(9)

print((d[0] * 10 + d[1]) * 10**d[2])
