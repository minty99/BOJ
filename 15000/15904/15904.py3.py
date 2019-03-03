s = input()
over = False
while True:
    i = s.find('U')
    if i == -1: break
    s = s[:i] + s[i+1:]
    l = i

    i = s.find('C', l)
    if i == -1: break
    s = s[:i] + s[i+1:]
    l = i

    i = s.find('P', l)
    if i == -1: break
    s = s[:i] + s[i+1:]
    l = i

    i = s.find('C', l)
    if i == -1: break
    s = s[:i] + s[i+1:]

    print("I love UCPC")
    over = True
    break
if not over: print("I hate UCPC")
