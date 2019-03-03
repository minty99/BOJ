from math import sqrt

t = int(input())
for i in range(t):
	x, y = [ int(x) for x in input().split() ]
	d = y - x
	max = int(sqrt(d))
	now = max**2
	count = max*2-1
	count += int((d - now) / max)
	if (d - now) % max != 0: count += 1
	print(count)