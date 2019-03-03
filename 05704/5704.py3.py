s = ""
while True:
    a = [ 0 for x in range(26) ]
    s = input()
    if s == "*": break
    for c in s:
        if c == " ": continue
        a[ord(c) - ord('a')] = 1
    if sum(a) == 26: print("Y")
    else: print("N")
