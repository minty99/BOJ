s = input()
height = 10
for i in range(1, len(s)):
	if s[i] == s[i-1]: height += 5
	else: height += 10

print(height)
