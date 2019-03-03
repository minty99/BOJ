s = input()

while s.find('-') != -1:
    print(s[0], end="")
    s = s[s.find('-')+1:]
if len(s) > 0: print(s[0], end="")