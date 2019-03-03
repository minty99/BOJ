s = input()

ans = ""
for c in s:
    if c == '0':
        ans += "000"
    if c == '1':
        ans += "001"
    if c == '2':
        ans += "010"
    if c == '3':
        ans += "011"
    if c == '4':
        ans += "100"
    if c == '5':
        ans += "101"
    if c == '6':
        ans += "110"
    if c == '7':
        ans += "111"

while len(ans) > 1 and ans[0] == '0':
    ans = ans[1:]
print(ans)
