import math
answer = 0
x = int(input())
n = 2 ** int(math.log2(x))
while x > 0:
    if x >= n:
        x -= n
        answer += 1
    n /= 2
print(answer)
