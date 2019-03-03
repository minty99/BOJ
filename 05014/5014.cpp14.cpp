#include <cstdio>
#include <queue>
#include <utility>
#include <bitset>
using namespace std;
typedef pair<int, int> pii;

queue<pii> Q;
bitset<1000000> visited;

int BFS(int f, int s, int g, int u, int d)
{
    Q.emplace(s, 0);
    visited[s] = true;
    while(!Q.empty())
    {
        pii p = Q.front();
        Q.pop();
        if(p.first == g) return p.second;
        if(p.first + u <= f and !visited[p.first + u])
        {
            Q.emplace(p.first + u, p.second + 1);
            visited[p.first + u] = true;
        }
        if(p.first - d > 0 and !visited[p.first - d])
        {
            Q.emplace(p.first - d, p.second + 1);
            visited[p.first - d] = true;
        }
    }
    return -1;
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    int ans = BFS(f, s, g, u, d);
    if(ans == -1) printf("use the stairs");
    else printf("%d", ans);
}
