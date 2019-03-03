while True:
    n = input()
    if n == '0': break
    s = [ int(x) for x in n ]
    while len(s) != 1:
        ss = sum(s)
        s = [ int(x) for x in str(ss)]
    print(s[0])
