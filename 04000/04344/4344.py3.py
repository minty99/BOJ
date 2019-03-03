n = int(input())

for i in range(0, n):
	s = [int(x) for x in input().split()]
	avg = (sum(s)-s[0]) / s[0]
	cnt = 0
	for j in range(1, len(s)):
		if s[j] > avg: cnt += 1
	print("%.3f%%" % (cnt/s[0]*100))