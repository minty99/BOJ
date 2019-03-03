l, c = map(int, input().split())
s = input().split()
s.sort()
visited = [ False for _ in range(c) ]

def DFS(idx, ss):
    if len(ss) == l:
        cnt = 0
        for k in ss:
            if k in ['a', 'e', 'i', 'o', 'u']: cnt += 1
        if cnt >= 1 and l - cnt >= 2: print(ss)
        return
    visited[idx] = True
    for i in range(idx+1, c):
        if not visited[i]: DFS(i, ss + s[i])
    visited[idx] = False

for i in range(c): DFS(i, s[i])
