e, s, m = map(int, input().split())
n = 1
ee = 1
ss = 1
mm = 1
while True:
    if ee == e and ss == s and mm == m:
        print(n)
        break
    n += 1
    ee += 1
    ss += 1
    mm += 1
    if ee > 15: ee -= 15
    if ss > 28: ss -= 28
    if mm > 19: mm -= 19