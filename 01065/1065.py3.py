import math

def isHansu(n):
	l = [ int(n/1000), int((n%1000)/100), int((n%100)/10), int(n%10) ]
	start = 4 - (int(math.log10(n))+1)
	for i in range(start, 2):
		if l[i] - l[i+1] != l[i+1] - l[i+2]: return False
		
	return True

n = int(input())
count = 0
for i in range(1, n+1):
	if isHansu(i) is True: count += 1

print(count)