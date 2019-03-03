def d(n):
	s = sum([int(x) for x in list(str(n))])
	return n+s

s = set()
for i in range(1, 10001):
	n = i
	while True:
		n = d(n)
		if n >= 10000: break
		s.add(n)
		
for i in range(1, 10000):
	if i not in s: print(i)