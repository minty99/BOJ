s = input()
time = 0
t = [ 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 ]
for i in range(len(s)):
	n = ord(s[i]) - ord('A') # A = 0 B = 1 ...
	time += t[n]
print(time)