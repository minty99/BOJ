m = 987654321
sum = 0
for i in range(7):
	s = int(input())
	if s % 2 == 1:
		if m > s: m = s
		sum += s

if sum == 0: print(-1)
else:
	print(sum)
	print(m)
