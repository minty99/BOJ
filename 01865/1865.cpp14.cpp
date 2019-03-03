#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#define x first
#define y second

using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[501];
vector<int> upper;

int main()
{
    int t;
    scanf("%d", &t);
    // 0번 정점: 도착점.
    while(t --> 0)
    {
        for(int i = 1; i <= 500; i++) adj[i].clear();
        upper.clear();
        upper.resize(501);
        for(int i = 0; i <= 500; i++) upper[i] = 2e9;
        upper[1] = 0;
        int n, m, w;
        scanf("%d %d %d", &n, &m, &w);
        for(int i = 1; i <= m; i++)
        {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            if(e != 1) adj[s].emplace_back(e, t);
            if(e == 1) adj[s].emplace_back(0, t);
            if(s != 1) adj[e].emplace_back(s, t);
            if(s == 1) adj[e].emplace_back(0, t);
        }
        for(int i = 1; i <= w; i++)
        {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            if(e != 1) adj[s].emplace_back(e, -t);
            if(e == 1) adj[s].emplace_back(0, -t);
        }

        bool updated = false;
        for(int i = 1; i <= n+1; i++)
        {
            updated = false;
            for(int j = 0; j <= n; j++)
            {
                for(int k = 0; k < adj[j].size(); k++)
                {
                    int from = j;
                    int to = adj[j][k].x;
                    int cost = adj[j][k].y;
                    //printf("Check: from %d to %d, value %d and %d\n", from, to, upper[from]+cost, upper[to]);
                    if(upper[from] + cost < upper[to])
                    {
                        //printf("Relaxation: upper[%d] from %d to %d\n", to, upper[to], upper[from]+cost);
                        upper[to] = upper[from] + cost;
                        updated = true;
                    }
                }
            }
            if(!updated) break;
        }
        if(updated) printf("YES\n");
        else
        {
            //for(int i = 0; i <= n; i++) printf("%d ", upper[i]);
            if(upper[0] < 0) printf("YES\n");
            else printf("NO\n");
        }
    }
}
