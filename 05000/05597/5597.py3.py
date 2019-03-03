flag = [ False for x in range(31) ]

for i in range(28):
    flag[int(input())] = True

for i in range(1, 31):
    if flag[i] == False: print(i)

