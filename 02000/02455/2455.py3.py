n = 0
max = 0
for i in range(4):
	a, b = [ int(x) for x in input().split() ]
	n = n - a + b
	if n > max: max = n

print(max)
