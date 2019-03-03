t = int(input())

for i in range(t):
	h, w, n = [ int(x) for x in input().split() ]
	print("%d%02d" % ((n-1) % h + 1, int((n-1) / h)+1))