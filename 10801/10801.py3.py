a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

cnt_a = cnt_b = 0
for i in range(10):
    if a[i] > b[i]: cnt_a += 1
    elif a[i] < b[i]: cnt_b += 1

if cnt_a > cnt_b: print("A")
elif cnt_a < cnt_b: print("B")
else: print("D")
