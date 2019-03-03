pt = 0
for i in range(5):
	n = int(input())
	if n < 40: n = 40
	pt += n
 
print(int(pt/5))