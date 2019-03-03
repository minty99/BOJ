n = int(input())
cnt = n

for i in range(n):
	s = input()
	for j in range(ord('a'), ord('z')+1):
		flag = 0
		for k in s:
			if k == chr(j) and flag == 0: flag = 1
			if k != chr(j) and flag == 1: flag = 2
			if k == chr(j) and flag == 2:
				cnt -= 1
				break
		else: continue
		break

print(cnt)