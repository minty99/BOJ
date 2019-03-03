n = int(input())

a = int(n/5)
b = n%5

while True:
	if a<0:
		print(-1)
		break
	
	if b%3 == 0:
		print(int(a+b/3))
		break
	else:
		a -= 1
		b += 5