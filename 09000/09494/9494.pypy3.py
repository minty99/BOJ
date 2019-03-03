while True:
    lines = int(input())
    if lines == 0: break
    count = 0
    now = 0
    while count < lines:
        count += 1
        s = input()
        t = s.find(" ", now)
        if len(s) > now and t == -1: now = len(s)
        elif t > now: now = t 

    now += 1
    print(now)
