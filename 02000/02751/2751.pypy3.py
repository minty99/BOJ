n = int(input())
l = list()
for i in range(n): l += [int(input())]
l.sort()
for i in range(n): l[i] = str(l[i])
print('\n'.join(l))