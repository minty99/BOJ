s = input()
while len(s) % 3 != 0:
    s = "0" + s

ans = ""
for i in range(0, len(s), 3):
    c = s[i:i+3]
    if c == "000":
        ans += "0"
    if c == "001":
        ans += "1"
    if c == "010":
        ans += "2"
    if c == "011":
        ans += "3"
    if c == "100":
        ans += "4"
    if c == "101":
        ans += "5"
    if c == "110":
        ans += "6"
    if c == "111":
        ans += "7"

print(ans)
