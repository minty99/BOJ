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

lli DFS(int x, int y, int depth)
{
    if(v[x][y] == true) { curr[x][y][depth&1] = depth; return memo[x][y][depth&1] = 0; }
    if(x == xh && y == yh) { ans++; ans %= MOD; curr[x][y][depth&1] = depth; return memo[x][y][depth&1] = 1; }
    if(depth == t) { curr[x][y][depth&1] = depth; return memo[x][y][depth&1] = 0; }
    if(abs(x - xh) + abs(y - yh) + depth > t) { curr[x][y][depth&1] = depth; return memo[x][y][depth&1] = 0; }
    if(depth > 0 && depth == curr[x][y][depth&1]) { curr[x][y][depth&1] = depth; ans += memo[x][y][depth&1]; ans %= MOD; return memo[x][y][depth&1]; }

    for(int i = 0; i < 4; i++) DFS(x+d[i], y+d[3-i], depth+1);
    memo[x][y][depth&1] = 0;
    for(int i = 0; i < 4; i++)
    {
        memo[x][y][depth&1] += memo[x+d[i]][y+d[3-i]][~depth&1];
    }
    memo[x][y][depth&1] %= MOD;
    curr[x][y][depth&1] = depth;
    return memo[x][y][depth&1];
}

int main()
{
    scanf("%d %d %d %d %d %d", &xs, &ys, &t, &xh, &yh, &n);

    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a = a - xs + 200;
        b = b - ys + 200;
        if(0 <= a && a <= 400 && 0 <= b && b <= 400) v[a][b] = true;
    }

    xh = xh - xs + 200;
    yh = yh - ys + 200;
    xs = 200;
    ys = 200;

    DFS(200, 200, 0);
    printf("%lld", ans % MOD);
}
