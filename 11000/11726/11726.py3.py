def fact(a):
    ret = 1
    for i in range(1, a+1):
        ret *= i
    return ret

def comb(n, r):
    return fact(n) // (fact(n-r) * fact(r))

n = int(input())
x = n-1
answer = 1
if n%2 == 0: answer = 2
while x > (n//2):
    answer += comb(x, n-x)
    x -= 1
print(answer%10007)