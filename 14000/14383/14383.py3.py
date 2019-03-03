def flip(s, k): # s의 위쪽 k개를 뒤집는다.
    new_s = ""
    for i in range(k):
        if s[k-i-1] == '+': new_s += '-'
        else: new_s += '+'
    new_s += s[k:]
    return new_s

def finished(s):
    for x in s:
        if x == '-': return False
    return True

t = int(input())
for caseN in range(1, t+1):
    s = input()
    counter = 0

    while not finished(s):
        counter += 1
        p = len(s)-1
        while s[p] == '+' :
            s = s[:-1]
            p -= 1

        if s[0] == '+':
            ptr = 0
            while s[ptr] == s[ptr+1]: ptr += 1
            s = flip(s, ptr+1)
        else: s = flip(s, len(s))

    print("Case #%d: %d" % (caseN, counter))
