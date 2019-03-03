#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
#include <queue>
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
vector<int> G[5000], V[5000];
bitset<5000> visited;
int visit[5000];
lli d1[5000];
pll d2[5000];
priority_queue<pll, vector<pll>, greater<pll>> pq1;
priority_queue<pll, vector<pll>, greater<pll>> pq2;

int main()
{
    // freopen("in.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        G[a].push_back(b);
        G[b].push_back(a);
        V[a].push_back(c);
        V[b].push_back(c);
    }

    int from = 1;
    for(int i = 1; i <= n; i++) d1[i] = 1e12;
    d1[from] = 0;
    int curr = from;
    while(true)
    {
        visited[curr] = true;
        for(int i = 0; i < G[curr].size(); i++)
        {
            int k = G[curr][i];
            int v = V[curr][i];
            d1[k] = min(d1[curr] + v*2, d1[k]);
            pq1.emplace(d1[k], k);
        }
        while(!pq1.empty() && visited[pq1.top().second]) pq1.pop();
        if(pq1.empty()) break;
        curr = pq1.top().second;
        pq1.pop();
    }

    for(int i = 1; i <= n; i++) d2[i] = { 1e12, 1e12 };
    curr = 1;
    d2[curr].second = 0;
    while(true)
    {
        bool visitFlag = false;
        for(int i = 0; i < G[curr].size(); i++)
        {
            int k = G[curr][i];
            int v = V[curr][i];
            lli a = d2[k].first;
            lli b = d2[k].second;
            d2[k].first = min(d2[curr].second + v, d2[k].first);
            d2[k].second = min(d2[curr].first + v*4, d2[k].second);
            if(a != d2[k].first)
            {
                pq2.emplace(d2[k].first, k);
                visitFlag = true;
            }
            if(b != d2[k].second)
            {
                pq2.emplace(d2[k].second, k);
                visitFlag = true;
            }
        }
        if(!visitFlag) visit[curr]++;
        while(!pq2.empty() && visit[pq2.top().second] == 2) pq2.pop();
        if(pq2.empty()) break;
        curr = pq2.top().second;
        pq2.pop();
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        // printf("%lld, %lld/%lld\n", d1[i], d2[i].first, d2[i].second);
        if(d1[i] < min(d2[i].first, d2[i].second)) ans++;
    }
    printf("%d", ans);
}
