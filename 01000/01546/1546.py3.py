n = int(input())
s = [int(x) for x in input().split()]

ss = sum(s)
print(ss/max(s)*100/n)