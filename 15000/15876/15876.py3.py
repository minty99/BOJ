a, b = [int(x) for x in input().split()]

now = 0
cnt = 0
p = 0
while True:
    s = bin(now)[2:]
    for c in s:
        cnt += 1
        if p == 5: exit(0)
        if cnt % a == b or (cnt % a == 0 and a == b):
            print(c, end=" ")
            p += 1
    now += 1
