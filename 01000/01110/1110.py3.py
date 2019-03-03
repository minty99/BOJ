s = input()
n = int(s)
l = [int(x) for x in list(s)] # [2, 6]
if n < 10: l = [0, n]

cycle = 0
while True:
	cycle += 1
	l = [l[1], int(list(str(sum(l)))[-1])]
	if l[0]*10+l[1] == n:
		print(cycle)
		break