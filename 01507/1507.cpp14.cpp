#include <cstdio>
#include <utility>
#include <queue>
#define x first
#define y second
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
int v[30][30];
int w[30][30];
int n;
priority_queue<pip, vector<pip>, greater<pip>> pq;

bool visited[30];

int calc_distance(int x, int y, int current, int target)
{
    if(current > target) return 5e7;
    if(x == y) return 0;
    visited[x] = true;
    int distance = 5e7;
    for(int i = 1; i <= n; i++)
    {
        if(i == x) continue;
        if(visited[i]) continue;
        if(w[x][i] > 0) distance = min(distance, w[x][i] + calc_distance(i, y, current + w[x][i], target));
    }
    visited[x] = false;
    return distance;
}

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &v[i][j]);
            if(i < j) pq.emplace(v[i][j], make_pair(i, j));
        }

    while(!pq.empty())
    {
        pip p = pq.top();
        pq.pop();
        pii pos = p.y;

        for(int i = 0; i < 30; i++) visited[i] = false;
        int dist = calc_distance(pos.x, pos.y, 0, v[pos.x][pos.y]);
        if(dist == v[pos.x][pos.y]) continue;
        if(dist < v[pos.x][pos.y]) { printf("-1\n"); return 0; }
        w[pos.x][pos.y] = v[pos.x][pos.y];
        w[pos.y][pos.x] = v[pos.y][pos.x];
    }

    int sum = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            sum += w[i][j];
    printf("%d\n", sum/2);

}
