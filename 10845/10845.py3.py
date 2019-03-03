n = int(input())
queue = []
for i in range(n):
	s = input().split()
	if len(s) == 2: # push
		num = int(s[1])
		queue = [ num ] + queue
	if s[0] == "front":
		if len(queue) > 0: print(queue[len(queue)-1])
		else: print(-1)
	if s[0] == "size":
		print(len(queue))
	if s[0] == "empty":
		if len(queue) == 0: print(1)
		else: print(0)
	if s[0] == "pop":
		if len(queue) > 0:
			print(queue[len(queue)-1])
			queue = queue[:-1]
		else: print(-1)
	if s[0] == "back":
		if len(queue) > 0: print(queue[0])
		else: print(-1)
