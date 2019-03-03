s = [ int(x) for x in input() ]
c = [ 0 for i in range(10) ]
for x in s: c[x] += 1
count = 0
while True:
	for i in range(0, 10):
		if c[i] != 0: break
	else:
		print(count)
		break
	if c[6] == 0 and c[9] > 0: c[9] -= 1
	if c[9] == 0 and c[6] > 0: c[6] -= 1
	for i in range(0, 10):
		if c[i] > 0: c[i] -= 1
	count += 1