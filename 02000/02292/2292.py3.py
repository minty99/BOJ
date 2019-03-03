n = int(input())
dis = 1
now = 1
while True:
	if n <= now:
		print(dis)
		break
	now += dis * 6
	dis += 1