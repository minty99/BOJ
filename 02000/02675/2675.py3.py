t = int(input())

for i in range(t):
	r, s = input().split()
	r = int(r)
	
	ss = list(map(lambda x: x * r, s))
	print(''.join(ss))