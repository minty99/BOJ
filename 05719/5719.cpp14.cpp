#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

vector<int> v[505];
int adj[505][505];
vector<int> path;
bool dfsvisit[505];
vector<pii> kill_list;

int dijkstra(int s, int d)
{
    int dist[505], prev[505];
    bool visited[505];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 0; i < 505; i++) { dist[i] = 1e9; visited[i] = false; prev[i] = -1; }
    visited[501] = true;
    dist[s] = 0;
    pq.emplace(0, s);
    while(!pq.empty()) {
        pii p = pq.top();
        pq.pop();
        int currd = p.first;
        int curr = p.second;
        if(curr == d) break;
        if(visited[curr]) continue;
        visited[curr] = true;

        for(int to : v[curr]) {
            if(to == 501) continue;
            if(currd + adj[curr][to] < dist[to]) {
                dist[to] = currd + adj[curr][to];
                prev[to] = curr;
                pq.emplace(dist[to], to);
            }
        }
    }

    if(prev[d] == -1) return -1;
    return dist[d];
}

void DFS(int curr, int dest, int currlen, int target)
{
    if(currlen > target) return;
    if(dfsvisit[curr]) return;
    if(curr == dest) {
        if(currlen == target) {
            path.push_back(curr);
            int l = path.size();
            for(int i = 0; i < l; i++) {
                int ll = v[path[i]].size();
                for(int j = 0; j < ll; j++) {
                    if(v[path[i]][j] == path[i+1]) {
                        kill_list.emplace_back(path[i], j);
                        break;
                    }
                }
            }
            path.pop_back();
        }
        return;
    }

    path.push_back(curr);
    dfsvisit[curr] = true;
    int l = v[curr].size();
    for(int i = 0; i < l; i++)
        DFS(v[curr][i], dest, currlen + adj[curr][v[curr][i]], target);
    dfsvisit[curr] = false;
    path.pop_back();
}

int main()
{
    while(true) {
        int n, m, s, d;
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        scanf("%d %d", &s, &d);
        for(int i = 0; i < 505; i++) v[i].clear();
        memset(adj, 0, sizeof(adj));
        for(int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            v[a].push_back(b);
            adj[a][b] = c;
        }

        int optway = dijkstra(s, d);
        if(optway == -1) { printf("-1\n"); continue; }

        memset(dfsvisit, false, sizeof(dfsvisit));
        kill_list.clear();
        path.clear();
        DFS(s, d, 0, optway);
        int l = kill_list.size();
        for(int i = 0; i < l; i++) {
            pii p = kill_list[i];
            adj[p.first][v[p.first][p.second]] = 0;
            v[p.first][p.second] = 501;
        }

        optway = dijkstra(s, d);
        if(optway == -1) printf("-1\n");
        else printf("%d\n", optway);
    }
}
