n = int(input())
stack = []
for i in range(n):
	s = input().split()
	if len(s) == 2:
		num = int(s[1])
		stack.append(num)
	if s[0] == "top":
		if len(stack) > 0: print(stack[len(stack)-1])
		else: print(-1)
	if s[0] == "size":
		print(len(stack))
	if s[0] == "empty":
		if len(stack) == 0: print(1)
		else: print(0)
	if s[0] == "pop":
		if len(stack) > 0:
			print(stack[len(stack)-1])
			stack = stack[:-1]
		else: print(-1)
