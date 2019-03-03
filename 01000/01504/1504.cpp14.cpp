#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
typedef long long lli;

int* dijkstra(vector<pii> G[], int start)
{
    int* dist = new int [1000];
    bool visited[1000];
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < 1000; i++) dist[i] = 1e9;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, start);
    while(!pq.empty())
    {
        int d, idx = -1;
        do
        {
            pii p = pq.top();
            d = p.first;
            idx = p.second;
            pq.pop();
        } while(visited[idx] && !pq.empty());
        if(idx == -1) break;
        visited[idx] = true;
        int sz = G[idx].size();
        for(int j = 0; j < sz; j++)
        {
            int fromHere = d + G[idx][j].second;
            int legacy = dist[G[idx][j].first];
            if(fromHere < legacy) dist[G[idx][j].first] = fromHere;

            if(!visited[G[idx][j].first]) pq.emplace(dist[G[idx][j].first], G[idx][j].first);
        }
    }
    return dist;
}

int main()
{
    vector<pii> G[1000];
    int v, e;
    scanf("%d %d", &v, &e);

    for(int i = 1; i <= e; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    int x, y;
    scanf("%d %d", &x, &y);

    int *dist1 = dijkstra(G, 1);
    int *dist2 = dijkstra(G, x);
    int *dist3 = dijkstra(G, y);

    if(x == 1 || x == v || y == 1 || y == v)
    {
        if(x > y)
        {
            int t = x;
            x = y;
            y = t;
        }
        if(x == 1)
        {
            // 1-y-n
            if(y == v)
            {
                if(dist1[v] >= 1e9) printf("-1");
                else printf("%d", dist1[v]);
            }
            else
            {
                if(dist1[y] >= 1e9 || dist3[v] >= 1e9) printf("-1");
                else printf("%d", dist1[y] + dist3[v]);
            }
        }
        return 0;
    }
    // 1-x-y-n
    // 1-y-x-n
    lli w1 = (lli) dist1[x] + dist2[y] + dist3[v];
    lli w2 = (lli) dist1[y] + dist3[x] + dist2[v];
    if(w1 >= 1e9 && w2 >= 1e9) printf("-1");
    else if(w1 <= w2) printf("%lld", w1);
    else printf("%lld", w2);
}
