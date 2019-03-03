import math

def writeStar(out, x, y):
	out[x][y] = '*'
	out[x+1][y-1] = '*'
	out[x+1][y+1] = '*'
	for i in range(y-2, y+3): out[x+2][i] = '*'
	return out

n = int(input())
k = math.log2(n/3)

# set 1: 1/2/5 set 2: 2/4/10 set 3: 2/4/10 / 4/8/20

center = n # s1: 3, s2: 6, s3: 12, s4: 24

out = [ [ ' ' for x in range(0, 2*n+100)] for y in range(0, n+100)] # out[x][y] = line x, col y
writeStar(out, 1, center)
now = 3
while now < n:
	i = 1
	while i <= 2*n:
		if out[now][i] is '*' and out[now][i+5] is ' ' and out[now][i-5] is ' ':
			if out[now][i-1] is ' ': writeStar(out, now+1, i-1)
			else: writeStar(out, now+1, i+1)
			i += 3
		i += 1
	now += 3

for i in range(1, n+1):
	s = ''.join(out[i])
	print(s[1:2*n])