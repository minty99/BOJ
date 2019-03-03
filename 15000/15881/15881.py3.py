n = int(input())
s = input()

cnt = 0
idx = 0
l = n
while idx+3 < l:
    if s[idx:idx+4] == 'pPAp':
        idx += 4
        cnt += 1
    else: idx += 1
print(cnt)
