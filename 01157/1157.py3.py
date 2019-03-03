s = input().lower()

array = [ 0 ] * 26
for i in range(len(s)):
	array[ord(s[i]) - ord('a')] += 1

M = 0
pos = '?'
for i in range(26):
	if array[i] > M:
		M = array[i]
		pos = chr(i + ord('A'))
	elif array[i] == M:
		pos = '?'

print(pos)