def rev(s):
    return str(s)[::-1]

def plus(x, y):
    return int(x) + int(y)

x, y = map(int, input().split())
print(int(rev(plus(rev(x), rev(y)))))
