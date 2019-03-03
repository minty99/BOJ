import sys
sys.setrecursionlimit(200000)

n = int(input())
v = [ list() for _ in range(n+10000) ]
w = [ list() for _ in range(n+10000) ]
visited = [ False for _ in range(n+10000) ]
tw = [ [0, 0] for _ in range(n+10000) ]
MOD = 1000000007

def DFS(idx):
    visited[idx] = True
    sq = 0
    for i in range(len(v[idx])):
        if visited[v[idx][i]]: continue
        diff = (DFS(v[idx][i]) + 1) * w[idx][i]
        tw[idx][0] += diff
        sq += diff * diff

    tw[idx][1] = (tw[idx][0] * tw[idx][0] - sq) // 2
    tw[idx][0] %= MOD
    tw[idx][1] %= MOD
    return tw[idx][0]


for i in range(1, n):
    a, b, c = [ int(x) for x in input().split() ]
    v[a] += [b]
    v[b] += [a]
    w[a] += [c]
    w[b] += [c]

DFS(1)

answer = 0
for i in range(1, n+1):
    answer += tw[i][0] + tw[i][1]
    answer %= MOD
print(answer)
