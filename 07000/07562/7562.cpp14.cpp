#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <queue>
#define x first
#define y second

using namespace std;
typedef pair<int, int> pii;
int l;
pii from, to;
class p3 {
    public:
        int x, y, z;

    p3(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

queue<p3> Q;
int visited[310][310];

int BFS(int x, int y)
{
    Q.emplace(x, y, 0);
    while(!Q.empty())
    {
        x = Q.front().x;
        y = Q.front().y;
        int z = Q.front().z;
        Q.pop();
        if(x < 0 || y < 0 || x >= l || y >= l) continue;
        if(visited[x][y]) continue;
        visited[x][y] = 1;
        if(x == to.x && y == to.y) return z;
        Q.emplace(x-2, y-1, z+1);
        Q.emplace(x-2, y+1, z+1);
        Q.emplace(x-1, y-2, z+1);
        Q.emplace(x-1, y+2, z+1);
        Q.emplace(x+1, y-2, z+1);
        Q.emplace(x+1, y+2, z+1);
        Q.emplace(x+2, y-1, z+1);
        Q.emplace(x+2, y+1, z+1);
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t --> 0)
    {
        memset(visited, 0, sizeof(visited));
        queue<p3> Qt;
        Q.swap(Qt);
        scanf("%d %d %d %d %d", &l, &from.x, &from.y, &to.x, &to.y);
        int out = BFS(from.x, from.y);
        printf("%d\n", out);
    }
}
