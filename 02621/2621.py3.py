col = []
scr = []

for i in range(5):
    s = input().split()
    col += [s[0]]
    scr += [int(s[1])]

# rule 1
t = sorted(scr)
flag = True
for i in range(4):
    if col[i] != col[i+1] or t[i+1] - t[i] != 1:
        flag = False
        break

if flag:
    print(900 + t[4])
    exit()

# rule 2
if t[1] == t[2] == t[3] == t[4] or t[0] == t[1] == t[2] == t[3]:
    print(800 + t[3])
    exit()

# rule 3
if (t[0] == t[1] == t[2] and t[3] == t[4]) or (t[0] == t[1] and t[2] == t[3] == t[4]):
    if t[0] == t[2]: print(10 * t[0] + t[4] + 700)
    if t[0] != t[2]: print(10 * t[4] + t[0] + 700)
    exit()

# rule 4
if col[0] == col[1] == col[2] == col[3] == col[4]:
    print(t[4] + 600)
    exit()

# rule 5
for i in range(4):
    if t[i+1] - t[i] != 1: break
    if i == 3:
        print(t[4] + 500)
        exit(0)

# rule 6
if t[0] == t[1] == t[2] or t[1] == t[2] == t[3] or t[2] == t[3] == t[4]:
    print(t[2] + 400)
    exit(0)

# rule 7
flag = True
if (t[0] == t[1] and t[2] == t[3]): print(t[3] * 10 + t[0] + 300)
elif (t[0] == t[1] and t[3] == t[4]): print(t[4] * 10 + t[0] + 300)
elif (t[1] == t[2] and t[3] == t[4]): print(t[4] * 10 + t[1] + 300)
else: flag = False

if flag: exit()

# rule 8
for i in range(4):
    if t[i] == t[i+1]:
        print(200 + t[i])
        exit()

# rule 9
print(t[4] + 100)
