t = int(input())
for caseN in range(1, t+1):
    s = int(input())
    if s == 0:
        print("Case #%d: INSOMNIA" % caseN)
        continue

    now = 0
    flag = [ 0 for _ in range(10) ]
    while sum(flag) < 10:
        now += s
        for x in str(now):
            flag[int(x)] = 1

    print("Case #%d: %d" % (caseN, now))
