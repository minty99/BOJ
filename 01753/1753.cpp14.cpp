#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

int dist[30000];
vector<pii> G[30000];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
    for(int i = 0; i < 30000; i++) dist[i] = 1e9;
    int v, e;
    scanf("%d %d", &v, &e);
    int k;
    scanf("%d", &k);
    dist[k] = 0;

    for(int i = 1; i <= e; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        G[a].emplace_back(b, c);
    }

    pq.push(make_pair(dist[k], k));

    while(!pq.empty())
    {
        pii p = pq.top();
        int d = p.first;
        int idx = p.second;
        pq.pop();

        int sz = G[idx].size();
        for(int j = 0; j < sz; j++)
        {
            int fromHere = d + G[idx][j].second;
            int legacy = dist[G[idx][j].first];
            if(fromHere < legacy)
            {
                dist[G[idx][j].first] = fromHere;
                pq.emplace(dist[G[idx][j].first], G[idx][j].first);
            }
        }
    }

    for(int i = 1; i <= v; i++)
    {
        if(dist[i] >= 1e9) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
}
