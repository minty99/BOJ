arr = [ int(input()) for _ in range(9) ]
arr.sort()
for i in range(9):
    for j in range(i+1, 9):
        sum = 0
        for k in range(9):
            if not (k == i or k == j): sum += arr[k]
        if sum == 100:
            for k in range(9):
                if not (k == i or k == j):
                    print(arr[k])
