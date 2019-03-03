m = [ int(x) for x in input().split() ]
m.sort()

answer = [(0, 0)]
idx = 0
n = int(input())
for i in range(len(m)):
    for j in range(i+1, len(m)):
        if m[i] + m[j] == n:
            if answer[idx] != (m[i], m[j]):
                answer.append((m[i], m[j]))
                print(m[i], m[j])
                idx += 1

print(idx)
