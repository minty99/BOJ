s = input()

i = 0
cnt = 0
while i < len(s):
	slice2 = s[i:i+2]
	if slice2 == 'c=' or slice2 == 'c-' or slice2 == 'd-' or slice2 == 'lj' or slice2 == 'nj' or slice2 == 's=' or slice2 == 'z=':
		i += 1
	if s[i:i+3] == 'dz=': i += 2
	i += 1
	cnt += 1
	
print(cnt)