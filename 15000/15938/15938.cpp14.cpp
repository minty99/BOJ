#include <cstdio>
#include <cmath>
#define MOD 1000000007

typedef long long int lli;

bool v[402][402];
lli memo[402][402][2];
unsigned char curr[402][402][2];
int xs, ys, t, xh, yh, n;
lli ans = 0;
int d[4] = { 1, -1, 0, 0 };

void DFS(int x, int y, int depth)
{
    if(v[x][y] == true) { curr[x][y][depth&1] = depth; memo[x][y][depth&1] = 0; return; }
    if(x == xh && y == yh) { ans++; curr[x][y][depth&1] = depth; memo[x][y][depth&1] = 1; return; }
    if(depth == t) { curr[x][y][depth&1] = depth; memo[x][y][depth&1] = 0; return; }
    if(abs(x - xh) + abs(y - yh) + depth > t) { curr[x][y][depth&1] = depth; memo[x][y][depth&1] = 0; return; }
    if(depth == curr[x][y][depth&1]) { curr[x][y][depth&1] = depth; ans += memo[x][y][depth&1]; ans %= MOD; return; }

    DFS(x+1, y, depth+1);
    DFS(x-1, y, depth+1);
    DFS(x, y+1, depth+1);
    DFS(x, y-1, depth+1);

    memo[x][y][depth&1] = 0;
    memo[x][y][depth&1] += memo[x+1][y][~depth&1];
    memo[x][y][depth&1] += memo[x-1][y][~depth&1];
    memo[x][y][depth&1] += memo[x][y+1][~depth&1];
    memo[x][y][depth&1] += memo[x][y-1][~depth&1];
    memo[x][y][depth&1] %= MOD;

    curr[x][y][depth&1] = depth;
    return;
}

int main()
{
    scanf("%d %d %d %d %d %d", &xs, &ys, &t, &xh, &yh, &n);

    int a, b;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        a = a - xs + 200;
        b = b - ys + 200;
        if(0 <= a && a <= 400 && 0 <= b && b <= 400) v[a][b] = true;
    }

    xh = xh - xs + 200;
    yh = yh - ys + 200;
    xs = 200;
    ys = 200;

    curr[200][200][0] = curr[200][200][1] = -1;
    DFS(200, 200, 0);
    printf("%lld", ans % MOD);
}
