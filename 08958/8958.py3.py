n = int(input())
 
for i in range(n):
	s = input()
	pt = 0
	combo = 0
	for j in range(len(s)):
		if s[j] == 'O':
			combo += 1
			pt += combo
		else:
			combo = 0
	print(pt)
 