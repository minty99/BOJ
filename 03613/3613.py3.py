import sys
s = input()
if s.islower() and s[0] != '_' and s[-1] != '_':
    i = 0
    while i < len(s):
        if s[i] == '_':
            if s[i+1] == '_':
                print("Error!")
                sys.exit()
            s = s[:i] + s[i+1].upper() + s[i+2:]
        i += 1
elif not s.islower() and s[0].islower() and s.find("_") == -1:
    i = 0
    while i < len(s):
        if s[i].isupper():
            s = s[:i] + "_" + s[i].lower() + s[i+1:]
        i += 1
else:
    print("Error!")
    sys.exit()

print(s)
