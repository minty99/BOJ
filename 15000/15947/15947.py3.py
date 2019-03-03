n = int(input())
m = n-1

s = [ 'baby', 'sukhwan', '2', '1', 'very', 'cute', '2', '1', 'in', 'bed', '2', '1', 'baby', 'sukhwan']
# s: 0~13

idx = m%14
out = s[idx]
rep = n // 14 + 1
if out == '2' and rep >= 4:
    out = 'tu+ru*' + str(rep+1)
elif out == '2': out = 'tu' + 'ru'*(rep+1)

if out == '1' and rep >= 5:
    out = 'tu+ru*' + str(rep)
elif out == '1': out = 'tu' + 'ru'*rep
print(out)
