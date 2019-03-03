import sys

n = int(input())
arr = [[0 for x in range(n)] for y in range(n)]
cnt = [0 for x in range(n * n)]


def search(x, y, num):
    arr[x][y] = num
    cnt[-num] += 1
    if x - 1 >= 0 and arr[x - 1][y] == 1:
        search(x - 1, y, num)
    if x + 1 < n and arr[x + 1][y] == 1:
        search(x + 1, y, num)
    if y - 1 >= 0 and arr[x][y - 1] == 1:
        search(x, y - 1, num)
    if y + 1 < n and arr[x][y + 1] == 1:
        search(x, y + 1, num)


for i in range(n):
    s = sys.stdin.readline()
    for j in range(n):
        arr[i][j] = int(s[j])

num = 0
for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            num -= 1
            search(i, j, num)
cnt.sort()
print(-num)
for t in cnt:
    if t != 0: print(t)
