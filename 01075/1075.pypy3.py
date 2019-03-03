n = int(input())
f = int(input())

n -= n%100

for i in range(n, n+100):
    if i%f == 0:
        print("%02d" % (i%100))
        break
