s = input()
arr = []

for i in range(len(s)):
    arr += [s[i:]]

arr.sort()
for c in arr:
    print(c)
