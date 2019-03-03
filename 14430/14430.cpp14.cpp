#include <cstdio>
using namespace std;

int memo[310][310];
int v[310][310];
int n, m;

void DFS(int x, int y, int curr)
{
    if(memo[x][y] > curr) return;
    memo[x][y] = curr + v[x][y];
    if(x == n and y == m) return;
    if(x < 1 or x > n) return;
    if(y < 1 or y > m) return;
    DFS(x+1, y, memo[x][y]);
    DFS(x, y+1, memo[x][y]);
}

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &v[i][j]);
    DFS(1, 1, 0);
    printf("%d", memo[n][m]);
}
