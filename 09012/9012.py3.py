t = int(input())
for i in range(t):
	count = 0
	s = input()
	for j in s:
		if j == '(': count += 1
		else: count -= 1
		if count < 0:
			print("NO")
			break
	else:
		if count == 0: print("YES")
		else: print("NO")
